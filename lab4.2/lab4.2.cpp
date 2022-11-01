#include <stdlib.h>
#include "malloc.h"
#include "locale.h"
#include "iostream"

using namespace std;

struct Node{
	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* root;
int quantity = 0;

struct Node* CreateTree(struct Node* root, struct Node* r, int data)
{
	if (r == NULL)
	{
		r = (struct Node*)malloc(sizeof(struct Node));
		if (r == NULL)
		{
			printf("Ошибка выделения памяти");
			exit(0);
		}

		r->left = NULL;
		r->right = NULL;
		r->data = data;
		if (root == NULL) return r;

		if (data > root->data)	root->left = r;
		else root->right = r;
		return r;
	}

	if (data > r->data)
		CreateTree(r, r->left, data);
	else
		CreateTree(r, r->right, data);

	return root;
}

void print_tree(struct Node* r, int l)
{

	if (r == NULL)
	{
		return;
	}

	print_tree(r->right, l + 1);
	for (int i = 0; i < l; i++)
	{
		printf(" ");
	}

	printf("%d\n", r->data);
	print_tree(r->left, l + 1);
}

int searchroot(Node* tree, int search)
{

	if (tree != NULL) {


		if (search == tree->data) {
			quantity++;
		}


		searchroot(tree->left, search);
		searchroot(tree->right, search);
		return 0;
	}
}

int main()
{
	struct Node* root;
	setlocale(LC_ALL, "");
	int D, start = 1;
	int k = 1;

	root = NULL;

	printf("-1 - окончание построения дерева\n");
	printf("\nВведите число: ");

	while (start)
	{

		scanf_s("%d", &D);
		if (D == -1)
		{
			printf("Построение дерева окончено.\n\n");
			start = 0;
		}
		else {
			root = CreateTree(root, root, D);
		}
	}

	print_tree(root, 0);
	while (k)
	{
		printf("\n1. Поиск элемента по дереву\n2. Выход\n\nПункт меню: ");
		cin >> k;
		if (k == 1)
		{
			int find;
			printf("Введите элемент поиска: ");
			cin >> find;
			searchroot(root, find);

			if (quantity != 0) {
				printf("Элемент присутствует. \n");
				cout << "Количество таких чисел: " << quantity << "\n";
			}
			else
				printf("Элемент отсутствует. \n");
		}
		quantity = 0;
		if (k == 2)
			return 0;
	}
	return 0;
}