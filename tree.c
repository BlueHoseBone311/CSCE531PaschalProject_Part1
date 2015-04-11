/*@Title   tree.c - Routines used by Bison for decl creation, and type building
 * @authors  Venugopal Boppa, Christopher A. Greer, Christian Merchant
 * @class   CSCE531
 * @Project Pascal Compiler Part II
 * @date    04-17-15
*/


#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "tree.h"
#include <string.h>
#include "encode.h"

static TYPE_LIST unresolved_Pointers = NULL; 

//Project 1 functions



void create_typename(ST_ID id,TYPE new_type)
{
	ST_DR new_rec;
	new_rec= stdr_alloc();

	//Fill the fields of the new symbol table data record
	new_rec->tag=TYPENAME;
	new_rec->u.typename.type=new_type;


	// Install the new data record in the symbol table
	if (!st_install(id, new_rec)) {
		error("This Type name is already installed");
	}

}//end create_typename


void create_gdecl(VAR_ID_LIST list,TYPE type)
{
  VAR_ID_LIST node;
  TYPETAG tag;

  ST_DR new_rec;
  BOOLEAN resolved;
  if (type == NULL) {
    error("Variable(s) must be of data type");
    return;
  }

  tag = ty_query(type);
  if (tag == TYFUNC || tag == TYERROR) {
      error("Variable(s) must be of data type");

      new_rec = stdr_alloc();
      new_rec->u.decl.type = type;
      new_rec->u.decl.sc = NO_SC;
      new_rec->tag = GDECL;

      if (tag == TYERROR) {
		new_rec->u.decl.err = TRUE;
      }

      resolved = st_install(list->id, new_rec);
      return;
   }
	while(list!=NULL)
	{

		resolve_all_ptr();

		new_rec = stdr_alloc();

		// Fill the fields of the new symbol table data record
		new_rec->tag=GDECL;
		new_rec->u.decl.type=type;
		new_rec->u.decl.sc=NO_SC;
		new_rec->u.decl.is_ref=FALSE;
		new_rec->u.decl.v.offset = 0;
		new_rec->u.decl.err =FALSE;


		// Install the new data record in the symbol table
		if (!st_install(list->id,new_rec)) {
			//writing an error message
			error("Duplicate variable declaration: \"%s\"", st_get_id_str(list->id));
			free(new_rec);
		}

		list=list->next;
	}//end while
}//create_gdecl


TYPE check_typename(ST_ID id) {

	ST_DR checktype;
	int check;

     //if the id is null then bug is found
	if (id == NULL)
		bug("null id passed.");

	if ((checktype = st_lookup(id, &check)) == NULL) {
		error("Undeclared type name: \"%s\"", st_get_id_str(id));
		return ty_build_basic(TYERROR);
	}

	return checktype->u.typename.type;

}//end check_typename

TYPE check_function_type(TYPE type) {

	if (ty_query(type) == TYERROR) {
		error("Error in the function return type");
		return ty_build_basic(TYERROR);
	}

	if (ty_query(type) == TYFUNC) {
		error("Function return type must be simple type");
		return type;
	}

	if (ty_query(type) == TYARRAY) {
		error("Function return type must be simple type");
		return type;
	}

	return type;
}//end check_function_type


TYPE check_array(TYPE type, INDEX_LIST i) {

	if (ty_query(type) == TYERROR) {
		error("Data type expected for array elements");
		return ty_build_basic(TYERROR);
	}
	if (ty_query(type) == TYFUNC) {
		error("Data type expected for array elements");
		error("Variable(s) must be of data type");
		return ty_build_basic(TYERROR);
	}

	return ty_build_array(type, i);
}//end check_array


VAR_ID_LIST build_var_id_list (VAR_ID_LIST list,ST_ID id)
{
  VAR_ID_LIST id_list;

  id_list = (VAR_ID_LIST) malloc(sizeof(VAR_ID));

  id_list->id = id;

  id_list->next = NULL;

  if (list!=NULL)
  {
	  // pushing the list to the back of new id
        id_list->next=list;
  }

  return id_list;

}//end build_var_id_list


