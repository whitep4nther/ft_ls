/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   columns.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 05:09:40 by ihermell          #+#    #+#             */
/*   Updated: 2014/12/04 17:14:06 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			print_columns_data_lst(t_data *lst)
{
	int			*sizes;
	int			count;
	int			width;

	if (!lst)
		return ;
	sizes = (int*)malloc(sizeof(int) * 2);
	bzero(sizes, sizeof(int) * 2);
	width = get_name_len(lst);
	count = lst_count(lst);
	sizes[1] = g_settings[S_WIN_COLS] / (width + 1);
	sizes[0] = (count + sizes[1] - 1) / sizes[1];
	print_mcolumns(lst, sizes, count, width);
}

void			print_mcolumns(t_data *lst, int *sizes, int count, int width)
{
	int			i;
	int			j;
	int			len;
	int			tmp;
	t_data		*file;

	i = -1;
	while (++i < sizes[0])
	{
		j = -1;
		tmp = sizes[1];
		while (++j < tmp)
		{
			if (j * sizes[0] + i >= count)
				continue ;
			file = lst_at(j * sizes[0] + i, lst);
			ft_putstr(file->d_name);
			len = ft_strlen(file->d_name);
			if ((j + 1) * sizes[0] + i < count)
				while (len++ <= width)
					ft_putchar(' ');
		}
		ft_putchar('\n');
	}
	free(sizes);
}
