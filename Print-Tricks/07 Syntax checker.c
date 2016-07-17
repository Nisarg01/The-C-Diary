/* Nisarg vasavada's Syntax Checker
 *
 */



#include <stdio.h>


char c;

/* Set the state/count variables 
since we are going to check the characters, we will term variables as follows

--------------------------------------------------------------------------
Line Number				: linenr
Barenthesis 			: parens ""
Brackets 				: brackets ()
Braces 					: braces {}
Single quotes 			: singqs ''
Double quotes 			: dubqs ""
Line escape sequences 	: escapes \n
Multi line comments 	: mcomms / followed by * (I wrote it this way
													since nesting multi
													line comments is not
													Possible)
Single line comments 	: scomms / followed by  /
---------------------------------------------------------------------------

*/

//in the beginning of the program all values will be naturally 0
int linenr, parens, brackets, braces, singqs, dubqs, escapes, mcomms, scomms = 0;

int main() 
{
	
	//starting from line 1
	linenr = 1;
	// Begin streaming!
	while ((c = getchar()) != EOF) 
	{

		//checking if any single line comments
		if (scomms == 1) 
		{
			if (c == '\n') 
			{
				scomms--;
			}

			else 
			{
				continue;
			}
		} 

		else if (mcomms == 1) 
		{
			if (c == '*') 
			{
				if (getchar() == '/') 
				{
					mcomms--;
				}
			}
		} 

		else 
		{
			// Check for escape sequences
			if (c == '\\') 
			{
				escapes++;
				c = getchar();
				// This does not detect all sequences; just the ones covered in Chapter 1.
				if (c != '\\' && c != 't' && c != '\'' && c != '"' && c != 'n' && c != 'b' && c != '0') 
				{
					break;
				} 
				else 
				{
					escapes--;
				}
			}
			// Newline behavior
			if (c == '\n') 
			{
				if (singqs > 0 || dubqs > 0) 
				{
					break;
				}
				linenr++;
			}
			// Parentheses
			if (c == '(') 
			{
				parens++;
			}

			if (c == ')') 
			{
				parens -= 1;
				if (parens < 0) 
				{
					break;
				}
			}

			// Brackets
			if (c == '[') 
			{
				brackets++;
			}

			if (c == ']') 
			{
				brackets--;
				
				if (brackets < 0) 
				{
					break;
				}
			}

			// Braces
			if (c == '{') 
			{
				braces++;
			}
			if (c == '}') 
			{
				braces--;
				if (braces < 0) 
				{
					break;
				}
			}

			// Double quotes
			if (c == '"') 
			{
				if (dubqs == 0) 
				{
					dubqs++;
				}

				else 
				{
					dubqs--;
				}
			}

			// Single quotes, which are only checked outside of doubles.
			if (c == '\'' && dubqs == 0) 
			{
				if (singqs == 0) 
				{
					singqs++;
				} 

				else 
				{
					singqs--;
				}
			}


			// Comment detection
			if (c == '/') 
			{
				if (getchar() == '*') 
				{
					mcomms++;
				}
				
				if (getchar() == '/') 
				{
					scomms++;
				}
			}
		}
	}

	if (escapes > 0) 
	{
		printf("Invalid escape sequence on line %d!\n", linenr);
		return 1;
	}

	if (singqs > 0) 
	{
		printf("Unclosed single quote on line %d!\n", linenr);
		return 1;
	}

	if (dubqs > 0) 
	{
		printf("Unclosed double quote on line %d!\n", linenr);
		return 1;
	}

	if (brackets > 0) 
	{
		printf("Unclosed brackets on line %d!\n", linenr);
		return 1;
	}
	
	if (brackets < 0) 
	{
		printf("Too many close brackets on line %d!\n", linenr);
		return 1;
	}
	
	if (parens > 0) 
	{
		printf("Unclosed parenthesis on line %d!\n", linenr);
		return 1;
	}
	
	if (parens < 0) 
	{
		printf("Too many close parentheses on line %d!\n", linenr);
		return 1;
	}
	
	if (braces > 0) 
	{
		printf("Unclosed braces on line %d!\n", linenr);
		return 1;
	}
	
	if (braces < 0) 
	{
		printf("Too many close braces on line %d!\n", linenr);
		return 1;
	}
	
	if (mcomms == 1) 
	{
		printf("Unclosed comment at end of file!\n");
		return 1;
	}

	printf("All clean.\n");
	return 0;
}
