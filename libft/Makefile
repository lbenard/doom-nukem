# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/05 18:02:14 by lbenard           #+#    #+#              #
#    Updated: 2019/10/10 21:43:40 by lbenard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libft.a
SRCS_LIST		=	containers/list/init_list_head.c		\
					containers/list/list_foreach.c			\
					containers/list/list_is_last.c			\
					containers/list/list_is_empty.c			\
					containers/list/list_size.c				\
					containers/list/list_add.c				\
					containers/list/list_add_entry.c		\
					containers/list/list_add_tail.c			\
					containers/list/list_del.c				\
					containers/list/list_del_entry.c		\
					containers/list/list_move.c				\
					containers/list/list_move_tail.c		\
					containers/list/new_lst.c				\
					containers/list/new_lstcpy.c			\
					containers/list/new_lstmap.c			\
					containers/list/lst_iter.c				\
					containers/list/lst_last.c				\
					containers/list/lst_find.c				\
					containers/list/lst_content_find.c		\
					containers/list/lst_add.c				\
					containers/list/lst_push_back.c			\
					containers/list/lst_del_one.c			\
					containers/list/lst_del.c				\
					containers/list/lst_remove.c			\
					containers/list/lst_strjoin.c			\
					containers/list/free_lst.c				\
					containers/vector/init_vector.c			\
					containers/vector/init_vector_data.c	\
					containers/vector/vector_reserve.c		\
					containers/vector/vector_shrink.c		\
					containers/vector/vector_double.c		\
					containers/vector/vector_clear.c		\
					containers/vector/vector_insert.c		\
					containers/vector/vector_push_back.c	\
					containers/vector/destroy_vector.c		\
					colors/rgb/ft_rgb.c						\
					colors/rgb/ft_rgb_int.c					\
					colors/rgb/ft_rgb_hsv.c					\
					colors/rgb/rgb_to_int.c					\
					colors/rgba/ft_rgba.c					\
					colors/rgba/ft_rgba_rgb.c				\
					colors/rgba/ft_rgba_int.c				\
					colors/rgba/ft_rgba_hsv.c				\
					colors/hsv/ft_hsv.c						\
					colors/hsv/hsv_to_int.c					\
					sizes/ft_usize.c						\
					sizes/ft_isize.c						\
					maths/maths/ft_abs.c					\
					maths/maths/ft_max.c					\
					maths/maths/ft_min.c					\
					maths/maths/ft_atoi.c					\
					maths/maths/ft_atof.c					\
					maths/maths/ft_itoa.c					\
					maths/maths/ft_nblen.c					\
					maths/transform/ft_transform.c			\
					maths/transform/ft_transform_default.c	\
					maths/vec2i/ft_vec2i.c					\
					maths/vec3i/ft_vec3i.c					\
					maths/vec4i/ft_vec4i.c					\
					maths/vec2f/ft_vec2f.c					\
					maths/vec2f/vec2f_dot.c					\
					maths/vec2f/vec2f_scalar.c				\
					maths/vec2f/vec2f_distance.c			\
					maths/vec3f/ft_vec3f.c					\
					maths/vec3f/vec3f_dot.c					\
					maths/vec3f/vec3f_scalar.c				\
					maths/vec3f/vec3f_distance.c			\
					maths/vec3f/vec3f_normalize.c			\
					maths/vec3f/vec3f_to_vec2f.c			\
					maths/vec3f/vec3f_to_vec4f.c			\
					maths/vec4f/ft_vec4f.c					\
					maths/vec4f/vec4f_dot.c					\
					maths/vec4f/vec4f_scalar.c				\
					maths/vec4f/vec4f_to_vec3f.c			\
					maths/vec2d/ft_vec2d.c					\
					maths/vec2d/vec2d_dot.c					\
					maths/vec2d/vec2d_scalar.c				\
					maths/vec2d/vec2d_distance.c			\
					maths/vec3d/ft_vec3d.c					\
					maths/vec3d/vec3d_dot.c					\
					maths/vec3d/vec3d_scalar.c				\
					maths/vec3d/vec3d_distance.c			\
					maths/vec3d/vec3d_to_vec2d.c			\
					maths/vec3d/vec3d_to_vec4d.c			\
					maths/vec4d/ft_vec4d.c					\
					maths/vec4d/vec4d_dot.c					\
					maths/vec4d/vec4d_scalar.c				\
					maths/vec4d/vec4d_to_vec3d.c			\
					maths/vec2ld/ft_vec2ld.c				\
					maths/vec2ld/vec2ld_dot.c				\
					maths/vec2ld/vec2ld_scalar.c			\
					maths/vec2ld/vec2ld_distance.c			\
					maths/vec3ld/ft_vec3ld.c				\
					maths/vec3ld/vec3ld_dot.c				\
					maths/vec3ld/vec3ld_scalar.c			\
					maths/vec3ld/vec3ld_distance.c			\
					maths/vec3ld/vec3ld_to_vec2ld.c			\
					maths/vec3ld/vec3ld_to_vec4ld.c			\
					maths/vec4ld/ft_vec4ld.c				\
					maths/vec4ld/vec4ld_dot.c				\
					maths/vec4ld/vec4ld_scalar.c			\
					maths/vec4ld/vec4ld_to_vec3ld.c			\
					maths/mat3f/ft_mat3f.c					\
					maths/mat3f/ft_mat3f_identity.c			\
					maths/mat3f/mat3f_x_mat3f.c				\
					maths/mat3f/mat3f_x_vec3f.c				\
					maths/mat4f/ft_mat4f.c					\
					maths/mat4f/ft_mat4f_identity.c			\
					maths/mat4f/ft_mat4f_translation.c		\
					maths/mat4f/ft_mat4f_scaling.c			\
					maths/mat4f/ft_mat4f_rotation.c			\
					maths/mat4f/mat4f_x_mat4f.c				\
					maths/mat4f/mat4f_x_vec4f.c				\
					ft/io/ft_putchar.c						\
					ft/io/ft_putstr.c						\
					ft/io/ft_putendl.c						\
					ft/io/ft_putnbr.c						\
					ft/io/ft_putchar_fd.c					\
					ft/io/ft_putstr_fd.c					\
					ft/io/ft_putendl_fd.c					\
					ft/io/ft_putnbr_fd.c					\
					ft/mem/ft_memset.c						\
					ft/mem/ft_bzero.c						\
					ft/mem/ft_memcpy.c						\
					ft/mem/ft_memccpy.c						\
					ft/mem/ft_memmove.c						\
					ft/mem/ft_memchr.c						\
					ft/mem/ft_memcmp.c						\
					ft/mem/ft_memalloc.c					\
					ft/mem/ft_memdel.c						\
					ft/str/ft_strlen.c						\
					ft/str/ft_strnlen.c						\
					ft/str/ft_strdup.c						\
					ft/str/ft_strndup.c						\
					ft/str/ft_strcpy.c						\
					ft/str/ft_strncpy.c						\
					ft/str/ft_strcat.c						\
					ft/str/ft_strncat.c						\
					ft/str/ft_strlcat.c						\
					ft/str/ft_strchr.c						\
					ft/str/ft_strrchr.c						\
					ft/str/ft_strstr.c						\
					ft/str/ft_strnstr.c						\
					ft/str/ft_strcmp.c						\
					ft/str/ft_strncmp.c						\
					ft/str/ft_strnew.c						\
					ft/str/ft_strdel.c						\
					ft/str/ft_strclr.c						\
					ft/str/ft_striter.c						\
					ft/str/ft_striteri.c					\
					ft/str/ft_strmap.c						\
					ft/str/ft_strmapi.c						\
					ft/str/ft_strequ.c						\
					ft/str/ft_strnequ.c						\
					ft/str/ft_strsub.c						\
					ft/str/ft_strjoin.c						\
					ft/str/ft_strtrim.c						\
					ft/str/ft_strsplit.c					\
					ft/str/ft_strcount.c					\
					ft/str/ft_getline.c						\
					ft/str/ft_skipchr.c						\
					ft/str/ft_nextline.c					\
					ft/str/ft_isalpha.c						\
					ft/str/ft_isdigit.c						\
					ft/str/ft_isalnum.c						\
					ft/str/ft_isascii.c						\
					ft/str/ft_isprint.c						\
					ft/str/ft_isspace.c						\
					ft/str/ft_isupper.c						\
					ft/str/ft_islower.c						\
					ft/str/ft_isnumber.c					\
					ft/str/ft_toupper.c						\
					ft/str/ft_tolower.c						\
					ft/str/ft_get_next_line.c

