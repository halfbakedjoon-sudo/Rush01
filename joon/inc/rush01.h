/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: branlee <branlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 21:48:59 by branlee           #+#    #+#             */
/*   Updated: 2026/07/23 21:53:41 by branlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

// main.c
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

// solve.c
int	check_row_duplicates(int **grid, int row, int size);
int	check_col_duplicates(int **grid, int col, int size);
int	row_clue_ok(int **grid, int row, int size, int clues[24]);
int	col_clue_ok(int **grid, int col, int size, int clues[24]);

// clue_ok.c
int	get_left(int *row, int size);
int	get_right(int *col, int size);

#endif