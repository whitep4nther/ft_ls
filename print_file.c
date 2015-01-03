/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 01:22:13 by ihermell          #+#    #+#             */
/*   Updated: 2014/12/04 16:59:35 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				print_basic_file(t_data *file)
{
	ft_putstr(file->d_name);
	if (g_flags[FLAG_P] && file->type == T_DIR)
		ft_putchar('/');
	ft_putchar('\n');
}

void				print_detailled_file(t_data *file, int *width)
{
	int				device_len;

	device_len = (width[HAS_DEVICE]) ? width[P_MAJOR] + width[P_MINOR] + 3
		: width[FILE_SIZE];
	print_permissions(file);
	print_nbr_col(file->stat->st_nlink, width[NLINK]);
	print_user_group(file, width);
	if (file->type == T_CHR || file->type == T_BLK)
		print_device(file, width);
	else
		print_nbr_col(file->stat->st_size, device_len);
	print_which_date(file->stat);
	ft_putstr(file->d_name);
	if (file->type == T_LNK)
		print_pointed_dir(file);
	else if (g_flags[FLAG_P] && file->type == T_DIR)
		ft_putchar('/');
	ft_putchar('\n');
}

void				print_char_col(char *col, int width)
{
	int				len;

	len = ft_strlen(col);
	ft_putstr(col);
	while (width-- - len >= 0)
		ft_putchar(' ');
}

void				print_nbr_col(int nb, int width)
{
	int				len;

	len = ft_intlen(nb);
	while (width-- - len >= 0)
		ft_putchar(' ');
	ft_putnbr(nb);
	ft_putchar(' ');
}

void				print_which_date(t_stat *stat)
{
	if (g_flags[FLAG_UU])
		print_date(stat->st_birthtime);
	else if (g_flags[FLAG_C])
		print_date(stat->st_ctime);
	else if (g_flags[FLAG_U])
		print_date(stat->st_atime);
	else
		print_date(stat->st_mtimespec.tv_sec);
}
