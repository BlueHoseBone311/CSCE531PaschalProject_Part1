#ifndef TREE_C
#define TREE_C
#include "types.h"
#include "symtab.h"
#include "message.h"


//definitions for a list of multiple variables
typedef struct var_id {
    ST_ID id;
    struct var_id *next;
} VAR_ID, *VAR_ID_LIST;


void create_typename(ST_ID id,TYPE new_type);
/*
	This function creates a new type name record and installs it in on the symbol table.
  	If the type name is already installed in the symbol table a message is issued.
*/

void create_gdecl(VAR_ID_LIST list,TYPE type);
//This function creates a global var parameter list

TYPE check_typename( ST_ID id );
/*
	This function checks if an ST_ID is already installed in the symbol table and if not an error message is created.
   	If an error message is created it returns the error type otherwise it returns the original type
*/

TYPE check_array(TYPE array, INDEX_LIST i);
/*
	This function checks an array to see if it's element type is valid.
 	If the type is not valide an error is issued.
*/

TYPE check_function_type(TYPE t);
/*
	Checks a function type to see if it's a simple type and if not returns an error.
*/

VAR_ID_LIST build_var_id_list (VAR_ID_LIST list,ST_ID id);
/*
	Builds a variable id list by pushing the new id to the front of the list.
*/

PARAM_LIST build_param_list(VAR_ID_LIST id_list,TYPE type,BOOLEAN value);
/*
	Builds a parameter list from a type list
*/

PARAM_LIST concat_param_list (PARAM_LIST list1,PARAM_LIST list2);
/*
	Concatenates two parameter lists together as one.
 	 Returns the newly combined parameter list.
*/

PARAM_LIST check_param(PARAM_LIST p);
/*
	Checks to see if the parameter list is a simple type
	If the is is null it calls the bug message to report a compiler bug.
*/

INDEX_LIST concat_index_list (INDEX_LIST list1,TYPE type);
/*
	This function adds a new node at the end of an index list.
 	Returns the new index list
*/

INDEX_LIST create_list_from_type(TYPE type);
/*
	This function creates the index list for the arrays.
 	It returns the index list
*/
TYPE_LIST create_unresolved_ptr(TYPE type);
/*
	This function creates the unresolved list for the ptrs
	It returns a type_list
*/
void resolve_all_ptr();
/*
	Traverses the linked list of unresolved pointers and resolves them..
 	An error message is issued for every unresolved pointer.
*/

<<<<<<< HEAD
TYPE check_subrange(long low, long high); 	
=======
TYPE check_subrange(int low, int high);
>>>>>>> 8c8c57f75b93f25f75b07d28790b4d613489599b

#endif

