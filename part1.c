/*
 * Machine Problem #1
 * CS 241, Spring 2010
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "mp1-functions.h"

int main()
{
	/*
	 * [Part 1]:
	 *   Edit the provided part1.c file to print out the tweleve "Illinois" lines
	 *   that are provided in the code inside mp1-functions.c.
	 */
        
        //pass 81 value to print first Illinois.
        first_step(81);
        
        // initialize a varaible with value 132 and pass its pointer as an argument.
        int val = 132;
        second_step(&val);

        // pass a double pointer to string which has value 8942 as its value.
        // int double_val = 8942;
        int** pp = (int **) malloc(sizeof(int*));
        *pp = (int *) malloc(sizeof(int)); 
        *pp[0] = 8942;
        double_step(pp);

        free(*pp);
        free(pp);
        // initialize a pointer value to zero and pass it to strange_step function.
        int* p_val = 0;
        strange_step(p_val);

        // pass a character array whose fourth value is zero.
        int name[4] = {0};
        empty_step(name);

        // create a character array and pointer to that array.
        char s[4];
        char* s1;
        s1 = s;
        s[3] = 'u';
        two_step(s, s1);

        // create a character array and assign other these values.
        char first[10];
        char* second = first + 2;
        char* third = second + 2;
        three_step(first, second, third);

        // use above arrays assign values in such away that they will call this.
        *first = 0;
        *second = *first + 4;
        *third = *second + 4;
        triple_step(first, second, third);
        
        // use the above arrays to call third
        //third = second = first; 
        first[1] = 0;
        second[2] = first[1] + 8;
        third[3] = second[2] + 8;
        step_step_step(first, second, third);         

        // everything is set just call above function.
        triple_three_step_step_step(first, second, third);

        // create an integer which is less than 256
        int b = 10;
        char* a = (char* )&b;
        it_may_be_odd(a, b);

        // create an integer array with initial value 0;
        p_val =(int *) malloc(sizeof(int));
        *p_val = 513;
        the_end(p_val, p_val);
        free(p_val);

	return 0;
}
