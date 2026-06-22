/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kai <kai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 03:33:33 by kai               #+#    #+#             */
/*   Updated: 2026/06/22 05:26:32 by kai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define KEY_ESC 65307
#define KEY_LEFT 65361
#define KEY_UP 65362
#define KEY_RIGHT 65363
#define KEY_DOWN 65364
#define MOVE_STEP 0.1

static void	exit_clean(t_fractol *f)
{
	mlx_destroy_image(f->mlx, f->img);
	mlx_destroy_window(f->mlx, f->win);
	mlx_destroy_display(f->mlx);
	free(f->mlx);
	exit(0);
}

int	close_window(t_fractol *f)
{
	exit_clean(f);
	return (0);
}

// calucates an dupdate new view range
static void	move_view(t_fractol *f, double dr, double di)
{
	double	range_r;
	double	range_i;

	range_r = (f->max_r - f->min_r) * dr;
	range_i = (f->max_i - f->min_i) * di;
	f->min_r += range_r;
	f->max_r += range_r;
	f->min_i += range_i;
	f->max_i += range_i;
	render_fractal(f);
}

// handle key events for moving the view and exiting
int	key_hook(int keycode, t_fractol *f)
{
	if (keycode == KEY_ESC)
		exit_clean(f);
	else if (keycode == KEY_LEFT)
		move_view(f, -MOVE_STEP, 0.0);
	else if (keycode == KEY_RIGHT)
		move_view(f, MOVE_STEP, 0.0);
	else if (keycode == KEY_UP)
		move_view(f, 0.0, MOVE_STEP);
	else if (keycode == KEY_DOWN)
		move_view(f, 0.0, -MOVE_STEP);
	return (0);
}
