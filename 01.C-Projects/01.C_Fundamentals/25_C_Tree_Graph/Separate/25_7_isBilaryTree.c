/*
Дефинирайте функция, която проверява дали дървото е binary search tree (дали
върховете са “сортирани отляво-надясно” по стойност)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

typedef struct tree {
	int data;
	struct tree* left;
	struct tree* right;
} tree;

typedef struct treeLimits {
	int min;
	int max;
}limits;

void binaryTreeInt_addLeaf(tree** node, int data) {
	if (*node == NULL)
	{
		*node = (tree*)malloc(sizeof(tree));
		if (*node == NULL)
		{
			printf("\nCannot alocate memory!!!");
			return;
		}
		(*node)->data = data;
		(*node)->left = NULL;
		(*node)->right = NULL;
		return;
	}
	if (data < (*node)->data)
	{
		binaryTreeInt_addLeaf(&(*node)->left, data);
	}
	else if (data > (*node)->data)
	{
		binaryTreeInt_addLeaf(&(*node)->right, data);
	}
}
void binaryTreeInt_empty(tree** node)
{
	if (*node == NULL)
		return;
	if ((*node)->left != NULL)
	{
		binaryTreeInt_empty(&(*node)->left);
		free((*node)->left);
	}
	if ((*node)->right != NULL)
	{
		binaryTreeInt_empty(&(*node)->right);
		free((*node)->right);
	}
	free(*node);
	*node = NULL;
}
void binaryTreeInt_print(tree** node)
{
	if (*node == NULL)
	{
		return;
	}
	binaryTreeInt_print(&(*node)->left);
	printf("%d -> ", (*node)->data);
	binaryTreeInt_print(&(*node)->right);
}
void binaryTreeInt_init(tree* node, int data)
{
	if (node == NULL)
	{
		printf("\nNode is NULL pointer!!!");
		return;
	}
	node->data = data;
	node->left = NULL;
	node->right = NULL;
}

tree* binaryTreeInt_searchInt(tree** node, int data)
{
	if (*node == NULL)
	{
		return NULL;
	}
	tree* find = NULL;
	if ((*node)->data == data)
	{
		return *node;
	}
	else if (data < (*node)->data)
	{
		find = binaryTreeInt_searchInt(&(*node)->left, data);
	}
	else if (data > (*node)->data)
	{
		find = binaryTreeInt_searchInt(&(*node)->right, data);
	}
	return find;
}
int binaryTreeInt_high(tree** node)
{
	if (*node == NULL)
		return 0;
	int highLeft = 0;
	int highRight = 0;
	if ((*node)->left != NULL)
	{
		highLeft = binaryTreeInt_high(&(*node)->left);
	}
	if ((*node)->right != NULL)
	{
		highRight = binaryTreeInt_high(&(*node)->right);
	}
	int high = max(highLeft, highRight);
	if ((*node)->left == NULL && (*node)->right == NULL)
	{
		return high;
	}
	else
	{
		return ++high;
	}
}
int binaryTreeInt_sumElements(tree** node)
{
	if (*node == NULL)
		return 0;
	return (*node)->data + binaryTreeInt_sumElements(&(*node)->left) + binaryTreeInt_sumElements(&(*node)->right);
}
limits* binaryTreeInt_minMax(limits* lim, tree* node)
{
	if (node == NULL)
		return NULL;
	limits* limLeft = binaryTreeInt_minMax(lim, node->left);
	limits* limRight = binaryTreeInt_minMax(lim, node->right);
	if (limLeft != NULL && limRight != NULL)
	{
		lim->min = min(limLeft->min, limRight->min);
		lim->max = max(limLeft->max, limRight->max);
	}
	if (node->data < lim->min)
	{
		lim->min = node->data;
	}
	if (node->data > lim->max)
	{
		lim->max = node->data;
	}
	return lim;
}

bool binaryTreeInt_isBinaryTree(tree** node)
{
	if (*node == NULL)
	{
		printf("\nThe tree is empty!");
		return 1;
	}
	bool isBinaryLeft = 0;
	bool isBinaryRight = 0;
	if ((*node)->left == NULL && (*node)->right == NULL)
	{
		return 1;
	}
	if ((*node)->left != NULL && (*node)->left->data < (*node)->data)
	{
		isBinaryLeft = binaryTreeInt_isBinaryTree(&(*node)->left);
	}
	else
	{
		return 0;
	}
	if ((*node)->right != NULL && (*node)->right->data > (*node)->data)
	{
		isBinaryRight = binaryTreeInt_isBinaryTree(&(*node)->left);
	}
	else
	{
		return 0;
	}
	return (isBinaryLeft && isBinaryRight) ? 1 : 0;
}

int main(void)
{
	tree* root = NULL;
	binaryTreeInt_addLeaf(&root, 4);
	binaryTreeInt_addLeaf(&root, 2);
	binaryTreeInt_addLeaf(&root, 6);
	binaryTreeInt_addLeaf(&root, 1);
	binaryTreeInt_addLeaf(&root, 3);
	binaryTreeInt_addLeaf(&root, 5);
	binaryTreeInt_addLeaf(&root, 7);
	binaryTreeInt_print(&root);
	printf("\nBinarry tree %d", binaryTreeInt_isBinaryTree(&root));
	printf("\n------------------------------\n");
	int num = 1;
	tree* search = binaryTreeInt_searchInt(&root, num);
	tree* new = (tree*)malloc(sizeof(tree));
	if (new == NULL)
		return 0;
	search->left = new;
	(search->left)->data = 8;
	(search->left)->left = NULL;
	(search->left)->right = NULL;
	binaryTreeInt_print(&root);
	printf("\nBinarry tree %d", binaryTreeInt_isBinaryTree(&root));
	return 0;
}
