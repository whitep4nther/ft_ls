/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/23 23:19:10 by ihermell          #+#    #+#             */
/*   Updated: 2014/12/04 17:21:44 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char			*dir_new_path(t_data *dir, char *name)
{
	char			*new_path;
	char			*temp;

	if (dir->path[0] == '/' && dir->path[1] == '\0')
		new_path = ft_strdup(name);
	else
		new_path = ft_strjoin("/", name);
	temp = new_path;
	new_path = ft_strjoin(dir->path, new_path);
	free(temp);
	return (new_path);
}

t_data				*get_dir_data_lst(t_data *dir)
{
	DIR				*dirp;
	struct dirent	*ent;
	t_data			*data_lst;
	char			*np;

	data_lst = NULL;
	if ((dirp = opendir(dir->path)) != NULL)
	{
		while ((ent = readdir(dirp)) != NULL)
		{
			np = dir_new_path(dir, ent->d_name);
			lst_push_data(lst_new_data(ft_strdup(ent->d_name), np), &data_lst);
		}
		closedir(dirp);
	}
	else
		return (dir_error(dir));
	return (data_lst);
}

void				*dir_error(t_data *dir)
{
	ft_putstr_fd("ft_ls: ", 2);
	ft_putstr_fd(dir->d_name, 2);
	ft_putstr_fd(": ", 2);
	perror ("");
	g_settings[S_RETURN] = 1;
	return (NULL);
}
