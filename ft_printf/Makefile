# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: celva <celva@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/01 12:51:03 by celva             #+#    #+#              #
#    Updated: 2019/12/30 14:40:49 by celva            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCDIR = srcs/
OBJDIR = objs/
INCDIR = includes/

SRCS =	ft_printf.c \
		parsing_flags.c \
		parsing_type2.c \
		parsing_hashtag.c \
		parsing_type.c \
		float.c \
		insert_accuracy.c \
		line_creation.c \
		parsing_flags_main.c \
		insert_w_pars_spec.c \
		parsing_type3.c \
		f_parsing_type.c \
		basic_processing.c

OBJECTS = $(addprefix $(OBJDIR), $(SRCS:.c=.o))

LIBDIR = libft/
FTLIB = $(addprefix $(LIBDIR), libft.a)
FTINC = -I $(LIBDIR)/includes
FTLNK = -L $(LIBDIR)

FLAGS = -Wall -Wextra -Werror

all: obj $(FTLIB) $(NAME)

obj:
	mkdir -p $(OBJDIR)

$(FTLIB):
		make -C $(LIBDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	gcc $(FLAGS) -I $(INCDIR) $(FTINC) -o $@ -c $<

$(NAME): $(OBJECTS)
		cp libft/libft.a ./$(NAME)
		ar rc $(NAME) $(OBJECTS)
		ranlib $(NAME)

clean:
		/bin/rm -rf $(OBJDIR)
		make -C $(LIBDIR) clean

fclean: clean
		/bin/rm -f $(NAME)
		make -C $(LIBDIR) fclean

re:		fclean all

.PHONY: clean fclean all re
