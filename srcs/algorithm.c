/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuery <sjuery@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 14:56:17 by sjuery            #+#    #+#             */
/*   Updated: 2018/01/23 19:15:02 by sjuery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static int		check_contact(t_filler *flr, t_points cd)
{
	int			contact;
	t_points	cdc;

	contact = 0;
	cdc.y = 0;
	if (cd.y + flr->piece_size.y > flr->map_size.y ||
		cd.x + flr->piece_size.x > flr->map_size.x)
		return (0);
	while (cdc.y < flr->piece_size.y)
	{
		cdc.x = 0;
		while (cdc.x < flr->piece_size.x)
		{
			if (flr->piece[cdc.y][cdc.x] == '*')
			{
				if (flr->map[cd.y + cdc.y][cd.x + cdc.x] == flr->player)
					contact++;
				if (flr->map[cd.y + cdc.y][cd.x + cdc.x] == flr->opponent)
					return (0);
			}
			cdc.x++;
		}
		cdc.y++;
	}
	return (contact == 1);
}

int				algorithm(t_filler *flr)
{
	t_points	cd;

	cd.y = (flr->dir == 0 || flr->dir == 2) ? 0 : flr->map_size.y;
	while (cd.y <= flr->map_size.y && cd.y >= 0)
	{
		cd.x = (flr->dir == 0 || flr->dir == 3) ? 0 : flr->map_size.x;
		while (cd.x <= flr->map_size.x && cd.x >= 0)
		{
			if (check_contact(flr, cd) == 1)
			{
				ft_putnbr(cd.y);
				ft_putchar(' ');
				ft_putnbr(cd.x);
				ft_putchar('\n');
				flr->dir = 3 - flr->dir;
				return (1);
			}
			cd.x = cd.x + ((flr->dir == 0 || flr->dir == 3) ? 1 : -1);
		}
		cd.y = cd.y + ((flr->dir == 0 || flr->dir == 2) ? 1 : -1);
	}
	ft_putstr("0 0\n");
	return (0);
}
