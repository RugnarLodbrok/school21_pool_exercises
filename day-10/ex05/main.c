#include <stdio.h>

int ft_is_sort(int *tab, int length, int(*f)(int, int));

int more(int a, int b)
{
	return a - b;
}

int main()
{
	int a[5] = {0, 1, 2, 3, 4};
	printf("is sort: %d\n", ft_is_sort(a, 5, more));
	return 0;
}