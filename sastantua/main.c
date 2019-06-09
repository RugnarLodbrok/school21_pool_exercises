#include <unistd.h>
#include "ex00/sastantua.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main()
{
	sastantua(25);
	return (0);
}
