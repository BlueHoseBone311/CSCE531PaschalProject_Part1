 /*@Title   encode.c - size calculations and code generating functtions
 * @authors  Venugopal Boppa, Christopher A. Greer, Christian Merchant
 * @class   CSCE531
 * @Project Pascal Compiler Part II
 * @date    04-17-15
*/

#include <stdio.h>
#include <stdlib.h>
#include "encode.h"


static int calc_array_size(TYPE array_type, int align);
static TYPE get_array_align_element(TYPE array);
static TYPE get_subrange_align_element(TYPE query_type);



void encode_declaration (TYPE type, VAR_ID_LIST varlist_id)
{

	if (ty_query(type)==TYERROR)
	{
		return;
	}
	if (ty_query(type)==TYFUNC)
	{
		return;
	}

	while (varlist_id)
	{
		ST_ID id = varlist_id->id;
		unsigned int size;
		char *decl_id;
		int align;

		TYPETAG tag;
		TYPE base_type;

		if (!id)
		{
			bug("Oops! ST_ID Received is Null\n");
		}

		tag = ty_query(type);
		if(tag == TYARRAY)
		{
            base_type = get_array_align_element(type);
			align = encode_get_base_size(base_type);
			size = calc_array_size(type, align);
		}
		else if (tag == TYSUBRANGE)
		{
			base_type = get_subrange_align_element(type);
			align = encode_get_base_size(base_type);
			size = align;
		}
		else
		{
			align = encode_get_base_size(type);
			size = align;
		}

		decl_id=st_get_id_str(id);

		b_global_decl(decl_id, align, size);

		switch (tag)
		{
			case TYARRAY:
				b_skip(size);
				break;
			case TYSUBRANGE:
				b_skip(size);
				break;
			case TYFLOAT:
				b_skip(size);
				break;
			case TYDOUBLE:
				b_skip(size);
				break;
			case TYLONGDOUBLE:
				b_skip(size);
				break;
			case TYUNSIGNEDINT:
				b_skip(size);
				break;
			case TYUNSIGNEDCHAR:
				b_skip(size);
				break;
			case TYUNSIGNEDSHORTINT:
				b_skip(size);
				break;
			case TYUNSIGNEDLONGINT:
				b_skip(size);
				break;
			case TYSIGNEDCHAR:
				b_skip(size);
				break;
			case TYSIGNEDINT:
				b_skip(size);
				break;
			case TYSIGNEDLONGINT:
				b_skip(size);
				break;
			case TYSIGNEDSHORTINT:
				b_skip(size);
				break;
			case TYPTR:
				b_skip(size);
				break;
			case TYSET:
				bug("Typetag ERROR  (%d)", tag);
				break;
			case TYSTRUCT:
				bug("Typetag ERROR (%d)", tag);
				break;
			case TYUNION:
				bug("Typetag ERROR (%d)", tag);
				break;
			case TYENUM:
				bug("Typetag ERROR (%d)", tag);
				break;
			case TYFUNC:
				break;
			case TYVOID:
				msgn("Type: Void");
				break;
			case TYERROR:
				msgn("Type: Error");
				break;
			default:
				bug(" Typetag error - Hit Default Action in (%d) ", tag); break;
		}

		varlist_id = varlist_id->next;
	}
}

/*Allocates space for basic types */
unsigned int encode_get_base_size (TYPE type)
{
	TYPETAG tp_tag;
	unsigned int bit_length;
	tp_tag = ty_query(type);

	switch (tp_tag)
	{
		case TYFLOAT:
			bit_length = 4;
			break;
		case TYDOUBLE:
			bit_length = 8;
			break;
		case TYLONGDOUBLE:
			bit_length = 8;
			break;
		case TYUNSIGNEDINT:
			bit_length = 4;
			break;
		case TYUNSIGNEDCHAR:
			bit_length = 1;
			break;
		case TYUNSIGNEDSHORTINT:
			bit_length = 2;
			break;
		case TYUNSIGNEDLONGINT:
			bit_length = 4;
			break;
		case TYSIGNEDCHAR:
			bit_length = 1;
			break;
		case TYSIGNEDINT:
			bit_length = 4;
			break;
		case TYSIGNEDLONGINT:
			bit_length = 4;
			break;
		case TYSIGNEDSHORTINT:
			bit_length = 2;
			break;
		case TYPTR:
			bit_length = 4;
			break;
		case TYARRAY:
			bug("encountered array typetag in encode_get_base_size");
			break;
		case TYSET:
			bug("illegal typetag (%d) in \"encode_get_base_size\"", tp_tag);
			break;
		case TYSTRUCT:
			bug("illegal typetag (%d) in \"encode_get_base_size\"", tp_tag);
			break;
		case TYUNION:
			bug("illegal typetag (%d) in \"encode_get_base_size\"", tp_tag);
			break;
		case TYENUM:
			bug("illegal typetag (%d) in \"encode_get_base_size\"", tp_tag);
			break;
		case TYFUNC:
			break;
		case TYSUBRANGE:
			bug("encountered subrange typetag in encode_get_base_size");
			break;
		case TYVOID:
			break;
		case TYERROR:
			break;
		default:
			bug(" Typetag error - Hit Default Action in (%d) ", tp_tag); break;
	}
	return bit_length;
}

