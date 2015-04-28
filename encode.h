 /*@Title   encode.h - header for size calculations and code generating functions
 * @authors  Venugopal Boppa, Christopher A. Greer, Christian Merchant
 * @class   CSCE531
 * @Project Pascal Compiler Part II
 * @date    04-17-15
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

/*creates a new label and pushes it onto the exit label stack*/
void new_exit_label_push();

/*checks if the stack is empty, and then pops it off the stack and returns it*/
char *old_exit_label_pop();

/*Returns the label without popping off of the stack*/
char *current_exit_label_peek();

/*checks whether an exit label exists on the stack, returns TRUE if so*/
BOOLEAN check_exit_label_stack();

char * encode_for_preamble(EXPR var, EXPR init, int dir, EXPR limit);


void encode_dispatch(VAL_LIST vals, char * label);
#endif
