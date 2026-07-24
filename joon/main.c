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
//#include "rush01.h"
int		parse(int argc, char **argv, int clues[24]);
int		**get_grid(int size);
int		check_row_duplicates(int **grid, int row, int size);
int		check_col_duplicates(int **grid, int col, int size);
int		get_left(int *row, int size);
int		get_right(int *row, int size);
int		row_clue_ok(int **grid, int row, int size, int clues[24]);
int		col_clue_ok(int **grid, int col, int size, int clues[24]);
int		solve(int **grid, int size, int clues[24], int pos);
void	printf_grid(int **grid, int size);
void	free_grid(int **grid, int size);
void	ft_putchar(char c);
void	ft_putnbr(int n);
int	check(char **input);

int	main(int argc, char **argv)
{
	int	clues[24];
	int	size;
	int	**grid;

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
