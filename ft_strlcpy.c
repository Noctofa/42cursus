/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:59:30 by sgaspard          #+#    #+#             */
/*   Updated: 2022/10/24 14:40:51 by sgaspard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	int	i;

	i = 0;
	if (size > 0)
	{
		while (size > 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
			size--;
		}
		dst[i] = '\0';
	}
	while (src[i] != '\0')
		i++;
	return (i);
}
/*
 *int    main(void)
 *{
 	char    dest[40] = "";
 * 	char    src[] = "";
 * 	size_t    size;
 *
 * 	size = 8;
 * 	printf("%d\n", ft_strlcpy(dest, src, size));
 * 	printf("%lu", strlcpy(dest, src, size));
 * 	return (0);
 *}*/
