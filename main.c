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
	t_fractol	var;

	if (parser_args(argc, argv, &var) != 0)
		return (1);
	init_fractol(&var);
	render_fractal(&var);
	mlx_hook(var.win, 17, 0, close_window, &var);
	mlx_key_hook(var.win, key_hook, &var);
	mlx_mouse_hook(var.win, mouse_hook, &var);
	mlx_loop(var.mlx);
	return (0);
}
