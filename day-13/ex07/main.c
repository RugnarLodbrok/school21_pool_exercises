
#include <stdio.h>
#include "ft_btree.h"
#include <stdlib.h>

#define COUNT 10

void print_t(t_btree *tree);

t_btree	*btree_create_node(void *item);
void btree_apply_prefix(t_btree *root, void (*applyf)(void *));
void btree_apply_infix(t_btree *root, void (*applyf)(void *));
void btree_apply_suffix(t_btree *root, void (*applyf)(void *));
void *btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(void *, void *));
void btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *));
int	btree_level_count(t_btree *root);
void	btree_apply_by_level(t_btree *root, void (*applyf)(void *item, 
	int current_level, int is_first_elem));

void btree_insert_int(t_btree **root, int item, int (*cmpf)(void *, void *))
{
	int *data;

	data = malloc(sizeof(int));
	*data = item;
	printf("insert int: %d\n", item);
	btree_insert_data(root, (void*)data, cmpf);
}

int cmpf(void *a, void *b)
{
	int aa;
	int bb;

	aa = *(int*)a;
	bb = *(int*)b;
	if (aa > bb)
		return 1;
	if (aa < bb)
		return -1;
	return 0;
}

void	print_item(void *item)
{
	printf("[%d]", *(int*)item);
}

void	level_fn(void *item, int current_level, int is_first_elem)
{
	printf("[%d][level=%d][frst=%d]\n", *(int*)item, current_level, is_first_elem);
}

int	main()
{
	t_btree *tree;
	int data_ref;
	int searched_data;
	void *addr;

	data_ref = 3;
	tree = 0;
	btree_insert_int(&tree, 5, &cmpf);
	btree_insert_int(&tree, 4, &cmpf);
	/*btree_insert_int(&tree, 2, &cmpf);
	btree_insert_int(&tree, 6, &cmpf);
	btree_insert_int(&tree, 3, &cmpf);
	btree_insert_int(&tree, 1, &cmpf);*/
	//print_t(tree);
	printf("prefix: ");
	btree_apply_prefix(tree, &print_item);
	printf("\ninfix: ");
	btree_apply_infix(tree, &print_item);
	printf("\nsuffix: ");
	btree_apply_suffix(tree, &print_item);
	printf("\n");
	printf("level count: %d\n", btree_level_count(tree));
	addr = btree_search_item(tree, &data_ref, cmpf);
	if (addr)
	{
		searched_data = *(int*)addr;
		printf("assign done\n");
		printf("found!%d==%d\n", data_ref, searched_data);
	}
	else
		printf("%d not found\n", data_ref);
	printf("=====testing apply by level======\n");
	btree_apply_by_level(tree, &level_fn);
	return 0;
}
