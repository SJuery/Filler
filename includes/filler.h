/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuery <sjuery@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 19:22:42 by sjuery            #+#    #+#             */
/*   Updated: 2018/01/23 19:41:47 by sjuery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "../libft/libft.h"
# include "../minilibx/mlx.h"

enum	e_state { map_size, map_gen, piece_size, piece_gen, algo, finish };

typedef struct				s_points
{
	int						x;
	int						y;
}							t_points;

typedef struct				s_filler
{
	enum e_state			state;
	int						count;
	char					**map;
	t_points				map_size;
	char					**piece;
	t_points				piece_size;
	char					player;
	t_points				player_pos;
	char					opponent;
	t_points				opponent_pos;
	int						dir;
	int						diff;
}							t_filler;

typedef struct				s_visual
{
	void					*mlx;
	void					*win;
	void					*img;
	int						*img_int;
	int						zero;
}							t_visual;

int							algorithm(t_filler *flr);
void						vis_create(t_filler *flr, t_visual *vis);
void						vis_update(t_filler *flr, t_visual *vis);
void						vis_fill(t_filler *flr, t_visual *vis, t_points
															coords, int color);

#endif
