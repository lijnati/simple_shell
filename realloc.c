#include "shell.h"

/**
 * _memset - fills memory with a constant byte
 * @s: pointer to the memory area
 * @b: the byte to fill *s with
 * @n: the number of bytes to be filled
 *
 * Return: a pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

/**
 * ffree - frees an array of strings
 * @pp: pointer to the array of strings
 */
void ffree(char **pp)
{
	if (!pp)
		return;

	for (int i = 0; pp[i]; i++)
		free(pp[i]);

	free(pp);
}

/**
 * _realloc - reallocates a block of memory
 * @ptr: pointer to the previous block
 * @old_size: size of the previous block
 * @new_size: size of the new block
 *
 * Return: pointer to the new block, or NULL on failure
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	_memset(p, 0, new_size);
	_memcpy(p, ptr, old_size);
	free(ptr);

	return (p);
}
