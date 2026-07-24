/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicates_left.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johiew <johiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 14:22:35 by johiew            #+#    #+#             */
/*   Updated: 2026/06/21 14:22:37 by johiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_row_duplicates(int **grid, int row, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (grid[row][i] != 0 && grid[row][i] == grid[row][j])
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_col_duplicates(int **grid, int col, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (grid[i][col] != 0 && grid[i][col] == grid[j][col])
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
