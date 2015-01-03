/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 19:29:08 by ihermell          #+#    #+#             */
/*   Updated: 2014/11/07 18:38:28 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nb_words(char *str, char delimiter)
{
	int		sum;

	sum = 0;
	while (*str != '\0')
	{
		while (*str == delimiter)
			str++;
		if (*str == '\0')
			return (sum);
		sum++;
		while (*str != delimiter && *str != '\0')
			str++;
	}
	return (sum);
}

void	ft_go_to_next_word(char **s, char delimiter)
{
	while (**s == delimiter)
		(*s)++;
}

int		ft_strlen_word(char *s, char delimiter)
{
	int		sum;

	sum = 0;
	while (*s != delimiter && *s++ != '\0')
		sum++;
	return (sum);
}

void	ft_copy_word(char **tab, char **s, char delimiter)
{
	int		i;

	i = 0;
	if (**s != '\0')
	{
		*tab = (char*)malloc(sizeof(char) * ft_strlen_word(*s, delimiter) + 1);
		while (**s != delimiter && **s != '\0')
		{
			(*tab)[i] = **s;
			i++;
			(*s)++;
		}
		(*tab)[i] = '\0';
	}
}

char	**ft_strsplit(const char *s, char c)
{
	char	*str;
	char	**tab;
	int		nb_words;
	int		i;

	if (!s)
		return (NULL);
	str = (char*)s;
	i = 0;
	nb_words = ft_nb_words(str, c);
	tab = (char**)malloc(sizeof(char*) * nb_words + 1);
	tab[nb_words] = 0;
	while (*str != '\0')
	{
		ft_go_to_next_word(&str, c);
		ft_copy_word(tab + i, &str, c);
		i++;
	}
	return (tab);
}
