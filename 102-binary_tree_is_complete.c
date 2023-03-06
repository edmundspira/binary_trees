#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: The binary tree to check.
 *
 * Return: If tree is NULL or not complete, return 0. Otherwise, return 1.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size;

	if (tree == NULL)
		return (0);

	size = binary_tree_size(tree);

	return (is_complete(tree, 0, size));
}

/**
 * is_complete - Checks if a binary tree is complete
 * @node: Node under review in the currrent call stack
 * @index: Index the node should be at if the tree was in a queue
 * @size: Size of the tree the node belongs to
 *
 * Return: 1 if complete, 0 otherwise
 */
int is_complete(const binary_tree_t *node, size_t index, size_t size)
{
	if (!node)
		return (1);

	if (index >= size)
		return (0);

	return (is_complete(node->left, (2 * index) + 1, size)
		&& is_complete(node->right, (2 * index) + 2, size));
}

/**
 * binary_tree_size - Measures the size of a binary tree.
 * @tree: The binary tree to measure the size of.
 *
 * Return: The size of the tree.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}
