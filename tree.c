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


//Project II functions
EXPR make_convert_expr(EXPR sub_expr, TYPE type)
{
  EXPR expr;
  expr = make_un_expr(CONVERT_OP, sub_expr);
  expr->type = type;

  return expr;
}//end make_convert_expr
EXPR check_assign(EXPR assign)
{
  EXPR left, right;
  TYPETAG left_tag, right_tag;
  left = assign->u.binop.left;
  right = assign->u.binop.right;

  left_tag = ty_query(left->type);
  right_tag = ty_query(right->type);
  if (right_tag == TYERROR || left_tag == TYERROR) {
    return make_error_expr();
  }
  if (left_tag == right_tag) {
    return assign;
  }
  if (left_tag == TYDOUBLE) {

    if (right_tag != TYFLOAT && right_tag != TYSIGNEDLONGINT) {
      error("Illegal conversion");
      return make_error_expr();
    }
    if (right_tag == TYFLOAT || right_tag == TYSIGNEDLONGINT) {

      if (assign->u.binop.right->tag == INTCONST) {
	assign->u.binop.right = make_realconst_expr(assign->u.binop.right->u.intval);
      } else {
	assign->u.binop.right = make_convert_expr(assign->u.binop.right, ty_build_basic(TYDOUBLE));
      }
    }

    return assign;
  }
  if (left_tag == TYFLOAT) {


    if (right_tag != TYDOUBLE && right_tag != TYSIGNEDLONGINT) {
      error("Illegal conversion");
      return make_error_expr();
    }
    assign->u.binop.right = make_convert_expr(assign->u.binop.right, ty_build_basic(TYFLOAT));

    return assign;
  }
  if (left_tag == TYUNSIGNEDCHAR && right->tag == STRCONST) {

    if (strlen(right->u.strval) != 1) {
      error("Illegal conversion");
      return make_error_expr();
    }

    assign->u.binop.right = make_intconst_expr(right->u.strval[0], ty_build_basic(TYSIGNEDLONGINT));

    return assign;
  }

  if (left_tag == TYUNSIGNEDCHAR && right_tag == TYSIGNEDLONGINT) {
     return assign;
  }
  error("Illegal conversion");
  return make_error_expr();
}


BOOLEAN isTagCharNum(TYPETAG t)
{
  switch (t) {
    case TYSIGNEDLONGINT:
    case TYFLOAT:
    case TYDOUBLE:
    case TYUNSIGNEDCHAR:
    case TYSIGNEDCHAR:
      return TRUE;
  }

  return FALSE;
}

BOOLEAN isTagNumerical(TYPETAG t)
{
  switch (t)
  {
    case TYSIGNEDLONGINT:
    case TYFLOAT:
    case TYDOUBLE:
      return TRUE;
  }

  return FALSE;
}


EXPR castIntExpr(EXPR expr)
{

  if (expr->tag == INTCONST) {
    expr = make_realconst_expr(expr->u.intval);
  }

  if (expr->tag == UNOP && expr->u.unop.op == CONVERT_OP && expr->u.unop.operand->tag == INTCONST)
   {
    expr = make_realconst_expr(expr->u.unop.operand->u.intval);
  }

  return expr;
}


EXPR make_intconst_expr(long val, TYPE type) {
   EXPR ret;
   ret = (EXPR)malloc(sizeof(EXPR_NODE));
   assert(ret != NULL);
   ret->tag = INTCONST;
   ret->type = ty_build_basic(TYSIGNEDLONGINT);
   ret->u.intval = val;

   if (ty_query(type) != TYSIGNEDLONGINT) {
      ret = make_convert_expr(ret, type);
   }
   return ret;
}//end make_intconst_expr

EXPR make_realconst_expr(double val) {
   EXPR ret;
   ret = (EXPR)malloc(sizeof(EXPR_NODE));
   assert(ret != NULL);
   ret->tag = REALCONST;
   ret->type = ty_build_basic(TYDOUBLE);
   ret->u.realval = val;
   return ret;
}//end make_realconst_expr

EXPR make_strconst_expr(char *str) {
   EXPR ret;
   ret = (EXPR)malloc(sizeof(EXPR_NODE));
   assert(ret != NULL);
   ret->tag = STRCONST;
   ret->type = ty_build_ptr(ty_build_basic(TYUNSIGNEDCHAR));
   ret->u.strval = str;
   return ret;
}//end make_strconst_expr

EXPR make_null_expr(EXPR_NULLOP op) {
   EXPR ret;
   ret = (EXPR)malloc(sizeof(EXPR_NODE));
   assert(ret != NULL);
   ret->tag = NULLOP;
   ret->u.nullop.op = op;

   if (op == NIL_OP) {
      ret->type = ty_build_basic(TYVOID);
   }
   else if (op == NULL_EOF_OP || op == NULL_EOLN_OP) {
      ret->type = ty_build_basic(TYSIGNEDCHAR);
   }
   return ret;
}//end make_null_expr

EXPR make_error_expr() {
   EXPR ret;
   ret = (EXPR)malloc(sizeof(EXPR_NODE));
   assert(ret != NULL);
   ret->tag = ERROR;
   ret->type = ty_build_basic(TYERROR);
   return ret;
}//make_error_expr

