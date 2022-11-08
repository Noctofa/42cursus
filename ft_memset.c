/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:55:10 by sgaspard          #+#    #+#             */
/*   Updated: 2022/10/13 12:02:38 by sgaspard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*dst;

	dst = str;
	while (n-- > 0)
	{
		*dst = c;
		dst++;
	}
	return (str);
}
/*
void	printArray(int arr[], int n)
{
   for (int i=0; i<n; i++)
      printf("%d ", arr[i]);
}
 
int main()
{
    int n = 10;
    int arr[n];
  
    // Fill whole array with 100.
    ft_memset(arr, -1, n*sizeof(arr[0]));
    printf("Array after memset()\n");
    printArray(arr, n);
  
    return 0;
}*/
