# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/21 19:33:38 by lbenard           #+#    #+#              #
#    Updated: 2020/08/10 22:24:34 by lbenard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	doom-nukem
SRCS_LIST		=	main.c																			\
																									\
					engine/array/array.c															\
					engine/array/init.c																\
					engine/array/destroy.c															\
																									\
					engine/a_star/init.c															\
					engine/a_star/a_star.c															\
					engine/a_star/analyse.c															\
					engine/a_star/child.c															\
					engine/a_star/list.c															\
					engine/a_star/node.c															\
																									\
					engine/ascii_font/ascii_font.c													\
					engine/ascii_font/init.c														\
					engine/ascii_font/destroy.c														\
																									\
					engine/blend/add.c																\
					engine/blend/colorize.c															\
					engine/blend/invert.c															\
																									\
					engine/controller/xbox/perpendicular_axis.c										\
																									\
					engine/cursor/cursor.c															\
					engine/cursor/cursor_from_file.c												\
					engine/cursor/init.c															\
					engine/cursor/init_from_file.c													\
					engine/cursor/set_visibility.c													\
					engine/cursor/set_pos.c															\
					engine/cursor/destroy.c															\
																									\
					engine/delta/get_delta_ptr.c													\
					engine/delta/get_last_delta.c													\
					engine/delta/get_wall_time.c													\
					engine/delta/set_last_delta.c													\
																									\
					engine/entity_index/new_entity_descriptor_node.c								\
					engine/entity_index/entity_index.c												\
					engine/entity_index/init.c														\
					engine/entity_index/register.c													\
					engine/entity_index/get.c														\
					engine/entity_index/destroy.c													\
																									\
					engine/entities/entity_list/entity_list.c										\
					engine/entities/entity_list/init.c												\
					engine/entities/entity_list/add_entity.c										\
					engine/entities/entity_list/add_entity_ref.c									\
					engine/entities/entity_list/remove.c											\
					engine/entities/entity_list/update.c											\
					engine/entities/entity_list/destroy.c											\
																									\
					engine/entities/entity_node/new.c												\
					engine/entities/entity_node/new_ref.c											\
					engine/entities/entity_node/entity_from_node.c									\
					engine/entities/entity_node/free.c												\
																									\
					engine/entities/entity/init.c													\
					engine/entities/entity/init_default.c											\
					engine/entities/entity/vtable.c													\
																									\
					engine/error/throw_error_errno.c												\
					engine/error/throw_error_str.c													\
					engine/error/throw_error.c														\
					engine/error/throw_result_str.c													\
					engine/error/throw_result.c														\
																									\
					engine/event/callback_node/new.c												\
					engine/event/callback_node/free.c												\
																									\
					engine/event/event_handler/event_handler.c										\
					engine/event/event_handler/init.c												\
					engine/event/event_handler/add_callback.c										\
					engine/event/event_handler/add_sub_handler.c									\
					engine/event/event_handler/remove_sub_handler.c									\
					engine/event/event_handler/call.c												\
					engine/event/event_handler/destroy.c											\
																									\
					engine/frame/frame.c															\
					engine/frame/frame_from_file.c													\
					engine/frame/init.c																\
					engine/frame/init_from_file.c													\
					engine/frame/update.c															\
					engine/frame/clear.c															\
					engine/frame/fill.c																\
					engine/frame/fill_blend.c														\
					engine/frame/layer.c															\
					engine/frame/layer_opaque.c														\
					engine/frame/layer_add.c														\
					engine/frame/coordinates.c														\
					engine/frame/ft_frame_transform_default.c										\
					engine/frame/ft_frame_transform_position.c										\
					engine/frame/ft_frame_transform.c												\
					engine/frame/layer_transform.c													\
					engine/frame/layer_transform_add.c												\
					engine/frame/destroy.c															\
																									\
					engine/input/ft_key_event.c														\
					engine/input/ft_mouse_event.c													\
					engine/input/ft_stick_event.c													\
					engine/input/ft_button_event.c													\
					engine/input/ft_input_set.c														\
					engine/input/input_set_get_uid.c												\
					engine/input/input.c															\
					engine/input/init.c																\
					engine/input/register.c															\
					engine/input/get_id.c															\
					engine/input/attach.c															\
					engine/input/get.c																\
					engine/input/update.c															\
					engine/input/destroy.c															\
					engine/input/new_event_update_event.c											\
																									\
					engine/lookup_table/cosine.c													\
					engine/lookup_table/sine.c														\
					engine/lookup_table/tangent.c													\
																									\
					engine/map/block_from_key.c														\
					engine/map/map_entity_node.c													\
					engine/map/init_map_entity_node.c												\
					engine/map/entity_from_name.c													\
					engine/map/destroy_map_entity_node.c											\
					engine/map/free_entity_list.c													\
					engine/map/map.c																\
					engine/map/init.c																\
					engine/map/parse_size.c															\
					engine/map/parse_map.c															\
					engine/map/parse_player.c														\
					engine/map/parse_entities.c														\
					engine/map/destroy.c															\
																									\
					engine/parsing/dn_read_file.c													\
					engine/parsing/dn_is_flag_correct.c												\
					engine/parsing/dn_is_kv_correct.c												\
					engine/parsing/dn_is_line_correct.c												\
					engine/parsing/dn_new_flag.c													\
					engine/parsing/dn_select_flag.c													\
					engine/parsing/dn_get_key.c														\
					engine/parsing/dn_get_value.c													\
					engine/parsing/dn_get_values.c													\
					engine/parsing/dn_free_values.c													\
					engine/parsing/dn_strsplit_length.c												\
																									\
					engine/sfml/image/image.c														\
					engine/sfml/image/init.c														\
					engine/sfml/image/destroy.c														\
					engine/sfml/render_texture/render_texture.c										\
					engine/sfml/render_texture/init.c												\
					engine/sfml/render_texture/destroy.c											\
					engine/sfml/sprite/sprite.c														\
					engine/sfml/sprite/init.c														\
					engine/sfml/sprite/destroy.c													\
																									\
					engine/shape/new_vertex_node.c													\
					engine/shape/vertices_side.c													\
					engine/shape/shape.c															\
					engine/shape/init.c																\
					engine/shape/push_vertex.c														\
					engine/shape/update_box.c														\
					engine/shape/sort.c																\
					engine/shape/get_center.c														\
					engine/shape/is_point_in_shape.c												\
					engine/shape/render.c															\
					engine/shape/destroy.c															\
																									\
					engine/sound/sound.c															\
					engine/sound/init.c																\
					engine/sound/play.c																\
					engine/sound/destroy.c															\
																									\
					engine/render_utils/row.c														\
					engine/render_utils/column.c													\
					engine/render_utils/line.c														\
																									\
					engine/scene/init.c																\
					engine/scene/destroy.c															\
																									\
					engine/text/text.c																\
					engine/text/init.c																\
					engine/text/set.c																\
					engine/text/set_ref.c															\
					engine/text/ft_text_settings.c													\
					engine/text/render.c															\
					engine/text/destroy.c															\
																									\
					engine/window/window.c															\
					engine/window/init.c															\
					engine/window/update.c															\
					engine/window/is_running.c														\
					engine/window/is_focused.c														\
					engine/window/set_name.c														\
					engine/window/get_mouse_pos.c													\
					engine/window/close.c															\
					engine/window/destroy.c															\
																									\
					game/game/game.c																\
					game/game/singleton.c															\
					game/game/start.c																\
					game/game/init_block_descriptors.c												\
					game/game/init_entity_descriptors.c												\
					game/game/set_scene.c															\
					game/game/loop.c																\
					game/game/close.c																\
					game/game/stop.c																\
																									\
					game/block_descriptor/block_descriptor.c										\
					game/block_descriptor/init.c													\
					game/block_descriptor/from_id.c													\
					game/block_descriptor/destroy.c													\
																									\
					game/entity_descriptor/entity_descriptor.c										\
					game/entity_descriptor/init.c													\
					game/entity_descriptor/from_name.c												\
					game/entity_descriptor/destroy.c												\
																									\
					game/animation/spritesheet.c													\
					game/animation/animation.c														\
																									\
					game/entities/list/player/ft_corners.c											\
					game/entities/list/player/player_entity.c										\
					game/entities/list/player/init.c												\
					game/entities/list/player/update.c												\
					game/entities/list/player/take_damage.c											\
					game/entities/list/player/is_colliding.c										\
					game/entities/list/player/is_vertical_collide.c									\
					game/entities/list/player/is_horizontal_collide.c								\
					game/entities/list/player/is_corner_collide.c									\
					game/entities/list/player/north_east_rebound.c									\
					game/entities/list/player/south_east_rebound.c									\
					game/entities/list/player/south_west_rebound.c									\
					game/entities/list/player/north_west_rebound.c									\
					game/entities/list/player/destroy.c												\
																									\
					game/entities/list/camera/camera_entity.c										\
					game/entities/list/camera/init.c												\
					game/entities/list/camera/update.c												\
					game/entities/list/camera/render.c												\
					game/entities/list/camera/destroy.c												\
																									\
					game/entities/list/button/button_entity.c										\
					game/entities/list/button/dynamic_button_entity.c								\
					game/entities/list/button/init.c												\
					game/entities/list/button/init_dynamic.c										\
					game/entities/list/button/update.c												\
					game/entities/list/button/render.c												\
					game/entities/list/button/destroy.c												\
																									\
					game/entities/list/checkbox/checkbox_entity.c									\
					game/entities/list/checkbox/checkbox_entity_base.c								\
					game/entities/list/checkbox/init.c												\
					game/entities/list/checkbox/init_base.c											\
					game/entities/list/checkbox/update.c											\
					game/entities/list/checkbox/render.c											\
					game/entities/list/checkbox/destroy.c											\
					game/entities/list/checkbox/ft_checkbox_position.c								\
					game/entities/list/checkbox/ft_checkbox_position_pos.c							\
					game/entities/list/checkbox/create.c											\
					game/entities/list/checkbox/create_relative.c									\
					game/entities/list/checkbox/create_relative_pos.c								\
					game/entities/list/checkbox/set_relative.c										\
					game/entities/list/checkbox/set_pos.c											\
					game/entities/list/checkbox/init_radio_group.c									\
					game/entities/list/checkbox/update_radio_group.c								\
					game/entities/list/checkbox/radio_group_set_active.c							\
																									\
					game/entities/list/editor/camera/editor_camera_entity.c							\
					game/entities/list/editor/camera/init.c											\
					game/entities/list/editor/camera/update.c										\
					game/entities/list/editor/camera/screen_to_editor_camera_pos.c					\
					game/entities/list/editor/camera/editor_camera_pos.c							\
					game/entities/list/editor/camera/editor_camera_pos_to_screen.c					\
					game/entities/list/editor/camera/transform_camera_pos.c							\
					game/entities/list/editor/camera/transform_screen_pos.c							\
					game/entities/list/editor/camera/destroy.c										\
					game/entities/list/editor/camera/new_editor_camera_zoom_event.c					\
																									\
					game/entities/list/editor/component/component_entity.c							\
					game/entities/list/editor/component/init.c										\
					game/entities/list/editor/component/update.c									\
					game/entities/list/editor/component/camera_pos.c								\
					game/entities/list/editor/component/screen_pos.c								\
					game/entities/list/editor/component/destroy.c									\
																									\
					game/entities/list/editor/grid_component/grid_component_entity.c				\
					game/entities/list/editor/grid_component/init.c									\
					game/entities/list/editor/grid_component/update.c								\
					game/entities/list/editor/grid_component/render.c								\
					game/entities/list/editor/grid_component/is_hovered.c							\
					game/entities/list/editor/grid_component/destroy.c								\
																									\
					game/entities/list/editor/player_component/player_component_entity.c			\
					game/entities/list/editor/player_component/init.c								\
					game/entities/list/editor/player_component/update.c								\
					game/entities/list/editor/player_component/render.c								\
					game/entities/list/editor/player_component/is_hovered.c							\
					game/entities/list/editor/player_component/destroy.c							\
																									\
					game/entities/list/editor/preview_checkbox/preview_checkbox_entity.c			\
					game/entities/list/editor/preview_checkbox/init.c								\
					game/entities/list/editor/preview_checkbox/update.c								\
					game/entities/list/editor/preview_checkbox/render.c								\
					game/entities/list/editor/preview_checkbox/destroy.c							\
																									\
					game/entities/list/editor/block_checkbox/block_checkbox_entity.c				\
					game/entities/list/editor/block_checkbox/init.c									\
					game/entities/list/editor/block_checkbox/update.c								\
					game/entities/list/editor/block_checkbox/render.c								\
					game/entities/list/editor/block_checkbox/destroy.c								\
					game/entities/list/editor/block_checkbox/create.c								\
					game/entities/list/editor/block_checkbox/set_relative.c							\
					game/entities/list/editor/block_checkbox/set_pos.c								\
																									\
					game/entities/list/editor/entity_checkbox/entity_checkbox_entity.c				\
					game/entities/list/editor/entity_checkbox/init.c								\
					game/entities/list/editor/entity_checkbox/update.c								\
					game/entities/list/editor/entity_checkbox/render.c								\
					game/entities/list/editor/entity_checkbox/destroy.c								\
					game/entities/list/editor/entity_checkbox/create.c								\
					game/entities/list/editor/entity_checkbox/set_relative.c						\
					game/entities/list/editor/entity_checkbox/set_pos.c								\
																									\
					game/entities/list/editor/block_component/block_component_entity.c				\
					game/entities/list/editor/block_component/init.c								\
					game/entities/list/editor/block_component/update.c								\
					game/entities/list/editor/block_component/render.c								\
					game/entities/list/editor/block_component/is_hovered.c							\
					game/entities/list/editor/block_component/destroy.c								\
																									\
					game/entities/list/editor/entity_component/entity_component_entity.c			\
					game/entities/list/editor/entity_component/init.c								\
					game/entities/list/editor/entity_component/update.c								\
					game/entities/list/editor/entity_component/render.c								\
					game/entities/list/editor/entity_component/is_hovered.c							\
					game/entities/list/editor/entity_component/destroy.c							\
																									\
					game/entities/list/image/image_entity_from_file.c								\
					game/entities/list/image/init_from_file.c										\
					game/entities/list/image/update.c												\
					game/entities/list/image/render.c												\
					game/entities/list/image/destroy.c												\
																									\
					game/entities/list/monster/ft_monster_stats.c									\
					game/entities/list/monster/monster_entity.c										\
					game/entities/list/monster/init.c												\
					game/entities/list/monster/update.c												\
					game/entities/list/monster/destroy.c											\
					game/entities/list/monster/orientate_sprite.c									\
					game/entities/list/monster/a_star_monster.c										\
																									\
					game/entities/list/onepunchman/onepunchman_entity.c								\
					game/entities/list/onepunchman/init.c											\
					game/entities/list/onepunchman/update.c											\
					game/entities/list/onepunchman/destroy.c										\
																									\
					game/entities/list/weird_alien/weird_alien_entity.c								\
					game/entities/list/weird_alien/init.c											\
					game/entities/list/weird_alien/update.c											\
					game/entities/list/weird_alien/destroy.c										\
																									\
					game/entities/list/ghast/ghast_entity.c											\
					game/entities/list/ghast/init.c													\
					game/entities/list/ghast/update.c												\
					game/entities/list/ghast/destroy.c												\
					game/entities/list/ghast/shot_fireball.c										\
																									\
					game/entities/list/fireball/fireball_entity.c									\
					game/entities/list/fireball/init.c												\
					game/entities/list/fireball/update.c											\
					game/entities/list/fireball/destroy.c											\
																									\
					game/entities/list/nyarlathotep/nyarlathotep_entity.c							\
					game/entities/list/nyarlathotep/init.c											\
					game/entities/list/nyarlathotep/update.c										\
					game/entities/list/nyarlathotep/destroy.c										\
					game/entities/list/nyarlathotep/rotate.c										\
																									\
					game/entities/list/sprite/sprite_entity.c										\
					game/entities/list/sprite/sprite_entity_size.c									\
					game/entities/list/sprite/init.c												\
					game/entities/list/sprite/init_size.c											\
					game/entities/list/sprite/destroy.c												\
					game/entities/list/sprite/update.c												\
					game/entities/list/sprite/vtable.c												\
																									\
					game/entities/list/weapon/ft_weapon_specs_default.c								\
					game/entities/list/weapon/weapon_entity.c										\
					game/entities/list/weapon/init.c												\
					game/entities/list/weapon/update.c												\
					game/entities/list/weapon/destroy.c												\
																									\
					game/entities/list/pistol/pistol_entity.c										\
					game/entities/list/pistol/init.c												\
					game/entities/list/pistol/update.c												\
					game/entities/list/pistol/destroy.c												\
																									\
					game/events/close_game_event.c													\
																									\
					game/scenes/list/editor/editor_scene.c											\
					game/scenes/list/editor/init.c													\
					game/scenes/list/editor/fill_from_map.c											\
					game/scenes/list/editor/update.c												\
					game/scenes/list/editor/render.c												\
					game/scenes/list/editor/export_map.c											\
					game/scenes/list/editor/add_block.c												\
					game/scenes/list/editor/add_entity.c											\
					game/scenes/list/editor/destroy.c												\
					game/scenes/list/editor/new_cursor_event.c										\
					game/scenes/list/editor/new_block_create_event.c								\
					game/scenes/list/editor/new_entity_create_event.c								\
																									\
					game/scenes/list/menu/menu_scene.c												\
					game/scenes/list/menu/init.c													\
					game/scenes/list/menu/update.c													\
					game/scenes/list/menu/render.c													\
					game/scenes/list/menu/destroy.c													\
																									\
					game/scenes/list/noise_test/noise_test_scene.c									\
					game/scenes/list/noise_test/init.c												\
					game/scenes/list/noise_test/update.c											\
					game/scenes/list/noise_test/render.c											\
					game/scenes/list/noise_test/destroy.c											\
																									\
					game/scenes/list/script/script_scene.c											\
					game/scenes/list/script/init.c													\
					game/scenes/list/script/update.c												\
					game/scenes/list/script/render.c												\
					game/scenes/list/script/destroy.c												\
					game/scenes/list/script/new_skip_event.c										\
																									\
					game/scenes/list/raycasting/raycasting_scene.c									\
					game/scenes/list/raycasting/init.c												\
					game/scenes/list/raycasting/init_vars.c											\
					game/scenes/list/raycasting/init_modules.c										\
					game/scenes/list/raycasting/init_entity_lists.c									\
					game/scenes/list/raycasting/init_assets.c										\
					game/scenes/list/raycasting/init_inputs.c										\
					game/scenes/list/raycasting/init_weapon.c										\
					game/scenes/list/raycasting/add_entities.c										\
					game/scenes/list/raycasting/add_death_buttons.c									\
					game/scenes/list/raycasting/update.c											\
					game/scenes/list/raycasting/render.c											\
					game/scenes/list/raycasting/render_sprites.c									\
					game/scenes/list/raycasting/render_weapon_display.c								\
					game/scenes/list/raycasting/render_tooltip.c									\
					game/scenes/list/raycasting/add_entity.c										\
					game/scenes/list/raycasting/kill_monster.c										\
					game/scenes/list/raycasting/weapon_use.c										\
					game/scenes/list/raycasting/weapon_shoot.c										\
					game/scenes/list/raycasting/weapon_reload.c										\
					game/scenes/list/raycasting/render_weapon.c										\
					game/scenes/list/raycasting/destroy.c											\
					game/scenes/list/raycasting/cast.c												\
																									\
					game/scenes/list/sector/sector_scene.c											\
					game/scenes/list/sector/init.c													\
					game/scenes/list/sector/update.c												\
					game/scenes/list/sector/render.c												\
					game/scenes/list/sector/destroy.c												\
																									\
					game/map_parser/check/close_curly_braces.c										\
					game/map_parser/check/curly_braces.c											\
					game/map_parser/check/open_curly_braces.c										\
					game/map_parser/check/utility.c													\
					game/map_parser/debug/debug.c													\
					game/map_parser/get_data_in_string/get_index.c									\
					game/map_parser/get_data_in_string/get_key.c									\
					game/map_parser/get_data_in_string/get_value_type.c								\
					game/map_parser/get_data_in_string/get_value.c									\
					game/map_parser/object/getter/get_child_object.c								\
					game/map_parser/object/getter/get_float_value.c									\
					game/map_parser/object/getter/get_int_value.c									\
					game/map_parser/object/getter/get_string_value.c								\
					game/map_parser/object/create.c													\
					game/map_parser/object/free.c													\
					game/map_parser/read_file/get_file_datas.c										\
					game/map_parser/split_data/free_string_array.c									\
					game/map_parser/split_data/new_string_array.c									\
					game/map_parser/split_data/split_data.c											\
					game/map_parser/parser.c														\
					game/map_parser/to_object.c														\
																									\
					game/hud/hud_game.c


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
CFLAGS			=	-Wall -Wextra -Werror -O3 -Ofast -flto# -fsanitize=address # -Wno-deprecated

LDFLAGS			:=	$(LIB_FOLDERS) $(LIBS)
ifneq ($(UNAME), Linux)
	LDFLAGS			:=  $(LDFLAGS) \
						-Wl,-rpath,$(SFML_FOLDER)/extlibs/libs-osx/Frameworks \
						-Wl,-rpath,$(SFML_FOLDER)/lib \
						-Wl,-rpath,$(CSFML_FOLDER)/lib
	RUN_PREFIX		:=	LD_LIBRARY_PATH=CSFML/lib:SFML/lib
	CFLAGS := $(CFLAGS) -Wno-deprecated-declarations
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

RANDOM			=	$(shell echo $$RANDOM)

PREFIX			=	$(BOLD)$(LIGHT_CYAN)[$(NAME)]$(RESET):

all: $(CSFML) $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	@$(LD) $(OBJS) -o $(NAME) $(LDFLAGS)
	@printf "\e[0K$(PREFIX) done\n"

$(OBJS_FOLDER)%.o: $(SRCS_FOLDER)%.c
	@printf "$(PREFIX) $<\n"
	@mkdir -p $(dir $@)
	@gcc -c $< -o $@ $(INCLUDES) $(CFLAGS) -DCOMPILE_RANDOM=$(RANDOM)
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
