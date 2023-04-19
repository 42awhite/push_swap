/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:13:37 by ablanco-          #+#    #+#             */
/*   Updated: 2023/03/16 19:54:20 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2)
{
	size_t			c;
	unsigned char	*strs1;
	unsigned char	*strs2;

	strs1 = (unsigned char *)s1;
	strs2 = (unsigned char *)s2;
	c = 0;
	while ((strs1[c] != '\0' || strs2[c] != '\0'))
	{
		if (strs1[c] != strs2[c])
			return (strs1[c] - strs2[c]);
		c++;
	}
	return (0);
}

/*
int main(void)
{
	char str[] = "Intento procrastinar";
	char str2[] = "Intento procrastinar";

	printf("%d\n", ft_strncmp(str, str2, 10));
	printf("%d\n", strncmp(str, str2, 10));
}
*/
