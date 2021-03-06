/**********************************************************************/
/* lab 1 DVG C01 - Lexer OBJECT                                       */
/**********************************************************************/

/**********************************************************************/
/* Include files                                                      */
/**********************************************************************/
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

/**********************************************************************/
/* Other OBJECT's METHODS (IMPORTED)                                  */
/**********************************************************************/
#include "keytoktab.h"

/**********************************************************************/
/* OBJECT ATTRIBUTES FOR THIS OBJECT (C MODULE)                       */
/**********************************************************************/
#define BUFSIZE 1024
#define LEXSIZE   30
static char buffer[BUFSIZE];
static char lexbuf[LEXSIZE];
static int  pbuf  = 0;               /* current index program buffer  */
static int  plex  = 0;               /* current index lexeme  buffer  */

/**********************************************************************/
/*  PRIVATE METHODS for this OBJECT  (using "static" in C)            */
/**********************************************************************/
/**********************************************************************/
/* buffer functions                                                   */
/**********************************************************************/
/**********************************************************************/
/* Read the input file into the buffer                                */
/**********************************************************************/

static void get_prog()
{
 /*  printf("\n******** GETPROG *******");
   
   char ch, file_name[25];
   FILE *fp;
   
   printf("\nEnter the name of the file you wish to open: ");
   fgets(file_name, sizeof(file_name), stdin);
   
   fp = fopen(file_name, "r");
   
   if(fp == NULL)
   {
      printf("Error opening the file.");
      exit(EXIT_FAILURE);
   }
   int i = 0;
   while((ch == fgetc(fp)) != EOF)
   {
      buffer[i] = fgetc(fp);
      i++;
   }
   buffer[i] = '$';
   buffer[i+1] = '\0';
   fclose(fp);
*/
   int  i;

   i=0; while ((buffer[i] = fgetc(stdin)) != EOF){
      i++;
   }
   buffer[i] = '$'; buffer[i+1] = '\0';

}     

/**********************************************************************/
/* Display the buffer                                                 */
/**********************************************************************/  

static void pbuffer()
{   
   int i = 0;
   printf("\n --------- file text \n ");
   
   
   while(/*buffer[i] != '\0' ||*/ buffer[i] != '$')
   { 
<<<<<<< HEAD
      printf("%c", buffer[i]);
=======
      printf("\n%c", buffer[i]);
>>>>>>> 5d2f52e96458d03d51c9b62dbf3dfce636fe3119
      i++;
   }
   printf("\n --------- end of file text \n ");
}

<<<<<<< HEAD

/**********************************************************************/
/* Display the buffer                                                 */
/**********************************************************************/  
/*static void lbuffer()
{   
   int i = 0;
   printf("\n\n\n\n --------- lexbuf text \n ");
   
   
   while(lexbuf[i] != '\0')
   { 
      printf("%c", lexbuf[i]);
      i++;
   }
   printf("\n --------- end of lexbuf text \n ");
}*/

=======
>>>>>>> 5d2f52e96458d03d51c9b62dbf3dfce636fe3119
/**********************************************************************/
/* Copy a character from the program buffer to the lexeme buffer      */
/**********************************************************************/

static void get_char()
{   
   lexbuf[plex] = buffer[pbuf];
   plex++; 
   pbuf++;
}

/**********************************************************************/
/* End of buffer handling functions                                   */
/**********************************************************************/

/**********************************************************************/
/*  PUBLIC METHODS for this OBJECT  (EXPORTED)                        */
/**********************************************************************/
/**********************************************************************/
/* Return a token                                                     */
/**********************************************************************/
int get_token()
{  
   // om filen ej är inläst görs detta första gången funktionen körs
	if(strlen(buffer) == 0) { get_prog(); pbuffer(); }
	
	// tömmer lexemebufferten 
	memset(lexbuf, 0, LEXSIZE); plex=0;
	
	// hoppar över whitespaces
	while(isspace(buffer[pbuf]))			{ pbuf++; }
	// om tecknet inte är alfanumeriskt skall det läsas in ett och ett (med enda undantaget för ":=")
	if(!isalnum(buffer[pbuf]))	{ 
		if(buffer[pbuf]==':' && buffer[pbuf+1]=='=') {
			get_char(); get_char(); lexbuf[plex] = '\0'; return lex2tok(lexbuf);
		}
		else {
			get_char(); lexbuf[plex] = '\0'; return lex2tok(lexbuf);
		}
	}
	
	/*The current character is a letter - the token is either a keyword token or id
	
    1. read the string of alphanumeric characters into a (local) lexeme buffer
    2. search the keyword table to see if the string has a match - if found, return the corresponding token
    3. if not found in the keyword table, the lexeme is an id - return token id */
	
	// om teknen är alfanumeriska ska de samtliga läsas in för att skapa en lexeme
	while(isalnum(buffer[pbuf]))			{ get_char(); }
	lexbuf[plex] = '\0';
<<<<<<< HEAD
	return key2tok(lexbuf); // key2tok ska anropas här? // benji //det ska den // käck
	//return lexbuf;
=======
	return key2tok(lexbuf); // key2tok ska anropas här? // benji
	
>>>>>>> 5d2f52e96458d03d51c9b62dbf3dfce636fe3119
	
    
    
}

/**********************************************************************/
/* Return a lexeme                                                    */
/**********************************************************************/
char * get_lexeme()
{  
  return lexbuf; // retunerar det som finns i lexeme buffern, vid den tidpunkten den anropas, lexbuf ändras efter varje anrop till get tÖken
}

/**********************************************************************/
/* End of code                                                        */
/**********************************************************************/