EXPR make_id_expr(ST_ID id) {
   ST_DR data_rec;
   int block;
   EXPR ret;
   ret = (EXPR)malloc(sizeof(EXPR_NODE));
   assert(ret != NULL);

   //look up information for id, error if not found or TYPENAME
   data_rec = st_lookup(id, &block);
   if (data_rec == NULL) {
      error("Undeclared identifier \"%s\" in expression", st_get_id_str(id));
      return make_error_expr();
   }

   if (data_rec->tag == TYPENAME) {
      error("Identifier \"%s\" installed as TYPENAME", st_get_id_str(id));
      return make_error_expr();
   }

   //switch statement to fill rest of fields for ret
   ret->type = data_rec->u.decl.type;
   switch(data_rec->tag) {
      case GDECL:
         ret->tag = GID;
         ret->u.gid = id;
         break;
      case LDECL:
      case PDECL:
         ret->tag = LVAR;
         ret->u.lvar.is_ref = data_rec->u.decl.is_ref;
         ret->u.lvar.link_count = st_get_cur_block() - block;
         ret->u.lvar.offset = data_rec->u.decl.v.offset;
         break;
      case FDECL:
         if (block <= 1) {
            ret->tag = GID;
            ret->u.gid = id;
         }
         else {
            ret->tag = LFUN;
            ret->u.lfun.global_name = data_rec->u.decl.v.global_func_name;
            ret->u.lfun.link_count = st_get_cur_block() - block;
         }
         break;

      default: ("Hit default in make_id_expr");

   }
   return ret;
}// end make_id_expr

