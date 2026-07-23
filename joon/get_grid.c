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

int	**get_grid(int size)
{
	int	**grid;
	int	i;
	int	j;

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
	i = 0;
	j = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
	return (grid);
}
