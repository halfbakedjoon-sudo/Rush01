/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: branlee <branlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 18:10:36 by johiew            #+#    #+#             */
/*   Updated: 2026/07/23 21:54:09 by branlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	solve(int **grid, int size, int clues[24], int pos)
{
	int	row;
	int	col;
	int	i;

	if (pos == (size * size))
		return (1);
	row = pos / size;
	col = pos % size;
	i = 1;
	while (i <= size)
	{
		grid[row][col] = i;
		if (check_row_duplicates(grid, row, size) && check_col_duplicates(grid, col, size))
		{
			if (col == (size - 1))
			{
				if (row_clue_ok(grid, row, size, clues) == 0)
				{
					grid[row][col] = 0;
					i++;
					continue ;
				}
			}
			if (row == (size - 1))
			{
				if (col_clue_ok(grid, col, size, clues) == 0)
				{
					grid[row][col] = 0;
					i++;
					continue ;
				}
			}
			if (solve(grid, size, clues, pos + 1))
				return (1);
		}
		grid[row][col] = 0;
		i++;
	}
	return (0);
}