EXPR make_un_expr(EXPR_UNOP op, EXPR sub) {
   /*new node variables & initial assignments*/
   EXPR ret;
   ret = (EXPR)malloc(sizeof(EXPR_NODE));
   assert(ret != NULL);
   ret->tag = UNOP;
   ret->type = sub->type;
   ret->u.unop.op = op;
   ret->u.unop.operand = sub;
   /*querying variables*/
   TYPETAG sub_tag = ty_query(sub->type);
   ST_ID id;
   TYPE base_type,next;
   long low, high;


   if (op == DEREF_OP) {
      return ret;
   }


   sub_tag = ty_query(sub->type);
   //subexpression is unary-converted
   if (is_lval(sub) == FALSE) {
      if (sub_tag == TYFLOAT) {
         EXPR convertedNode = make_un_expr(CONVERT_OP, sub);
         convertedNode->type = ty_build_basic(TYDOUBLE);
         ret->u.unop.operand = convertedNode;
      }
      else if (sub_tag == TYSUBRANGE) {
         EXPR convertedNode = make_un_expr(CONVERT_OP, sub);
         base_type = ty_query_subrange(sub->type, &low, &high);
         convertedNode->type = base_type;
         ret->u.unop.operand = convertedNode;
      }
   }

   sub_tag = ty_query(sub->type);
   //switch statement on op for error checking
   switch (op) {
      case CONVERT_OP:
         break;
      case DEREF_OP:
         break;
      case NEG_OP:
         //must be of type TYSIGNEDLONGINT, TYDOUBLE
         if (sub_tag != TYSIGNEDLONGINT &&  sub_tag != TYDOUBLE) {
            error("Incorrect type in NEG_OP");
            return make_error_expr();
         }
            sub->u.intval = sub->u.intval * -1;
            ret->type = ty_build_basic(TYSIGNEDLONGINT);
         break;
      case ORD_OP:
         //must be CHAR
         if (sub_tag != TYUNSIGNEDCHAR && sub_tag != TYSIGNEDCHAR) {
           /* error("Incorrect type in ORD_OP");
            return make_error_expr();*/
         }

         //since it returns int...I think the type needs to be changed
         ret->type = ty_build_basic(TYSIGNEDLONGINT);
         break;
      case CHR_OP:
         //converts byte value to char value...check type
         if (sub_tag != TYSIGNEDLONGINT && sub_tag != TYDOUBLE ) {
            error("Incorrect type in CHR_OP");
            return make_error_expr();
         }

         //returns char so updated type
         ret->type = ty_build_basic(TYUNSIGNEDCHAR);
         break;
      case UN_SUCC_OP:
         //check type, must be ordinal type
         if (sub_tag != TYSIGNEDLONGINT && sub_tag != TYDOUBLE && sub_tag != TYUNSIGNEDCHAR) {
            error("Incorrect type in UN_SUCC_OP");
            return make_error_expr();
         }
         break;
      case UN_PRED_OP:
         if (sub_tag != TYSIGNEDLONGINT && sub_tag != TYDOUBLE && sub_tag != TYUNSIGNEDCHAR) {
            error("Incorrect type in UN_PRED_OP");
            return make_error_expr();
         }
         break;
      case UPLUS_OP:
         //check type
         if (sub_tag != TYSIGNEDLONGINT && sub_tag != TYDOUBLE) {
            error("Incorrect type in UPLUS_OP");
            return make_error_expr();
         }
         break;
      case INDIR_OP:
         //returns a pointer, not sure if any other errors/checks
         ret->type = ty_query_ptr(sub->type, &id);
      default:
         break;
   }
   return ret;
}//make_un_expr
EXPR perform_expr_op(EXPR expr){

	EXPR_BINOP op;
	double real_val;
	long int_val;
	TYPETAG tag;
	op = expr->u.binop.op;
  	tag = ty_query(expr->type);

  	switch(op)
	   {
	    case ASSIGN_OP:    break;
	    case ADD_OP:
	    case SUB_OP:
	    case MUL_OP:
	    case DIV_OP:
	    case MOD_OP:
    	case REALDIV_OP:
    		if((expr->u.binop.left->tag == INTCONST || expr->u.binop.left->tag == REALCONST) && (expr->u.binop.right->tag == INTCONST || expr->u.binop.right->tag == REALCONST))
   	      	{
				//determine if real operation
				if(tag == TYDOUBLE || tag == TYFLOAT)
				{
					//determine if left value is real or int
					if(expr->u.binop.left->tag == REALCONST)
					{
					    real_val = expr->u.binop.left->u.realval;
					}
					else
					{
						real_val = expr->u.binop.left->u.intval;
	  		      	}

	  		      	//determine if right value is real or int and perform necessary operation
	  		      	if(expr->u.binop.right->tag == REALCONST)
	  		      	{
						switch(op)
						{
							case ADD_OP:
								real_val += expr->u.binop.right->u.realval;
								break;
							case SUB_OP:
								real_val -= expr->u.binop.right->u.realval;
								break;
							case MUL_OP:
								real_val *= expr->u.binop.right->u.realval;
								break;
							case DIV_OP:
								real_val /= expr->u.binop.right->u.realval;
								break;
						}//end real operations rigth side real

					}//end if
					else
					{
						switch(op)
						{
							case ADD_OP:
								real_val += expr->u.binop.right->u.intval;
								break;
							case SUB_OP:
								real_val -= expr->u.binop.right->u.intval;
								break;
							case MUL_OP:
								real_val *= expr->u.binop.right->u.intval;
								break;
							case DIV_OP:
								real_val /= expr->u.binop.right->u.intval;
								break;
						}//end real operations right side int
					}//end else

				 expr = make_realconst_expr(real_val);
			 	}//end if to determine if real operations

			 	else
			 	{
				    int_val=expr->u.binop.left->u.intval;

					 switch(op)
					 {
						case ADD_OP:
							int_val += expr->u.binop.right->u.intval;
							break;
	    				case SUB_OP:
	    					int_val -= expr->u.binop.right->u.intval;
	    					break;
	    				case MUL_OP:
	    					int_val *= expr->u.binop.right->u.intval;
	    					break;
						case DIV_OP:
							int_val /= expr->u.binop.right->u.intval;
							break;
	    				case MOD_OP:
	    					int_val %= expr->u.binop.right->u.intval;
	    					break;
    					case REALDIV_OP:
    						int_val += expr->u.binop.right->u.intval;
					}//end int operations

			    	expr=make_intconst_expr(int_val,ty_build_basic(TYSIGNEDLONGINT));
				}//end else
			}//end if
		break;//end of math operations in swith statement
		case EQ_OP:
	    case LESS_OP:
	    case LE_OP:
	    case NE_OP:
	    case GE_OP:
	    case GREATER_OP:
	      if (expr->u.binop.left->tag == INTCONST && expr->u.binop.right->tag == INTCONST)
	      {
		   if(op==EQ_OP)
	             {
			  int_val = expr->u.binop.left->u.intval == expr->u.binop.left->u.intval;
		     }
	       else if(op==LESS_OP)
		     {
		  	int_val = expr->u.binop.left->u.intval < expr->u.binop.left->u.intval;
		     }
	       else if(op==LE_OP)
	            {
		       int_val = expr->u.binop.left->u.intval <= expr->u.binop.left->u.intval;
		     }
	       else if(op==NE_OP)
		    {
		       int_val = expr->u.binop.left->u.intval != expr->u.binop.left->u.intval;
		    }
	       else if(op==GE_OP)
	            {
		       int_val = expr->u.binop.left->u.intval >= expr->u.binop.left->u.intval;
		    }
	       else if(op==GREATER_OP)
		    {
		        int_val = expr->u.binop.left->u.intval > expr->u.binop.left->u.intval;
	      	}

	      expr = make_intconst_expr(int_val, ty_build_basic(TYSIGNEDLONGINT));
		  expr = make_convert_expr(expr, ty_build_basic(TYSIGNEDCHAR));
	 	 }//end if
		else if(expr->u.binop.left->tag==STRCONST&&expr->u.binop.right->tag==STRCONST && strlen(expr->u.binop.left->u.strval) == 1 && strlen(expr->u.binop.right->u.strval) == 1)
        {
	   		if(op==EQ_OP)
      	    {
	         	int_val = expr->u.binop.left->u.strval[0] == expr->u.binop.left->u.strval[0];
	     	}
            else if(op==LESS_OP)
            {
	         	int_val = expr->u.binop.left->u.strval[0] < expr->u.binop.left->u.strval[0];
	     	}
           	else if(op==LE_OP)
            {
	        	 int_val=expr->u.binop.left->u.strval[0] <= expr->u.binop.left->u.strval[0];
	      	}
            else if(op == NE_OP)
            {
	      	    int_val = expr->u.binop.left->u.strval[0] != expr->u.binop.left->u.strval[0];
	     	}
         	else if (op == GE_OP)
            {
	     	      int_val = expr->u.binop.left->u.strval[0] >= expr->u.binop.left->u.strval[0];
	     	}
         	else if (op == GREATER_OP)
            {
	     	     int_val = expr->u.binop.left->u.strval[0] > expr->u.binop.left->u.strval[0];
	     	}
		expr = make_intconst_expr(int_val, ty_build_basic(TYSIGNEDLONGINT));
		expr = make_convert_expr(expr, ty_build_basic(TYSIGNEDCHAR));
      	}//end else if

	}//end swith statement

	return expr;

}//end perform_expr_op

