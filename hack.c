/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hack.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/04 17:24:59 by ihermell          #+#    #+#             */
/*   Updated: 2014/12/04 17:27:13 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				ft_sort_hack(t_data *start, t_data *data_lst,
				int (*f)(t_data *, t_data *))
{
	if (g_flags[FLAG_R] && f(start, data_lst) < 0)
	{
		lst_insert_before(lst_copy_data(data_lst), start);
		return (1);
	}
	else if (!g_flags[FLAG_R] && f(start, data_lst) > 0)
	{
		lst_insert_before(lst_copy_data(data_lst), start);
		return (1);
	}
	return (0);
}
