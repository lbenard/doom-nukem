# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/21 19:33:38 by lbenard           #+#    #+#              #
#    Updated: 2019/12/19 23:34:00 by lbenard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	doom-nukem
SRCS_LIST		=	main.c																		\
																								\
					engine/array/array.c														\
					engine/array/init.c															\
					engine/array/destroy.c														\
																								\
					engine/ascii_font/ascii_font.c												\
					engine/ascii_font/init.c													\
					engine/ascii_font/destroy.c													\
																								\
					engine/blend/add.c															\
					engine/blend/colorize.c														\
																								\
					engine/controller/xbox/perpendicular_axis.c									\
																								\
					engine/cursor/cursor.c														\
					engine/cursor/cursor_from_file.c											\
					engine/cursor/init.c														\
					engine/cursor/init_from_file.c												\
					engine/cursor/set_visibility.c												\
					engine/cursor/destroy.c														\
																								\
					engine/delta/get_delta_ptr.c												\
					engine/delta/get_last_delta.c												\
					engine/delta/get_wall_time.c												\
					engine/delta/set_last_delta.c												\
																								\
					engine/entities/entity_list/entity_list.c									\
					engine/entities/entity_list/init.c											\
					engine/entities/entity_list/add_entity.c									\
					engine/entities/entity_list/update.c										\
					engine/entities/entity_list/destroy.c										\
																								\
					engine/entities/entity_node/new.c											\
					engine/entities/entity_node/entity_from_node.c								\
					engine/entities/entity_node/free.c											\
																								\
					engine/entities/entity/init.c												\
					engine/entities/entity/init_default.c										\
					engine/entities/entity/vtable.c												\
																								\
					engine/error/throw_error_errno.c											\
					engine/error/throw_error_str.c												\
					engine/error/throw_error.c													\
					engine/error/throw_result_str.c												\
					engine/error/throw_result.c													\
																								\
					engine/event/callback_node/new.c											\
					engine/event/callback_node/free.c											\
																								\
					engine/event/event_handler/event_handler.c									\
					engine/event/event_handler/init.c											\
					engine/event/event_handler/add_callback.c									\
					engine/event/event_handler/add_sub_handler.c								\
					engine/event/event_handler/remove_sub_handler.c								\
					engine/event/event_handler/call.c											\
					engine/event/event_handler/destroy.c										\
																								\
					engine/frame/frame.c														\
					engine/frame/frame_from_file.c												\
					engine/frame/init.c															\
					engine/frame/init_from_file.c												\
					engine/frame/update.c														\
					engine/frame/clear.c														\
					engine/frame/fill.c															\
					engine/frame/fill_blend.c													\
					engine/frame/layer.c														\
					engine/frame/layer_opaque.c													\
					engine/frame/coordinates.c													\
					engine/frame/ft_frame_transform_default.c									\
					engine/frame/ft_frame_transform_position.c									\
					engine/frame/ft_frame_transform.c											\
					engine/frame/layer_transform.c												\
					engine/frame/destroy.c														\
																								\
					engine/game/game.c															\
					engine/game/singleton.c														\
					engine/game/start.c															\
					engine/game/set_scene.c														\
					engine/game/loop.c															\
					engine/game/close.c															\
					engine/game/stop.c															\
																								\
					engine/input/ft_key_event.c													\
					engine/input/ft_mouse_event.c												\
					engine/input/ft_stick_event.c												\
					engine/input/ft_button_event.c												\
					engine/input/ft_input_set.c													\
					engine/input/input_set_get_uid.c											\
					engine/input/input.c														\
					engine/input/init.c															\
					engine/input/register.c														\
					engine/input/get_id.c														\
					engine/input/attach.c														\
					engine/input/get.c															\
					engine/input/update.c														\
					engine/input/destroy.c														\
																								\
					engine/lookup_table/cosine.c												\
					engine/lookup_table/sine.c													\
					engine/lookup_table/tangent.c												\
																								\
					engine/map/texture_node.c													\
					engine/map/init_texture_node.c												\
					engine/map/texture_from_key.c												\
					engine/map/destroy_texture_node.c											\
					engine/map/free_texture_list.c												\
					engine/map/block_node.c														\
					engine/map/init_block_node.c												\
					engine/map/block_from_key.c													\
					engine/map/destroy_block_node.c												\
					engine/map/free_block_list.c												\
					engine/map/map.c															\
					engine/map/init.c															\
					engine/map/parse_texture_list.c												\
					engine/map/parse_block_list.c												\
					engine/map/parse_size.c														\
					engine/map/parse_map.c														\
					engine/map/parse_player.c													\
					engine/map/destroy.c														\
																								\
					engine/parsing/dn_read_file.c												\
					engine/parsing/dn_is_flag_correct.c											\
					engine/parsing/dn_is_kv_correct.c											\
					engine/parsing/dn_is_line_correct.c											\
					engine/parsing/dn_new_flag.c												\
					engine/parsing/dn_select_flag.c												\
					engine/parsing/dn_get_key.c													\
					engine/parsing/dn_get_value.c												\
					engine/parsing/dn_get_values.c												\
					engine/parsing/dn_free_values.c												\
					engine/parsing/dn_strsplit_length.c											\
																								\
					engine/raycasting/angle/ft.c												\
					engine/raycasting/ray/ft.c													\
					engine/raycasting/ray/is_ray_in_map.c										\
					engine/raycasting/ray/ray_hitting_texture.c									\
					engine/raycasting/raycasting/raycasting.c									\
					engine/raycasting/raycasting/init.c											\
					engine/raycasting/raycasting/update.c										\
					engine/raycasting/raycasting/find_obstacle.c								\
					engine/raycasting/raycasting/destroy.c										\
																								\
					engine/sfml/image/image.c													\
					engine/sfml/image/init.c													\
					engine/sfml/image/destroy.c													\
					engine/sfml/render_texture/render_texture.c									\
					engine/sfml/render_texture/init.c											\
					engine/sfml/render_texture/destroy.c										\
					engine/sfml/sprite/sprite.c													\
					engine/sfml/sprite/init.c													\
					engine/sfml/sprite/destroy.c												\
																								\
					engine/render_utils/row.c													\
					engine/render_utils/column.c												\
					engine/render_utils/line.c													\
																								\
					engine/scene/init.c															\
					engine/scene/destroy.c														\
																								\
					engine/text/text.c															\
					engine/text/init.c															\
					engine/text/set.c															\
					engine/text/set_ref.c														\
					engine/text/ft_text_settings.c												\
					engine/text/render.c														\
					engine/text/destroy.c														\
																								\
					engine/window/window.c														\
					engine/window/init.c														\
					engine/window/update.c														\
					engine/window/is_running.c													\
					engine/window/is_focused.c													\
					engine/window/set_name.c													\
					engine/window/close.c														\
					engine/window/destroy.c														\
																								\
					game/entities/list/player/ft_corners.c										\
					game/entities/list/player/player_entity.c									\
					game/entities/list/player/init.c											\
					game/entities/list/player/update.c											\
					game/entities/list/player/is_colliding.c									\
					game/entities/list/player/is_vertical_collide.c								\
					game/entities/list/player/is_horizontal_collide.c							\
					game/entities/list/player/is_corner_collide.c								\
					game/entities/list/player/north_east_rebound.c								\
					game/entities/list/player/south_east_rebound.c								\
					game/entities/list/player/south_west_rebound.c								\
					game/entities/list/player/north_west_rebound.c								\
					game/entities/list/player/destroy.c											\
																								\
					game/entities/list/button/button_entity.c									\
					game/entities/list/button/dynamic_button_entity.c							\
					game/entities/list/button/init.c											\
					game/entities/list/button/init_dynamic.c									\
					game/entities/list/button/update.c											\
					game/entities/list/button/render.c											\
					game/entities/list/button/destroy.c											\
																								\
					game/entities/list/checkbox/checkbox_entity.c								\
					game/entities/list/checkbox/init.c											\
					game/entities/list/checkbox/update.c										\
					game/entities/list/checkbox/render.c										\
					game/entities/list/checkbox/destroy.c										\
																								\
					game/entities/list/editor_camera/editor_camera_entity.c						\
					game/entities/list/editor_camera/init.c										\
					game/entities/list/editor_camera/update.c									\
					game/entities/list/editor_camera/destroy.c									\
					game/entities/list/editor_camera/new_camera_zoom_event.c					\
																								\
					game/entities/list/editor_component/init.c									\
					game/entities/list/editor_component/update.c								\
					game/entities/list/editor_component/camera_pos.c							\
					game/entities/list/editor_component/destroy.c								\
																								\
					game/entities/list/editor_grid_component/editor_grid_component_entity.c		\
					game/entities/list/editor_grid_component/init.c								\
					game/entities/list/editor_grid_component/update.c							\
					game/entities/list/editor_grid_component/render.c							\
					game/entities/list/editor_grid_component/destroy.c							\
																								\
					game/entities/list/editor_vertex_component/editor_vertex_component_entity.c	\
					game/entities/list/editor_vertex_component/init.c							\
					game/entities/list/editor_vertex_component/update.c							\
					game/entities/list/editor_vertex_component/render.c							\
					game/entities/list/editor_vertex_component/is_selected.c					\
					game/entities/list/editor_vertex_component/destroy.c						\
																								\
					game/entities/list/image/image_entity_from_file.c							\
					game/entities/list/image/init_from_file.c									\
					game/entities/list/image/update.c											\
					game/entities/list/image/render.c											\
					game/entities/list/image/destroy.c											\
																								\
					game/entities/list/minimap/minimap_entity.c									\
					game/entities/list/minimap/init.c											\
					game/entities/list/minimap/update.c											\
					game/entities/list/minimap/render.c											\
					game/entities/list/minimap/destroy.c										\
																								\
					game/events/close_game_event.c												\
																								\
					game/scenes/list/benchmark/benchmark_scene.c								\
					game/scenes/list/benchmark/init.c											\
					game/scenes/list/benchmark/update.c											\
					game/scenes/list/benchmark/render.c											\
					game/scenes/list/benchmark/destroy.c										\
																								\
					game/scenes/list/editor/editor_scene.c										\
					game/scenes/list/editor/init.c												\
					game/scenes/list/editor/update.c											\
					game/scenes/list/editor/render.c											\
					game/scenes/list/editor/destroy.c											\
																								\
					game/scenes/list/menu/menu_scene.c											\
					game/scenes/list/menu/init.c												\
					game/scenes/list/menu/update.c												\
					game/scenes/list/menu/render.c												\
					game/scenes/list/menu/destroy.c												\
																								\
					game/scenes/list/raycasting/raycasting_scene.c								\
					game/scenes/list/raycasting/init.c											\
					game/scenes/list/raycasting/update.c										\
					game/scenes/list/raycasting/render.c										\
					game/scenes/list/raycasting/destroy.c

