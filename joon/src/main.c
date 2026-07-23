/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: branlee <branlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 13:08:25 by johiew            #+#    #+#             */
/*   Updated: 2026/07/23 21:51:05 by branlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putnbr(int n)
{
	ft_putchar(n + '0');
}

int	main(int argc, char **argv)
{
	int	clues[24];
	int	i;
	int	j;
	int	size;
	int	**grid;

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
