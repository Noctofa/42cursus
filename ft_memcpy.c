/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:06:09 by sgaspard          #+#    #+#             */
/*   Updated: 2022/10/24 14:33:06 by sgaspard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*memdst;
	char	*memsrc;
	int		i;

	i = 0;
	memdst = dst;
	memsrc = (char *)src;
	if (memdst == NULL && memsrc == NULL)
		return (NULL);
	while (n-- > 0)
	{
		memdst[i] = memsrc[i];
		i++;
	}
	return (dst);
}
/*
int main () {
   const char src[5] = "ouin";
   char dest[4] = "non";
   printf("Before ft_memcpy dest = %s\n", dest);
   ft_memcpy(dest, src, 2);
   printf("After ft_memcpy dest = %s\n", dest);

   return(0);
}*/