UNAME			=	$(shell uname)

SRCS_FOLDER		=	./srcs/
SRCS			=	$(addprefix $(SRCS_FOLDER), $(SRCS_LIST))
OBJS_LIST		=	$(SRCS_LIST:.c=.o)
OBJS_FOLDER		=	./objs/
OBJS			=	$(addprefix $(OBJS_FOLDER), $(OBJS_LIST))

LIBFT_FOLDER	=	libft
LIBFT			=	$(LIBFT_FOLDER)/libft.a

ifneq ($(UNAME), Linux)
	SFML_FOLDER		=	SFML
	SFML_ABSOLUTE	=	$(addprefix $(shell pwd)/, $(SFML_FOLDER))
	CSFML_FOLDER	=	CSFML
	CSFML			=	$(CSFML_FOLDER)/lib
endif

CXX				=	gcc
LD				=	gcc

INCLUDES		:=	-I includes					\
					-I $(LIBFT_FOLDER)/includes
LIB_FOLDERS		:=	-L$(LIBFT_FOLDER)

ifneq ($(UNAME), Linux)
	INCLUDES		:=	$(INCLUDES) -I $(CSFML_FOLDER)/include
	LIB_FOLDERS		:=	$(LIB_FOLDERS) -L $(CSFML_FOLDER)/lib
