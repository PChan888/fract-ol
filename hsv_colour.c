/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hsv_colour.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kai <kai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 01:27:41 by kai               #+#    #+#             */
/*   Updated: 2026/06/21 04:37:45 by kai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// 0x00RRGGBB binary shift
// (0x00)(77)(255)(0) 00000000 01001101 11111111 00000000
static int	hsv_to_rgb(double h, double f)
{
	double	t;
	double	q;
	int		i;

	t = f;
	q = 1.0 - f;
	i = (int)(h / 60.0) % 6;
	if (i == 0)
		return (((int)(255) << 16) | ((int)(t * 255) << 8) | 0);
	if (i == 1)
		return (((int)(q * 255) << 16) | ((int)(255) << 8) | 0);
	if (i == 2)
		return (0 | ((int)(255) << 8) | (int)(t * 255));
	if (i == 3)
		return (0 | ((int)(q * 255) << 8) | (int)(255));
	if (i == 4)
		return (((int)(t * 255) << 16) | 0 | (int)(255));
	return (((int)(255) << 16) | 0 | (int)(q * 255));
}

// calculate the color
// iter = max iter is white
// calulate for hue iter compared to max iter
// then multi by 360 to get hue value
// f is fractional part of 60° sector.
int	iter_to_color(int iter, int max_iter)
{
	double	h;
	double	f;

	if (iter == max_iter)
		return (0x000000);
	h = (double)iter / max_iter * 360.0;
	f = h / 60.0 - (int)(h / 60.0);
	return (hsv_to_rgb(h, f));
}
