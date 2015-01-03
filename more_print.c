/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 18:29:58 by ihermell          #+#    #+#             */
/*   Updated: 2014/12/03 10:32:09 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				print_printable_dir(t_data *data_lst)
{
	t_data			*print_lst;

	if (g_flags[FLAG_A])
		print_lst = data_lst;
	else if (g_flags[FLAG_AA])
		print_lst = lst_exclude(data_lst, &is_tree_dir);
	else
		print_lst = lst_exclude(data_lst, &is_hidden);
	print_data_lst(print_lst);
	if (!g_flags[FLAG_A])
		lst_pseudo_free(print_lst);
}
