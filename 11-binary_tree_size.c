#include "binary_trees.h"

/**
 * binary_tree_size - Gets the size of a node in a binary tree
 * @tree: Node for which size is to be gotten
 *
 * Return: size of the tree, or 0 otherwise
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}
