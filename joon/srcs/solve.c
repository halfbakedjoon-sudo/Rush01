/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johiew <johiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 18:10:36 by johiew            #+#    #+#             */
/*   Updated: 2026/06/21 18:10:38 by johiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_row_duplicates(int **grid, int row, int size);
int	check_col_duplicates(int **grid, int col, int size);
int	row_clue_ok(int **grid, int row, int size, int clues[24]);
int	col_clue_ok(int **grid, int col, int size, int clues[24]);

int	check_grid(int **grid, int row, int col, int clues[24])
{
	if (col == 6 - 1 && !row_clue_ok(grid, row, 6, clues))
		return (0);
	if (row == 6 - 1 && !col_clue_ok(grid, col, 6, clues))
		return (0);
	return (1);
}

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
		if (check_row_duplicates(grid, row, size)
			&& check_col_duplicates(grid, col, size)
			&& check_grid(grid, row, col, clues)
			&& solve(grid, size, clues, pos + 1))
			return (1);
		grid[row][col] = 0;
		i++;
	}
	return (0);
}
