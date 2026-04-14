/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leogarci <leogarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 18:57:36 by leogarci          #+#    #+#             */
/*   Updated: 2025/10/18 17:10:50 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../all_libft/all_libft.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define FOV 1.396263402 // 80 (M_PI / 180)
# define MAX 100
# define M_PI 3.14159265358979323846
# define SSAA_FACTOR 2
# define SSAA_WIDTH 3840  // width * ssaa_factor
# define SSAA_HEIGHT 2160 // height * ssaa_factor
# define SSAA_HEIGHT_DIV_2 1080
# define NUM_RAYS SSAA_WIDTH
# define SSAA_FACTOR_DOUBLE 4
# define FOV_ 0.00036361       // FOV / SSAA_WIDTH
# define FOV_DIV_2 0.698131701 // fov / 2

typedef enum e_boolean
{
	TRUE,
	FALSE,
	BREAK,
}					t_boolean;

typedef struct s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
}					t_mlx;

typedef enum e_wall
{
	NORTH,
	SOUTH,
	EAST,
	WEST,
}					t_wall;

typedef struct s_user
{
	float			x;
	float			y;
	float			angle;
	t_wall			facing;
	char			key_states[256];
}					t_user;

typedef struct s_ray
{
	float			angle;
	float			distance;
	t_wall			wall_dir;
	int				side;
	t_boolean		hit;
	float			x;
	float			y;
	float			wall_x;
}					t_ray;

typedef struct s_all_ray
{
	float			x;
	float			y;
	float			dir_x;
	float			dir_y;
	float			step_size;
	float			distance;
	float			prev_x;
	float			prev_y;
	int				grid_x;
	int				grid_y;
	int				prev_grid_x;
	int				prev_grid_y;
}					t_all_ray;

typedef struct s_img
{
	void			*img_ptr;
	char			*pwd;
	char			*data_addr;
	int				bpp;
	int				size_line;
	int				width;
	int				height;
	int				endian;
	int				bpp_div_8;
}					t_img;

typedef struct s_map
{
	t_img			nsew[4];
	int				rgb_fc[2][3];
	char			**map;
	t_mlx			mlx[1];
	t_user			user[1];
	t_img			*display_img;
	t_img			ssaa_img;
	t_img			final_a;
	t_img			final_b;
	t_img			*draw_img;
}					t_map;

typedef struct s_rgbn
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
}					t_rgbn;

typedef struct s_color_accum
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
}					t_color_accum;

typedef struct s_wall_calc
{
	int				wall_height;
	int				wall_height_div_2;
	int				start;
	int				end;
	float			texture_x;
	float			step;
	float			tex_pos;
}					t_wall_calc;

typedef struct s_wall_draw_params
{
	int				i;
	int				y;
	int				end;
	float			tex_pos;
	float			step;
	t_img			*texture;
	t_img			*img;
	float			texture_x;
}					t_wall_draw_params;

typedef struct s_raycast_params
{
	float			ray_dir_x;
	float			ray_dir_y;
	int				map_x;
	int				map_y;
	float			delta_dist_x;
	float			delta_dist_y;
	float			perp_wall_dist;
	int				hit;
	int				side;
	float			wall_x;
	int				step_x;
	int				step_y;
	float			side_dist_x;
	float			side_dist_y;
}					t_raycast_params;

typedef struct s_stack_params
{
	char			**src_map;
	int				i;
	int				count;
	char			**stack_lines;
	char			**stack_map;
	t_map			*cubd;
}					t_stack_params;

/*				major function				*/

t_boolean			ft_parsing(char *str, t_map *cub);

/*				checker function			*/

t_boolean			check_ea(char *str, t_map *cubd);
t_boolean			check_we(char *str, t_map *cubd);
t_boolean			check_so(char *str, t_map *cubd);
t_boolean			check_no(char *str, t_map *cubd);
t_boolean			check_f(char *str, t_map *cubd);
t_boolean			check_c(char *str, t_map *cubd);
t_boolean			ft_isspacestr(char *str, t_map *cubd);
t_boolean			parse_map(char **file, int i, t_map *cubd);
t_boolean			check_first_and_last_line(char *str);
t_boolean			check_horizontal(char **map);

