/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:19:07 by sgaspard          #+#    #+#             */
/*   Updated: 2022/11/21 14:37:52 by sgaspard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isnegatif(int sign, int i, const char *str)
{
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	return (sign);
}

int	ft_atoi(const char *str)
{
	int					i;
	int					sign;
	long long unsigned	tmp;
	long long unsigned	res;

	tmp = 0;
	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	ft_isnegatif(sign, i, str);
	while (str[i] >= '0' && str[i] <= '9')
	{
		tmp = res;
		res = res * 10 + (str[i] - '0');
		if (res < tmp && sign == 1)
			return (-1);
		if (res < tmp + 1 && sign == -1)
			return (0);
		i++;
	}
	return (sign * res);
}
