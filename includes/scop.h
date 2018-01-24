/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 20:33:29 by pbondoer          #+#    #+#             */
/*   Updated: 2018/01/24 21:36:09 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SCOP_H
# define SCOP_H
# include "get_next_line.h"
# include "libft.h"
# include "ft_printf.h"

/*
** --- Primitives
*/

typedef struct	s_vector {
	double	x;
	double	y;
	double	z;
}				t_vector;

/*
** --- Parser
*/

typedef struct	s_obj {
	int			vertex_count;
	int			face_count;
	int			triangle_count;
	t_vector	*vertices;
}				t_obj;

int				read_obj(char *file);

/*
** --- Environment
*/

typedef struct	s_env {
	t_obj		obj;
}				t_env;

t_env			*env();

#endif
