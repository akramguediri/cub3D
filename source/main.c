/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguediri <aguediri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 22:20:31 by otuyishi          #+#    #+#             */
/*   Updated: 2024/01/19 17:02:16 by aguediri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	map_scan(void)
// {

// }

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + ((y * data->line_len) + (x * (data->bits_per_pixel/8)));
// 	*(unsigned int *)dst = color;
// }

// int	main(void)
// {
// 	void	*mlx;
// 	t_data	*img = NULL;

// 	img = (t_data *)malloc(sizeof(t_data));
// 	mlx = mlx_init(1920, 1080, "THIS IS CUBE3D", 100);
// 	img->img = mlx_new_image(mlx, 1920, 1080);
// 	int i = 0;
// 	mlx_image_to_window(mlx, img->img, 0, 0);
// 	while (i++ < 1000)
// 		mlx_put_pixel(img->img, i, i, 0x00FF00FF);
// 	mlx_loop(mlx);
// }

// int	main(int argc, char *argv[])
// {
// 	double	posX;
// 	double	posY;
// 	double	dirX;
// 	double	dirY;
// 	double	planeX;
// 	double	planeY;
// 	int		x;
// 	double	cameraX;
// 	double	rayDirX;
// 	double	rayDirY;
// 	int		mapX;
// 	int		mapY;
// 	double	sideDistX;
// 	double	sideDistY;
// 	double	deltaDistX;
// 	double	deltaDistY;
// 	double	perpWallDist;
// 	int		stepX;
// 	int		stepY;
// 	int		hit;
// 	int		side;
// 	int		lineHeight;
// 	int		drawStart;
// 	int		drawEnd;
// 			ColorRGB color;
// 	double	oldDirX;
// 	double	oldPlaneX;
// 	double	oldDirX;
// 	double	oldPlaneX;
// 	void	*mlx;

// 	posX = 22;
// 	posY = 12;
// 	dirX = -1;
// 	dirY = 0;
// 	planeX = 0;
// 	planeY = 0.66;
// 	double time = 0; //time of current frame
//   	double oldTime = 0; //time of previous frame
// 	mlx = mlx_init(SCREEN_W, SCREEN_H, "Raycaster", 0);
// 	while (!done())
// 	{
// 		x = 0;
// 		while (x < w)
// 		{
// 			cameraX = 2 * x / double (w) - 1;
// 			rayDirX = dirX + planeX * cameraX;
// 			rayDirY = dirY + planeY * cameraX;
// 			deltaDistX = abs(1 / rayDirX);
// 			deltaDistY = abs(1 / rayDirY);
// 			if (rayDirX == 0)
// 				deltaDistX = 1e30;
// 			else
// 				deltaDistX = abs(1 / rayDirX);
// 			if (rayDirY == 0)
// 				deltaDistY = 1e30;
// 			else
// 				deltaDistX = abs(1 / rayDirY);
// 			mapX = int (posX);
// 			mapY = int (posY);
// 			hit = 0;
// 			if (rayDirX < 0)
// 			{
// 				stepX = -1;
// 				sideDistX = (posX - mapX) * deltaDistX;
// 			}
// 			else
// 			{
// 				stepX = 1;
// 				sideDistX = (mapX + 1.0 - posX) * deltaDistX;
// 			}
// 			if (rayDirY < 0)
// 			{
// 				stepY = -1;
// 				sideDistY = (posY - mapY) * deltaDistY;
// 			}
// 			else
// 			{
// 				stepY = 1;
// 				sideDistY = (mapY + 1.0 - posY) * deltaDistY;
// 			}
// 			while (hit == 0)
// 			{
// 				if (sideDistX < sideDistY)
// 				{
// 					sideDistX += deltaDistX;
// 					mapX += stepX;
// 					side = 0;
// 				}
// 				else
// 				{
// 					sideDistY += deltaDistY;
// 					mapY += stepY;
// 					side = 1;
// 				}
// 				if (worldMap[mapX][mapY] > 0)
// 					hit = 1;
// 			}
// 			if (side == 0)
// 				perpWallDist = (sideDistX - deltaDistX);
// 			else
// 				perpWallDist = (sideDistY - deltaDistY);
// 			lineHeight = (int)(h / perpWallDist);
// 			// calculate lowest and highest pixel to fill in current stripe
// 			drawStart = -lineHeight / 2 + h / 2;
// 			if (drawStart < 0)
// 				drawStart = 0;
// 			drawEnd = lineHeight / 2 + h / 2;
// 			if (drawEnd >= h)
// 				drawEnd = h - 1;
// 			switch (worldMap[mapX][mapY])
// 			{
// 			case 1:
// 				color = RGB_Red;
// 				break ; // red
// 			case 2:
// 				color = RGB_Green;
// 				break ; // green
// 			case 3:
// 				color = RGB_Blue;
// 				break ; // blue
// 			case 4:
// 				color = RGB_White;
// 				break ; // white
// 			default:
// 				color = RGB_Yellow;
// 				break ; // yellow
// 			}
// 			// give x and y sides different brightness
// 			if (side == 1)
// 				color = color / 2;
// 			// draw the pixels of the stripe as a vertical line
// 			verLine(x, drawStart, drawEnd, color);
// 			oldTime = time;
// 			time = getTicks();
// 			double frameTime = (time - oldTime) / 1000.0;
// 				// frameTime is the time this frame has taken, in seconds
// 			print(1.0 / frameTime);                       // FPS counter
// 			redraw();
// 			cls();
// 			// speed modifiers
// 			double moveSpeed = frameTime * 5.0;
// 				// the constant value is in squares/second
// 			double rotSpeed = frameTime * 3.0;
// 				// the constant value is in radians/second
// 			readKeys();
// 			// move forward if no wall in front of you
// 			if (keyDown(SDLK_UP))
// 			{
// 				if (worldMap[int(posX + dirX * moveSpeed)][int(posY)] == false)
// 					posX += dirX * moveSpeed;
// 				if (worldMap[int(posX)][int(posY + dirY * moveSpeed)] == false)
// 					posY += dirY * moveSpeed;
// 			}
// 			// move backwards if no wall behind you
// 			if (keyDown(SDLK_DOWN))
// 			{
// 				if (worldMap[int(posX - dirX * moveSpeed)][int(posY)] == false)
// 					posX -= dirX * moveSpeed;
// 				if (worldMap[int(posX)][int(posY - dirY * moveSpeed)] == false)
// 					posY -= dirY * moveSpeed;
// 			}
// 			// rotate to the right
// 			if (keyDown(SDLK_RIGHT))
// 			{
// 				// both camera direction and camera plane must be rotated
// 				oldDirX = dirX;
// 				dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
// 				dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
// 				oldPlaneX = planeX;
// 				planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
// 				planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
// 			}
// 			// rotate to the left
// 			if (keyDown(SDLK_LEFT))
// 			{
// 				// both camera direction and camera plane must be rotated
// 				oldDirX = dirX;
// 				dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
// 				dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
// 				oldPlaneX = planeX;
// 				planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
// 				planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
// 			}
// 			x++;
// 		}
// 	}
// }

int	error_exit(t_data *data, char *str)
{
	mlx_close_window(data->mlx);
	mlx_strerror(mlx_errno);
	write(2, str, ft_strlen(str));
	return (EXIT_FAILURE);
}

// int	initialization(t_data *data, t_img *img)
// {
// 	int	i;

// 	i = 0;
// 	data->win_mlx = mlx_image_to_window(data->mlx, img->img, 0, 0);
// 	img->img = mlx_new_image(data->mlx, MAP_W, MAP_H);
// }

// int	pass_parsing(t_data *data, t_map *map, char **argv)
// {
// 	return (1);
// }
char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	char		*newline;
	int			countread;
	int			to_copy;

	line = ft_strdup(buf);
	while (!(ft_strchr(line, '\n')) && (countread = read(fd, buf,
				BUFFER_SIZE)) > 0)
	{
		buf[countread] = '\0';
		line = ft_strjoin(line, buf);
	}
	if (ft_strlen(line) == 0)
		return (free(line), NULL);
	newline = ft_strchr(line, '\n');
	if (newline != NULL)
	{
		to_copy = newline - line + 1;
		ft_strlcpy(buf, newline + 1, BUFFER_SIZE + 1);
	}
	else
	{
		to_copy = ft_strlen(line);
		ft_strlcpy(buf, "", BUFFER_SIZE + 1);
	}
	line[to_copy] = '\0';
	return (line);
}
void	manage_directions(char *s, t_map *data)
{
	char	**t;

	t = ft_split(s, ' ');
	if (t[0][0] == 'N')
		data->north = ft_strdup(t[1]);
	else if (t[0][0] == 'S')
		data->south = ft_strdup(t[1]);
	else if (t[0][0] == 'W')
		data->west = ft_strdup(t[1]);
	else if (t[0][0] == 'E')
		data->east = ft_strdup(t[1]);
}
void	manage_sfc(char *s, t_map *data)
{
	char	**t;

	t = ft_split(s, ' ');
	if (t[0][0] == 'F')
		data->f = ft_strdup(t[1]);
	else if (t[0][0] == 'S')
		data->s = ft_strdup(t[1]);
	else if (t[0][0] == 'C')
		data->c = ft_strdup(t[1]);
}
t_map	*manage_data(char *s)
{
	int		i;
	t_map	*data;
	char	**t;
	char	**t1;
	char	*map;

	data = (t_map *)malloc(sizeof(t_map));
	map = "";
	i = 0;
	t = ft_split(s, '\n');
	while (t[i])
	{
		if (!ft_strnstr(t[i], "NO", 2) || !ft_strnstr(t[i], "SO", 2)
			|| !ft_strnstr(t[i], "WE", 2) || !ft_strnstr(t[i], "EA", 2))
			manage_directions(t[i], data);
		else if (!ft_strnstr(t[i], "S", 1) || !ft_strnstr(t[i], "C", 1)
			|| !ft_strnstr(t[i], "F", 1))
			manage_sfc(t[i], data);
		else if (!ft_strnstr(t[i], "S", 1))
		{
			t1 = ft_split(t[i], ' ');
			data->h = ft_atoi(t1[1]);
			data->w = ft_atoi(t1[2]);
		}
		else if (!ft_strnstr(t[i], "0", 1) || !ft_strnstr(t[i], "1", 1))
		{
			map = ft_strjoin(map, t[i]);
			map = ft_strjoin(map, "\n");
		}
		i++;
	}
	data->map = ft_split(map, '\n');
	return (data);
}
t_map	*get_map_data(char *s)
{
	int		fd;
	char	*line;
	char	*str;
	t_map	*data;

	fd = open(s, O_RDONLY);
	str = "";
	data = NULL;
	if (!fd)
	{
		perror("Error opening file");
		return (NULL);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		str = ft_strjoin(str, line);
		free(line);
	}
	close(fd);
	printf("%s", str);
	data = manage_data(str);
	return (data);
}

int	main(int argc, char **argv)
{
	t_map	*map;

	// t_data	*data;
	// t_img	*img;
	// data = ft_calloc(sizeof(t_data), 1);
	if (argc != 2 || ft_strnstr(argv[1], ".cub", 4))
		printf("error");
	// 	return (error_exit(data->mlx, "Add one arg (map with ext '.cub')"));
	// data->mlx = mlx_init(SCREEN_W, SCREEN_H, "CUBE3D", 100);
	// if (!data->mlx)
	// 	return (error_exit(data->mlx, "MLX Failed to init"));
	map = get_map_data(argv[1]);
	// initialization(&data, &img);
	// pass_parsing(data, &map, argv);
	// free(data);
}