/* STATIC SUBROUTINES */

static int calc_array_size(TYPE array_type, int align)
{
	long low;
	long high;
	TYPE indc_type;
	TYPE type;
	unsigned int align_size = align;
	INDEX_LIST indices;

	type = array_type;

	while (ty_query(type) == TYARRAY)
	{
		type = ty_query_array(type, &indices);
		while (indices != NULL)
		{
			indc_type = ty_query_subrange(indices->type,&low,&high);
			align_size *= high - low + 1;
			indices = indices->next;
		}
	}
	return align_size;
}

static TYPE get_array_align_element(TYPE query_type)
{
	TYPE new_type_query;
	INDEX_LIST ilist;
	if (ty_query(query_type) != TYARRAY)
	{
		return query_type;
	}

	 new_type_query = ty_query_array(query_type, &ilist);
	 get_array_align_element(new_type_query);

}

static TYPE get_subrange_align_element(TYPE query_type)
{
	TYPE new_type_query;
	if (ty_query(query_type) != TYSUBRANGE)
	{
		return query_type;
	}

	new_type_query = ty_strip_modifier(query_type);
	get_array_align_element(new_type_query);
}


//Project II

int get_formal_param_offset(TYPETAG tag)
{
  return b_get_formal_param_offset(tag);
}

int getSize(TYPE type)
{
   int size = encode_get_base_size(type);
   return size;
}

void begin_funct_body(char *global_funct_name, TYPE type, int local_var_offset)
{
   TYPE funct_type;
   TYPE param_type;
   PARAM_LIST param_list;
   BOOLEAN funct_args_flag;
   TYPETAG funct_tag;
   TYPETAG param_tag;

   int block;
   ST_DR data_record;
   long low,high;

   //query the function to get variables
   funct_type = ty_query_func(type, &param_list, &funct_args_flag);
   funct_tag = ty_query(funct_type);



   while (param_list != NULL)
   {
      param_tag = ty_query(param_list->type);
      data_record = st_lookup(param_list->id, &block);

      /*Subrange? Use Base Type*/
      if (param_tag == TYSUBRANGE)
      {
         param_type = ty_query_subrange(type, &low, &high);
         b_store_formal_param(ty_query(param_type));
      }
      else if (data_record->u.decl.is_ref == TRUE) { //VAR param_list
         b_store_formal_param(TYPTR);
      }
      else
      {
         b_store_formal_param(param_tag);
      }

      param_list = param_list->next;
   }

   //nonvoid pascal function types
   if (funct_tag != TYVOID)
   {
      b_alloc_return_value();
   }

   //local variables
   b_alloc_local_vars(local_var_offset - b_get_local_var_offset());
}

void end_funct_body(char *global_funct_name, TYPE type)
{
   TYPE funct_type;
   PARAM_LIST params;
   BOOLEAN funct_arg_flag;
   TYPETAG funct_tag;
   long low,high;

   //query function
   funct_type = ty_query_func(type, &params, &funct_arg_flag);
   funct_tag = ty_query(funct_type);

   //pops the function id from the global stack;
   func_top--;

   //pascal function (nonvoid types)
   if (funct_tag != TYVOID)
   {
      if (funct_tag == TYSUBRANGE)
      {
         b_prepare_return(ty_query(ty_query_subrange(funct_type, &low, &high)));
      }
      else
      {
         b_prepare_return(funct_tag);
      }
   }

   b_func_epilogue(global_funct_name);
   st_exit_block();
}

