/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaisonn <amaisonn@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 23:10:38 by amaisonn          #+#    #+#             */
/*   Updated: 2023/04/23 23:10:38 by amaisonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	init_pile(t_pile *pile, char **data)
{
	int	i;
	int	ii;

	ii = 0;
	while (data[ii])
		ii++;
	pile->a = ft_calloc(ii, sizeof(int));
	pile->len_a = ii;
	pile->b = ft_calloc(ii, sizeof(int));
	pile->len_b = 0;
	i = 0;
	while (i < ii)
	{
		pile->a[i] = ft_atoi(data[i]);
		i++;
	}
}

static int	argv_classic(t_pile *pile, char **argv, int argc)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (check_input(argv[i]) == 1)
			return (0);
		i++;
	}
	init_pile(pile, argv + 1);
	return (1);
}

static void	free_split(char **tab_split)
{
	int	i;

	i = 0;
	while (tab_split[i])
	{
		free(tab_split[i]);
		i++;
	}
	free(tab_split);
}

static int	argv_split(t_pile *pile, char **argv)
{
	char	**tab_split;
	int		i;

	tab_split = ft_split(argv[1], ' ');
	i = 0;
	while (tab_split[i] != 0)
	{
		if (check_input(tab_split[i]) == 1)
		{
			free_split(tab_split);
			return (0);
		}
		i++;
	}
	init_pile(pile, tab_split);
	free_split(tab_split);
	return (1);
}

int	treat_argv(t_pile *pile, int argc, char **argv)
{
	if (argc == 2 && ft_strlen(argv[1]) == 1)
	{
		if (check_input(argv[1]) == 1)
			return (0);
		init_pile(pile, argv + 1);
	}
	else if (argc == 2 && ft_strlen(argv[1]) > 1)
	{
		if (argv_split(pile, argv) == 0)
			return (0);
	}
	else if (argc > 2)
	{
		if (argv_classic(pile, argv, argc) == 0)
			return (0);
	}
	if (check_double(pile) == 1)
		return (0);
	replace_pile(pile);
	return (1);
}
