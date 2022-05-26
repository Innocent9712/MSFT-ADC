clea#include <stdio.h>
/**
 * main - function to check a string
 * Description: The function receives a string and checks if the number of
 * Brackets, Parenthesis and Curly braces are properly paired.
 * Prints "true" if true and "false" if false.
 *
 * Return: 0;
 */

int main(void)
{
	char string[40];
	unsigned int curly = 0, square = 0, parenthesis = 0, i = 0;

	puts("Enter a string of braces to check: ");
	fgets(string, 40, stdin);

	while (string[i])
	{
		if (string[i] == 40 || string[i] == 41)
			parenthesis++;
		else if (string[i] == 91 || string[i] == 93)
			square++;
		else if (string[i] == 123 || string[i] == 125)
			curly++;
		i++;
	}

	if ((curly + square + parenthesis) == 0)
	{
		puts("false");
		return (0);
	}

	if (curly % 2 == 0 && square % 2 == 0 && parenthesis % 2 == 0)
		puts("true");
	else
		puts("false");

	printf("curly braces: %d, parenthesis: %d, brackets: %d\n",
	       curly, parenthesis, square);

	return (0);
}
