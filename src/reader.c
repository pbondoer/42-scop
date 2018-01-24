/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 19:58:02 by pbondoer          #+#    #+#             */
/*   Updated: 2018/01/24 22:03:03 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

/*
** This is a simple obj parser. Supports v and f for now, more to come.
** Also supports quads.
*/

int		read_obj(char *file) {
	int		fd;
	int		ret;
	char	*line;

	if ((fd = open(file, O_RDONLY)) == -1)
	{
		perror("scop");
		exit(errno);
	}

	line = NULL;
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		if (ft_strchr(line, '#') == line ||
			ft_strchr(line, 'o') == line ||
			ft_strchr(line, 's') == line ||
			ft_strncmp(line, "usemtl", 6) == 0 ||
			ft_strncmp(line, "mtllib", 6) == 0)
			continue;
		// face
		if (ft_strchr(line, 'v') == line)
		{
			//ft_printf("vertex: %s\n", line);
			// read a vertex
			t_vector v;
			sscanf(line, "v %lf %lf %lf", &v.x, &v.y, &v.z);
			printf("vertices[%3d] = % f % f % f\n", env()->obj.vertex_count, v.x, v.y, v.z);
			env()->obj.vertex_count++;
		}
		else if (ft_strchr(line, 'f') == line)
		{
			int i = 0;
			int cur;

			ft_printf("face[%3d] =", env()->obj.face_count);
			line = strchr(line, ' ');
			while((cur = atoi(line)))
			{
				ft_printf(" %3d", cur);
				i++;
				if (i > 3)
					env()->obj.triangle_count++;
				line = line + 1;
				if ((line = strchr(line, ' ')) == NULL)
					break;
			}
			ft_printf("\n");

			env()->obj.face_count++;
			env()->obj.triangle_count++;
		}
		else {
			ft_printf("unknown!!\n%s\nABORTING\n", line);
			exit(1);
		}
	}

	// allocate needed

	if (ret == -1)
	{
		ft_printf("error gnl");
		exit(0);
	}

	ft_printf("Successfully read %s\n");
	ft_printf(" - %d vertices\n", env()->obj.vertex_count);
	ft_printf(" - %d faces\n", env()->obj.face_count);
	ft_printf(" - %d triangles\n", env()->obj.triangle_count);

	return (0);
}
