# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: celva <celva@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/03 14:02:51 by dkathlee          #+#    #+#              #
#    Updated: 2019/12/25 11:50:11 by celva            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCDIR = srcs/
OBJDIR = objs/
INCDIR = includes/

SRCS =	ft_atoi.c ft_btree_apply_infix.c ft_btree_apply_prefix.c \
	ft_btree_apply_suffix.c ft_btree_create_node.c \
	ft_btree_insert_data.c ft_btree_level_count.c \
	ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	ft_isdigit.c ft_islower.c ft_isprint.c ft_isupper.c \
	ft_itoa.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c \
	ft_lstmap.c ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memchr.c \
	ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c \
	ft_powi.c ft_powr.c ft_putchar.c ft_putchar_fd.c ft_putendl.c \
	ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c \
	ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c \
	ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c \
	ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c \
	ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c \
	ft_strnew.c ft_strnlen.c ft_strnstr.c ft_strrchr.c ft_strsplit.c \
	ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c \
	ft_realloc.c ft_dlst_create_elem.c ft_dlst_create_elemc.c \
	ft_dlst_push_front.c ft_dlst_push_back.c ft_dlst_deli.c ft_dlst_delete.c \
	ft_dlst_geti.c ft_dlst_popi.c ft_dlst_len.c ft_intlen.c ft_itoa_ull.c \
	ft_str_symb.c ft_strjoin_del.c ft_memjoin.c ft_memjoin_del.c \
	get_next_line.c ft_index_simb.c

OBJECTS = $(addprefix $(OBJDIR), $(SRCS:.c=.o))

FLAGS = -Wall -Wextra -Werror

all: obj $(NAME)

obj: 
	@mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	@gcc $(FLAGS) -I $(INCDIR) -o $@ -c $<

$(NAME): $(OBJECTS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)

clean:
	@/bin/rm -rf $(OBJECTS)

fclean: clean
	@/bin/rm -f $(NAME)

re:	@fclean all
