#include "Header.h"

// ASKS USER TO CHOOSES THE CORRECT DATA-SET FROM A GIVEN LIST OF CHARACTERS.
FILE* menu(void)
{
	FILE* infile = NULL;
	char user_in = '\0';
	while (user_in == '\0')
	{
		printf("From the following list of data-sets:\t(a) for set-a\n\t\t\t\t\t(b) for set-b\n\t\t\t\t\t(c) for set-c\n\t\t\t\t\t(d) for set-d\n\t\t\t\t\t(e) for set-c\n\nChoose a data-set by entering a letter: ");
		scanf("%c", &user_in);

		if (user_in == 'a')
		{
			infile = fopen("a_example.in", "r");
		}
		else if (user_in == 'b')
		{
			infile = fopen("b_small.in", "r");
		}
		else if (user_in == 'c')
		{
			infile = fopen("c_medium.in", "r");
		}
		else if (user_in == 'd')
		{
			infile = fopen("d_quite_big.in", "r");
		}
		else if (user_in == 'e')
		{
			infile = fopen("e_also_big.in", "r");
		}
		else
		{	// This is our warning message to let the user knows that they entered an unsupported character, and they need to input again.
			printf("\n\t\tINVALID INPUT. PLEASE ENTER THE CORRECT LETTER.\n\n");
			user_in = '\0';
		}
	}
	return infile;
}

// TAKES AN OPENED INFILE AND EXTRACTS ONE INTEGER VALUE FROM IT, IS MEANT TO BE RECYCLED IN LOOPS.
int read_datapoint(FILE* infile)
{
	int datapoint = 0;

	fscanf(infile, "%d", &datapoint);

	return datapoint;
}