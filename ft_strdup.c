/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:40:54 by sgaspard          #+#    #+#             */
/*   Updated: 2022/11/08 15:47:09 by sgaspard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	char	*dest;

	dest = malloc(sizeof(*src) * (ft_strlen(src) + 1));
	if (!dest)
		return (0);
	ft_strcpy(dest, src);
	return (dest);
}
/*
int	main(void)
{
	printf("%s", strdup("Salut\n"));
	printf("%s", ft_strdup("Salut"));
}*/