endif

LIBS			=	-lft				\
					-lm					\
					-lcsfml-graphics	\
					-lcsfml-window		\
					-lcsfml-system		\
					-lcsfml-audio

# CFLAGS			=	-Wall -Wextra -Werror -O3 -Ofast -flto -g
CFLAGS			=	-Wall -Wextra -Werror -O3 -Ofast -flto -Wno-deprecated

LDFLAGS			:=	$(LIB_FOLDERS) $(LIBS)
ifneq ($(UNAME), Linux)
	LDFLAGS			:=	$(LDFLAGS) \
						-Wl,-rpath,$(SFML_FOLDER)/extlibs/libs-osx/Frameworks
	RUN_PREFIX		:=	LD_LIBRARY_PATH=CSFML/lib:SFML/lib
endif

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

all: $(CSFML) $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	@$(LD) $(OBJS) -o $(NAME) $(LDFLAGS)
	@printf "\e[0K$(PREFIX) done\n"

$(OBJS_FOLDER)%.o: $(SRCS_FOLDER)%.c
	@printf "$(PREFIX) $<\n"
	@mkdir -p $(dir $@)
	@gcc -c $< -o $@ $(INCLUDES) $(CFLAGS)
	@printf "\e[1A\e[0K"

run: all
	@$(RUN_PREFIX) ./$(NAME)

