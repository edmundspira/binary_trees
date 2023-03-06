#include "binary_trees.h"

/**
 * binary_tree_preorder - Visit all nodes using the preoder traversal algorithm
 * @tree: A pointer to the root of the tree
 * @func: A pointer to a function to call on every node visited
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	func(tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}
