/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:26:47 by sgaspard          #+#    #+#             */
/*   Updated: 2022/11/14 17:45:56 by sgaspard         ###   ########.fr       */
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
