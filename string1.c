#include "shell.h"

/**
 * str_copy - copies a string
 * @destination: the destination
 * @source: the source
 *
 * Return: pointer to destination
 */
char *str_copy(char *destination, char *source)
{
	int index = 0;

	if (destination == source || source == 0)
		return (destination);
	while (source[index])
	{
		destination[index] = source[index];
		index++;
	}
	destination[index] = 0;
	return (destination);
}

/**
 * str_duplicate - duplicates a string
 * @str_to_duplicate: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *str_duplicate(const char *str_to_duplicate)
{
	int length = 0;
	char *result;

	if (str_to_duplicate == NULL)
		return (NULL);
	while (*str_to_duplicate++)
		length++;
	result = malloc(sizeof(char) * (length + 1));
	if (!result)
		return (NULL);
	for (length++; length--;)
		result[length] = *--str_to_duplicate;
	return (result);
}

/**
 * put_string - prints an input string
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void put_string(char *str)
{
	int index = 0;

	if (!str)
		return;
	while (str[index] != '\0')
	{
		put_character(str[index]);
		index++;
	}
}

/**
 * put_character - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int put_character(char character)
{
	static int index;
	static char buffer[WRITE_BUF_SIZE];

	if (character == BUF_FLUSH || index >= WRITE_BUF_SIZE)
	{
		write(1, buffer, index);
		index = 0;
	}
	if (character != BUF_FLUSH)
		buffer[index++] = character;
	return (1);
}
