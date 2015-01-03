/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 18:02:05 by ihermell          #+#    #+#             */
/*   Updated: 2014/12/03 14:44:37 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*copy;

	if (!s)
		return (NULL);
	if (!(copy = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	copy[len] = '\0';
	if (!copy)
		return (NULL);
	ft_strncpy(copy, s + start, len);
	return (copy);
}