SRCS_FOLDER		=	./srcs/
SRCS			=	$(addprefix $(SRCS_FOLDER), $(SRCS_LIST))
OBJS_LIST		=	$(SRCS_LIST:.c=.o)
OBJS_FOLDER		=	./objs/
OBJS			=	$(addprefix $(OBJS_FOLDER), $(OBJS_LIST))
INCLUDES		=	-I includes/
CFLAGS			=	-Wall -Wextra -Werror -O3 -Ofast -flto

# Colors
BOLD			=	\e[1m
DIM				=	\e[2m
ITALIC			=	\e[3m
UNDERLINED		=	\e[4m

BLACK			=	\e[30m
RED				=	\e[31m
GREEN			=	\e[32m
YELLOW			=	\e[33m
BLUE			=	\e[34m
MAGENTA			=	\e[35m
CYAN			=	\e[36m
LIGHT_GRAY		=	\e[37m
DARK_GRAY		=	\e[90m
LIGHT_RED		=	\e[91m
LIGHT_GREEN		=	\e[92m
LIGHT_YELLOW	=	\e[93m
LIGHT_BLUE		=	\e[94m
LIGHT_MAGENTA	=	\e[95m
LIGHT_CYAN		=	\e[96m
WHITE			=	\e[97m
RESET			=	\e[0m

PREFIX			=	$(BOLD)$(LIGHT_CYAN)[$(NAME)]$(RESET):

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@ranlib $(NAME)
	@printf "$(PREFIX) done\n"

$(OBJS_FOLDER)%.o: $(SRCS_FOLDER)%.c
	@printf "$(PREFIX) $(shell basename $<)\n"
	@mkdir -p $(dir $@)
	@gcc -c $< -o $@ $(INCLUDES) $(CFLAGS)
	@printf "\e[1A\e[0K"

clean:
	@printf "$(PREFIX) clean\n"
	@rm -rf $(OBJS_FOLDER)

fclean:
	@rm -rf $(OBJS_FOLDER) $(NAME)
	@printf "$(PREFIX) fclean\n"

re: fclean all

.PHONY: clean fclean re
