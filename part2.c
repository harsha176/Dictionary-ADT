/*
 * Machine Problem #1
 * CS 241, Spring 2010
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "libdictionary/libdictionary.h"

int main(int argc, char **argv)
{
	/*
	 * Ensure that the program provides exactly one command-line argument.
	 * If the program doesn't, display usage information and exit.
	 */
	if (argc != 2)
	{
		printf("Usage: %s <file name>\n", argv[0]);
		return 1;
	}

	/*
	 * Use the command-line argument provided as the file name and attempt
	 * to open the file. If the fopen() fails, display an error message and exit.
	 */
	FILE *file = fopen(argv[1], "r");
	if (!file)
	{
		printf("Unable to open file %s. Exiting.\n", argv[1]);
		return 2;
	}

	/*
	 * Initialize the dictionary data structure.
	 */
	dictionary_t dictionary;
	if (dictionary_init(&dictionary) != 0)
	{
		printf("Failed to initialize the dictionary data structure.\n");
		return 3;
	}

	/*
	 * Read the file, line by line, calling dictionary_parse() on each line of
	 * input from the file.
	 */
	char buffer[1024]; buffer[0] = '\0';
	while (fgets(buffer, 1024, file))
	{
		/* Since fgets() returns the newline characters, we'll remove any that exist. */
		int index;
		for (index = 0; buffer[index] != '\0'; index++)
			if (buffer[index] == '\n' || buffer[index] == '\r')
				buffer[index] = '\0';

		if (dictionary_parse(&dictionary, buffer) != 0)
		{
			printf("Failed to parse the file data into the dictionary.\n");
			dictionary_destroy(&dictionary);
                        return 4;
		}
	}

	/*
	 * Print the contents of the dictionary.
	 */
	dictionary_print(&dictionary);

	/*
	 * Free up the memory used by the dictionary and close the file.
	 */
	dictionary_destroy(&dictionary);
	fclose(file);

	return 0;
}
