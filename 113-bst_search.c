#include "binary_trees.h"

/**
 * bst_search - Searches for a value in a Binary Search Tree
 * @tree: Pointer to the root node of the tree
 * @value: Value of the node to find
 *
 * Return: A pointer to the node with @value, or NULL on failure
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (!tree)
		return (NULL);

	if (tree->n == value)
		return ((bst_t *)tree);

	return (tree->n < value ? bst_search(tree->right, value)
				: bst_search(tree->left, value));
}
