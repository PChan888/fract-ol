/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kai <kai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 03:32:25 by kai               #+#    #+#             */
/*   Updated: 2026/06/22 03:32:28 by kai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define SCROLL_UP 4
#define SCROLL_DOWN 5
#define ZOOM_IN 0.9

static void	zoom_view(t_fractol *f, double factor, int x, int y)
{
	t_complex	c;
	double		range_r;
	double		range_i;

	c = ft_map_complex(x, y, f);
	range_r = (f->max_r - f->min_r) * factor;
	range_i = (f->max_i - f->min_i) * factor;
	f->min_r = c.r - (c.r - f->min_r) * factor;
	f->min_i = c.i - (c.i - f->min_i) * factor;
	f->max_r = f->min_r + range_r;
	f->max_i = f->min_i + range_i;
	render_fractal(f);
}

int	mouse_hook(int button, int x, int y, t_fractol *f)
{
	if (button == SCROLL_UP)
		zoom_view(f, ZOOM_IN, x, y);
	else if (button == SCROLL_DOWN)
		zoom_view(f, 1.0 / ZOOM_IN, x, y);
	return (0);
}
