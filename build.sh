#!/bin/bash
# -*- coding: utf-8-unix -*-

GOSH=gosh
CFLAGS="-DHAVE_BOOL"

CB_BUILD=0
CB_CLEAN=0
CB_TEST=0

function cb_build ()
{
    mkdir -p log
    $GAUCHE_CONFIG --fixup-extension zinnialib zinnia
    $GOSH $GENSTUB zinnialib.stub
    if [ $? -ne 0 ]; then
        exit
    fi
    com="gcc -c zinnialib_head.c '-I$GAUCHE_INCDIR'"
    echo $com
    eval $com
    if [ $? -ne 0 ]; then
        exit
    fi
    com="gcc -c zinnialib_tail.c '-I$GAUCHE_INCDIR'"
    echo $com
    eval $com
    if [ $? -ne 0 ]; then
        exit
    fi
    com="LANG=C gcc -c zinnialib.c '-I$GAUCHE_INCDIR' $CFLAGS 2>&1 | tee log/zinnialib.c.log"
    echo $com
    eval $com
    if [ $? -ne 0 ]; then
        exit
    fi
    com="LANG=C gcc -c zinnia.c '-I$GAUCHE_INCDIR' $CFLAGS 2>&1 | tee log/zinnia.c.log"
    echo $com
    eval $com
    if [ $? -ne 0 ]; then
        exit
    fi
    com="LANG=C gcc -lmingw32 `gauche-config --dylib-ldflags` zinnia.dll *.o  -L. -lzinnia '-L$GAUCHE_LIBDIR' -lgauche-0.9"
    echo $com
    eval $com
    if [ $? -ne 0 ]; then
        exit
    fi
}

function cb_clean ()
{

    rm -f *.o
    rm -f zinnialib.c
    rm -f config.status
    rm -f configure
    rm -f *.exe
    rm -f zinnia.dll
    rm -f *.log
    rm -fr autom4te.*
    rm -f *_head.*
    rm -f *_tail.*

}

function cb_test ()
{
        #$GOSH -I. test/test-demon.scm
    $GOSH -I. -I./lib test.scm
}


while [ $# -gt 0 ]; do
    case "$1" in
        -g|debug)
            shift
            CFLAGS="$CFLAGS -DHAVE_BOOL -DDEBUG"
            ;;
        -gf|debugfunc)
            shift
            CFLAGS="$CFLAGS -DHAVE_BOOL -DDEBUG -DDEBUG_FUNC"
            ;;
        -t|test)
            shift
            CB_TEST=1
            ;;
        -lt|libtest)
            shift
            ;;
        -c|clean)
            shift
            CB_CLEAN=1
            ;;
        -b|build)
            CB_BUILD=1
            shift
            ;;
        *)
            shift
            ;;
    esac
done

GAUCHE_INCDIR=`gauche-config --incdirs`
GAUCHE_LIBDIR=`gauche-config --archdirs`
GAUCHE_CONFIG=gauche-config
GENSTUB=`gauche-config --syslibdir`
GENSTUB="$GENSTUB/genstub"

if [ $CB_BUILD -eq 1 ]; then
    cb_build
fi
if [ $CB_CLEAN -eq 1 ]; then
    cb_clean
fi
if [ $CB_TEST -eq 1 ]; then
    cb_test
fi
