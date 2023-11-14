#include "shell.h"

/**
 **_strncpy - Copies string
 *@dest: Destination string to be copied to
 *@src: Source string
 *@n: Amount of characters to be copied
 *Return: The concatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int a, j;
	char *s = dest;

	a = 0;
	while (src[a] != '\0' && a < n - 1)
	{
		dest[a] = src[a];
		a++;
	}
	if (a < n)
	{
		j = a;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 **_strncat - Concatenates two strings
 *@dest: First string
 *@src: Second string
 *@n: Amount of bytes to be maximally used
 *Return: The concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
	int a, j;
	char *s = dest;

	a = 0;
	j = 0;
	while (dest[a] != '\0')
		a++;
	while (src[j] != '\0' && j < n)
	{
		dest[a] = src[j];
		a++;
		j++;
	}
	if (j < n)
		dest[a] = '\0';
	return (s);
}

/**
 **_strchr - Locates a character in a string
 *@s: String to be parsed
 *@c: Character to look for
 *Return: (s) a pointer to the memory area s
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
