#include <stdio.h>
#include <unistd.h>
#include "ft_stock_par.h"

void ft_show_tab(struct s_stock_par *par);
struct s_stock_par	*ft_param_to_tab(int ac, char **av);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int main(int argc, char *argv[])
{
	struct s_stock_par	*tab;

	tab = ft_param_to_tab(argc, argv);
	ft_show_tab(tab);
	return 0;
}
