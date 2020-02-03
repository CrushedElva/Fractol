# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: celva <celva@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/14 16:14:00 by celva             #+#    #+#              #
#    Updated: 2020/01/28 16:17:38 by celva            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCDIR = srcs/
OBJDIR = objs/
INCDIR = includes/

SRCS = fractol.c

OBJECTS = $(addprefix $(OBJDIR), $(SRCS:.c=.o))

MLXDIR = mlx/
MLXLIB = $(addprefix $(MLXDIR), mlx.a)
MLXINC = -I $(MLXDIR)
MLXLNK = -L $(MLXDIR) -l mlx -framework OpenGL -framework AppKit

FTDIR = ft_printf/
FTLIB = $(addprefix $(FTDIR), libftprintf.a)
FTINC = -I $(FTDIR)/includes -I $(FTDIR)/libft/includes/
FTLNK = -L $(FTDIR)

all: obj $(FTLIB) $(NAME)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	gcc -g $(MLXINC) $(FTINC) -I $(INCDIR) -o $@ -c $<

$(FTLIB):
	make -C $(FTDIR)

$(MLXLIB):
	make -sC $(MLXDIR)

$(NAME): $(OBJECTS)
	gcc -g $(OBJECTS) $(MLXLNK) $(FTLNK) $(FTLIB) -lm -o $(NAME) -framework OpenCL

clean: 
	@/bin/rm -rf $(OBJDIR)
	@make -C $(FTDIR) clean
	@make -C $(MLXDIR) clean

fclean: clean
	@/bin/rm -rf $(NAME)
	@make -C $(FTDIR) fclean

re: fclean all

.PHONY: all obj clean fclean re