void encode_expr(EXPR expr)
{

  if (expr == NULL)
  {
    bug("Attempt to encode null expression in 'encode_expr'");
  }

  switch (expr->tag)
  {


    case NULLOP:   b_push_const_int(0);
	  		       break;

	case UNOP:     encode_unop(expr->u.unop.op, expr);
	  		       break;

	case BINOP:	   encode_binop(expr->u.binop.op, expr);
			       break;

	case FCALL:	   encode_funct_call(expr->u.fcall_or_array_access.function_or_array, expr->u.fcall_or_array_access.args_or_indices);
	  		       break;

	case INTCONST: 	b_push_const_int(expr->u.intval);
	  		        if(ty_query(expr->type) == TYUNSIGNEDCHAR)
			        {
						b_convert(TYSIGNEDLONGINT, TYUNSIGNEDCHAR);
	  			    }
	 		        break;

	case REALCONST: b_push_const_double(expr->u.realval);
					break;

	case STRCONST:  b_push_const_string(expr->u.strval);
			        break;
	case GID:		b_push_ext_addr(st_get_id_str(expr->u.gid));
			        break;

	case LVAR:		b_push_loc_addr(0);
					int i = 0;
	  				for (i = 0; i < expr->u.lvar.link_count; i++)
					{
						b_offset(FUNC_LINK_OFFSET);
						b_deref(TYPTR);
	 			 	}
					b_offset(expr->u.lvar.offset);
	 		        if (expr->u.lvar.is_ref == TRUE)
	                {
						b_deref(TYPTR);
	  			    }
	  			    break;


	case ARRAY_ACCESS: break;
	case LFUN: break;
    case ERROR: break;
    default: bug("Error: Hit default in encode_expr");

  }//End Switch
}//End encode_expr

void encode_unop(EXPR_UNOP op, EXPR expr)
{
  long low, high;
  TYPETAG tag, rval_tag;
  ST_ID id;
  TYPE type, base_type;
  BOOLEAN converted_to_int;

  encode_expr(expr->u.unop.operand);

  converted_to_int = FALSE;
  tag = ty_query(expr->u.unop.operand->type);
  rval_tag = ty_query(expr->type);

  switch(op)
   {

     case UPLUS_OP:   break;
     case NEG_OP:   b_negate(tag); break;

     case ORD_OP: 	if(tag==TYUNSIGNEDCHAR)
					{
					b_convert(tag, TYSIGNEDLONGINT);
					}
					break;
     case CHR_OP:   if(tag==TYSIGNEDLONGINT)
					{
						b_convert(tag, TYUNSIGNEDCHAR);
					}
					break;

     case UN_SUCC_OP:   if(tag!=TYSIGNEDLONGINT)
						{
							b_convert(tag,TYSIGNEDLONGINT);
							converted_to_int=TRUE;
						}
						b_push_const_int(1);
						b_arith_rel_op(B_ADD, TYSIGNEDLONGINT);
						if(converted_to_int==TRUE)
						{
							b_convert(TYSIGNEDLONGINT,tag);
						}
						break;

    case UN_PRED_OP: if(tag!=TYSIGNEDLONGINT)
					{
						b_convert(tag,TYSIGNEDLONGINT);
						converted_to_int=TRUE;
					}
					b_push_const_int(-1);
					b_arith_rel_op(B_ADD, TYSIGNEDLONGINT);
					if(converted_to_int==TRUE)
					{
						b_convert(TYSIGNEDLONGINT, tag);
					}
					break;

    case NEW_OP:       b_alloc_arglist(4);
                       b_push_const_int(getSize(ty_query_ptr(expr->u.unop.operand->type, &id)));
	                   b_load_arg(TYUNSIGNEDINT);
                       b_funcall_by_name("malloc", TYPTR);
                       b_assign(TYPTR);
                       b_pop();
                       break;

    case DISPOSE_OP:   b_load_arg(TYPTR);
                       b_funcall_by_name("free", TYVOID);
                       break;

    case DEREF_OP:     b_deref(tag);
                       break;

    case SET_RETURN_OP: b_set_return(ty_query(expr->u.unop.operand->type)); break;
    case INDIR_OP:   break;
    case CONVERT_OP: if(tag==TYSUBRANGE)
					{
						base_type = ty_query_subrange(expr->u.unop.operand->type, &low, &high);
						b_convert(TYSUBRANGE, ty_query(base_type));
					}
					else if(tag==TYPTR)
					{

					}
					else
					{
						b_convert(tag, rval_tag);
					}
					break;
    default: bug("Error: Hit default in encode_unop");
  }
}

