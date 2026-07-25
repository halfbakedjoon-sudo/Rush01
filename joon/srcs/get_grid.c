/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johiew <johiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 13:32:19 by johiew            #+#    #+#             */
/*   Updated: 2026/06/21 13:32:22 by johiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	**assign_zero(int size, int **input)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			input[i][j] = 0;
			j++;
		}
		i++;
	}
	return (input);
}

int	**get_grid(int size)
{
	int	**grid;
	int	i;

	grid = malloc(size * sizeof(int *));
	if (!grid)
		return (NULL);
	i = 0;
	while (i < size)
	{
		grid[i] = malloc(size * sizeof(int));
		if (!grid[i])
			return (NULL);
		i++;
	}
	assign_zero(size, grid);
	return (grid);
}
