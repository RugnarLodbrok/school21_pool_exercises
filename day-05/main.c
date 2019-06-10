/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 13:29:50 by ksticks           #+#    #+#             */
/*   Updated: 2019/06/06 13:29:52 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void			ft_putstr(char *str);									// ex00
void			ft_putnbr(int nb);										// ex01
int				ft_atoi(char *str);										// ex02
char			*ft_strcpy(char *dest, char *src);						// ex03
char			*ft_strncpy(char *dest, char *src, unsigned int n);		// ex04
char			*ft_strstr(char *str, char *to_find);					// ex05
int				ft_strcmp(char *s1, char *s2);							// ex06
int				ft_strncmp(char *s1, char *s2, unsigned int n);			// ex07
char			*ft_strupcase(char *str);								// ex08
char			*ft_strlowcase(char *str);								// ex09
char			*ft_strcapitalize(char *str);							// ex10
int				ft_str_is_alpha(char *str);								// ex11
int				ft_str_is_numeric(char *str);							// ex12
int				ft_str_is_lowercase(char *str);							// ex13
int				ft_str_is_uppercase(char *str);							// ex14
int				ft_str_is_printable(char *str);							// ex15
char			*ft_strcat(char *dest, char *src);						// ex16
char			*ft_strncat(char *dest, char *src, int nb);				// ex17
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);	// ex18
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);	// ex19
void			ft_putnbr_base(int nbr, char *base);					// ex20

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main()
{
	printf("------EX00------\n");
	ft_putstr("abcd\n");

	printf("------EX01------\n");
	ft_putnbr(-435);
	ft_putchar('\n');

	printf("------EX02------\n");
	int i = 20;
	char *a[i];
	a[0] = "-2147483648";
	a[1] = "-21t";
	a[2] = "--320";
	a[3] = "-0";
	a[4] = "d00t";
	a[5] = "0043";
	a[6] = "1000000";
	a[7] = "709551615";
	a[8] = "2147483647";
	a[9] = "21474836432";
	a[10] = "+999";
	a[11] = "-+777";
	a[12] = "+-888";
	a[13] = "-t04";
	a[14] = "++111";
	a[15] = "\t123\t45";
	a[16] = "\r-123\r45";
	a[17] = "\n+123\n45";
	a[18] = " +123 45";
	a[19] = "\x0E+123 45 x01";
	while (i--)
		printf("atoi %s:\t%d==%d\n", a[i], ft_atoi(a[i]), atoi(a[i]));
	ft_putchar('\n');

	printf("------EX03------\n");
	i = 15;
	a[0] = "abcdefghijklmno";
	a[1] = "abcdefghijklmn";
	a[2] = "abcdefghijklm";
	a[3] = "abcdefghijkl";
	a[4] = "abcdefghijk";
	a[5] = "abcdefghij";
	a[6] = "abcdefghi";
	a[7] = "a";
	a[8] = "ab";
	a[9] = "abc";
	a[10] = "abcd";
	a[11] = "abcde";
	a[12] = "abcdef";
	a[13] = "abcdefg";
	a[14] = "abcdefgh";
	char b[16];
	b[12] = 0;

	while (i--)
	{
		printf("strcpy: %s\t", a[i]);
		strcpy(b, a[i]);
		printf("%s==", b);
		b[0] = 'N';
		ft_strcpy(b, a[i]);
		printf("%s\n", b);
	}
	printf("\n");

	printf("------EX04------\n");
	printf("TODO TESTS\n\n");

	printf("------EX05------\n");
	char *haystack[8];
	char *needle[8];
	haystack[0] = "aaa";
	needle[0] = "bbb";
	haystack[1] = "aaa";
	needle[1] = "a";
	haystack[2] = "aaa";
	needle[2] = "aaaa";
	haystack[3] = "";
	needle[3] = "aaa";
	haystack[4] = "aaa";
	needle[4] = "";
	haystack[5] = "abc";
	needle[5] = "abc";
	haystack[6] = "";
	needle[6] = "";
	haystack[7] = "";
	needle[7] = "";
	i = 0;
	while (i < 8)
	{
		printf("haystack, needle: %s, %s;\tstrstr(),ft_strstr():\t%s %s\n", haystack[i], needle[i], strstr(haystack[i], needle[i]), ft_strstr(haystack[i], needle[i]));
		i++;
	}
	printf("\n");

	printf("------EX06&7------\n");
	char			*strcmp_a[8];
	char			*strcmp_b[8];
	unsigned long	strcmp_n[8];
	strcmp_a[0] = "abc";	strcmp_b[0] = "abc";		strcmp_n[0] = 0;
	strcmp_a[1] = "aa";		strcmp_b[1] = "ab";			strcmp_n[1] = 2;
	strcmp_a[2] = "abc";	strcmp_b[2] = "";			strcmp_n[2] = 0;
	strcmp_a[3] = "";		strcmp_b[3] = "bca";		strcmp_n[3] = 2;
	strcmp_a[4] = "abx";	strcmp_b[4] = "aby";		strcmp_n[4] = 0;
	strcmp_a[5] = "123e";	strcmp_b[5] = "123exxx";	strcmp_n[5] = 5;
	strcmp_a[6] = "ab";		strcmp_b[6] = "a";			strcmp_n[6] = 1;
	strcmp_a[7] = "";		strcmp_b[7] = "";			strcmp_n[7] = 2;

	i = 0;
	while (i < 8)
	{
		printf("a, b, n: %s\t%s\t%d\tstrcmp() = \t%d\t%d\tstrncmp() = \t%d\t%d\n",
			strcmp_a[i], strcmp_b[i], (int)strcmp_n[i],
			strcmp(strcmp_a[i], strcmp_b[i]), ft_strcmp(strcmp_a[i], strcmp_b[i]),
			strncmp(strcmp_a[i], strcmp_b[i], strcmp_n[i]), ft_strncmp(strcmp_a[i], strcmp_b[i], strcmp_n[i]));
		i++;
	}
	printf("\n");

	printf("------EX08&9------\n");
	char str[100];
	ft_strcpy(str, "aBc123.fDEd3!@#$%%^&*()\\/");
	printf("%s", str);
	printf("\t->\t%s\t->\t", ft_strupcase(str));
	printf("%s\n", ft_strlowcase(str));
	printf("\n");

	printf("------EX010------\n");
	ft_strcpy(str, "hi there i hate \"c\"; ^E ^e 7e");
	printf("%s\t->\t", str);
	ft_strcapitalize(str);
	printf("%s\n", str);
	printf("\n");

	printf("------EX011&12&13&14&15------\n");
	printf("%s\tis alpha: %d\n", "ABc", ft_str_is_alpha("ABc"));
	printf("%s\tis alpha: %d\n", "abc", ft_str_is_alpha("abc"));
	printf("%s\tis alpha: %d\n", "1abc", ft_str_is_alpha("1abc"));
	printf("%s\tis alpha: %d\n", "ab+c", ft_str_is_alpha("ab+C"));
	printf("%s\tis alpha: %d\n", "", ft_str_is_alpha(""));

	printf("%s\tis numeric: %d\n", "ABc", ft_str_is_numeric("ABc"));
	printf("%s\tis numeric: %d\n", "abc", ft_str_is_numeric("abc"));
	printf("%s\tis numeric: %d\n", "132", ft_str_is_numeric("123"));
	printf("%s\tis numeric: %d\n", "12+c", ft_str_is_numeric("12+C"));
	printf("%s\tis numeric: %d\n", "", ft_str_is_numeric(""));

	printf("%s\tis upper: %d\n", "1", ft_str_is_uppercase("1"));
	printf("%s\tis upper: %d\n", "ab", ft_str_is_uppercase("ab"));
	printf("%s\tis upper: %d\n", "Ab", ft_str_is_uppercase("Ab"));
	printf("%s\tis upper: %d\n", "AB", ft_str_is_uppercase("AB"));
	printf("%s\tis upper: %d\n", "", ft_str_is_uppercase(""));

	printf("%s\tis lower: %d\n", "1", ft_str_is_lowercase("1"));
	printf("%s\tis lower: %d\n", "ab", ft_str_is_lowercase("ab"));
	printf("%s\tis lower: %d\n", "Ab", ft_str_is_lowercase("Ab"));
	printf("%s\tis lower: %d\n", "AB", ft_str_is_lowercase("AB"));
	printf("%s\tis lower: %d\n", "", ft_str_is_lowercase(""));

	printf("`%s'\tis printable: %d\n", "1", ft_str_is_printable("1"));
	printf("`%s'\tis printable: %d\n", "ab", ft_str_is_printable("ab"));
	printf("`%s'\tis printable: %d\n", "\x20\x21\x22", ft_str_is_printable("\x20\x21\x22"));
	printf("`%s'\tis printable: %d\n", "\x1f\x21", ft_str_is_printable("\33\39"));
	printf("`%s'\tis printable: %d\n", "", ft_str_is_printable(""));
	printf("\n");

	printf("------EX016&17------\n");
	ft_strcpy(str, "abcd");
	ft_strcat(str, "DDDDDDD");
	printf("CAT: %s\n", str);
	printf("\n");
	ft_strcpy(str, "abcd");
	ft_strncat(str, "DDDDDDD", 3);
	printf("CAT3: %s\n", str);
	printf("\n");

	printf("------EX018------\n");
	ft_strcpy(str, "!!!!!!!!!!!!!!!!!!!!!!!!!");
	ft_strcpy(str, "abc");
	printf("str, strlcat():\t\t%s\t%lu\n", str, strlcat(str, "DDD", 10));
	printf("remainings: %s\n", str + 7);
	ft_strcpy(str, "!!!!!!!!!!!!!!!!!!!!!!!!!");
	ft_strcpy(str, "abc");
	printf("str, ft_strlcat():\t%s\t%d\n", str, ft_strlcat(str, "DDD", 10));
	printf("remainings: %s\n", str + 7);
	printf("\n");

	printf("------EX019------\n");
	printf("ft_strlcpy(): %d, %s\n", ft_strlcpy(str, "abcdefg", 3), str);
	printf("\n");

	printf("------EX019------\n");
	ft_putnbr_base(-2147483648, "01");
	printf("\n");
	return 0;
}
