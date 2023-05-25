/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspard <sgaspard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:48:09 by sgaspard          #+#    #+#             */
/*   Updated: 2023/05/25 13:35:00 by sgaspard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_free(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

size_t	ft_countwords(char const *s, char c)
{
	size_t	i;
	size_t	word;

	if (!s[0])
		return (0);
	i = 0;
	word = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			word++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		word++;
	return (word);
}

void	ft_skipword(char **skipword, size_t *skipwordlen, char c)
{
	size_t	i;

	*skipword += *skipwordlen;
	*skipwordlen = 0;
	i = 0;
	while (**skipword && **skipword == c)
		(*skipword)++;
	while ((*skipword)[i])
	{
		if ((*skipword)[i] == c)
			return ;
		(*skipwordlen)++;
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	char	*skipword;
	size_t	skipwordlen;
	size_t	i;

	if (!s)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * (ft_countwords(s, c) + 1));
	if (!tab)
		return (NULL);
	i = 0;
	skipword = (char *)s;
	skipwordlen = 0;
	while (i < ft_countwords(s, c))
	{
		ft_skipword(&skipword, &skipwordlen, c);
		tab[i] = (char *)malloc(sizeof(char) * (skipwordlen + 1));
		if (!tab[i])
			return (ft_free(tab));
		ft_strlcpy(tab[i], skipword, skipwordlen + 1);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
