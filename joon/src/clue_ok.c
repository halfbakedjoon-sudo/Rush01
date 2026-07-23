/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clue_ok.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: branlee <branlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 16:48:29 by johiew            #+#    #+#             */
/*   Updated: 2026/07/23 21:54:21 by branlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	row_clue_ok(int **grid, int row, int size, int clues[24])
{
	if (get_left(grid[row], size) != clues[size * 2 + row])
	{
		return (0);
	}
	if (get_right(grid[row], size) != clues[size * 3 + row])
	{
		return (0);
	}
	return (1);
}

int	col_clue_ok(int **grid, int col, int size, int clues[24])
{
	int	temp[size];
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		temp[i] = grid[i][col];
		i++;
	}
	if (get_left(temp, size) != clues[col])
		return (0);
	if (get_right(temp, size) != clues[size + col])
		return (0);
	return (1);
}
