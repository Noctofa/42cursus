/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsignednbr.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:54:24 by sgaspard          #+#    #+#             */
/*   Updated: 2023/02/13 14:46:42 by sgaspard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	ft_print_unsignednb_len(unsigned int nb)
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
			nb = nb / 10;
		}
	}
	return (len);
}

static void	ft_print_screen_unsignednb(unsigned int nb)
{
	if (nb >= 10)
	{
		ft_print_screen_unsignednb(nb / 10);
		ft_print_screen_unsignednb(nb % 10);
	}
	else
	{
		ft_print_chr(nb + '0');
	}
}

int	ft_print_unsignednb(unsigned int nb)
{
	ft_print_screen_unsignednb(nb);
	return (ft_print_unsignednb_len(nb));
}
