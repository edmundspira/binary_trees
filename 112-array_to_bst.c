#include "binary_trees.h"

/**
 * array_to_bst - Creates a new binary search tree from values in an array
 * @array: Pointer to the first integer in the array
 * @size: Size of the array
 *
 * Return: A pointer to the root node in the array
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root = NULL;
	size_t i;

	if (!array || !size)
		return (NULL);

	for (i = 0; i < size; i++)
		bst_insert(&root, array[i]);

	return (root);
}