EXPR make_bin_expr(EXPR_BINOP op, EXPR left, EXPR right)
{
  EXPR ret;
  TYPE next;
  long low, high;

  if(left->tag == ERROR || right->tag == ERROR) {
    return make_error_expr();
  }

  ret = malloc(sizeof(EXPR_NODE));
  ret->tag = BINOP;
  ret->type = right->type;
  ret->u.binop.op = op;
  ret->u.binop.left = left;
  ret->u.binop.right = right;
  ret = perform_expr_op(ret);
  if(ret->tag!=BINOP)
  {
    return ret;
  }

  TYPETAG left_type = ty_query(left->type);
  TYPETAG right_type = ty_query(right->type);

  if(op==ASSIGN_OP)
   {

    if(is_lval(left) != TRUE)
     {
      error("Assignment requires l-value on the left");
      return make_error_expr();
     }
    if(is_lval(right) && is_lval(left) == TRUE)
    {
     right = ret->u.binop.right = make_un_expr(DEREF_OP, right);
    }
    if(right_type == TYVOID)
     {
      error("Cannot convert between nondata types");
      return make_error_expr();
    }
    if(right_type == TYFLOAT)
     {
      ret->u.binop.right = make_convert_expr(right, ty_build_basic(TYDOUBLE));
    }
   else if(right_type == TYSUBRANGE)
    {
      next = ty_query_subrange(right->type, &low, &high);
      ret->u.binop.right = make_convert_expr(right, next);
    }
    return check_assign(ret);
  }

  if (is_lval(left))
  {
    ret->u.binop.left = make_un_expr(DEREF_OP, left);
  }
  if (is_lval(right))
  {
    ret->u.binop.right = make_un_expr(DEREF_OP, right);
  }

  if(left_type==TYFLOAT || left_type==TYSUBRANGE)
   {

    if (left_type == TYFLOAT)
    {
      ret->u.binop.left = make_convert_expr(left, ty_build_basic(TYDOUBLE));
    }
   else
     {
      next = ty_query_subrange(left->type, &low, &high);
      ret->u.binop.left = make_convert_expr(left, next);
    }
    left_type = ty_query(ret->u.binop.left->type);
  }

  if (left_type == TYFLOAT || right_type == TYSUBRANGE) {

    if (right_type == TYFLOAT)
    {
      ret->u.binop.right = make_convert_expr(right, ty_build_basic(TYDOUBLE));
    }
  else
   {
      next = ty_query_subrange(right->type, &low, &high);
      ret->u.binop.right = make_convert_expr(right, next);
    }

    right_type = ty_query(ret->u.binop.right->type);
  }

  if (left_type == TYDOUBLE || right_type == TYDOUBLE)
   {
    if (left_type == TYSIGNEDLONGINT) {
      ret->u.binop.left = make_convert_expr(ret->u.binop.left, ty_build_basic(TYDOUBLE));

     left_type = ty_query(ret->u.binop.left->type);
    }
    if (right_type == TYSIGNEDLONGINT) {
      ret->u.binop.right = make_convert_expr(ret->u.binop.right, ty_build_basic(TYDOUBLE));

      right_type = ty_query(ret->u.binop.right->type);
    }
  }

  switch (op)
    {
    case ASSIGN_OP:
      break;
    case ADD_OP:
    case SUB_OP:
    case MUL_OP:
    case DIV_OP:
      if (isTagNumerical(right_type) == FALSE || isTagNumerical(left_type) == FALSE) {
      	error("Nonnumerical type argument(s) to arithmetic operation");
	return make_error_expr();
      }

      if (left_type == TYDOUBLE || right_type == TYDOUBLE) {

	if (left_type == TYSIGNEDLONGINT) {
	  ret->u.binop.left = castIntExpr(ret->u.binop.left);
	}

	if (right_type == TYSIGNEDLONGINT) {
	  ret->u.binop.right = castIntExpr(ret->u.binop.right);
	}

	ret->type = ty_build_basic(TYDOUBLE);
      } else {
	ret->type = ty_build_basic(TYSIGNEDLONGINT);
      }
      break;

    case MOD_OP:
    case REALDIV_OP:

      if (right_type != TYSIGNEDLONGINT || left_type != TYSIGNEDLONGINT) {
	error("Noninteger type argument(s) to integer arithmetic operation");
	return make_error_expr();
      }

      ret->type = ty_build_basic(TYSIGNEDLONGINT);
      break;

    case EQ_OP:
    case LESS_OP:
    case LE_OP:
    case NE_OP:
    case GE_OP:
    case GREATER_OP:
      if(right_type != left_type) {
	error("Incompatible type arguments to comparison operator");
	return make_error_expr();
      }
      if ((right_type) == FALSE && isTagCharNum(left_type) == FALSE) {
      	error("Illegal type arguments to comparison operator");
	return make_error_expr();
      }
      if(left_type == TYUNSIGNEDCHAR || right_type == TYSIGNEDCHAR) {
	ret->u.binop.left = make_convert_expr(ret->u.binop.left, ty_build_basic(TYSIGNEDLONGINT));
      }
      if(right_type == TYUNSIGNEDCHAR || right_type == TYSIGNEDCHAR) {
	ret->u.binop.right = make_convert_expr(ret->u.binop.right, ty_build_basic(TYSIGNEDLONGINT));
      }
      ret->type = ty_build_basic(TYSIGNEDLONGINT);
      ret = make_convert_expr(ret, ty_build_basic(TYSIGNEDCHAR));
      break;
  }

  return ret;
}//end make_bin_expr

