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

/*Primary method to set alignment for various types*/

void encode_declaration (TYPE type, VAR_ID_LIST varlist_id);

/*Provides the size of the base element given the type*/
unsigned int encode_get_base_size (TYPE type);

int getSize(TYPE type);
int get_local_var_offset();
void decl_encode(TYPE type, VAR_ID_LIST list_id);
int get_formal_param_offset(TYPETAG tag);


#endif
