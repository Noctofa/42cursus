/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utili.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:43:12 by sgaspard          #+#    #+#             */
/*   Updated: 2023/01/25 16:06:36 by sgaspard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	ft_print_chr(int c)
{
	return ((write(1, &c, 1)));
}

int	ft_print_str(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_print_nbr(int nbr)
{
	int		len;
	char	*nb;

	len = 0;
	nb = ft_itoa(nbr);
	len = ft_print_str(nb);
	free(nb);
	return (len);
}
