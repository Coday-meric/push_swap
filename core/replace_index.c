/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaisonn <amaisonn@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 16:25:41 by amaisonn          #+#    #+#             */
/*   Updated: 2023/04/23 16:25:41 by amaisonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	index_min(t_pile *pile)
{
	int	i;
	int	ii;
	int	tmp;

	i = 0;
	tmp = pile->a[0];
	while (i < pile->len_a)
	{
		if (pile->a[i] <= tmp)
		{
			tmp = pile->a[i];
			ii = i;
		}
		i++;
	}
	return (ii);
}

static int	index_max(t_pile *pile)
{
	int	i;
	int	ii;
	int	tmp;

	i = 0;
	tmp = pile->a[0];
	while (i < pile->len_a)
	{
		if (pile->a[i] >= tmp)
		{
			tmp = pile->a[i];
			ii = i;
		}
		i++;
	}
	return (ii);
}

static void	check_index(t_pile *pile, int tmp, int *tmp_, int *tmp_i)
{
	int	i;

	i = 0;
	while (i < pile->len_a)
	{
		if (pile->a[i] > tmp && pile->a[i] <= *tmp_)
		{
			*tmp_ = pile->a[i];
			*tmp_i = i;
		}
		i++;
	}
}

void	replace_pile(t_pile *pile)
{
	int	ii;
	int	*cpy_a;
	int	tmp;
	int	tmp_;
	int	tmp_i;

	cpy_a = ft_calloc(pile->len_a + 1, sizeof(int));
	tmp = pile->a[index_min(pile)];
	cpy_a[index_min(pile)] = 0;
	ii = 1;
	while (ii < pile->len_a)
	{
		tmp_i = 0;
		tmp_ = pile->a[index_max(pile)];
		check_index(pile, tmp, &tmp_, &tmp_i);
		tmp = pile->a[tmp_i];
		cpy_a[tmp_i] = ii;
		ii++;
	}
	free(pile->a);
	pile->a = cpy_a;
}
