/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moar_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/04 15:29:31 by ihermell          #+#    #+#             */
/*   Updated: 2014/12/04 16:10:05 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_data			*lst_at(int i, t_data *lst)
{
	int			j;

	j = 0;
	while (lst)
	{
		if (i == j)
			return (lst);
		j++;
		lst = lst->next;
	}
	return (NULL);
}
