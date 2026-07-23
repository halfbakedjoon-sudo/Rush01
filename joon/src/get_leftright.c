/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_left.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johiew <johiew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 16:36:35 by johiew            #+#    #+#             */
/*   Updated: 2026/06/21 16:36:37 by johiew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
