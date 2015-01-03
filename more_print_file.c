/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_print_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 11:33:16 by ihermell          #+#    #+#             */
/*   Updated: 2014/12/03 10:37:25 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				print_file_type(t_data *file)
{
	if (file->type == T_DIR)
		ft_putchar('d');
	else if (file->type == T_FILE)
		ft_putchar('-');
	else if (file->type == T_LNK)
		ft_putchar('l');
	else if (file->type == T_FIFO)
		ft_putchar('p');
	else if (file->type == T_SOCK)
		ft_putchar('s');
	else if (file->type == T_BLK)
		ft_putchar('b');
	else if (file->type == T_CHR)
		ft_putchar('c');
}

void				print_device(t_data *file, int *width)
{
	int				major_len;
	int				major_width;

	major_len = ft_intlen(major(file->stat->st_rdev));
	major_width = width[P_MAJOR];
	ft_putchar(' ');
	while (major_width-- - major_len >= 0)
		ft_putchar(' ');
	ft_putnbr(major(file->stat->st_rdev));
	ft_putchar(',');
	print_nbr_col(minor(file->stat->st_rdev), width[P_MINOR]);
}

void				print_pointed_dir(t_data *file)
{
	int				res;
	char			name[256];

	res = readlink(file->path, name, 256);
	name[res] = '\0';
	ft_putstr(" -> ");
	ft_putstr(name);
}

void				print_date(time_t timestamp)
{
	char			*date;
	time_t			now;

	now = time(NULL);
	date = ctime(&timestamp);
	if (g_flags[FLAG_TT])
	{
		date[24] = '\0';
		ft_putstr(date + 4);
		ft_putchar(' ');
		return ;
	}
	write(1, date + 4, 7);
	if (timestamp > now || now - timestamp > 15778463)
	{
		ft_putchar(' ');
		write(1, date + 20, 4);
	}
	else
		write(1, date + 11, 5);
	ft_putchar(' ');
}

void				print_user_group(t_data *file, int *width)
{
	if (!g_flags[FLAG_G])
	{
		if (getpwuid(file->stat->st_uid))
			print_char_col(getpwuid(file->stat->st_uid)->pw_name, width[USER]);
		else
			print_char_col(ft_itoa(file->stat->st_uid), width[USER]);
		ft_putchar(' ');
	}
	if (getgrgid(file->stat->st_gid))
		print_char_col(getgrgid(file->stat->st_gid)->gr_name, width[GRP]);
	else
		print_char_col(ft_itoa(file->stat->st_gid), width[GRP]);
}
