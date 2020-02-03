/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celva <celva@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 10:08:26 by celva             #+#    #+#             */
/*   Updated: 2020/01/28 15:37:27 by celva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <OpenCL/opencl.h>
# include <OpenCL/cl.h>
# include <OpenCL/cl_gl.h>
# include <OpenCL/cl_gl_ext.h>
# include <OpenCL/cl_ext.h>
# include <OpenCL/gcl.h>
# include "ft_printf.h"
# define X_WIN 1300
# define Y_WIN 1000
# define MAX_ITER 80

typedef struct	s_complex
{
	double re;
	double im;
}				t_complex;
typedef struct	s_color
{
	unsigned char b;
	unsigned char g;
	unsigned char r;
	unsigned char a;
}				t_color;
typedef struct	s_all
{
	int			bits_pp;
	int			endian;
	t_complex	factor;
	t_complex	c;
	t_complex	min;
	t_complex	max;
	void		*ptr_init;
	void		*ptr_win;
	void		*ptr_img;
	int			size_l;
	t_color		*str_pxs;
}				t_all;
#endif
