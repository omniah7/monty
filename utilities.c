#include "monty.h"
/**
 * isInteger - checks if a string has an int at the begining of it
 * @s: the string to be checked
 * Return: true if it has an int. false otherwise
 */
bool isInteger(char *s)
{
	if (!s)
		return (false);

	if (!isdigit(s[0]))
	{
		if (s[0] == '-' && isdigit(s[1]))
		{
			return (true);
		}
		return (false);
	}
	return (true);
}
/**
 * toInteger - converts a string into an interger
 * @s: the string to be converted
 * Return: the interger
 */
int toInteger(char *s)
{
	char n[10];
	int i, j;
	bool negative = false;

	if (s[0] == '-')
		negative = true;

	for (i = (negative) ? 1 : 0, j = 0; s[i]; i++, j++)
	{
		if (!isdigit(s[i]))
			break;

		n[j] = s[i];
	}
	if (negative)
		return (atoi(n) * -1);
	return (atoi(n));
}

/**
 * isChar - checks if an int can be converted to a char
 * @c: the integer to be checked
 * Return: true if it is a char. false otherwise
 */
bool isChar(int c)
{
	if (c >= 0 && c <= 127)
	{
		return (true);
	}
	return (false);
}
