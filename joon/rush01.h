#include <stdlib.h>
#include <unistd.h>

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

int	check(char **input)
{
	int	n;

	n = 0;
	while (input[1][n])
	{
		if (n % 2 == 0 && !(input[1][n] >= '0' && input[1][n] <= '9'))
		{
			return (1);
		}
		if (n % 2 == 1 && input[1][n] != ' ')
		{
			return (2);
		}
		n++;
	}
	return (0);
}

int	parse(int argc, char **argv, int clues[24])
{
	int	i;
	int	j;

	if (argc != 2)
		return (1);
	i = 0;
	j = 0;
	while (argv[1][i])
	{
		if (argv[1][i] >= '1' && argv[1][i] <= '5')
		{
			clues[j] = argv[1][i] - '0';
			j++;
		}
		i++;
	}
	if (j != 24)
	{
		return (1);
	}
	return (0);
}

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

int	get_left(int *row, int size)
{
	int	i;
	int	max;
	int	count;

	i = 0;
	max = 0;
	count = 0;
	while (i < size)
	{
		if (row[i] > max)
		{
			max = row[i];
			count++;
		}
		i++;
	}
	return (count);
}

int	get_right(int *row, int size)
{
	int	i;
	int	max;
	int	count;

	i = size - 1;
	max = 0;
	count = 0;
	while (i >= 0)
	{
		if (row[i] > max)
		{
			max = row[i];
			count++;
		}
		i--;
	}
	return (count);
}

int	row_clue_ok(int **grid, int row, int size, int clues[24])
{
	if (get_left(grid[row], size) != clues[size * 2 + row])
	{
		return (0);
	}
	if (get_right(grid[row], size) != clues[size * 3 + row])
	{
		return (0);
	}
	return (1);
}

int	col_clue_ok(int **grid, int col, int size, int clues[24])
{
	int	temp[6];
	int	i;

	i = 0;
	while (i < size)
	{
		temp[i] = grid[i][col];
		i++;
	}
	if (get_left(temp, size) != clues[col])
		return (0);
	if (get_right(temp, size) != clues[size + col])
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
			&& check_col_duplicates(grid, col, size))
		{
			if (col == (size - 1))
			{
				if (row_clue_ok(grid, row, size, clues) == 0)
				{
					grid[row][col] = 0;
					i++;
					continue ;
				}
			}
			if (row == (size - 1))
			{
				if (col_clue_ok(grid, col, size, clues) == 0)
				{
					grid[row][col] = 0;
					i++;
					continue ;
				}
			}
			if (solve(grid, size, clues, pos + 1))
				return (1);
		}
		grid[row][col] = 0;
		i++;
	}
	return (0);
}

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

void	free_grid(int **grid, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putnbr(int n)
{
	ft_putchar(n + '0');
}
