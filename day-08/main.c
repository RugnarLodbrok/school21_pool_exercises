#include <unistd.h>
#include <stdio.h>
#include <string.h>

char	*ft_strdup(char *src);											// ex00
int		*ft_range(int min, int max);									// ex01
int		ft_ultimate_range(int **range, int min, int max);				// ex02
char	*ft_concat_params(int argc, char **argv);						// ex03
char	**ft_split_whitespaces(char *str);								// ex04
void	ft_print_words_tables(char **tab);								// ex05
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);	// ex06
char	**ft_split(char *str, char *charset);							// ex07

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int main()
{
	int i;
	int n;

	printf("------EX00------\n");
	char str[256];
	strcpy(str, "1234567890");
	char *str2 = ft_strdup(str);
	char *str3 = strdup(str);
	strcpy(str, "???????????????????");
	printf("%s: `%s`==`%s`\n", str, str2, str3);
	ft_putchar('\n');
	printf("------EX01------\n");

	int* rng = ft_range(3, 8);		//todo: check if min == max
	for(i = 0; i < 5; ++i)
		printf("%d, ", rng[i]);
	printf("\n");
	printf("------EX02------\n");
	
	n = ft_ultimate_range(&rng, 10, 15);
	for(i = 0; i < 5; ++i)
		printf("%d, ", rng[i]);
	printf("\n");
	printf("size = %d, sizeof = %d\n", n, (int)sizeof(rng));
	printf("\n");
	printf("------EX03------\n");
	printf("\n");
	char *strs[3];
	strs[0] = "abc";
	strs[1] = "123";
	strs[2] = "xyz";
	printf("`%s`\n", ft_concat_params(3, strs));

	printf("------EX04&5------\n");
	ft_print_words_tables(ft_split_whitespaces(" abc dcd  123\t&&&\nxyz\n"));
	ft_print_words_tables(ft_split_whitespaces(" \n"));

	printf("\n");
	printf("------EX06------\n");
	char *nbr = "-4434534";
	printf("convert: %s -> %s\n", nbr, ft_convert_base(nbr, "0123456789", "0123456789abcdef"));
	nbr = "4434534";
	printf("convert: %s -> %s\n", nbr, ft_convert_base(nbr, "0123456789", "0123456789abcdef"));
	nbr = "-1023";
	printf("convert: %s -> %s\n", nbr, ft_convert_base(nbr, "0123456789", "0123456789abcdef"));
	nbr = "1023";
	printf("convert: %s -> %s\n", nbr, ft_convert_base(nbr, "0123456789", "0123456789abcdef"));
	nbr = "0";
	printf("convert: %s -> %s\n", nbr, ft_convert_base(nbr, "0123456789", "0123456789abcdef"));
	nbr = "0.1234";
	printf("convert: %s -> %s\n", nbr, ft_convert_base(nbr, "0123456789", "0123456789abcdef"));
	nbr = "-80000000";
	printf("convert: %s -> %s\n", nbr, ft_convert_base(nbr, "0123456789abcdef", "0123456789"));
	printf("---\n");
	printf("\n");
	printf("\n");
	printf("------EX07------\n");
	ft_print_words_tables(ft_split("abcdefghijklmnopqrstuvwxyz", "flqtw"));

	return 0;
}
