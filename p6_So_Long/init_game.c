/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 19:15:10 by aakpinar          #+#    #+#             */
/*   Updated: 2025/03/20 21:30:54 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	init_game(void)
{
	return ((t_game){
		.map.map = NULL,
		.map.row = 0,
		.map.column = 0,
		.map.collectibles = 0,
		.map.exit = 0,
		.map.player = 0,
		.block.collectibles = NULL,
		.block.exit = NULL,
		.block.floor = NULL,
		.block.player = NULL,
		.block.wall = NULL,
		.moves = -1,
	});
}
