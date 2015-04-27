/*@Title   main.c - Main method for a Pascal language declaration compiler
 * @authors  Venugopal Boppa, Christopher A. Greer, Christian Merchant
 * @class   CSCE531
 * @Project Pascal Compiler Part III
 * @date    04-27-15
*/


#include "defs.h"
#include "types.h"
#include "symtab.h"

#include <stdio.h>

FILE *errfp;		/* file to which message.c will write */

/* For debugging purposes only */
#ifdef YYDEBUG
extern int yydebug;
#endif

int main()
{
	int status, yyparse();

	errfp = stderr;
	ty_types_init();
	st_init_symtab();
	st_establish_data_dump_func(stdr_dump);
#ifdef YYDEBUG
	yydebug = 1;		/* DEBUG */
#endif
	status = yyparse();
#if 0
	st_dump();
#endif
	return status;
}

