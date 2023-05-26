#include "shell.h"

/**
 * _memset - fills memory with a constant byte
 * @k: the pointer to the memory area
 * @t: the byte to fill *k with
 * @n: the amount of bytes to be filled
 * Return: (s) a pointer to the memory area s
 */
char *_memset(char *k, char t, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		k[i] = t;
	return (k);
}

/**
 * ffree - frees a string of strings
 * @kn: string of strings
 */
void ffree(char **kn)
{
	char **a = kn;

	if (!kn)
		return;
	while (*kn)
		free(*kn++);
	free(a);
}

/**
 * _realloc - reallocates a block of memory
 * @ptr: pointer to previous malloc'ated block
 * @old_size: byte size of previous block
 * @new_size: byte size of new block
 *
 * Return: pointer to da ol'block nameen.
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
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
