/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:10:01 by sgaspard          #+#    #+#             */
/*   Updated: 2023/01/25 15:55:15 by sgaspard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	ft_formats(va_list arg, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_print_chr(va_arg(arg, int));
	else if (format == 's')
		len += ft_print_str(va_arg(arg, char *));
	else if (format == 'p')
		len += ft_print_ptr(va_arg(arg, unsigned long long));
	else if (format == 'd' || format == 'i')
		len += ft_print_nbr(va_arg(arg, int));
	else if (format == 'u')
		len += ft_print_unsignednb(va_arg(arg, unsigned int));
	else if (format == 'x' || format == 'X')
		len += ft_print_hexa(va_arg(arg, unsigned int), format);
	else if (format == '%')
		len += ft_print_chr('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	arg;
	int		len;

	i = 0;
	len = 0;
	va_start(arg, str);
	if (!str)
	{
		len = write(1, "(null)", 6);
		va_end(arg);
		return (len);
	}
	while (str[i])
	{
		if (str[i] == '%')
			len += ft_formats(arg, str[++i]);
		else
			len += ft_print_chr(str[i]);
		i++;
	}
	va_end(arg);
	return (len);
}