EXPR make_fcall_expr(EXPR func, EXPR_LIST args) {
   BOOLEAN check;
   PARAM_LIST param;
   TYPE ret_type;
   TYPETAG expr_type;
   EXPR_LIST aCopy = args; //copy of arg list for adding deref/convert

   //check that func is of function type
   if (ty_query(func->type) != TYFUNC) {
      error("not functiontype");
      return make_error_expr();
   }

   //check check_args flag
   ret_type = ty_query_func(func->type, &param, &check);

   if (!check) { //likely an external function
      //make all arguments r-values and unary-convert
      while (aCopy != NULL) {
         if (is_lval(aCopy->expr)) { //create a deref node
            EXPR derefNode = make_un_expr(DEREF_OP, aCopy->expr);
            aCopy->expr = derefNode; //expr now points to deref node
         }

         //perform conversions
         expr_type = ty_query(aCopy->expr->type);
         if (expr_type == TYSIGNEDCHAR || expr_type == TYUNSIGNEDCHAR) {
            EXPR convertedNode = make_un_expr(CONVERT_OP, aCopy->expr);
            convertedNode->type = ty_build_basic(TYSIGNEDLONGINT);
            aCopy->expr = convertedNode;//expr now points to convert node
         }
         else if (expr_type == TYFLOAT) {
            EXPR convertedNode = make_un_expr(CONVERT_OP, aCopy->expr);
            convertedNode->type = ty_build_basic(TYDOUBLE);
            aCopy->expr = convertedNode;//expr now points to convert node
         }

         aCopy = aCopy->next;
      }
   }
   else { //check_args is true
      while (aCopy != NULL && param != NULL) {
         if (param->is_ref == TRUE) { //VAR parameter
            //actual arg must be an l-value whose type
            //matches the type of the formal param
            if(ty_test_equality(aCopy->expr->type, param->type) == FALSE) {
               error("types not equal");
               return make_error_expr();
            }
         }
         else {
            //make actual arg an r-value
            if (is_lval(aCopy->expr) == TRUE) {
               EXPR derefNode = make_un_expr(DEREF_OP, aCopy->expr);
               aCopy->expr = derefNode; //expr now points to convert node
            }

            //perfrom conversions
            expr_type = ty_query(aCopy->expr->type);
            if (expr_type == TYSIGNEDCHAR || expr_type == TYUNSIGNEDCHAR) {
               EXPR convertedNode = make_un_expr(CONVERT_OP, aCopy->expr);
               convertedNode->type = ty_build_basic(TYSIGNEDLONGINT);
               aCopy->expr = convertedNode;
            }
            else if (expr_type == TYFLOAT) {
               EXPR convertedNode = make_un_expr(CONVERT_OP, aCopy->expr);
               convertedNode->type = ty_build_basic(TYDOUBLE);
               aCopy->expr = convertedNode;
            }
         }

         //try to convert to type of formal parameter

        aCopy = aCopy->next;
        param = param->next;
      }
   }
   //check number formal args and param args and if differ then error

   //create an fcall node
   EXPR ret;
   ret = (EXPR)malloc(sizeof(EXPR_NODE));
   assert(ret != NULL);
   ret->tag = FCALL;
   ret->type = ret_type;
   ret->u.fcall_or_array_access.args_or_indices = args;
   ret->u.fcall_or_array_access.function_or_array = func;

   return ret;
}//end make_fcall_expr

EXPR_LIST expr_list_reverse(EXPR_LIST list) {
   EXPR_LIST tmp;
   EXPR_LIST prev = NULL;

   while (list != NULL) {
      tmp = list->next;
      list->next = prev;
      prev = list;
      list = tmp;
   }

   return prev;
}//end expr_list_reverse

