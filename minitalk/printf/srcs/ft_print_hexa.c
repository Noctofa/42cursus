/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:25:14 by sgaspard          #+#    #+#             */
/*   Updated: 2023/02/13 14:44:33 by sgaspard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	ft_print_hexa_len(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		len++;
	else
	{
		while (nb != 0)
		{
			len++;
			nb = nb / 16;
		}
	}
	return (len);
}

static void	ft_print_screen_hexa(unsigned int nb, const char format)
{
	if (nb >= 16)
	{
		ft_print_screen_hexa(nb / 16, format);
		ft_print_screen_hexa(nb % 16, format);
	}	
	else if (nb < 10)
	{
		ft_print_chr(nb + '0');
	}
	else
	{
		if (format == 'x')
			ft_print_chr(nb - 10 + 'a');
		else if (format == 'X')
			ft_print_chr(nb - 10 + 'A');
	}
}

int	ft_print_hexa(unsigned int nb, char format)
{
	ft_print_screen_hexa(nb, format);
	return (ft_print_hexa_len(nb));
}
