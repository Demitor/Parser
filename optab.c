/**********************************************************************/
/* lab 1 DVG C01 - Operator Table OBJECT                              */
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
#define NENTS 4

static int optab[][NENTS] = {
   {'+', integer, integer, integer},
   {'+', real,    real,    real},
   {'+', integer, real,    real},
   {'+', real,    integer, real},
   {'*', integer, integer, integer},
   {'*', real,    real,    real},
   {'*', integer, real,    real},
   {'*', real,    integer, real},
   {'$', undef,   undef,   undef}
   };

/**********************************************************************/
/*  PRIVATE METHODS for this OBJECT  (using "static" in C)            */
/**********************************************************************/

/**********************************************************************/
/*  PUBLIC METHODS for this OBJECT  (EXPORTED)                        */
/**********************************************************************/

void p_optab()
{
   
   printf("\n________________________________________________________\nTHE OPERATOR TABLE\n________________________________________________________\n");
   printf("\noperator\t\targ1\t\targ2\t\tresult\n________________________________________________________");
   int i = 0;
   while(i < 7)
   {
      printf("\n\t%s,\t\t%s,\t\t%s,\t\t%s", tok2lex(optab[i][0]), tok2lex(optab[i][1]), tok2lex(optab[i][2]), tok2lex(optab[i][3]));
      i++;
   }
   printf("\n________________________________________________________");
}

/**********************************************************************/
/* return the type of a binary expression op arg1 arg2                */
/**********************************************************************/
int get_otype(int op, int arg1, int arg2)
{  
   int i = 0;
   while(i < 7)
   {
      //printf("\nComparing: %s with %s\n%s with %s\n%s with %s\n\n", tok2lex(op), tok2lex(optab[i][0]), tok2lex(arg1), tok2lex(optab[i][1]), tok2lex(arg2),tok2lex(optab[i][2]));
      if(strcmp(tok2lex(op), tok2lex(optab[i][0])) == 0 && strcmp(tok2lex(arg1), tok2lex(optab[i][1])) == 0 && strcmp(tok2lex(arg2), tok2lex(optab[i][2])) == 0)
      {
         //printf("\n*** RETURNING: %s\t%s\t%s\t%s", tok2lex(optab[i][0]), tok2lex(optab[i][1]), tok2lex(optab[i][2]), tok2lex(optab[i][3]));
         return optab[i][3];
      }else if(strcmp(tok2lex(op), tok2lex(optab[i][0])) == 0 && strcmp(tok2lex(arg2), tok2lex(optab[i][1])) == 0 && strcmp(tok2lex(arg1), tok2lex(optab[i][2])) == 0)
      {
         //printf("\n*** RETURNING: %s\t%s\t%s\t%s", tok2lex(optab[i][0]), tok2lex(optab[i][1]), tok2lex(optab[i][2]), tok2lex(optab[i][3]));
         return optab[i][3];
      }
      i++;
   }
   //printf("\n*** RETURNING: %s\t%s\t%s\t%s", tok2lex(optab[8][0]), tok2lex(optab[8][1]), tok2lex(optab[8][2]), tok2lex(optab[8][3]));
   return optab[8][3];
}

/**********************************************************************/
/* End of code                                                        */
/**********************************************************************/
