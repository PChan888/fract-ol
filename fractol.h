/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kai <kai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 00:55:52 by kai               #+#    #+#             */
/*   Updated: 2026/06/20 20:37:58 by kai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include "minilibx-linux/mlx.h"
# include "Libft/libft.h"

# define MANDELBROT 1
# define JULIA 2

# define WIDTH 800
# define HEIGHT 800

// mlx for holding mlx_init
// win for holding mlx_new_window
// img for holding mlx_new_image
// addr for holding mlx_get_data_addr
// bpp for holding bits per pixel
// line_len for holding size of a line in bytes
// endian for holding endianess of the image
// max iter for holding max iter before black
// min_r, max_r, min_i, max_i for holding complex plane
// julia_r, julia_i for holding julia constant
// type for holding which fractal to render (mandelbrot, julia)
typedef struct s_fractol
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	int			max_iter;
	double		min_r;
	double		max_r;
	double		min_i;
	double		max_i;
	double		julia_r;
	double		julia_i;
	int			type;
}				t_fractol;

typedef struct s_complex
{
	double		r;
	double		i;
}				t_complex;

int			print_help_guide(void);
int			parser_args(int argc, char **argv, t_fractol *f);
double		ft_atof(const char *str);
void		init_fractol(t_fractol *f);
t_complex	ft_map_complex(int x, int y, t_fractol *f);
int			iterations(t_complex c, t_fractol *f);
void		put_pixel(t_fractol *f, int x, int y, int color);
void		render_fractal(t_fractol *f);
int			iter_to_color(int iter, int max_iter);
int			close_window(t_fractol *f);
int			key_hook(int keycode, t_fractol *f);
int			mouse_hook(int button, int x, int y, t_fractol *f);

#endif