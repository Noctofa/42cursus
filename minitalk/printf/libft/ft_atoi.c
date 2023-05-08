/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:19:07 by sgaspard          #+#    #+#             */
/*   Updated: 2022/12/15 16:28:22 by sgaspard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	ft_isnegatif(char *str, int *sign, int *i)
{
	if (str[*i] == '-')
		*sign = -*sign;
	*i = *i + 1;
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	tmp;
	long	res;

	tmp = 0;
	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
		ft_isnegatif((char *)str, &sign, &i);
	while (str[i] >= '0' && str[i] <= '9')
	{
		tmp = res;
		res = res * 10 + (str[i++] - '0');
		if (res < tmp && sign == 1)
			return (-1);
		if (res != 0 && res < tmp && sign == -1)
			return (0);
	}
	return (sign * res);
}
