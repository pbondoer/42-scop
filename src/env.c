/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 20:26:52 by pbondoer          #+#    #+#             */
/*   Updated: 2018/01/24 20:35:32 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

/*
** This is a singleton that contains most of the data needed.
** I usually don't /like/ singletons, as I find them to be a bad pattern.
** However, due to the fact I can't use a global and that glfw/C doesn't have
** a mechanism for parameters in callbacks, this is how it's going to be.
**
** If anyone knows of a better way, I'd love your feedback!
** Reach me @pbondoer on twitter
*/

t_env		*env()
{
	static t_env p = {
		.obj = { .vertex_count = 0, .face_count = 0, .triangle_count = 0 }
	};

	return (&p);
}