EXPR_LIST expr_prepend(EXPR expr, EXPR_LIST list) {
   EXPR_LIST alt_list;
   alt_list = (EXPR_LIST)malloc(sizeof(EXPR_LIST_NODE));

   alt_list->expr = expr;
   alt_list->next = NULL;

   //check if list is empty
   if (list != NULL) {
      //pushing the list to the end of alt_list
      alt_list->next = list;
   }

   return alt_list;
}//end expr_prepend

TYPE check_subrange_expr(EXPR lo, EXPR hi) {
   long low, high;

   // check if INTCONSTS
   if (lo->tag != INTCONST || hi->tag != INTCONST) {
      error("Subrange indexs are not Integers");
      return ty_build_basic(TYERROR);
   }

   // create new subrange type if lo < hi
   low = lo->u.intval;
   high = hi->u.intval;

   if (low < high) {
      return ty_build_subrange(ty_build_basic(TYSIGNEDLONGINT), low, high);
   }

   error("Empty subrange in array index");
   error("Illegal index type (ignored)");

   return ty_build_basic(TYERROR);
}

int process_var_decl(VAR_ID_LIST ids, TYPE type, int cur_offset) {
   int block;
   ST_DR data_block;
   ST_DR data_rec;

   //check type, it must by data type
   TYPETAG tag = ty_query(type);
   if (tag == TYFUNC) {
      error("Variable(s) must be of data type");
   }

   if (st_get_cur_block() >= 1) { //global variables
      create_gdecl(ids, type);
      //decl_encode(type, ids);
         }
   else { //local variables
      //compute size and alignment requirement
      int size = getSize(type);
      int alignment = size;

      //decrease cur_offset to the alignment
      if (tag == TYSIGNEDCHAR || tag == TYUNSIGNEDCHAR ){
         //no alignment changes
      }
      else {
         cur_offset = cur_offset - alignment;
         while (ids != NULL) {
            cur_offset = cur_offset - size;
            data_rec = stdr_alloc();
            data_rec->tag = LDECL;
            data_rec->u.decl.type = type;
            data_rec->u.decl.sc = NO_SC;
            data_rec->u.decl.is_ref = FALSE;
            data_rec->u.decl.v.offset = cur_offset;

            if (!st_install(ids->id, data_rec)) {
               error("Duplicate variable declaration: \"%s\"", st_get_id_str(ids->id));
               free(data_rec);
            }

            ids = ids->next;
         }
      }
   }
   return cur_offset;
}//end process_var_decl

void build_func_decl(ST_ID id, TYPE type, DIRECTIVE dir) {
   PARAM_LIST params;
   BOOLEAN check;
   TYPE returntype;

   // creates data record
   ST_DR data_rec;
   data_rec = stdr_alloc();
   data_rec->tag = GDECL;

   if (dir == DIR_EXTERNAL) {
      //retrieve return type
      //set check args to false and return new functype
      data_rec->u.decl.sc = EXTERN_SC;
      returntype = ty_query_func(type, &params, &check);
      data_rec->u.decl.type = ty_build_func(returntype, params, FALSE);
   }
   else if (dir == DIR_FORWARD) {
      //type is not altered
      data_rec->u.decl.sc = NO_SC;
      data_rec->u.decl.type = type;
   }
   else {
      //othewise an invalid directive
   }

   data_rec->u.decl.is_ref = FALSE;
   data_rec->u.decl.v.global_func_name = st_get_id_str(id);

   //install into symbol table
   if (!st_install(id,data_rec)) {
      //error message if doesn't work
      error("Duplicate forward or external function declaration");
      free(data_rec);
   }
}//end build_func_decl

int enter_function(ST_ID id, TYPE type, char *global_func_name)
{
  int block;
  ST_DR stdr;
  PARAM_LIST param1, param2;
  BOOLEAN c_args1, c_args2;
  TYPE type1, type2;
  TYPETAG type_tag1;

  type1 = ty_query_func(type, &param1, &c_args1);
  type_tag1 = ty_query(type1);
  stdr = st_lookup(id, &block);

  if (stdr == NULL) {
    //create record
    stdr = stdr_alloc();
    stdr->tag = FDECL;
    stdr->u.decl.type = type;
    stdr->u.decl.sc = NO_SC;
    stdr->u.decl.is_ref = FALSE;
    stdr->u.decl.v.global_func_name = global_func_name;

    //install it
    st_install(id, stdr);
  }
 else
 {

    if(stdr->tag != GDECL || stdr->u.decl.sc != NO_SC) {
      error("Duplicate function declaration");
      return;
    }

    type2 = ty_query_func(stdr->u.decl.type, &param2, &c_args2);
    if (ty_test_equality(type1, type2) != TRUE) {
      error("Incorrect return type");
      return;
    }

    stdr->tag = FDECL;
    stdr->u.decl.v.global_func_name = global_func_name;
  }

  func_top++;
  func_stack_id[func_top] = id;

  st_enter_block();

  base_top++;

  b_init_formal_param_offset();
  if (st_get_cur_block() > 2) {
    b_store_formal_param(TYPTR);
  }

  install_local_params(param1);

  //base_stack_offset[base_top] = get_local_var_offset();

  if (type_tag1 != TYVOID) {
    base_stack_offset[base_top] -= 8;
  }

  return base_stack_offset[base_top];
}//end enter_function

