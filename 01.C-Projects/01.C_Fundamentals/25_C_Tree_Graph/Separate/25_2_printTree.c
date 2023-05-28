/*
● Дефинирайте функция, която обхожда и принтира всеки елемент от дървото в избрана от вас
последователност. (inorder, preorder, postorder, ..)
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
	binaryTreeInt_empty(&root);
	return 0;
}
