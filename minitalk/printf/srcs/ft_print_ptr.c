/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:48:25 by sgaspard          #+#    #+#             */
/*   Updated: 2023/02/13 14:45:56 by sgaspard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	ft_print_ptr_len(uintptr_t nb)
{
	int	len;

	len = 2;
	if (nb == 0)
		len++;
	while (nb != 0)
	{
		len++;
		nb = nb / 16;
	}
	return (len);
}

static void	ft_print_screen_ptr(uintptr_t nb)
{
	if (nb >= 16)
	{
		ft_print_screen_ptr(nb / 16);
		ft_print_screen_ptr(nb % 16);
	}
	else if (nb < 10)
	{
		ft_print_chr(nb + '0');
	}
	else
		ft_print_chr(nb - 10 + 'a');
}

int	ft_print_ptr(unsigned long long nb)
{
	int	len;

	len = 0;
	write(1, "0x", 2);
	if (!nb)
		write(1, "0", 1);
	else
		ft_print_screen_ptr(nb);
		len += ft_print_ptr_len(nb);
	return (len);
}
