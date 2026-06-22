/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kai <kai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 04:08:53 by kai               #+#    #+#             */
/*   Updated: 2026/06/22 00:00:00 by kai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// how do we turn complex numbers like -2.0 or 0.97 to pixels
// and map it on the screen?
// find the extreme on both sides of the complex plane subtract them and divide
// by the corresponding dimension of the window to get the pixel size.
// find  y or x by subtracting from respective extreme
// then muliplying by pixel size to get the pixel coordinates
t_complex	ft_map_complex(int x, int y, t_fractol *f)
{
	t_complex	c;

	c.r = f->min_r + (double)x * (f->max_r - f->min_r) / WIDTH;
	c.i = f->max_i - (double)y * (f->max_i - f->min_i) / HEIGHT;
	return (c);
}

static void	set_start(t_complex *z, t_complex *c, t_fractol *f)
{
	if (f->type == JULIA)
	{
		z->r = c->r;
		z->i = c->i;
		c->r = f->julia_r;
		c->i = f->julia_i;
	}
	else
	{
		z->r = 0.0;
		z->i = 0.0;
	}
}

// complex z to hold the running value, c holds the fixed point being tested
int	iterations(t_complex c, t_fractol *f)
{
	t_complex	z;
	int			iter;
	double		tmp;

	set_start(&z, &c, f);
	iter = 0;
	while (z.r * z.r + z.i * z.i < 4.0 && iter < f->max_iter)
	{
		tmp = z.r * z.r - z.i * z.i + c.r;
		z.i = 2.0 * z.r * z.i + c.i;
		z.r = tmp;
		iter++;
	}
	return (iter);
}

void	put_pixel(t_fractol *f, int x, int y, int color)
{
	char	*pixel;

	pixel = f->addr + (y * f->line_len + x * (f->bpp / 8));
	*(int *)pixel = color;
}

void	render_fractal(t_fractol *f)
{
	t_complex	c;
	int			x;
	int			y;
	int			color;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c = ft_map_complex(x, y, f);
			color = iter_to_color(iterations(c, f), f->max_iter);
			put_pixel(f, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}
