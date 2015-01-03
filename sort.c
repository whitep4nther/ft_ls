/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 11:26:42 by ihermell          #+#    #+#             */
/*   Updated: 2014/12/04 17:34:44 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_data				*sort(t_data *data_lst, int (*f)(t_data *, t_data *))
{
	t_data			*new;
	char			found;

	if (!data_lst)
		return (NULL);
	new = NULL;
	lst_push_data(lst_copy_data(data_lst), &new);
	data_lst = data_lst->next;
	while (data_lst)
	{
		found = 0;
		while (!found)
		{
			found = ft_sort_hack(new, data_lst, f);
			if (!new->next)
				break ;
			new = new->next;
		}
		if (!found)
			lst_insert_after(lst_copy_data(data_lst), new);
		data_lst = data_lst->next;
		new = lst_find_head(new);
	}
	return (new);
}

int					sort_by_d_name(t_data *data1, t_data *data2)
{
	return (ft_strcmp(data1->d_name, data2->d_name));
}

int					sort_by_mtime(t_data *data1, t_data *data2)
{
	if (data2->stat->st_mtimespec.tv_sec
		== data1->stat->st_mtimespec.tv_sec)
		return (sort_by_d_name(data1, data2));
	return (data2->stat->st_mtimespec.tv_sec
	- data1->stat->st_mtimespec.tv_sec);
}

int					sort_by_birthtime(t_data *data1, t_data *data2)
{
	if (data2->stat->st_birthtime == data1->stat->st_birthtime)
		return (sort_by_d_name(data1, data2));
	return (data2->stat->st_birthtime - data1->stat->st_birthtime);
}

int					sort_by_ctime(t_data *data1, t_data *data2)
{
	if (data2->stat->st_ctime == data1->stat->st_ctime)
		return (sort_by_d_name(data1, data2));
	return (data2->stat->st_ctime - data1->stat->st_ctime);
}
