#include "binary_trees.h"

/**
 * binary_tree_postorder - Uses the postorder traversal algo to traversal tree
 * @tree: Pointer to the root of the tree
 * @func: Pointer to the function to call on each item in the node
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	func(tree->n);
}
