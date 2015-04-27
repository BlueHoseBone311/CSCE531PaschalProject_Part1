 /*@Title   encode.h - header for size calculations and code generating functions
 * @authors  Venugopal Boppa, Christopher A. Greer, Christian Merchant
 * @class   CSCE531
 * @Project Pascal Compiler Part III
 * @date    04-27-15
*/

#ifndef ENCODE_H
#define ENCODE_H
#include "types.h"
#include "symtab.h"
#include "message.h"
#include "backend-x86.h"
#include "tree.h"
#include "defs.h"

/*Primary method to set alignment for various types*/

extern int exit_label_top;
extern char *exit_label_stack[100];

void encode_declaration (TYPE type, VAR_ID_LIST varlist_id);

/*Provides the size of the base element given the type*/
unsigned int encode_get_base_size (TYPE type);

int getSize(TYPE type);
int get_local_var_offset();
void decl_encode(TYPE type, VAR_ID_LIST list_id);
int get_formal_param_offset(TYPETAG tag);
void begin_funct_body(char *global_funct_name, TYPE type, int local_var_offset);
void end_funct_body(char *global_funct_name, TYPE type);
void encode_unop(EXPR_UNOP op, EXPR expr);
void encode_binop(EXPR_BINOP b_op, EXPR expr);
void encode_funct_call(EXPR funct, EXPR_LIST args);
#endif
