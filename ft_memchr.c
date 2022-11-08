/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:26:47 by sgaspard          #+#    #+#             */
/*   Updated: 2022/10/21 14:48:38 by sgaspard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*memstr;

	memstr = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		if (*memstr == (unsigned char)c)
			return ((void *)memstr);
		i++;
		memstr++;
	}
	return (NULL);
}
/*
int	main()
{
	char *str = "hey";
	char c = 'y';

	printf("%p\n", ft_memchr(str, c, 2));
	printf("%p", memchr(str, c, 2));
	return (0);
}*/
