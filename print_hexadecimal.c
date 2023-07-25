#include "main.h"
/**
* print_hex_base - base function for printing hexadecimal numbers
* @arg: argument list containing hexadecimal
* @_case: a in caps on lower, printing the hex number in caps in lower
* Return: number of digits printed
*/
int print_hex_base(va_list arg, char _case)
{
	unsigned int num = va_arg(arg, unsigned int);

	int nbrCharacters;

	if (num == 0)
		return (_putchar('0'));
	nbrCharacters = print_unsignedIntToHex(num, _case);
	return (nbrCharacters);
}
/**
* print_hex - prints a hexadecimal in lower case.
* @arg: list that contains hexadecimal to print.
* Return: number of digits printed.

*/
int print_hex(va_list arg)
{
	return (print_hex_base(arg, 'a'));
}
#include "main.h"
/**
* print_binary - function that prints the binary representation of a number.
* @n: number  printed in binary.
* @printed: hold the number of characters printed.
*/

void print_binary(unsigned int n, unsigned int *printed)
{
	if (n > 1)
	{
		*printed += 1;
		print_binary(n >> 1, printed);
	}
	_putchar((n & 1) + '0');
}
/**
* print_HEX - prints a hexadecimal in upper case
* @arg: list that contains hexadecimal to print
* Return: number of digits printed
*/
int print_HEX(va_list arg)
{
	return (print_hex_base(arg, 'A'));
}