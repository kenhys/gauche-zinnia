/*
 * zinnia.h
 */

/* Prologue */
#ifndef GAUCHE_ZINNIA_H
#define GAUCHE_ZINNIA_H

#include <gauche.h>
#include <gauche/extend.h>

SCM_DECL_BEGIN

#include "libzinnia.h"

extern ScmClass *CZinniaRecognizerClass;
extern ScmClass *CZinniaCharacterClass;
extern ScmClass *CZinniaResultClass;
extern ScmClass *CZinniaTrainerClass;

#define ZINNIA_RECOGNIZER_P(obj)      SCM_XTYPEP(obj, CZinniaRecognizerClass)
#define ZINNIA_RECOGNIZER_UNBOX(obj)  SCM_FOREIGN_POINTER_REF(zinnia_recognizer_t*, obj)
#define ZINNIA_RECOGNIZER_BOX(ptr)    Scm_MakeForeignPointer(CZinniaRecognizerClass, ptr)

#define ZINNIA_CHARACTER_P(obj)      SCM_XTYPEP(obj, CZinniaCharacterClass)
#define ZINNIA_CHARACTER_UNBOX(obj)  SCM_FOREIGN_POINTER_REF(zinnia_character_t*, obj)
#define ZINNIA_CHARACTER_BOX(ptr)    Scm_MakeForeignPointer(CZinniaCharacterClass, ptr)

#define ZINNIA_RESULT_P(obj)      SCM_XTYPEP(obj, CZinniaResultClass)
#define ZINNIA_RESULT_UNBOX(obj)  SCM_FOREIGN_POINTER_REF(zinnia_result_t*, obj)
#define ZINNIA_RESULT_BOX(ptr)    Scm_MakeForeignPointer(CZinniaResultClass, ptr)

#define ZINNIA_TRAINER_P(obj)      SCM_XTYPEP(obj, CZinniaTrainerClass)
#define ZINNIA_TRAINER_UNBOX(obj)  SCM_FOREIGN_POINTER_REF(zinnia_trainer_t*, obj)
#define ZINNIA_TRAINER_BOX(ptr)    Scm_MakeForeignPointer(CZinniaTrainerClass, ptr)

/*
 * The following entry is a dummy one.
 * Replace it for your declarations.
 */

extern ScmObj test_zinnia(void);

/* Epilogue */
SCM_DECL_END

#endif  /* GAUCHE_ZINNIA_H */
