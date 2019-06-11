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
int				ft_atoi_base(char *str, char *base);					// ex21
void			ft_putstr_non_printable(char *str);						// ex22
void			*ft_print_memory(void *addr, unsigned int size);		// ex23

typedef struct {
    char *a;
    char *b;
} tStringPair;

tStringPair* new_tStringPair(char *a, char *b)
{
	tStringPair* p = malloc(sizeof(tStringPair));
	p->a = a;
	p->b = b;
	return p;
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int len;

	len = 0;
	while (*(str + len) != '\0')
	{
		len++;
	}
	return (len);
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
	a[6] = "-\t1000000";
	a[7] = "709551615";
	a[8] = "2147483647";
	a[9] = "21474836432";
	a[10] = " +999";
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
	char test_ex04_0[256] = "asdf";
	char test_ex04_1[256] = "asdf";
	printf("%s==%s\n", ft_strncpy(test_ex04_0, "uiop", 5), strncpy(test_ex04_1, "uiop", 5));
	printf("%s==%s\n", ft_strncpy(test_ex04_0, "qwerty", 4), strncpy(test_ex04_1, "qwerty", 4));
	printf("%s==%s\n", ft_strncpy(test_ex04_0, "z", 1), strncpy(test_ex04_1, "z", 1));

	printf("------EX05------\n");
	tStringPair strstr_tests[8];
	strstr_tests[0].a = "aaa";
	strstr_tests[0].b = "bbb";

	strstr_tests[1].a = "aaa";
	strstr_tests[1].b = "a";

	strstr_tests[2].a = "aaa";
	strstr_tests[2].b = "aaaa";

	strstr_tests[3].a = "";
	strstr_tests[3].b = "bbb";

	strstr_tests[4].a = "aaa";
	strstr_tests[4].b = "";

	strstr_tests[5].a = "abc";
	strstr_tests[5].b = "abc";

	strstr_tests[6].a = "";
	strstr_tests[6].b = "";

	strstr_tests[7].a = "";
	strstr_tests[7].b = "";

	i = 0;
	while (i < 8)
	{
		printf("haystack, needle: %s, %s;\tstrstr(),ft_strstr():\t%s %s\n",
			strstr_tests[i].a, strstr_tests[i].b,
			strstr(strstr_tests[i].a, strstr_tests[i].b),
			ft_strstr(strstr_tests[i].a, strstr_tests[i].b));
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
	ft_strcpy(str, "hi there i HATE \"c\"; ^E ^e 7e");
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
	tStringPair cpy_tests[5];
	int sizes[5];
	cpy_tests[0].a = "AAA";
	cpy_tests[0].b = "BBB";
	sizes[0] = 9;

	cpy_tests[1].a = "AAAA";
	cpy_tests[1].b = "BBBB";
	sizes[1] = 9;

	cpy_tests[2].a = "AAAAA";
	cpy_tests[2].b = "BBBBB";
	sizes[2] = 9;

	cpy_tests[3].a = "AAAAAAAA";
	cpy_tests[3].b = "BBBBBBBB";
	sizes[3] = 9;

	cpy_tests[4].a = "AAAA";
	cpy_tests[4].b = "BBBB";
	sizes[4] = 0;

	char* s1;
	char* s2;
	int size;

	for (i = 0; i < 5; ++i)
	{
		s1 = cpy_tests[i].a;
		s2 = cpy_tests[i].b;
		size = sizes[i];

		ft_strcpy(str, "!!!!!!!!!!!!!!!!!!!!!!!!!");
		ft_strcpy(str, s1);
		printf("%s\t+ %s\t= ", s1, s2);
		printf("%d-%s\tOR ", (int)strlcat(str, s2, size), str);	//todo: print whats after \0

		ft_strcpy(str, "!!!!!!!!!!!!!!!!!!!!!!!!!");
		ft_strcpy(str, s1);
		printf("%d-%s\n", ft_strlcat(str, s2, size), str);

	}
	printf("------EX019------\n");
	strcpy(str, "..................");
	printf("ft_strlcpy(): %d, %s\n", ft_strlcpy(str, "abcdefg", 3), str);
	printf("ft_strlcpy(): %d, %s\n", ft_strlcpy(str, "abcdefg", 3), str);
	printf("\n");

	printf("------EX020------\n");
	ft_putnbr_base(-2147483648, "01");
	printf("\n");
	printf("\n");

	printf("------EX021------\n");
	tStringPair atoi_base_tests[8];
	atoi_base_tests[0].a = "";
	atoi_base_tests[0].b = "";

	atoi_base_tests[1].a = "000";
	atoi_base_tests[1].b = "0";

	atoi_base_tests[2].a = "100";
	atoi_base_tests[2].b = "01";

	atoi_base_tests[3].a = "102";
	atoi_base_tests[3].b = "01";

	atoi_base_tests[4].a = " -101";
	atoi_base_tests[4].b = "01";

	atoi_base_tests[5].a = "";
	atoi_base_tests[5].b = "";

	atoi_base_tests[6].a = "";
	atoi_base_tests[6].b = "";

	atoi_base_tests[7].a = "";
	atoi_base_tests[7].b = "";

	for (i = 0; i < 8; ++i)
		printf("a, b: %s\t%s\t atoi:\t%d==%d\n",
			atoi_base_tests[i].a, atoi_base_tests[i].b,
			(int)strtol( atoi_base_tests[i].a, 0, ft_strlen(atoi_base_tests[i].b)),
			ft_atoi_base( atoi_base_tests[i].a, atoi_base_tests[i].b));
	printf("\n");

	printf("------EX022------\n");
	ft_putstr_non_printable("abcd1234 \\n==\n, \\r==\r, \\f3==\xf3");
	printf("\n");
	printf("\n");

	printf("------EX023------\n");
	//ft_print_memory("abcdefgfjdsfjldjfg\tldsjgklfd\x00jlgdfjklgjf", 54);
	ft_print_memory("asdfasdfqwertytyzxcvzxcv\0\0\xff\x7f\x01", 33);
	printf("\n");

	return 0;
}
