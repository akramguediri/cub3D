#ifndef CUB3D_H
# define CUB3D_H

# include "MLX42.h"
# include "fcntl.h"
# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define MAP_W 24
# define MAP_H 24
# define SCREEN_W 640
# define SCREEN_H 480
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_player
{
	double		x;
	double		y;
	double		dir_x;
	double		dir_y;
	double		pl_x;
	double		pl_y;
	double		rotations;
	double		dest_x;
	double		dest_y;
	double		tot_rotations;
}				t_player;

typedef struct s_ray
{
	double		x_dir;
	double		y_dir;
	double		x_plane;
	double		y_plane;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		camera_x;
	double		ray_dir_x;
	double		ray_dir_y;
}				t_ray;

typedef struct s_img
{
	void		*img;
	int			width;
	int			height;
	int			endian;
	int			bits_per_pixel;
	int			line_len;
}				t_img;

typedef struct s_data
{
	char		*addr;
	void		*mlx;
	void		*win_mlx;
	float		x0;
	float		x1;
	float		y0;
	float		y1;
	t_ray		*rays;
	t_player	*player;
}				t_data;

typedef struct s_map
{
	int			h;
	int			w;
	size_t		len_map;
	char		**map;
	char		*north;
	char		*south;
	char		*east;
	char		*west;
	char		*s;
	char		*f;
	char		*c;
}				t_map;

t_map			*get_map_data(char *s);

#endif
