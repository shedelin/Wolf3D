/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w3_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 19:32:09 by shedelin          #+#    #+#             */
/*   Updated: 2014/01/15 19:32:11 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "wolf_3D.h"
#include "libft.h"

void	w3_error(int error)
{
	if (error == 0)
		ft_putendl_fd("No map entry.", 2);
	if (error == 1)
		ft_putendl_fd("Too many arguments.", 2);
	if (error == 2)
		ft_putendl_fd("Bad map.", 2);
	if (error == 3)
		ft_putendl_fd("open map fail.", 2);
	if (error == 4)
		ft_putendl_fd("No player in map, put 'P' in the map.", 2);
	exit(0);
}