$(LIBFT):
	@printf "\e[0K"
	@printf "$(PREFIX) libft all\n";
	@make -C libft
	@printf "\e[2A\e[0K"
	@printf "$(PREFIX) libft all done\n";

$(CSFML):
	@printf "\e[0K"
	@printf "$(PREFIX) CSFML\n";
	@cd $(SFML_FOLDER); \
		cmake .; \
		make
	@cd $(CSFML_FOLDER); \
		cmake -DSFML_DIR=$(SFML_ABSOLUTE); \
		make
	@printf "\e[1A\e[0K"
	@printf "$(PREFIX) CSFML done\n";

libft-clean:
	@printf "\e[0K"
	@printf "$(PREFIX) libft clean\n";
	@make -C $(LIBFT_FOLDER) clean >/dev/null
	@printf "\e[1A\e[0K"
	@printf "$(PREFIX) libft clean done\n";

libft-fclean:
	@printf "\e[0K"
	@printf "$(PREFIX) libft fclean\n";
	@make -C $(LIBFT_FOLDER) fclean >/dev/null
	@printf "\e[1A\e[0K"
	@printf "$(PREFIX) libft fclean done\n";

csfml-clean:
	@printf "\e[0K"
	@printf "$(PREFIX) CSFML clean\n";
	@if test "$(CSFML_FOLDER)" != "" ; then \
		make -C $(CSFML_FOLDER) clean >/dev/null; \
	fi
	@printf "\e[1A\e[0K"
	@printf "$(PREFIX) CSFML clean done\n";

csfml-fclean:
	@printf "\e[0K"
	@printf "$(PREFIX) CSFML fclean\n";
	@if test "$(CSFML_FOLDER)" != ""; then \
		make -C $(CSFML_FOLDER) clean >/dev/null; \
		rm -rf $(CSFML_FOLDER)/lib; \
	fi
	@printf "\e[1A\e[0K"
	@printf "$(PREFIX) CSFML fclean done\n";

clean: libft-clean csfml-clean
	@printf "\e[0K"
	@printf "$(PREFIX) cleaned object files\n"
	@rm -rf $(OBJS_FOLDER)

fclean: clean libft-fclean csfml-fclean
	@printf "\e[0K"
	@printf "$(PREFIX) cleaned binary file\n"
	@rm -rf $(NAME)

separator:
	@printf "\n"

re: fclean separator $(LIBFT) all

.PHONY: norm libft-clean libft-fclean csfml-clean csfml-fclean clean fclean re
