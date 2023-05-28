#include "hw_25.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

typedef struct tree {
	int data;
	struct tree* left;
	struct tree* right;
}tree;

typedef struct treeLimits {
	int min;
	int max;
}limits;

void	binaryTreeInt_addLeaf(tree** node, int data) {
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
void	binaryTreeInt_empty(tree** node)
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
void	binaryTreeInt_print(tree** node)
{
	if (*node == NULL)
	{
		return;
	}
	binaryTreeInt_print(&(*node)->left);
	printf("%d -> ", (*node)->data);
	binaryTreeInt_print(&(*node)->right);
}
void	binaryTreeInt_init(tree* node, int data)
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
tree*	binaryTreeInt_searchInt(tree** node, int data)
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
int		binaryTreeInt_high(tree** node)
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
int		binaryTreeInt_sumElements(tree** node)
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
bool	binaryTreeInt_isBinaryTree(tree** node)
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


void hw_25_1_addRemove(void)
/*
Реализирайте ваша имплементация на двоично дърво с цели числа.
● Дефинирайте функции за добавяне и премахване на върхове от дървото.
*/
{
	printf("\n-----------------task 25_1-----------------------\n");
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
}
void hw_25_2_printTree(void)
/*
● Дефинирайте функция, която обхожда и принтира всеки елемент от дървото в избрана от вас
последователност. (inorder, preorder, postorder, ..)
*/
{
	printf("\n-----------------task 25_2-----------------------\n");
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
}
void hw_25_3_searchInt(void)
/*
Дефинирайте функция, за търсене на стойност на връх в дървото.
*/
{
	printf("\n-----------------task 25_3-----------------------\n");
	tree* root = NULL;
	binaryTreeInt_addLeaf(&root, 4);
	binaryTreeInt_addLeaf(&root, 2);
	binaryTreeInt_addLeaf(&root, 6);
	binaryTreeInt_addLeaf(&root, 1);
	binaryTreeInt_addLeaf(&root, 3);
	binaryTreeInt_addLeaf(&root, 5);
	binaryTreeInt_addLeaf(&root, 7);
	binaryTreeInt_print(&root);
	int num = 1;
	tree* search = binaryTreeInt_searchInt(&root, num);
	if (search == NULL)
	{
		printf("\nThe number %d is not found!", num);
	}
	else
	{
		printf("\nThe number %d is found!", search->data);
	}
	binaryTreeInt_empty(&root);
}
void hw_25_4_high(void)
/*
Дефинирайте функция, която връща височината на дървото
*/
{
	printf("\n-----------------task 25_4-----------------------\n");
	tree* root = NULL;
	binaryTreeInt_addLeaf(&root, 4);
	binaryTreeInt_addLeaf(&root, 2);
	binaryTreeInt_addLeaf(&root, 6);
	binaryTreeInt_addLeaf(&root, 1);
	binaryTreeInt_addLeaf(&root, 3);
	binaryTreeInt_addLeaf(&root, 5);
	binaryTreeInt_addLeaf(&root, 7);
	binaryTreeInt_print(&root);
	int treeHigh = binaryTreeInt_high(&root);
	printf("\nTree high is %d", treeHigh);
	printf("\n------------------------------\n");
	int num = 1;
	tree* search = binaryTreeInt_searchInt(&root, num);
	tree* new = (tree*)malloc(sizeof(tree));
	if (new == NULL)
		return;
	search->left = new;
	(search->left)->data = 8;
	(search->left)->left = NULL;
	(search->left)->right = NULL;
	binaryTreeInt_print(&root);
	treeHigh = binaryTreeInt_high(&root);
	printf("\nTree high is %d", treeHigh);
	binaryTreeInt_empty(&root);
}
void hw_25_5_sumElements(void)
/*
 Дефинирайте функция, която връща сумата от всички елементи на дървото
*/
{
	printf("\n-----------------task 25_5-----------------------\n");
	tree* root = NULL;
	binaryTreeInt_addLeaf(&root, 4);
	binaryTreeInt_addLeaf(&root, 2);
	binaryTreeInt_addLeaf(&root, 6);
	binaryTreeInt_addLeaf(&root, 1);
	binaryTreeInt_addLeaf(&root, 3);
	binaryTreeInt_addLeaf(&root, 5);
	binaryTreeInt_addLeaf(&root, 7);
	binaryTreeInt_print(&root);
	printf("\nSum = %d", binaryTreeInt_sumElements(&root));
}
void hw_25_6_minMaxElement(void)
/*
 Дефинирайте функция, която връща най-малката и най-голямата стойност на
елемент от дървото. Какви начини има да върнем и двете от една функция?
*/
{
	printf("\n-----------------task 25_6-----------------------\n");
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
}
void hw_25_7_isBilaryTree(void)
/*
Дефинирайте функция, която проверява дали дървото е binary search tree (дали
върховете са “сортирани отляво-надясно” по стойност)
*/
{
	printf("\n-----------------task 25_7-----------------------\n");
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
		return;
	search->left = new;
	(search->left)->data = 8;
	(search->left)->left = NULL;
	(search->left)->right = NULL;
	binaryTreeInt_print(&root);
	printf("\nBinarry tree %d", binaryTreeInt_isBinaryTree(&root));
}
void hw_25_8_(void)
/*
* Реализирайте ваша имплементация на граф, в който всеки връх е град(има стойност - име на град)
и в който имаме тегло на ребрата - дължината на пътя между два града
● Дефинирайте функции за добавяне и премахване на нови градове и за добавяне и премахване
на нови пътища между два града
*/
{
	printf("\n-----------------task 25_8-----------------------\n");
}
void hw_25_9_(void)
/*
 Дефинирайте функция, която проверява дали има път от един град до друг (път в граф - може
да минава през няколко града)
*/
{
	printf("\n-----------------task 25_9-----------------------\n");
}
void hw_25_10_(void)
/*
 Дефинирайте функция, която намира път от един връх до друг. Mоже и най-прекия, например с
алгоритъма на Дийкстра (Dijkstra's Algorithm)
*/
{
	printf("\n-----------------task 25_10-----------------------\n");
}