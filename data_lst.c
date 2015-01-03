/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 03:22:11 by ihermell          #+#    #+#             */
/*   Updated: 2014/12/04 15:17:06 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				print_block_size(t_data *data_lst)
{
	quad_t			sum;

	sum = 0;
	while (data_lst)
	{
		sum += data_lst->stat->st_blocks;
		data_lst = data_lst->next;
	}
	ft_putstr("total ");
	ft_putlnbr(sum);
	ft_putchar('\n');
}

int					*lst_max_properties_length(t_data *data_lst)
{
	int				*max;
	int				len;

	max = (int*)malloc(sizeof(int) * 7);
	bzero(max, sizeof(int) * 7);
	while (data_lst)
	{
		if (data_lst->type == T_CHR || data_lst->type == T_BLK)
			max[HAS_DEVICE] = 1;
		if ((len = ft_intlen(data_lst->stat->st_nlink)) > max[NLINK])
			max[NLINK] = len;
		if ((len = get_user_len(data_lst->stat)) > max[USER])
			max[USER] = len;
		if ((len = get_gr_len(data_lst->stat)) > max[GRP])
			max[GRP] = len;
		if ((len = ft_intlen(data_lst->stat->st_size)) > max[FILE_SIZE])
			max[FILE_SIZE] = len;
		if ((len = ft_intlen(major(data_lst->stat->st_rdev))) > max[P_MAJOR])
			max[P_MAJOR] = len;
		if ((len = ft_intlen(minor(data_lst->stat->st_rdev))) > max[P_MINOR])
			max[P_MINOR] = len;
		data_lst = data_lst->next;
	}
	return (max);
}

int					get_user_len(t_stat *stat)
{
	int				len;

	if (getpwuid(stat->st_uid))
		len = ft_strlen(getpwuid(stat->st_uid)->pw_name);
	else
		len = ft_intlen(stat->st_uid);
	return (len);
}

int					get_gr_len(t_stat *stat)
{
	int				len;

	if (getgrgid(stat->st_gid))
		len = ft_strlen(getgrgid(stat->st_gid)->gr_name);
	else
		len = ft_intlen(stat->st_gid);
	return (len);
}

int					get_name_len(t_data *lst)
{
	int				max;
	int				len;

	max = 0;
	while (lst)
	{
		if ((len = ft_strlen(lst->d_name)) > max)
			max = len;
		lst = lst->next;
	}
	return (max);
}