void encode_binop(EXPR_BINOP b_op, EXPR expr)
{
  TYPETAG type_tag;
  TYPETAG left_type_tag, right_type_tag;
  encode_expr(expr->u.binop.left);
  encode_expr(expr->u.binop.right);
  type_tag = ty_query(expr->type);
  left_type_tag = ty_query(expr->u.binop.left->type);
  right_type_tag = ty_query(expr->u.binop.right->type);

ADD_OP, SUB_OP, MUL_OP, DIV_OP, MOD_OP, REALDIV_OP, EQ_OP, LESS_OP, LE_OP,
    GE_OP, GREATER_OP, ASSIGN_OP, NE_OP, BIN_SUCC_OP, BIN_PRED_OP;

  switch (b_op)
  {

    case ADD_OP:  b_arith_rel_op(B_ADD, type_tag); break;
	case SUB_OP: b_arith_rel_op(B_SUB, type_tag); break;
	case MUL_OP: b_arith_rel_op(B_MULT, type_tag);break;
	case DIV_OP: b_arith_rel_op(B_DIV, type_tag); break;
	case MOD_OP: b_arith_rel_op(B_MOD, type_tag); break;
	case REALDIV_OP: b_arith_rel_op(B_DIV, type_tag); break;
	case EQ_OP:b_arith_rel_op(B_EQ, type_tag);   break;
	case LESS_OP: b_arith_rel_op(B_LT, type_tag); break;
	case LE_OP: b_arith_rel_op(B_LE, type_tag); break;
	case NE_OP: b_arith_rel_op(B_NE, type_tag); break;
	case GE_OP: b_arith_rel_op(B_GE, type_tag); break;
	case GREATER_OP: b_arith_rel_op(B_GT, type_tag); break;
	case ASSIGN_OP:  if(expr->u.binop.left->tag == LVAR)
			 		 {
			     		b_push_loc_addr(expr->u.binop.left->u.lvar.offset);
    	             }

     		     	if(left_type_tag != right_type_tag)
			 		{
	                	b_convert(right_type_tag, left_type_tag);
                    }
    		        b_assign(left_type_tag);
     			    b_pop();
   		            break;
   	default: bug("Error: Hit default in encode_binop");
  }
}

void encode_funct_call(EXPR funct, EXPR_LIST args)
{
	int arg_list_size_align;
	EXPR_LIST funct_arg_list;
	PARAM_LIST funct_params;
	BOOLEAN funct_arg_flag;
	char *funct_global_name;
	TYPE funct_ret_type;
	TYPETAG arg_tag;

	funct_ret_type = ty_query_func(funct->type, &funct_params, &funct_arg_flag);
	arg_list_size_align = 0;
	funct_arg_list = args;

	if(funct->tag == GID)
	{
		funct_global_name = st_get_id_str(funct->u.gid);
	}
	funct_arg_list = args;

	while(funct_arg_list != NULL)
	{

		if(ty_query(funct_arg_list->expr->type)==TYDOUBLE||ty_query(funct_arg_list->expr->type)==TYFLOAT)
		{
			arg_list_size_align+=8;
		}
		else
		{
		    arg_list_size_align+=4;
		}

		funct_arg_list=funct_arg_list->next;
	}

  b_alloc_arglist(arg_list_size_align);
  funct_arg_list=args;
  while(funct_arg_list!=NULL)
  {
  	  encode_expr(funct_arg_list->expr);
      arg_tag = ty_query(funct_arg_list->expr->type);
  	  if(funct_params != NULL)
 	  {
  		    if(funct_params->is_ref==TRUE)
			{
				if(is_lval(funct_arg_list->expr)==FALSE)
				{
					bug("Error: lval expected in function argument in function argument in encode_funct_call");
				}

				if(ty_test_equality(funct_arg_list->expr->type, funct_params->type)==FALSE)
				{
					error("Param type mismatch in encode_funct_call");
				}
				b_load_arg(TYPTR);
    		}
		    else
            {
				if(is_lval(funct_arg_list->expr)==TRUE)
                {
	 				 b_deref(arg_tag);
			    }
		        if(arg_tag==TYSIGNEDCHAR||arg_tag==TYUNSIGNEDCHAR)
			    {

 					b_convert(arg_tag,TYSIGNEDLONGINT);
				  	b_load_arg(TYSIGNEDLONGINT);
			    }
				else if(arg_tag==TYFLOAT)
			    {
					b_convert(arg_tag,TYDOUBLE);
					b_load_arg(TYDOUBLE);
				}
				else
				{
					b_load_arg(arg_tag);
				}
    	    }
        }
         else
         {
			if(is_lval(funct_arg_list->expr)==TRUE)
		    {
	 			 b_deref(arg_tag);
		    }
			if(arg_tag==TYSIGNEDCHAR||arg_tag==TYUNSIGNEDCHAR)
			{
		 		 b_convert(arg_tag, TYSIGNEDLONGINT);
			     b_load_arg(TYSIGNEDLONGINT);
		    }
            else if(arg_tag==TYFLOAT)
           	{
		  		b_convert(arg_tag,TYDOUBLE);
	        	b_load_arg(TYDOUBLE);
		    }
			else
			{
		        b_load_arg(arg_tag);
			}
        }

	    funct_arg_list=funct_arg_list->next;

	    if(funct_params!=NULL)
		{
            funct_params=funct_params->next;
	    }

   }
   b_funcall_by_name(funct_global_name,ty_query(funct_ret_type));
}

