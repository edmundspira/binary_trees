#include "binary_trees.h"

/**
 * binary_tree_inorder - Uses the inorder traversal algo to print nodes in tree
 * @tree: Pointer to root of the tree
 * @func: Pointer to function to call on node's item
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	binary_tree_inorder(tree->left, func);
	func(tree->n);
	binary_tree_inorder(tree->right, func);
}
