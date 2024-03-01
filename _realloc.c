#include "main.h"

/**
  * _realloc - Reallocates a memory area
  * @ptr: Pointer to the previous memory area
  * @old_size: Size of te old memory area
  * @new_size: Size of what the new memory area should be
  *
  * Return: A pointer to the reallocated memory area
  */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned int min_size;
	void *new_ptr;

	if (ptr == NULL)
	{
		new_ptr = malloc(new_size);
		return (new_ptr);
	}

	if (ptr != NULL && new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (new_size == old_size)
	{
		return (ptr);
	}

	min_size = new_size < old_size ? new_size : old_size;

	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
	{
		return (NULL);
	}

	new_ptr = _memcpy(new_ptr, ptr, min_size);

	free(ptr);
	return (new_ptr);
}
