/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johiew <johiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 18:31:17 by johiew            #+#    #+#             */
/*   Updated: 2026/06/21 18:31:18 by johiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	printf_grid(int **grid, int size)
{
	int		row;
	int		col;
	char	c;

	row = 0;
	while (row < size)
	{
		col = 0;
		while (col < size)
		{
			c = grid[row][col] + '0';
			write(1, &c, 1);
			if (col != size - 1)
			{
				write(1, " ", 1);
			}
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
}
