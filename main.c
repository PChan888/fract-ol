/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kai <kai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 18:53:06 by kai               #+#    #+#             */
/*   Updated: 2026/06/22 03:33:10 by kai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	f;

	if (parser_args(argc, argv, &f) != 0)
		return (1);
	init_fractol(&f);
	render_fractal(&f);
	mlx_hook(f.win, 17, 0, close_window, &f);
	mlx_key_hook(f.win, key_hook, &f);
	mlx_mouse_hook(f.win, mouse_hook, &f);
	mlx_loop(f.mlx);
	return (0);
}