PARAM_LIST build_param_list(VAR_ID_LIST id_list,TYPE type,BOOLEAN value)
{

	VAR_ID_LIST id_parm = id_list;
	PARAM_LIST head = NULL;
    PARAM_LIST new;

	while(id_parm != NULL)
	{
          //adding values to the new id
	   new = (PARAM_LIST) malloc(sizeof(PARAM));
       new->id = id_parm->id;
       new->type = type;
	   new->sc = NO_SC;
	   new->err = FALSE;
       new->is_ref = value;
	   new->prev = NULL;
	   new->next = NULL;

       new->next=head;
       head=new;

       id_parm = id_parm->next;
	}//end while

	return new;

}//end build_param_list


PARAM_LIST check_param(PARAM_LIST p)
{

	if (!p){
		bug("%s:%d check_params received a NULL pointer\n", __FILE__, __LINE__);
	}
	if (!p->id){
		bug("%s:%d check_params received a pointer to NULL id\n", __FILE__, __LINE__);
	}


	PARAM_LIST c = p->next;
	while (c) {
		if (!strcmp(st_get_id_str(p->id), st_get_id_str(c->id))) {
			// ids are identical, return null instead of duplicate
			error("Duplicate parameter name: \"%s\"", st_get_id_str(p->id));
		}
		if (ty_query(c->type) == TYARRAY || ty_query(c->type) == TYFUNC) {
			error("Parameter type must be a simple type");
		}
		c = c->next;
	}

	return p;
}//end check_param



PARAM_LIST concat_param_list (PARAM_LIST list1,PARAM_LIST list2)
{
	if (!list1 && !list2){
		return NULL;
	}
	if (!list1){
		return list2;
	}
	if (!list2){
		return list1;
	}

	PARAM_LIST new_list;
	new_list=list1;
	while (new_list->next!=NULL)
	{
		new_list=new_list->next;
	}
	new_list->next=list2;

	return list1;
}//end concat_param_list


INDEX_LIST concat_index_list (INDEX_LIST list1,TYPE type)
{
	INDEX_LIST temp, new_list;

	new_list = (INDEX_LIST) malloc(sizeof(INDEX));
	new_list = create_list_from_type(type);

	temp=list1;
	while (temp->next)
	{
		temp = temp->next;
	}
	temp->next = new_list;

	return list1;

}//end concat_index_list



INDEX_LIST create_list_from_type(TYPE type)
{
	if (ty_query(type) == TYERROR) return NULL;
	INDEX_LIST index;
	index=(INDEX_LIST) malloc(sizeof(INDEX));
	index->type=type;
	index->next=NULL;
	index->prev=NULL;
	return index;
}//end create_list_from_type

TYPE check_unresolved(ST_ID id)
{
	TYPE new_ptr; 
	if (id == NULL)
	{
		bug ("tried to pass a null id in check_unresolved");
	}

	TYPE_LIST node = (TYPE_LIST) malloc(sizeof(TLIST_NODE));
	new_ptr = ty_build_unresolved_ptr(id);
	node->type = new_ptr; 
	node->next = NULL;

	if (unresolved_Pointers == NULL)
	{
		unresolved_Pointers = node; 
	}	
	else
	{
		while (unresolved_Pointers->next != NULL)
		{	
			unresolved_Pointers = unresolved_Pointers->next;
	    }
	    unresolved_Pointers->next = node; 
	    unresolved_Pointers->next->prev = unresolved_Pointers; 
    }	      

	return new_ptr; 
} 

void resolve_all_ptr()
{
	int holder;
	ST_ID id;
	ST_DR data_rec;
	TYPE type;

	while(unresolved_Pointers!=NULL)
	{
		type = ty_query_ptr(unresolved_Pointers->type, &id);
		data_rec = st_lookup(id, &holder);
		if (data_rec == NULL) {
			error("Unresolved type name: \"%s\"", st_get_id_str(id));
			continue;
		}
		if (data_rec->tag == TYPENAME)
		{
			if(!ty_resolve_ptr(type, data_rec->u.typename.type))
				error("Unresolved type name: \"%s\"", st_get_id_str(id));
		}
		else
		{
			error("Unidentified type tag\n");
		}
		unresolved_Pointers = unresolved_Pointers->next;
	}//end while
	
	unresolved_Pointers = NULL; 
}//end resolve_all_ptr



TYPE check_subrange(long low, long high)
{
      TYPE subrange;
      if(low > high)
      {
         error("Empty subrange in array index");
         error("illegal index type (ignored)");
         subrange = ty_build_basic(TYERROR);
       }
      else
      {
         subrange = ty_build_subrange(ty_build_basic(TYSIGNEDLONGINT), low, high);
      }

      return subrange;
}
