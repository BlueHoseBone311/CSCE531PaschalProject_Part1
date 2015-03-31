#include <stdio.h>
#include <stdlib.h>
#include "encode.h"
#include "backend-x86.h"

static TYPE get_array_element(TYPE array); 
static int calc_array_size(TYPE array_type, int align); 
static TYPE get_subrange_align_element(TYPE query_type);


void encode_align (TYPE type, VAR_ID_LIST varlist_id)
{

	if (ty_query(type)==TYERROR) return;
	if (ty_query(type)==TYFUNC) return;

	while (list_id) 
	{
		ST_ID id = list_id->id;
		unsigned int size;
		char *decl_id;
		int align;

		TYPETAG tag;
		TYPE base_type; 

		if (!id)bug("Oops! ST_ID Received is Null\n");

		tag = ty_query(type);
		if(tag == TYARRAY) 
		{
            base_type = get_array_element(type);
			align = encode_get_base_size(base_type);
			size = get_array_size(type, align);
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
				bug(" Typetag error - Hit Default Action in (%d) ", tag);
		}

		list_id = list_id->next;
	}
}

/*Allocates space for basic types */
void encode_get_base_size (char *id, TYPE type)
{
	TYPETAG tp_tag; 
	INDEX_LIST i; 
	unsigned int bit_length; 

	tp_tag = ty_query(type);
	switch (ty_tag)
	{

		case TYPTR:
			length = 4;
			break;
		case TYFLOAT:
			length = 4;
			break;
		case TYDOUBLE:
			length = 8;	
			break;
		case TYLONGDOUBLE:
			length = 8;
			break;
		case TYUNSIGNEDINT:
			length = 4;
			break;
		case TYUNSIGNEDCHAR:
			length = 1;
			break;
		case TYUNSIGNEDSHORTINT:
			length = 2;
			break;
		case TYUNSIGNEDLONGINT:
			length = 4;
			break;
		case TYSIGNEDCHAR:
			length = 1;
			break;
		case TYSIGNEDINT:
			length = 4;
			break;
		case TYSIGNEDLONGINT:
			length = 4;
			break;
		case TYSIGNEDSHORTINT:
			length = 2;
			break;
		case TYSTRUCT:
			break;
		case TYUNION:
			break;
		case TYENUM:
			break;
		case TYFUNC:
			break;	
		case TYVOID:
			break;
		case TYERROR:
			break;
		default:
			bug(" Typetag error - Hit Default Action in (%d) ", tag);
	}
}
/* STATIC SUBROUTINES */

static int calc_array_size(TYPE array_type, int align) 
{
	long lower; 
	long upper;
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
			indc_type = ty_query_subrange(indices->type,&lower,&upper);
			align_size *= high - low + 1;
			indices = indices->next;
		}
	}
	return align_size;
}

static TYPE get_array_align_element(TYPE query_type);
{
	TYPE new_type_query; 
	if (ty_query(query_type) != TYARRAY)
	{
		return query_type; 
	}

 TYPE new_type_query = ty_query_array(query_type, query_type->u.array.indices);
 get_array_align_element(new_type_query);	

} 

static TYPE get_subrange_align_element(TYPE query_type);
{
	TYPE new_type_query; 
	long lower; 
	long upper; 
	if (ty_query(query_type) != TYSUBRANGE)
	{
		return query_type; 
	}

	lower = query_type->u.subrange.low;
	upper = query_type->u.subrange.high;
	new_type_query = ty_query_array(query_type, lower, upper);
	get_array_align_element(new_type_query);	

} 
