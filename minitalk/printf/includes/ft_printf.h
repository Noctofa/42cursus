/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:48:23 by sgaspard          #+#    #+#             */
/*   Updated: 2023/02/13 14:43:36 by sgaspard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

int	ft_print_hexa(unsigned int nb, const char format);
int	ft_print_ptr(unsigned long long nb);
int	ft_print_unsignednb(unsigned int nb);
int	ft_print_str(char *str);
int	ft_print_nbr(int nbr);
int	ft_formats(va_list arg, const char format);
int	ft_printf(const char *str, ...);
int	ft_print_chr(int c);

#endif
