/*
 * zinnia.c
 */

#include "zinnia.h"

/*
 * The following function is a dummy one; replace it for
 * your C function definitions.
 */

ScmClass *CZinniaRecognizerClass;
ScmClass *CZinniaCharacterClass;
ScmClass *CZinniaResultClass;
ScmClass *CZinniaTrainerClass;

static void czinnia_recognizer_print(ScmObj obj, ScmPort *out, ScmWriteContext *ctx)
{
  zinnia_recognizer_t *p = ZINNIA_RECOGNIZER_UNBOX(obj);
  Scm_Printf(out, "#<zinnia_recognizer_t \"%p\">", p);
}

static void czinnia_recognizer_cleanup(ScmObj obj)
{
  zinnia_recognizer_t *p = ZINNIA_RECOGNIZER_UNBOX(obj);
}

static void czinnia_character_print(ScmObj obj, ScmPort *out, ScmWriteContext *ctx)
    
{
  zinnia_character_t *p = ZINNIA_CHARACTER_UNBOX(obj);
  Scm_Printf(out, "#<zinnia_character_t \"%p\">", p);
}

static void czinnia_character_cleanup(ScmObj obj)
{
  zinnia_character_t *p = ZINNIA_CHARACTER_UNBOX(obj);
}

static void czinnia_result_print(ScmObj obj, ScmPort *out, ScmWriteContext *ctx)
{
  zinnia_result_t *p = ZINNIA_RESULT_UNBOX(obj);
  Scm_Printf(out, "#<zinnia_result_t \"%p\">", p);
}

static void czinnia_result_cleanup(ScmObj obj)
{
  zinnia_result_t* q;
  q = ZINNIA_RESULT_UNBOX(obj);
}


/*
 * Module initialization function.
 */
extern void Scm_Init_zinnialib(ScmModule*);

void Scm_Init_zinnia(void)
{
    ScmModule *mod;

    /* Register this DSO to Gauche */
    SCM_INIT_EXTENSION(zinnia);

    /* Create the module if it doesn't exist yet. */
    mod = SCM_MODULE(SCM_FIND_MODULE("zinnia", TRUE));

  /* Create the foreign pointer class <mqueue-cpp>.
       The flag SCM_FOREIGN_POINTER_KEEP_IDENTITY makes Gauche to keep
       one-to-one mapping between the foreign object pointer (MQueue*)
       and its wrapping ScmObj.  With this flag, you can assume that
       when mqueue_cleanup is called, no other ScmForeignPointer object
       is pointing to the same MQueue*, thus you can delete it safely. */
    CZinniaRecognizerClass =
        Scm_MakeForeignPointerClass(mod, "<zinnia-recognizer>",
                                    czinnia_recognizer_print,
                                    czinnia_recognizer_cleanup,
                                    SCM_FOREIGN_POINTER_KEEP_IDENTITY|SCM_FOREIGN_POINTER_MAP_NULL);

      /* Create the foreign pointer class <mqueue-cpp>.
       The flag SCM_FOREIGN_POINTER_KEEP_IDENTITY makes Gauche to keep
       one-to-one mapping between the foreign object pointer (MQueue*)
       and its wrapping ScmObj.  With this flag, you can assume that
       when mqueue_cleanup is called, no other ScmForeignPointer object
       is pointing to the same MQueue*, thus you can delete it safely. */
    CZinniaCharacterClass =
        Scm_MakeForeignPointerClass(mod, "<zinnia-character>",
                                    czinnia_character_print,
                                    czinnia_character_cleanup,
                                    SCM_FOREIGN_POINTER_KEEP_IDENTITY|SCM_FOREIGN_POINTER_MAP_NULL);

      /* Create the foreign pointer class <mqueue-cpp>.
       The flag SCM_FOREIGN_POINTER_KEEP_IDENTITY makes Gauche to keep
       one-to-one mapping between the foreign object pointer (MQueue*)
       and its wrapping ScmObj.  With this flag, you can assume that
       when mqueue_cleanup is called, no other ScmForeignPointer object
       is pointing to the same MQueue*, thus you can delete it safely. */
    CZinniaResultClass =
        Scm_MakeForeignPointerClass(mod, "<zinnia-result>",
                                    czinnia_result_print,
                                    czinnia_result_cleanup,
                                    SCM_FOREIGN_POINTER_KEEP_IDENTITY|SCM_FOREIGN_POINTER_MAP_NULL);

    /* Register stub-generated procedures */
    Scm_Init_zinnialib(mod);
}
