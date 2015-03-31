#ifndef ENCODE_H
#define ENCODE_H
#include "types.h"
#include "symtab.h"
#include "message.h"
#include "backend-x86.h"

/*Primary method to set alignment for various types*/

void encode_declaration (TYPE type, VAR_ID_LIST varlist_id);


/*Allocates space for basic types */
unsigned int encode_get_base_size (TYPE type);



#endif 