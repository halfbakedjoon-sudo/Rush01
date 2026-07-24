/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johiew <johiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 13:08:25 by johiew            #+#    #+#             */
/*   Updated: 2026/06/21 13:08:27 by johiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "rush01.h"

int	main(int argc, char **argv)
{
	int	clues[24];
	int	size;
	int	**grid;

	if (argc < 2)
		return (printf("Too few arguments\n"));
	if (argc > 2)
		return (printf("Too many arguments\n"));
	if (check(argv) == 1)
		return (printf("expected number but not\n"));
	if (check(argv) == 2)
		return (printf("expected space but not\n"));
	size = 6;
	parse (argc, argv, clues);
	grid = get_grid(size);
	if (solve(grid, size, clues, 0) == 1)
	{
		printf_grid(grid, size);
	}
	else
	{
		write (1, "Error\n", 6);
	}
	free_grid(grid, size);
	return (0);
}
