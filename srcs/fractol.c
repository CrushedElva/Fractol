/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celva <celva@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 10:07:02 by celva             #+#    #+#             */
/*   Updated: 2020/01/28 16:36:24 by celva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex init_complex(double re, double im)
{
	t_complex complex;

	complex.re = re;
	complex.im = im;
	return (complex);
}

int	main(int ac, char **av)
{
	double t;
	t_all *a;
	int i;
	int j;
	t_complex z;
	int n;
	
	a = (t_all*)ft_memalloc(sizeof(t_all) * 1);
	a->ptr_init = mlx_init();
	a->ptr_img = mlx_new_image(a->ptr_init, X_WIN, Y_WIN);
	a->str_pxs = (t_color*)mlx_get_data_addr(a->ptr_img, &(a->bits_pp),
											&(a->size_l), &(a->endian));
	a->ptr_win = mlx_new_window(a->ptr_init, X_WIN, Y_WIN, "Fractol");
	
	a->min.re = -2.0;
	a->max.re = 2.0;
	a->max.im = (fabs(a->min.re) + fabs(a->max.re)) / X_WIN * Y_WIN / 2;
	a->min.im = -a->max.im;
	a->factor.re = (a->max.re - a->min.re) / (X_WIN - 1);
	a->factor.im = (a->max.im - a->min.im) / (Y_WIN - 1);
	i = 0;
	while (i < Y_WIN)
	{
		a->c.im = a->max.im - i * a->factor.im;
		j = 0;
		while (j < X_WIN)
		{
			a->c.re = a->min.re + j * a->factor.re;
			z = init_complex(a->c.re, a->c.im);
			n = 0;
			while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4 && n < MAX_ITER)
			{
				z = init_complex(pow(z.re, 2.0) - pow(z.im, 2.0) + a->c.re,
                2.0 * z.re * z.im + a->c.im);
				n++;
			}
			t = (double)n / (double)MAX_ITER;
			a->str_pxs[i * X_WIN + j].r = (int)(9 * (1 - t) * pow(t, 3) * 255);
			a->str_pxs[i * X_WIN + j].g = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
			a->str_pxs[i * X_WIN + j].b = (int)(8.5 * pow((1 - t), 3) * t * 255);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(a->ptr_init, a->ptr_win, a->ptr_img, 0, 0);
	mlx_loop(a->ptr_init);
}
