/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwichoi <hwichoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 20:14:59 by hwichoi           #+#    #+#             */
/*   Updated: 2022/11/04 22:48:06 by hwichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_str_size(int ac, char **av)
{
	int		i;
	int		size;
	int		checker;
	char	**spl_str;

	i = 0;
	size = 0;
	while (i < ac)
	{
		checker = 0;
		while (av[i][checker])
		{
			if (av[i][checker] == ' ')
				break ;
			checker++;
		}
		if (av[i][checker] == 0)
			print_err(1);
		spl_str = ft_split(av[i], ' ');
		size += get_size_spl_str(spl_str);
		ft_free_str(spl_str);
		i++;
	}
	return (size - 1);
}

int	*ft_av_to_arr(int ac, char **av, int size)
{
	int		ac_i;
	int		arr_i;
	int		*new_arr;
	char	**spl_str;

	ac_i = 1;
	arr_i = 0;
	new_arr = (int *)malloc(sizeof(int) * size);
	if (!new_arr)
		print_err(1);
	while (ac_i < ac)
	{
		spl_str = ft_split(av[ac_i], ' ');
		set_str_to_arr(new_arr, &arr_i, spl_str);
		ft_free_str(spl_str);
		ac_i++;
	}
	new_arr[arr_i] = '\0';
	return (new_arr);
}

void	ft_arr_to_stack(t_info *info, int *arr, int size)
{
	t_num	*new_node;
	int		i;

	i = 0;
	while (i < size)
	{
		new_node = ft_stack_new();
		info->size_a += 1;
		info->bot_a->content = (int)arr[i];
		info->bot_a->next = new_node;
		new_node->prev = info->bot_a;
		info->bot_a = new_node;
		i++;
	}
	info->bot_a = info->bot_a->prev;
	info->bot_a->next = NULL;
	free(new_node);
}

void	ft_check_arr_sort(int *arr, int size, int idx)
{
	int	i;
	int	checker;
	int	tmp;

	checker = 0;
	while (idx < size)
	{
		i = 0;
		while (i < size - 1)
		{
			if (arr[i] > arr[i + 1])
			{
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				checker++;
			}
			i++;
		}
		if (arr[idx] == arr[idx + 1])
			print_err(1);
		idx++;
	}
	if (checker == 0)
		print_err(-1);
}
