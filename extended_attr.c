/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extended_attr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 05:59:45 by ihermell          #+#    #+#             */
/*   Updated: 2014/12/03 09:46:46 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				has_extended_attr(char *path)
{
	int			count;

	count = listxattr(path, NULL, 0, XATTR_NOFOLLOW);
	if (count > 0)
		return (1);
	else
		return (0);
}
