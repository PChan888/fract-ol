/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kai <kai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 18:53:03 by kai               #+#    #+#             */
/*   Updated: 2026/06/20 18:49:53 by kai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	print_help_guide(void)
{
	ft_putstr_fd("Usage:\n", 1);
	ft_putstr_fd("    ./fractol <mandelbrot>\n", 1);
	ft_putstr_fd("    ./fractol <julia> <re> <im>\n", 1);
	return (1);
}

int	parser_args(int argc, char **argv, t_fractol *var)
{
	int	status;

	status = 0;
	if (argc == 2 && ft_strncmp(argv[1], "mandelbrot", 11) == 0)
		var->type = MANDELBROT;
	else if (argc == 4 && ft_strncmp(argv[1], "julia", 6) == 0)
	{
		var->type = JULIA;
		var->julia_r = ft_atof(argv[2]);
		var->julia_i = ft_atof(argv[3]);
	}
	else
	{
		print_help_guide();
		status = 1;
	}
	return (status);
}

double	ft_atof(const char *str)
{
	double	result;
	double	sign;
	double	dvr;

	result = 0.0;
	sign = 1.0;
	if (str[0] == '-')
		sign = -1.0;
	if (str[0] == '-' || str[0] == '+')
		str++;
	while (*str >= '0' && *str <= '9')
		result = result * 10.0 + (*str++ - '0');
	if (*str == '.')
	{
		str++;
		dvr = 10.0;
		while (*str >= '0' && *str <= '9')
		{
			result = result + (*str++ - '0') / dvr;
			dvr = dvr * 10.0;
		}
	}
	return (result * sign);
}
