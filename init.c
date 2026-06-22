/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kai <kai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 00:55:14 by kai               #+#    #+#             */
/*   Updated: 2026/06/20 19:20:00 by kai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mlx(t_fractol *f)
{
	f->mlx = mlx_init();
	if (!f->mlx)
	{
		ft_putstr_fd("Error: mlx_init failed\n", 2);
		exit(1);
	}
	f->win = mlx_new_window(f->mlx, 800, 800, "fractol");
	if (!f->win)
	{
		ft_putstr_fd("Error: mlx_new_window failed\n", 2);
		exit(1);
	}
	f->img = mlx_new_image(f->mlx, 800, 800);
	if (!f->img)
	{
		ft_putstr_fd("Error: mlx_new_image failed\n", 2);
		exit(1);
	}
	f->addr = mlx_get_data_addr(f->img, &f->bpp, &f->line_len, &f->endian);
	f->max_iter = 100;
}

// respective view for each fractal type
void	init_view(t_fractol *f)
{
	if (f->type == MANDELBROT)
	{
		f->min_r = -2.0;
		f->max_r = 1.0;
		f->min_i = -1.5;
		f->max_i = 1.5;
	}
	else if (f->type == JULIA)
	{
		f->min_r = -2.0;
		f->max_r = 2.0;
		f->min_i = -2.0;
		f->max_i = 2.0;
	}
}

void	init_fractol(t_fractol *f)
{
	init_mlx(f);
	init_view(f);
}
