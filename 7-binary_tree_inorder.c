#include "binary_trees.h"

/**
 * binary_tree_inorder - traverse a binary tree using in-order traversal
 * @tree: pointer to the parent node of the node to create
 * @func: pointer of function
 * Return: void
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{

	if (tree == NULL || func == NULL)
		return;

	binary_tree_preorder(tree->left, func);
	func(tree->n);
	binary_tree_preorder(tree->right, func);
}