void install_params(PARAM_LIST list) {
   long low,high;

   while (list != NULL) {
      //create symtab record
      ST_DR data_rec;
      data_rec = stdr_alloc();

      data_rec->tag = PDECL;	//parameters are installed as PDECL tag
      data_rec->u.decl.sc = list->sc;
      data_rec->u.decl.is_ref = list->is_ref;
      data_rec->u.decl.err = list->err;

      if (ty_query(list->type) == TYSUBRANGE) {
         data_rec->u.decl.type = ty_query_subrange(list->type, &low, &high);
      }
      else {
         data_rec->u.decl.type = list->type;
      }

      if (list->is_ref == TRUE) { //var parameter
         data_rec->u.decl.v.offset = b_get_formal_param_offset(TYPTR);
      }
      else {
         data_rec->u.decl.v.offset = b_get_formal_param_offset(ty_query(data_rec->u.decl.type));
      }

      st_install(list->id, data_rec);
      list = list->next;
   }
}//end install_params

EXPR check_assign_or_proc_call(EXPR lhs, ST_ID id, EXPR rhs) {


   PARAM_LIST params;
   BOOLEAN check;

   //case1, if rhs non null, then return binop node with assign_op
   if (rhs != NULL) {
      //exception if id is id of current function
      if (func_top >= 0 && id == func_stack_id[func_top]) {
         if (ty_query(ty_query_func(lhs->type, &params, &check)) != TYVOID) {
            //return type is nonvoid
            EXPR ret = make_un_expr(SET_RETURN_OP, rhs);
            ret->type = ty_query_func(lhs->type, &params, &check);
            return ret;
         }
         else {
            error("Function type is TYVOID\n");
            return make_error_expr();
         }
      }
      else {
         //returns binop with ASSIGN_OP
         EXPR ret = make_bin_expr(ASSIGN_OP, lhs, rhs);
         return ret;
      }
   }

   //case2, rhs is NULL
   else {
      if (lhs->tag == UNOP) {
         if (lhs->u.unop.op == NEW_OP || lhs->u.unop.op == DISPOSE_OP) {
            return lhs;
         }
      }


      if (lhs->tag == GID || lhs->tag == LFUN) {
         //check that lhs is a pascal procedure
         if (ty_query(lhs->type) == TYFUNC) {
            EXPR ret = make_fcall_expr(lhs, NULL);
            return ret;
         }
         else {
            error("Expected procedure name, saw data");
            return make_error_expr();
         }
      }
      else if (lhs->tag == FCALL) {

         //check the return type is void
         if (ty_query(lhs->type) == TYVOID) {
            return lhs;
         }
         else {
            error("Procedure call to a nonvoid type");
            return make_error_expr();
         }
      }
      else if(lhs->tag ==  ERROR )
        {
		//error("reached");
               return make_error_expr();
        }
      else
      {
         error("Procedure call expected");
         return make_error_expr();
      }
   }
}//end check_assign_or_proc_call

BOOLEAN is_lval(EXPR expr) {
   //first check tag of expr
   if (expr->tag == LVAR || expr->tag == ARRAY_ACCESS) { //all LVARs are l-val
      return TRUE;
   }
   else if (expr->tag == GID) {
      if (ty_query(expr->type) == TYFUNC || ty_query(expr->type) == TYERROR) { //l-val only if data type
         return FALSE;
      }
      else {
         return TRUE;
      }
   }
   else if (expr->tag == UNOP) {
      if (expr->u.unop.op == INDIR_OP) { //l-val if indirection op
         return TRUE;
      }
      else {
         return FALSE;
      }
   }
   else {
      return FALSE;
   }
}//end is_lval

void expr_free(EXPR expr) {
   if (expr->tag == UNOP) {
      if (expr->u.unop.operand != NULL) {
         expr_free(expr->u.unop.operand);
      }
      free(expr);
   }
   else if (expr->tag == BINOP) {
      if (expr->u.binop.left != NULL) {
         expr_free(expr->u.binop.left);
      }
      if (expr->u.binop.right != NULL) {
         expr_free(expr->u.binop.right);
      }
      free(expr);
   }
   else if (expr->tag == FCALL) {
      if (expr->u.fcall_or_array_access.function_or_array != NULL) {
         expr_free(expr->u.fcall_or_array_access.function_or_array);
      }
      if (expr->u.fcall_or_array_access.args_or_indices != NULL) {
         expr_list_free(expr->u.fcall_or_array_access.args_or_indices);
      }
      free(expr);
   }
   else {
      free(expr);
   }
}//end expr_free

void expr_list_free (EXPR_LIST list) {
   if (list->next != NULL) {
      expr_free(list->expr);
      expr_list_free(list->next);
   }
   expr_free(list->expr);
   free(list);
}


