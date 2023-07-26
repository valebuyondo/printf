#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
/**
* print_unsignedToBinary - prints an integer.
* @arg: argument
* Return: 0
*/
int print_unsignedToBinary(va_list arg)
{
	unsigned int n = va_arg(arg, unsigned int);
    	unsigned int printed = 0;
    	print_binary(n, &printed);
    	return (printed);
}
/**
* print_oct - prints number in octal base.
* @arg: list containing octal number to be printed
* Return: number of octals printed
*/
int print_oct(va_list arg)
{
	unsigned int num = va_arg(arg, unsigned int);

    	unsigned int copy;
    	char *octa;
    	int i, j = 0, charPrinted = 0;

    	if (num == 0)
    		return (_putchar('0'));

    	for (copy = num; copy != 0; j++)
    	{
    		copy = copy / 8;
    	}
    	octa = malloc(j);
    	if (!octa)
    		return (-1);
    	for (i = j - 1; i >= 0; i--)
    	{
    		octa[i] = num % 8 + '0';
    		num = num / 8;
    	}
    	for (i = 0; i < j && octa[i] == '0'; i++)
    		;
    	for (; i < j; i++)
    	{
    		_putchar(octa[i]);
    		charPrinted++;
    	}
    	free(octa);
    	return (charPrinted);
}
/**
* print_unsignedIntToHex - prints unsigned int to hexadecimal.
* @num: number to print.
* @_case: letter `a` on the case to print it (upper or lower).
* Return: number or char printed.
*/
int print_unsignedIntToHex(unsigned int num, char _case)
{
	unsigned int num2 = num;
    	int i, remainder, nbrCharacters = 0;

    	char *numhex;

    	if (num2 == 0)
    		return (_putchar('0'));

    	while (num2 != 0)
    	{
    		nbrCharacters++;
    		num2 /= 16;
    	}

    	numhex = malloc(nbrCharacters + 1); // Allocate memory for null terminator

    	if (numhex == NULL)
    		return (-1); // Handle memory allocation failure

    	for (i = 0; num != 0; i++)
    	{
    		remainder = num % 16;

    		if (remainder < 10)
    			numhex[i] = remainder + '0';
    		else
    			numhex[i] = remainder - 10 + _case;
    		num = num / 16;
    	}

    	numhex[i] = '\0'; // Add null terminator

    	// Print the hexadecimal representation
    	for (i = nbrCharacters - 1; i >= 0; i--)
    		_putchar(numhex[i]);

    	free(numhex);
    	return (nbrCharacters);
}
