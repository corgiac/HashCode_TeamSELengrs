/*
	CRIMSONCODE HACKATHON 2020
	TEAM: FUTURE SEL EGINEERS!
	MEMBERS: CHARLES NORDEN, FRED MATTER, DANIEL CLAWSON
	
	DATE: 2020-02-22, SATURDAY
	DESCRIPTION: Solving a given problem (retrieved from the 'Google Hash Code 2020' competition).

	For more information, please refer to the "readme.txt" file.
*/

#include "Header.h"

int main(void)
{
	FILE* infile = NULL;

	int max_slices = 0, max_pizzas = 0,
		datapoint = 0;
	
	// invokes the function menu() which asks user to pick a correct data-set from a pool of characters from a through e.
	infile = menu();
	
	// in the next 2 lines, the infile parameter is passed into the function read_datapoint(),
	// which reads and returns a number and assigns it to the appropriate parameter.
	max_slices = read_datapoint(infile);	// this parameter is the maximum slices of pizzas allowed to be ordered.
	max_pizzas = read_datapoint(infile);	// this paremeter is the pool of pizzas we can select from.
	printf("\n\tmax_slices = %d\t\tmax_pizzas = %d\n\n", max_slices, max_pizzas);
	
	// declares and initializes an array of variable size (depending on the value of max_pizzas) to store data extracted from the line 2.
	int* line_2_data = NULL;
	line_2_data = malloc(sizeof(int) * max_pizzas);

	// declares and initializes i, i is our counter for the next for-loop.
	// this for-loop repeatedly reads values from the raw data, starting from the 1st entry on the second line,
	// and assigns it to each block of the array <line_2_data>.
	int i = 0;
	int	counter = 0;	// our counter for number of selected pizzas.
	printf("Our raw data from line 2: (format: [block]slices)\n\n");
	for (i = 0; i < max_pizzas; i += 1)
	{
		line_2_data[i] = read_datapoint(infile);
		printf("[%d]%d  ", i, line_2_data[i]);
	}

	int sum = 0;
	int location_i = 0;
	int slices_at_block_i = 0;
	
	printf("\n\n\nFirst we add these values: (format: [block]slices:sum)\n");	// for format and styling purpose.

	// the following for-loop:
	// takes value of location at the very END of the array and starts adding it going BACKWARD (DESCENDING ORDER), one block at a time.
	// this for-loop gets the biggest sum in the least amount of time by
	// starting the summing operation from the block at the end of the array.
	for (i = max_pizzas - 1; sum <= max_slices; i -= 1)
	{
		sum = sum + line_2_data[i];	// first iteration: sum = 0, sum = 0 + value-at-final-block, repeats until condition is met.
		location_i = i;				// gets the value OF location i
		slices_at_block_i = line_2_data[i];	// gets value AT location i
		printf("[%d]%d:%d\n", location_i, slices_at_block_i, sum);
		counter += 1;
	}

	printf("\n\nWe correct the sum by subtract value from the previous data block in the array:\n\n");
	sum = sum - line_2_data[i + 1];		// corrects the issue of over-adding onto sum in the final iteration above.
	counter -= 1;
	printf("\t\t\tsum - line_2_data[%d]%d = %d\n\n", location_i, line_2_data[location_i], sum);

	int j = 0;
	int location_j = 0;
	int slice_at_block_j = 0;
	int total_pizzas = 0;

	printf("\nThen add the following values:\n");	// for format and styling purpose.

	// the following for-loop:
	// takes value of location at the very START of the array and starts adding it going FORWARD (ASCENDING ORDER), one block at a time.
	// this for-loop fine-tunes the value of sum by summing from the beginning blocks of the array,
	// which contains smaller values and therefore helps bring the <sum> closer to our maximum <pizza_slices> in a more controlled manner.
	for (j = 0; sum <= max_slices; j += 1)	// CORRECTED FROM location_i
	{
		sum = sum + line_2_data[j]; // first iteration: sum from previous for-loop, sum = 0 + value-at-final-block.
		location_j = j;				// gets the value OF location j
		slice_at_block_j = line_2_data[j]; // // gets value AT location j
		printf("[%d]%d:%d\n", location_j, slice_at_block_j, sum);
		counter += 1;
	}
	
	printf("\n\nSimilarly, we correct the sum by subtract value from the previous data block in the array:\n\n");
	sum = sum - line_2_data[j - 1];		// corrects the issue of over-adding onto sum in the final iteration above.
	counter -= 1;
	printf("\t\t\tsum - line_2_data[%d]%d = %d\n\n", location_j, line_2_data[location_j], sum);

	printf("\nThe result is <%d> true sum of slices from a total of <%d> ordered pizzas.\n\n", sum, counter);
	
	return 0;
}
