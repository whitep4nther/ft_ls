/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/23 00:17:54 by ihermell          #+#    #+#             */
/*   Updated: 2014/12/04 17:18:17 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				activate_flag(char flag)
{
	if (flag == 'R')
		g_flags[FLAG_RR] = 1;
	else if (flag == 'l')
	{
		g_flags[FLAG_L] = 1;
		g_flags[FLAG_CC] = 0;
	}
	else if (flag == 'a')
		g_flags[FLAG_A] = 1;
	else if (flag == 'r')
		g_flags[FLAG_R] = 1;
	else if (flag == 'C')
	{
		g_flags[FLAG_CC] = 1;
		g_flags[FLAG_L] = 0;
	}
	else if (flag == 'd')
		g_flags[FLAG_D] = 1;
	else if (flag == 't')
		g_flags[FLAG_T] = 1;
	else if (flag == 'p')
		g_flags[FLAG_P] = 1;
	else
		more_activate_flag(flag);
}

void				more_activate_flag(char flag)
{
	if (flag == 'U')
	{
		g_flags[FLAG_C] = 0;
		g_flags[FLAG_UU] = 1;
		g_flags[FLAG_U] = 0;
	}
	else if (flag == 'c')
	{
		g_flags[FLAG_C] = 1;
		g_flags[FLAG_UU] = 0;
		g_flags[FLAG_U] = 0;
	}
	else if (flag == 'u')
	{
		g_flags[FLAG_C] = 0;
		g_flags[FLAG_UU] = 0;
		g_flags[FLAG_U] = 1;
	}
	else if (flag == 'g')
	{
		g_flags[FLAG_G] = 1;
		g_flags[FLAG_L] = 1;
	}
	else
		moar_activate_flag(flag);
}

void				moar_activate_flag(char flag)
{
	if (flag == 'S')
		g_flags[FLAG_SS] = 1;
	else if (flag == 'A')
		g_flags[FLAG_AA] = 1;
	else if (flag == 'f')
	{
		g_flags[FLAG_A] = 1;
		g_flags[FLAG_F] = 1;
	}
	else if (flag == 'T')
		g_flags[FLAG_TT] = 1;
	else if (flag == '1')
	{
		g_flags[FLAG_CC] = 0;
		g_flags[FLAG_L] = 0;
	}
}
