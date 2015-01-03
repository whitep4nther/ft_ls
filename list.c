/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 00:06:24 by ihermell          #+#    #+#             */
/*   Updated: 2014/12/04 17:30:48 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_data			*lst_new_data(char *d_name, char *path)
{
	int			result;
	t_data		*new;
	t_stat		temp;

	new = (t_data*)malloc(sizeof(t_data));
	new->stat = (t_stat*)malloc(sizeof(t_stat));
	result = lstat(path, new->stat);
	if (g_settings[S_CALL] == 0 && g_flags[FLAG_L] == 0 && result == 0
		&& lst_data_type(new->stat) == T_LNK
		&& stat(path, &temp) == 0 && lst_data_type(&temp) == T_DIR)
		result = stat(path, new->stat);
	new->error = NULL;
	if (result == -1)
	{
		new->type = T_ERROR;
		new->error = strerror(errno);
	}
	else
		new->type = lst_data_type(new->stat);
	new->d_name = d_name;
	new->path = path;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void			lst_push_data(t_data *data, t_data **data_lst)
{
	if (data_lst)
	{
		data->prev = NULL;
		data->next = *data_lst;
		if (*data_lst)
			(*data_lst)->prev = data;
		*data_lst = data;
	}
}

void			lst_insert_before(t_data *insert, t_data *here)
{
	insert->next = here;
	insert->prev = here->prev;
	here->prev = insert;
	if (insert->prev)
		insert->prev->next = insert;
}

void			lst_insert_after(t_data *insert, t_data *here)
{
	insert->next = here->next;
	insert->prev = here;
	here->next = insert;
	if (insert->next)
		insert->next->prev = insert;
}

int				lst_count(t_data *data_lst)
{
	int			sum;

	sum = 0;
	while (data_lst)
	{
		sum++;
		data_lst = data_lst->next;
	}
	return (sum);
}
