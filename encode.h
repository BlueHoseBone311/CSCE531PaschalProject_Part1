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


#endif 