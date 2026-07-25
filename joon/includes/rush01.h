/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johiew <johiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 15:37:36 by johiew            #+#    #+#             */
/*   Updated: 2026/07/24 15:37:37 by johiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

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
int		check(char **input);

#endif
