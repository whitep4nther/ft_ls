/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/23 04:32:15 by ihermell          #+#    #+#             */
/*   Updated: 2014/12/03 11:51:36 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int					initialize(t_data *arg_lst)
{
	t_data		*errors;
	t_data		*files;
	t_data		*dirs;

	errors = NULL;
	files = NULL;
	dirs = NULL;
	lst_filter(arg_lst, &errors, &files, &dirs);
	e_args_error(errors);
	print_data_lst(files);
	print_dirs(dirs);
	lst_free(errors);
	lst_free(files);
	return (0);
}
