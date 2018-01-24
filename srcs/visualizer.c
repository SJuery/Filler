/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuery <sjuery@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 19:58:59 by sjuery            #+#    #+#             */
/*   Updated: 2018/01/23 21:18:24 by sjuery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	vis_create(t_filler *flr, t_visual *vis)
{
	t_points s;

	vis->img = mlx_new_image(vis->mlx, 1000, 1000);
	vis->img_int = (int*)mlx_get_data_addr(
		vis->img, &vis->zero, &vis->zero, &vis->zero);
	s.y = 0;
	while (s.y < 1000)
	{
		s.x = 0;
		while (s.x < 1000)
		{
			vis->img_int[((s.y * 1000) + s.x)] = 0XE5E5E5;
			s.x++;
		}
		s.y++;
	}
}

void	vis_fill(t_filler *flr, t_visual *vis, t_points coords, int color)
{
	t_points s;
	t_points dist;

	dist.y = (1000 / flr->map_size.y);
	dist.x = (1000 / flr->map_size.x);
	s.y = coords.y * dist.y;
	while (s.y < ((coords.y * dist.y) + dist.y))
	{
		s.x = coords.x * dist.x;
		while (s.x < ((coords.x * dist.x) + dist.x))
		{
			if (s.x < 1000 && s.y < 1000)
				if (s.y >= 0 && s.x >= 0)
					if (s.x != coords.x * dist.x && s.y != coords.y * dist.y)
						vis->img_int[((s.y * 1000) + s.x)] = color;
			s.x++;
		}
		s.y++;
	}
}

void	vis_update(t_filler *flr, t_visual *vis)
{
	t_points coords;

	coords.y = 0;
	while (coords.y < flr->map_size.y)
	{
		coords.x = 0;
		while (coords.x < flr->map_size.x)
		{
			if (flr->map[coords.y][coords.x] == flr->player)
				vis_fill(flr, vis, coords, 0x000000);
			if (flr->map[coords.y][coords.x] == flr->opponent)
				vis_fill(flr, vis, coords, 0xFFFFFF);
			coords.x++;
		}
		coords.y++;
	}
	mlx_put_image_to_window(vis->mlx, vis->win, vis->img, 0, 0);
	mlx_do_sync(vis->mlx);
}
