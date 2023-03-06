#include "binary_trees.h"

/**
 * binary_tree_levelorder - Goes through a binary tree by level-order traversal
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height, level;

	if (!tree || !func)
		return;

	height = binary_tree_height(tree);

	for (level = 0; level <= height; level++)
		_binary_tree_levelorder(tree, level, func);
}

/**
 * _binary_tree_levelorder - Traverses a binary tree level by level.
 * @tree: A pointer to the root node of the tree to traverse.
 * @level: The current level being traversed.
 * @func: A pointer to a function to call for each node.
 */
void _binary_tree_levelorder(const binary_tree_t *tree, size_t level,
			     void (*func)(int))
{
	if (!tree)
		return;

	if (level == 0)
		func(tree->n);
	else if (level > 0)
	{
		_binary_tree_levelorder(tree->left, level - 1, func);
		_binary_tree_levelorder(tree->right, level - 1, func);
	}
}

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: The height of the tree as a size_t value.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (!tree || (!tree->left && !tree->right))
		return (0);

	left_height  = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}
