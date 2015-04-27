/**********************************************************************/
/* lab 1 DVG C01 - Driver OBJECT                                      */
/**********************************************************************/

/**********************************************************************/
/* Include files                                                      */
/**********************************************************************/
#include <stdio.h>
#include <ctype.h>
#include <string.h>

/**********************************************************************/
/* Other OBJECT's METHODS (IMPORTED)                                  */
/**********************************************************************/
#include "keytoktab.h"

/**********************************************************************/
/* OBJECT ATTRIBUTES FOR THIS OBJECT (C MODULE)                       */
/**********************************************************************/
/**********************************************************************/
/* type definitions                                                   */
/**********************************************************************/
typedef struct tab {
	char 	* text;
	int 	token;
	} tab;
	
/**********************************************************************/
/* data objects (tables)                                              */
/**********************************************************************/
static tab tokentab[ ] = {
    {"id", 	        id},
	{"number", 		number},
	{":=", 	        assign},
	{"undef", 		undef},
	{"predef", 		predef},
	{"tempty", 		tempty},
	{"error",        error},
	{"type",         typ},
	{"$",            '$'},
	{"(",            '('},
	{")",            ')'},
	{"*",            '*'},
	{"+",            '+'},
	{",",            ','},
	{"-",            '-'},
	{".",            '.'},
	{"/",            '/'},
	{":",            ':'},
	{";",            ';'},
	{"=",            '='},
	{"TERROR", 	    nfound}
        };


static tab keywordtab[ ] = {
	{"program", 	program},
	{"input", 		input},
	{"output", 		output},
	{"var", 		var},
	{"begin", 		begin},
	{"end", 		end},
	{"boolean", 	boolean},
	{"integer", 	integer},
	{"real", 		real},
	{"KERROR", 		nfound}
	};
   
/**********************************************************************/
/*  PUBLIC METHODS for this OBJECT  (EXPORTED)                        */
/**********************************************************************/
/**********************************************************************/
/* Display the tables                                                 */
/**********************************************************************/
void p_toktab()
{  
	
   int i = 0;
   do{
   	printf("*** %s %i \n",keywordtab[i].text,keywordtab[i].token);	
   	i++;
   } while(keywordtab[i].token!=nfound);
  
   
   i = 0;
   do{
   	printf("*** %s %i \n", tokentab[i].text,tokentab[i].token);
   	i++;
   }while(tokentab[i].token != nfound);
    
   
}

/**********************************************************************/
/* lex2tok - convert a lexeme to a token                              */
/**********************************************************************/
toktyp lex2tok(char * fplex)
{
   int i = 0;
   while(i<21)
   {
   	if(strcmp(fplex, tokentab[i].text) == 0)
   	{
   		return tokentab[i].token;
   	}
   	i++;
   }
   return 0;
}

/**********************************************************************/
/* key2tok - convert a keyword to a token                             */
/**********************************************************************/
toktyp key2tok(char * fplex)
{
   //printf("( **** INNE I KEY2TOK ****** )");
   int i = 0;
   //  search the keyword table to see if the string has a match - if found, return the corresponding token 
   while(keywordtab[i].token != nfound)
   {
   	if(strcmp(fplex, keywordtab[i].text) == 0)
   	{
  		return keywordtab[i].token;
   	}
  	i++;
   }
   return tokentab[0].token; // if not found in the keyword table, the lexeme is an id - return token id
   }

/**********************************************************************/
/* tok2lex - convert a token to a lexeme                              */
/**********************************************************************/
char * tok2lex(toktyp ftok)
{
   int i = 0;
   while(tokentab[i].token != nfound){
	   if(tokentab[i].token == ftok){ return tokentab[i].text; 	}
	   	i++;
   }
   i = 0;
   while(keywordtab[i].token != nfound){
   		if(keywordtab[i].token == ftok){
	   		 return keywordtab[i].text;
   		}
	    i++;
   }
   return "ERROR";
   }
/**********************************************************************/
/* End of code                                                        */
/**********************************************************************/

