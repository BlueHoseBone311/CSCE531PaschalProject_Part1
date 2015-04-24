/*@Title   tree.h - Header file for Routines used by Bison for decl creation, and type building
 * @authors  Venugopal Boppa, Christopher A. Greer, Christian Merchant
 * @class   CSCE531
 * @Project Pascal Compiler Part II
 * @date    04-17-15
*/

#ifndef TREE_C
#define TREE_C
#include "types.h"
#include "symtab.h"
#include "message.h"


//Project I DEFINITIONS
//definitions for a list of multiple variables
typedef struct var_id {
    ST_ID id;
    struct var_id *next;
} VAR_ID, *VAR_ID_LIST;

//Project II DEFINITIONS

typedef enum {
    INTCONST, REALCONST, STRCONST, GID, LVAR, LFUN, UNOP, BINOP,
    FCALL, ERROR, ARRAY_ACCESS, NULLOP
} EXPR_TAG;

typedef enum {
    CONVERT_OP, DEREF_OP, ORD_OP, CHR_OP, SUCC_OP, PRED_OP, NEG_OP,
    NOT_OP, UPLUS_OP, UMINUS_OP, UN_SUCC_OP, UN_PRED_OP, INDIR_OP, NEW_OP,
    DISPOSE_OP, ADDRESS_OP, SET_RETURN_OP, EMPTY_OP
} EXPR_UNOP;

typedef enum {
    ADD_OP, SUB_OP, MUL_OP, DIV_OP, MOD_OP, REALDIV_OP, EQ_OP, LESS_OP, LE_OP,
    GE_OP, GREATER_OP, ASSIGN_OP, NE_OP, BIN_SUCC_OP, BIN_PRED_OP, OR_OP, AND_OP,
    XOR_OP, SYMDIFF_OP
} EXPR_BINOP;

typedef enum {
    NULL_EOF_OP, NULL_EOLN_OP, NIL_OP
} EXPR_NULLOP;

typedef struct {
    struct exprnode * expr;
    ST_ID id;
} EXPR_ID;

typedef struct exprlistnode {
    struct exprnode * expr;
    struct exprlistnode * next;
} EXPR_LIST_NODE, * EXPR_LIST;

typedef enum { DIR_EXTERNAL, DIR_FORWARD } DIRECTIVE;

typedef struct exprnode {
    EXPR_TAG tag;
    TYPE type;
    union {
		long intval;
		double realval;
		char * strval;
		ST_ID gid;	    /* For global variables and global functions */
		struct {            /* For local variables and formal parameters */
		    BOOLEAN is_ref; /* TRUE if expr is a VAR (reference) parameter */
		    int offset;     /* storage location relative to frame pointer */
		    int link_count; /* Number of ref links to follow to find the var */
		} lvar;
		struct {            /* For local functions */
		    char * global_name; /* The assembler entry point label */
		    int link_count; /* Number of ref links to follow to find the fcn */
		} lfun;
		struct {            /* For nullary operators */
		    EXPR_NULLOP op;
		} nullop;
		struct {            /* For unary operators */
		    EXPR_UNOP op;
		    struct exprnode * operand;
		} unop;
		struct {            /* For binary operators */
		    EXPR_BINOP op;
		    struct exprnode * left, * right;
		} binop;
		struct {     /* For procedure/function calls, array accesses  */
		    struct exprnode * function_or_array;
		    EXPR_LIST args_or_indices;
		} fcall_or_array_access;
    } u;
} EXPR_NODE, *EXPR;

typedef struct {
    ST_ID	id;
    TYPE	type;
} FUNCTION_HEAD;
//records the current func id to detect return values.
extern ST_ID func_stack_id[BS_DEPTH];
extern int func_top;

extern int base_stack_offset[BS_DEPTH];
extern int base_top;

//Project III definitions
typedef struct val_node {
   long lo, hi;
   TYPETAG type;
   struct val_node *next;
} VAL_LIST_REC, *VAL_LIST;

typedef struct {
   TYPETAG type;
   char *label;
   VAL_LIST values;
} CASE_RECORD;

//PROJECT I FUNCTIONS
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
TYPE check_unresolved(ST_ID id);
/*
	This method builds an unresolved pointer and adds it to the
	LL of unresolved pointers
	It returns the pointer of TYPE.
*/
void resolve_all_ptr();
/*
	Traverses the linked list of unresolved pointers and resolves them..
 	An error message is issued for every unresolved pointer.
*/

TYPE check_subrange(long low, long high);
/*
   Method that builds a subrange of type TYSIGNEDLONGINT, making sure
   that low and high are appropriate ranges
*/

//PROJECT II FUNCTIONS

//Functions for making required expressions
EXPR make_intconst_expr(long val, TYPE type);
EXPR make_realconst_expr(double val);
EXPR make_strconst_expr(char * str);
EXPR make_null_expr(EXPR_NULLOP op);
EXPR make_error_expr();
EXPR make_id_expr(ST_ID id);
EXPR make_un_expr(EXPR_UNOP op, EXPR sub);
EXPR make_bin_expr(EXPR_BINOP op, EXPR left, EXPR right);
EXPR make_fcall_expr(EXPR func, EXPR_LIST args);


//Reverses a list of Expr
EXPR_LIST expr_list_reverse(EXPR_LIST list);

/*Prepend and EXPR onto the front of an Expr list*/
EXPR_LIST expr_prepend(EXPR expr, EXPR_LIST list);

/*	Checks that both the lo and hi values are INTCONSTS.
	Checks to see if the second subrange is higher than the first.
	IF not returns error.
*/
TYPE check_subrange_expr(EXPR lo, EXPR hi);

//Process variable declarations and install ids into symbol table as either GDECL or LDECL
int process_var_decl(VAR_ID_LIST ids, TYPE type, int cur_offset);

//Builds the function declaration type and installs into the symbol table
void build_func_decl(ST_ID id, TYPE type, DIRECTIVE dir);

int enter_function(ST_ID id, TYPE type, char *global_func_name);

void install_local_params(PARAM_LIST list);

//Installs parameters that are used in the enter_function
void install_params(PARAM_LIST list);

//checks to see if this is an assignment or procedure
EXPR check_assign_or_proc_call(EXPR lhs, ST_ID id, EXPR rhs);

//checks to see if expr is a lval
BOOLEAN is_lval(EXPR expr);

//free expression
void expr_free(EXPR expr);

//free expression list
void expr_list_free(EXPR_LIST list);

//Project III

/* Creteas a new Array Access expr with the given array and indices
	Also checks that the array is of array type
	gets and converts the r-val of each index
	checks that the index type is correct
	checks that the number of indicies is correct
*/
EXPR make_array_access_expr(EXPR array, EXPR_LIST indices);

//Returns a new VAL_LIST node for a single case constat
VAL_LIST new_case_value(TYPETAG type, long lo, long hi);

/*	checks each case constant on list to ensure its type matches and
  	that the low value is less than or equal to the high value

  */
BOOLEAN check_case_values(TYPETAG type, VAL_LIST vals, VAL_LIST prev_vals);

//De-allocates a list of case constants
void case_value_list_free(VAL_LIST vals);

/* 	Sets the output parameters to the value and type of the expr.
	Expr must be INTCONST
*/
BOOLEAN get_case_value(EXPR expr, long *val, TYPETAG *type);

/*	Checks to ensure var is an l-value and that types match that
	of init and limit.
*/
BOOLEAN check_for_preamble(EXPR var, EXPR init, EXPR limit);

#endif

