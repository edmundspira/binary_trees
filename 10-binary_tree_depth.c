#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a tree
 * @tree: Node whose depth is to be measured
 *
 * Return: Depth of the node, or 0 if it could not be computed
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (!tree || !tree->parent)
		return (0);

	return (1 + binary_tree_depth(tree->parent));
}