void install_local_params(PARAM_LIST param)
{
  ST_DR stdr;
  long low, high;

  while(param != NULL) {
    //create new record
    stdr = stdr_alloc();
    stdr->tag = PDECL;
    stdr->u.decl.type = param->type;
    stdr->u.decl.sc = param->sc;
    stdr->u.decl.is_ref = param->is_ref;
    stdr->u.decl.err = param->err;

    //set offset (based on is_ref or type)
    if (param->is_ref == TRUE) {
      stdr->u.decl.v.offset = get_formal_param_offset(TYPTR);
    } else {
      if (ty_query(param->type) != TYSUBRANGE) {
	stdr->u.decl.v.offset = get_formal_param_offset(ty_query(param->type));
      } else {
	stdr->u.decl.v.offset = get_formal_param_offset(ty_query(ty_query_subrange(param->type, &low, &high)));
      }
    }

    //install parameter
    st_install(param->id, stdr);

    //get next item
    param = param->next;
  }
}

EXPR make_array_access_expr(EXPR array, EXPR_LIST indices) {
   //checks to make sure of type array
   if (ty_query(array->type) != TYARRAY) {
      error("Nonarray in array access expression");
      return make_error_expr();
   }

   //variables for querying
   TYPE array_type;
   INDEX_LIST i;
   EXPR_LIST test = indices;

   array_type = ty_query_array(array->type, &i);

   while (indices != NULL && i != NULL) {
      //gets the r value, deref if l-val
      if (is_lval(indices->expr) == TRUE) {
         indices->expr = make_un_expr(DEREF_OP, indices->expr);
      }

      //checks type with "formal" type
      if (ty_query(indices->expr->type) != TYSIGNEDLONGINT) {
         error("Incompatible index type in array access");
         return make_error_expr();
      }

      i = i->next;
      indices = indices->next;
   }

   //checks that both indices are same length
   if ((indices == NULL && i != NULL) || (indices != NULL && i == NULL)) {
      error("indices not equal");
      return make_error_expr();
   }

   //finally creates array_access node
   EXPR ret;
   ret = (EXPR)malloc(sizeof(EXPR_NODE));
   assert(ret != NULL);
   ret->tag = ARRAY_ACCESS;
   ret->type = array_type;
   ret->u.fcall_or_array_access.args_or_indices = test;
   ret->u.fcall_or_array_access.function_or_array = array;

   return ret;

}// end make_array_access_expr

VAL_LIST new_case_value(TYPETAG type, long lo, long hi) {
   VAL_LIST ret;
   ret = (VAL_LIST)malloc(sizeof(VAL_LIST_REC));
   ret->lo = lo;
   ret->hi = hi;
   ret->type = type;
   return ret;
}// end new_case_value

BOOLEAN check_case_values(TYPETAG type, VAL_LIST vals, VAL_LIST prev_vals) {
   while (vals != NULL) {
      //check type
      if (vals->type != type) {
         error("Case constant type does not match type of case expression");
         return FALSE;
      }
      //check subrange values
      if (vals->type == TYSUBRANGE) {
         if (vals->lo > vals->hi) {
            warning("Low value of subrange is greater than high value");
            //return FALSE //only true if no errors, this is warning
         }
      }
      //check for overlap
   }
   return TRUE;
}// end check_case_values


void case_value_list_free(VAL_LIST vals) {
   if (vals->next != NULL) {
      case_value_list_free(vals->next);
   }
   free(vals);
}//end case_value_list_free

BOOLEAN get_case_value(EXPR expr, long *val, TYPETAG *type) {
   //check type
   if (expr->tag == INTCONST) {
      *type = ty_query(expr->type);
      *val = expr->u.intval;
      return TRUE;
   }
   else if (expr->tag == STRCONST) {
      //try and convert
      if (strlen(expr->u.strval) == 1) { //convert
         *type = TYSIGNEDCHAR;
         *val = expr->u.strval[0];
         expr = make_intconst_expr(expr->u.strval[0], ty_build_basic(TYSIGNEDLONGINT));
         return TRUE;
      }
      else { //error
         error("STRCONST not length 1");
         return FALSE;
      }
   }
   else { //error
      error("Case constant not of INTCONST type");
   }
}//end get_case_value

BOOLEAN check_for_preamble(EXPR var, EXPR init, EXPR limit) {
   TYPETAG var_type = ty_query(var->type);
   //check lvalue
   if (is_lval(var) == FALSE) {
      error("Loop control variable not an l-value");
      return FALSE;
   }
   //check if ordinal type
   if (var_type != TYSIGNEDCHAR && var_type != TYUNSIGNEDCHAR && var_type != TYSIGNEDLONGINT) {
      error("Loop control variable is not an ordinal type");
      return FALSE;
   }
   //see if type matches, ignoring subranges for now
   if (!ty_test_equality(var->type, init->type)) {
      error("Types in loop do not match");
      return FALSE;
   }
   else if (!ty_test_equality(var->type, limit->type)) {
      error("Types in loop do not match");
      return FALSE;
   }

   return TRUE;
}//end check_for_preamble



