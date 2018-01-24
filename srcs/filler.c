/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuery <sjuery@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 14:43:42 by sjuery            #+#    #+#             */
/*   Updated: 2018/01/23 19:41:27 by sjuery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void	parse_player(t_filler *flr)
{
	t_points cd;

	cd.y = 0;
	flr->opponent = (flr->player == 'O') ? 'X' : 'O';
	while (cd.y < flr->map_size.y)
	{
		cd.x = 0;
		while (cd.x < flr->map_size.x)
		{
			if (flr->map[cd.y][cd.x] == flr->opponent)
			{
				flr->opponent_pos.x = cd.x;
				flr->opponent_pos.y = cd.y;
			}
			if (flr->map[cd.y][cd.x] == flr->player)
			{
				flr->player_pos.x = cd.x;
				flr->player_pos.y = cd.y;
			}
			cd.x++;
		}
		cd.y++;
	}
	flr->dir = (flr->opponent_pos.y > flr->player_pos.y) ? 1 : 0;
}

static void	parse_map(t_filler *flr, char *line)
{
	if (flr->state == map_size && ft_strstr(line, "Plateau"))
	{
		flr->count = 0;
		flr->map_size.y = ft_atoi(ft_strchr(line, ' '));
		flr->map_size.x = ft_atoi(ft_strrchr(line, ' '));
		if (!flr->map)
			flr->map = ft_memalloc(sizeof(char *) * flr->map_size.y);
		flr->state = map_gen;
	}
	else if (flr->state == map_gen && ft_isdigit(line[0]))
	{
		flr->map[flr->count++] = ft_strtrim(ft_strchr(line, ' '));
		if (flr->count == flr->map_size.y)
		{
			flr->state = piece_size;
		}
	}
}

static void	parse_piece(t_filler *flr, char *line)
{
	if (flr->state == piece_size && ft_strstr(line, "Piece"))
	{
		flr->count = 0;
		flr->piece_size.y = ft_atoi(ft_strchr(line, ' '));
		flr->piece_size.x = ft_atoi(ft_strrchr(line, ' '));
		free(flr->piece);
		if (!flr->piece)
			flr->piece = ft_memalloc(sizeof(char *) * flr->piece_size.y);
		flr->state = piece_gen;
	}
	else if (flr->state == piece_gen)
	{
		flr->piece[flr->count++] = line;
		if (flr->count == flr->piece_size.y)
		{
			flr->state = algo;
			if (flr->opponent_pos.x == 0 && flr->opponent_pos.y == 0 &&
				flr->player_pos.x == 0 && flr->player_pos.y == 0)
				parse_player(flr);
		}
	}
}

static void	free_all(t_filler *flr)
{
	int		i;

	i = 0;
	if (flr->piece)
		while (i < flr->piece_size.y && flr->piece[i])
			free(flr->piece[i++]);
	free(flr->piece);
	flr->piece = NULL;
	i = 0;
	if (flr->map)
		while (i < flr->map_size.y && flr->map[i])
			free(flr->map[i++]);
	free(flr->map);
	flr->map = NULL;
}

int			main(void)
{
	char		*line;
	t_filler	*flr;
	t_visual	*vis;

	flr = ft_memalloc(sizeof(t_filler));
	vis = ft_memalloc(sizeof(t_visual));
	vis->mlx = mlx_init();
	vis->win = mlx_new_window(vis->mlx, 1000, 1000, "Filler Visualizer");
	vis_create(flr, vis);
	while (get_next_line(0, &line))
	{
		if (ft_strstr(line, "$$$"))
			flr->player = (ft_atoi(ft_strchr(line, 'p') + 1) == 1) ? 'O' : 'X';
		parse_map(flr, line);
		parse_piece(flr, line);
		if (flr->state == algo)
		{
			flr->state = map_size;
			if (!algorithm(flr))
				return (1);
			vis_update(flr, vis);
			free_all(flr);
		}
	}
	return (0);
}
