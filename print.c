/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/23 22:51:51 by ihermell          #+#    #+#             */
/*   Updated: 2014/12/04 17:14:36 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				print_data_lst(t_data *data_lst)
{
	if (data_lst != NULL)
		g_settings[S_PRINT]++;
	if (g_flags[FLAG_F])
		data_lst = sort(data_lst, &sort_f);
	else if (g_flags[FLAG_SS])
		data_lst = sort(data_lst, &sort_by_size);
	else if (g_flags[FLAG_T] && g_flags[FLAG_UU])
		data_lst = sort(data_lst, &sort_by_birthtime);
	else if (g_flags[FLAG_T] && g_flags[FLAG_C])
		data_lst = sort(data_lst, &sort_by_ctime);
	else if (g_flags[FLAG_T] && g_flags[FLAG_U])
		data_lst = sort(data_lst, &sort_by_atime);
	else if (g_flags[FLAG_T])
		data_lst = sort(data_lst, &sort_by_mtime);
	else
		data_lst = sort(data_lst, &sort_by_d_name);
	if (g_flags[FLAG_L])
		print_detailled_data_lst(data_lst);
	else if (g_flags[FLAG_CC])
		print_columns_data_lst(data_lst);
	else
		print_basic_data_lst(data_lst);
	lst_pseudo_free(data_lst);
}

void				print_dirs(t_data *dirs)
{
	t_data			*data_lst;
	t_data			*dirs_lst;

	while (dirs)
	{
		g_settings[S_CALL]++;
		if (is_printable_dir(dirs))
			print_header_dir(dirs);
		data_lst = get_dir_data_lst(dirs);
		if (is_printable_dir(dirs))
			print_printable_dir(data_lst);
		if (g_flags[FLAG_RR])
		{
			dirs_lst = lst_include(data_lst, &is_explorable_dir);
			print_dirs(sort(dirs_lst, &sort_by_d_name));
			lst_pseudo_free(dirs_lst);
		}
		lst_free(data_lst);
		dirs = dirs->next;
	}
	lst_pseudo_free(lst_find_head(dirs));
}

void				print_header_dir(t_data *dir)
{
	if (g_settings[S_PRINT] > 0)
		ft_putchar('\n');
	if (g_settings[S_PRINT] > 0 || g_settings[S_NB_ARGS] > 1)
	{
		ft_putstr(dir->path);
		ft_putendl(":");
	}
}

void				print_basic_data_lst(t_data *data_lst)
{
	while (data_lst)
	{
		if (data_lst->error)
			e_file_error(data_lst);
		else
			print_basic_file(data_lst);
		data_lst = data_lst->next;
	}
}

void				print_detailled_data_lst(t_data *data_lst)
{
	int				*width;

	width = lst_max_properties_length(data_lst);
	if (data_lst && g_settings[S_CALL] > 0)
		print_block_size(data_lst);
	while (data_lst)
	{
		if (data_lst->error)
			e_file_error(data_lst);
		else
			print_detailled_file(data_lst, width);
		data_lst = data_lst->next;
	}
	free(width);
}
