#include "binary_trees.h"

/**
 * array_to_avl - Creates an AVL tree from an array of integers
 * @array: A pointer to the first integer in the array
 * @size: The number of elements in the array
 *
 * Return: A pointer to the root node in the array, or NULL if failed
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;
	size_t i    = 0;

	if (!array || !size)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		if (!avl_insert(&root, array[i]))
			return (NULL);
	}

	return (root);
}
