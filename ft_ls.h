/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 23:01:29 by ihermell          #+#    #+#             */
/*   Updated: 2014/12/04 17:37:59 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <math.h>
# include <stdio.h>
# include <dirent.h>
# include <errno.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/ioctl.h>
# include <sys/xattr.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>
# include "libft.h"

# define S_WIN_COLS			0
# define S_WIN_ROWS			1
# define S_NB_ARGS			2
# define S_CALL				3
# define S_PRINT			4
# define S_RETURN			5

# define FLAG_RR			0
# define FLAG_L				1
# define FLAG_A				2
# define FLAG_R				3
# define FLAG_T				4
# define FLAG_1				5
# define FLAG_D				6
# define FLAG_P				7
# define FLAG_UU			8
# define FLAG_C				9
# define FLAG_U				10
# define FLAG_SS			11
# define FLAG_AA			12
# define FLAG_F				13
# define FLAG_TT			14
# define FLAG_G				15
# define FLAG_CC			16

# define T_ERROR			0
# define T_DIR				1
# define T_CHR				2
# define T_BLK				3
# define T_FILE				4
# define T_FIFO				5
# define T_LNK				6
# define T_SOCK				7

# define NLINK				0
# define USER				1
# define GRP				2
# define FILE_SIZE			3
# define P_MAJOR			4
# define P_MINOR 			5
# define HAS_DEVICE			6

typedef struct stat	t_stat;

extern int			*g_settings;
extern char			*g_flags;

typedef struct		s_data
{
	char			type;
	char			*d_name;
	char			*path;
	char			*error;
	t_stat			*stat;
	struct s_data	*prev;
	struct s_data	*next;
}					t_data;

int					initialize(t_data *arg_lst);

int					parse(int ac, char **av, t_data **arg_lst);

t_data				*sort(t_data *data_lst, int (*f)(t_data *, t_data *));
int					ft_sort_hack(t_data *start, t_data *data_lst,
					int (*f)(t_data *, t_data *));
int					sort_by_d_name(t_data *data1, t_data *data2);
int					sort_by_mtime(t_data *data1, t_data *data2);
int					sort_by_birthtime(t_data *data1, t_data *data2);
int					sort_by_ctime(t_data *data1, t_data *data2);
int					sort_by_atime(t_data *data1, t_data *data2);
int					sort_by_size(t_data *data1, t_data *data2);
int					sort_f();

void				lst_filter(t_data *data_lst, t_data **errors,
					t_data **files, t_data **dirs);
t_data				*lst_exclude(t_data *data_lst, int (*f)(t_data *));
t_data				*lst_include(t_data *data_lst, int (*f)(t_data *));

int					has_extended_attr(char *path);

int					is_printable_dir(t_data *file);
int					is_explorable_dir(t_data *file);
int					is_dir(t_data *file);
int					is_hidden(t_data *file);
int					is_tree_dir(t_data *file);

int					get_name_len(t_data *lst);
int					get_gr_len(t_stat *stat);
int					get_user_len(t_stat *stat);
int					*lst_max_properties_length(t_data *data_lst);

t_data				*get_dir_data_lst(t_data *dir);
void				*dir_error(t_data *dir);

t_data				*lst_new_data(char *d_name, char *path);
void				lst_push_data(t_data *new, t_data **data_lst);
int					lst_count(t_data *data_lst);
void				lst_insert_before(t_data *insert, t_data *here);
void				lst_insert_after(t_data *insert, t_data *here);
t_data				*lst_copy_data(t_data *data);
t_data				*lst_find_head(t_data *data_lst);
void				lst_pseudo_free(t_data *data_lst);
void				lst_free(t_data *data_lst);
int					lst_data_type(t_stat *stat);
t_data				*lst_at(int i, t_data *lst);

void				print_columns_data_lst(t_data *lst);
void				print_mcolumns(t_data *lst, int *sizes, int count,
					int width);
void				print_user_group(t_data *file, int *width);
void				print_date(time_t timestamp);
void				print_which_date(t_stat *stat);
void				print_printable_dir(t_data *data_lst);
void				print_pointed_dir(t_data *file);
void				print_file_type(t_data *file);
void				print_device(t_data *file, int *width);
void				print_block_size(t_data *data_lst);
void				print_moar_permissions(t_data *file, char *rights);
void				print_more_permissions(t_data *file, char *rights);
void				print_permissions(t_data *file);
void				print_nbr_col(int nb, int width);
void				print_char_col(char *col, int width);
void				print_basic_file(t_data *file);
void				print_detailled_file(t_data *file, int *width);
void				print_data_lst(t_data *data_lst);
void				print_basic_data_lst(t_data *data_lst);
void				print_detailled_data_lst(t_data *data_lst);
void				print_dirs(t_data *dirs);
void				print_header_dir(t_data *dir);

void				e_args_error(t_data *args);
void				e_file_error(t_data *file);
void				e_illegal_option(char opt);

void				activate_flag(char flag);
void				more_activate_flag(char flag);
void				moar_activate_flag(char flag);

#endif