/*				parsing utils				*/

void				ft_free_array(char **array);
void				ft_print_array(char **array);
void				get_player_coordinate(t_map *cub);
int					load_all_textures(t_img *img, t_mlx *mlx, t_img *text,
						t_img *ssaa_img);
int					init_ssaa_image(t_img *ssaa_img, t_mlx *mlx, t_img *img,
						t_img *text);
int					ft_init_img(t_img *img, t_mlx *mlx, t_img *text,
						t_img *ssaa_img);
int					ft_init_win(t_mlx *mlx, t_img *textures, t_img *img,
						t_img *ssaa_img);
t_boolean			finalize_map_setup(t_stack_params *params);

/*				raytrack utils				*/

void				ft_raycasting(t_map *cub);
void				raycast(t_ray *ray, t_map *cub);
int					is_wall(int x, int y, char **map);

/*				mlx utils					*/

t_boolean			init_win(t_map *cub);
void				destroy_win(t_mlx *mlx, t_img *textures, t_img *img,
						t_img *ssaa_img);
void				ft_grape_calculator(t_map *cub);

/*				mlx helpers					*/

void				destroy_textures(t_mlx *mlx, t_img *textures);
void				destroy_images(t_mlx *mlx, t_img *img, t_img *ssaa_img);
void				destroy_mlx_display(t_mlx *mlx);
void				handle_movement_forward_back(int keycode, t_map *cub);
void				handle_movement_left_right(int keycode, t_map *cub);
void				destroy_win_test(t_mlx *mlx, t_img *textures, t_img *img,
						t_img *ssaa_img);
void				destroy_additional_image(t_mlx *mlx, t_img *test);

/*				ssaa utils					*/

unsigned int		compute_avg_color_for_pixel(t_img *ssaa_img, int x, int y);
void				write_pixel(t_img *img, int x, int y, unsigned int color);
void				downsample_to_window(t_img *ssaa_img, t_img *window_img);

/*				raycasting utils			*/

void				put_pixel_to_image(t_img *img, int x, int y, int color);
void				draw_wall_column(t_wall_draw_params *params);
void				fill_floor_ceiling(t_img *img, int floor_color,
						int ceiling_color);
void				draw_walls_rec(int i, t_ray *ray, t_map *cub,
						t_img *target_img);
void				draw_walls_single(int i, t_ray *ray, t_map *cub,
						t_img *target_img);

/*				raycast core				*/

void				init_ray_params(t_raycast_params *params, t_map *cub,
						int i);
void				calculate_step_and_side_dist(t_raycast_params *params,
						t_map *cub);
void				perform_dda(t_raycast_params *params, t_map *cub);
void				calculate_wall_distance(t_raycast_params *params,
						t_map *cub);
void				raycast_loop(t_ray *ray, t_map *cub);

/*				map checks					*/
t_boolean			check_first_and_last_line(char *str);
t_boolean			ft_check_in_between(char *str, int *start);
t_boolean			check_amount_player(char **map);
t_boolean			check_in_between(char **map);

/*				general utils				*/
int					render_scene(t_map *cub);
int					destroy_handler(t_mlx *mlx);
int					key_handler(int keycode, t_map *cub);
void				cast_rays(t_user *user, t_ray *ray);
int					init_final_images_a(t_map *cubd);
int					init_final_images_b(t_map *cubd);
int					get_texture_data_addr(t_img *img, int index);
int					load_texture_image(t_img *img, t_mlx *mlx, int index);
int					coords_util(int i, int j, t_map *cub);
t_boolean			ft_check_digit(char **rgb);
void				new_pos(t_map *cub, float new_x, float new_y);
t_boolean			check_break(char *cub, t_map *cubd);
t_boolean			_check_f_utils(char **rgb, t_map *cubd);
t_boolean			_check_c_utils(char **rgb, t_map *cubd);
t_boolean			exec_atoi_cub(char **rgb, t_map *cubd, int i);
int					count_strings(char **arr);

#endif
