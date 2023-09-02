#include "binary_trees.h"

/**
 * get_height - Function that measures the height of a binary tree
 * @tree: tree to go through
 * Return: the height
 */
size_t get_height(const binary_tree_t *tree)
{
	size_t left = 0;
	size_t right = 0;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (tree->parent != NULL);
	if (tree)
	{
		left = tree->left ? 1 + get_height(tree->left) : 0;
		right = tree->right ? 1 + get_height(tree->right) : 0;
	}
	return ((left > right) ? left : right);
}

/**
 * get_bfactor - Measures balance factor of a binary tree
 * @tree: tree to go through
 * Return: balanced factor
 */
int get_bfactor(const binary_tree_t *tree)
{
	int right = 0, left = 0, total = 0;

	if (tree)
	{
		left = ((int)get_height(tree->left));
		right = ((int)get_height(tree->right));
		total = left - right;
	}
	return (total);
}

/**
 * is_tree_perfect - function that says if a tree is perfect or not
 * it has to be the same quantity of levels in left as right, and also
 * each node has to have 2 nodes or none
 * @tree: tree to check
 * Return: 0 if is not a perfect or other number that is the level of height
 */
int is_tree_perfect(const binary_tree_t *tree)
{
	int left = 0, right = 0;

	if (tree->left && tree->right)
	{
		left = 1 + is_tree_perfect(tree->left);
		right = 1 + is_tree_perfect(tree->right);
		if (right == left && right != 0 && left != 0)
			return (right);
		return (0);
	}
	else if (!tree->left && !tree->right)
		return (1);
	else
		return (0);
}

/**
 * is_btree_perfect - perfect or not a tree
 * @tree: tree to check
 * Return: 1 is it is or 0 if not
 */
int is_btree_perfect(const binary_tree_t *tree)
{
	int result = 0;

	if (tree == NULL)
		return (0);
	result = is_tree_perfect(tree);
	if (result != 0)
		return (1);
	return (0);
}

/**
 * binary_tree_is_heap - checks if a binary tree is a valid Max Binary Heap
 * @tree: tree to check
 * Return: 1 if tree is a valid Max Binary Heap, and 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int bval;

	if (tree == NULL)
		return (0);
	if (tree->left && tree->left->n > tree->n)
		return (0);
	if (tree->right && tree->right->n > tree->n)
		return (0);
	if (is_btree_perfect(tree))
		return (1);
	bval = get_bfactor(tree);
	if (bval == 0)
		return (is_btree_perfect(tree->left) && binary_tree_is_heap(tree->right));
	if (bval == 1)
		return (binary_tree_is_heap(tree->left) && is_btree_perfect(tree->right));
	else
		return (0);
}
