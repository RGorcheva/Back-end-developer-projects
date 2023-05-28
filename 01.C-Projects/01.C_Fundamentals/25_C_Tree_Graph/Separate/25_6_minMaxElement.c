/*
 Дефинирайте функция, която връща най-малката и най-голямата стойност на
елемент от дървото. Какви начини има да върнем и двете от една функция?
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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
	limits lim = {
		root->data,
		root->data
	};
	limits* limit = binaryTreeInt_minMax(&lim, root);
	printf("\nmin = %d", limit->min);
	printf("\nmax = %d", limit->max);
	return 0;
}