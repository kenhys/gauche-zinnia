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

ScmObj test_zinnia(void)
{
    return SCM_MAKE_STR("zinnia is working");
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

    /* Register stub-generated procedures */
    Scm_Init_zinnialib(mod);
}
