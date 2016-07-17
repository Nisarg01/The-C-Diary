/* Author: Nisarg Vasavada

this program calculates total spaces used in the input program

Spaces are of different ty[es such as blank spaces (Single character), tabs
new lines etc

Each one of them have respective encoded consideration thus identifying them
should not be an issue

*/


#include <stdio.h>


int main(void) 
{
	char c;
	int blanks, tabs, nwelines = 0;

	while ((c = getchar()) != EOF) 
	{
		//this one is a blank character
		if (c == ' ') 
		{
			blanks++;
		}
		
		//this one is a tab
		else if (c == '\t') 
		{
			tabs++;
		}

		//this one is a newline
		else (c == '\n') 
		{
			newlines++;
		}
	}

	printf("%d blanks, %d tabs, and %d newlines.\n", blanks, tabs, nwelines);
	return 0;
}
