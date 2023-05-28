/*
Дефинирайте функция, която връща височината на дървото
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
	int treeHigh = binaryTreeInt_high(&root);
	printf("\nTree high is %d", treeHigh);
	binaryTreeInt_empty(&root);
	return 0;
}