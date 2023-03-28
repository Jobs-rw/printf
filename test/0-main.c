#include "main.h"
#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Entry point of the program.
 *              It calls _printf function to print integer values
 *              and prints the returned number of printed characters.
 *
 * Return: Always 0 (success)
 */
int main(void)
{
	int a;
	int number;

	number = 19912507;
	a = _printf("%i, %d\n", number, number);
	printf("%d\n", a);
	a = _printf("% ");
	printf("%d\n", a);
	return (0);
}

