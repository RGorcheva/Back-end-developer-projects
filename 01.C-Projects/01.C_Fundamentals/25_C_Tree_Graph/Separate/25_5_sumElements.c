/*
 Дефинирайте функция, която връща сумата от всички елементи на дървото
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int binaryTreeInt_sumElements(tree** node)
{
	if (*node == NULL)
		return 0;
	return (*node)->data + binaryTreeInt_sumElements(&(*node)->left) + binaryTreeInt_sumElements(&(*node)->right);
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
	printf("\nSum = %d", binaryTreeInt_sumElements(root));
	return 0;
}
