//nested if statements are focus of this program

// Author: Nisarg Vasavada

#include <stdio.h>


//these are macros
#define IN 1
#define OUT 0
#define MINWLENGTH 2
#define MAXWLENGTH 20

int main(void) 
{
	/* Rundown of variables:
	 * i, j = reusable placeholder variables
	 * state = inside or outside a word
	 * ltrs = letter count
	 * wrds = word count
	 * lines = you should be shot if you don't know
	 * lengths = an array that keeps track of how often words up to x chars long
	 *           occur.
	 */

	int state, ltrs, wrds, lines, wlen, i, j;
	int lengths[MAXWLENGTH];
	for (i = 0; i <= MAXWLENGTH; ++i) 
	{
		lengths[i] = 0;
	}

	ltrs = wrds = wlen = 0;
	lines = 1;
	state = OUT;
	// Capture input until it ends
	while ((i = getchar()) != EOF) 
	{
		// If it's whitespace, we've exited a word
		if (i == '\n' || i == ' ' || i == '\t') 
		{
			if (state == IN) 
			{
				++wrds; // ...and should increase the count.
				state = OUT;
				/* Check to see if the word is eligible to be counted. */
				if (wlen <= MAXWLENGTH) 
				{
					++lengths[wlen];
				}
				// Reset our word length now.
				wlen = 0;
			}
			/* If it's a new line, we're still out of a word but need to increment the
			   line count */
			if (i == '\n') 
			{
				++lines;
			}
		} 
			else 
			{
			/* If nothing else, we know it's just a random character or a letter. */
			state = IN;
			++wlen;
			}
		/* Everything that's input counts as a letter. */
		++ltrs;
	}

	printf("\nWORD LENGTH FREQUENCY\n     ");
	for (i = 5; i < 80; i += 5) {
		printf("   %2d", i);
	}

	printf("\n"); // End the chart heading.
	j = MINWLENGTH;
	while (j <= MAXWLENGTH) {
		i = lengths[j];
		if (i > 0) {
			printf("%2d | ", j);
			while (i > 0) {
				printf("#");
				i = i-1;
			}
			printf("\n");
		}
		++j;
	}
	printf("%d words, %d chars, %d lines.\n", wrds, ltrs, lines);
	return 0;
}
