/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 18:12:38 by ksticks           #+#    #+#             */
/*   Updated: 2019/06/15 18:12:39 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int match(char *s1, char *s2);

int main()
{
	char *a[16];
	char *b[16];

	a[0] = "";
	b[0] = "";

	a[1] = "main.c";
	b[1] = "*.c";

	a[2] = "a*c";
	b[2] = "abc";

	a[3] = "abc";
	b[3] = "*";

	a[4] = "abc";
	b[4] = "a*c";

	a[5] = "abc";
	b[5] = "a**c";

	a[6] = "ajgfkghlsdfhgkhfhfknccdfdl;k";
	b[6] = "a***c";

	a[7] = "ajgfkghlsdfhgkhfhfknccdfdl;k";
	b[7] = "a***c*";

	a[8] = "ajgfkghlsdfhgkhfhfknccdfdl;k";
	b[8] = "a**c*l";

	a[9] = "ajgfkghlsdfhgkhfhfknccdfdl;k";
	b[9] = "a*c*k";

	a[10] = "abc";
	b[10] = "a**";

	a[11] = "abc";
	b[11] = "a***";

	a[12] = "abcd";
	b[12] = "a***";

	a[13] = "abcd";
	b[13] = "a**";

	a[14] = "";
	b[14] = "*";

	a[15] = "maiiiiiin.c";
	b[15] = "*in.c";

	int i;

	for (i = 0; i < 16; ++i)
	{
		printf("%s\t%s\t: %d\n", a[i], b[i], match(a[i], b[i]));
		printf("----------\n");
	}

	return 0;
}
