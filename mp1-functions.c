/*
 * Machine Problem #1
 * CS 241, Spring 2010
 */

#include <stdio.h>

void first_step(int value)
{
	if (value == 81)
		printf("1: Illinois\n");
}

void second_step(int *value)
{
	if (*value == 132)
		printf("2: Illinois\n");
}

void double_step(int **value)
{
	if (*value[0] == 8942)
		printf("3: Illinois\n");
}

void strange_step(int *value)
{
	if (value == 0)
		printf("4: Illinois\n");
}

void empty_step(void *value)
{
	/* Sanity check to prevent a seg fault */
	if (value == NULL)
		return;

	if (((char *)value)[3] == 0)
		printf("5: Illinois\n");
}

void two_step(void *s, char *s2)
{
	/* Sanity check to prevent a seg fault */
	if (s2 == NULL)
		return;

	if (s == s2 && s2[3] == 'u')
		printf("6: Illinois\n");
}

void three_step(char *first, char *second, char *third)
{
	if (third == second + 2 && second == first + 2)
		printf("7: Illinois\n");
}

void triple_step(char *first, char *second, char *third)
{
	if (*third == *second + 4 && *second == *first + 4)
		printf("8: Illinois\n");
}

void step_step_step(char *first, char *second, char *third)
{
	if (third[3] == second[2] + 8 && second[2] == first[1] + 8)
		printf("9: Illinois\n");
}

void triple_three_step_step_step(char *first, char *second, char *third)
{
	if ( third    ==  second    + 2 &&  second    ==  first    + 2 &&
	    *third    == *second    + 4 && *second    == *first    + 4 &&
	     third[3] ==  second[2] + 8 &&  second[2] ==  first[1] + 8)
	{
		printf("10: Illinois\n");
	}
}

void it_may_be_odd(char *a, int b)
{
	/* Sanity check to prevent a seg fault */
	if (a == NULL)
		return;

	if (*a == b && b > 0)
	{
		printf("11: Illinois\n");
	}
}

void the_end(void *orange, void *blue)
{
	if (orange != NULL && orange == blue && ((char *)blue)[0] == 1 && *((int *)orange) % 3 == 0)
	{
		printf("12: Illinois\n");
	}
}
