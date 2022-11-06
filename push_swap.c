/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwichoi <hwichoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:54:24 by hwichoi           #+#    #+#             */
/*   Updated: 2022/11/06 16:55:18 by hwichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	print_err(int err_type)
{
	if (err_type >= 1)
		write(2, "Error\n", 6);
	exit (1);
}

t_info	*ft_info_new(void)
{
	t_num	*stack_a;
	t_info	*new_mem;

	new_mem = (t_info *)malloc(sizeof(t_info));
	if (new_mem == NULL)
		print_err(1);
	stack_a = ft_stack_new();
	new_mem->arr = NULL;
	new_mem->size_a = 0;
	new_mem->top_a = stack_a;
	new_mem->bot_a = stack_a;
	new_mem->size_b = 0;
	return (new_mem);
}

t_num	*ft_stack_new(void)
{
	t_num	*new_mem;

	new_mem = NULL;
	new_mem = (t_num *)malloc(sizeof(t_num));
	if (new_mem == NULL)
		print_err(1);
	new_mem->prev = NULL;
	new_mem->content = 0;
	new_mem->next = NULL;
	return (new_mem);
}

int	main(int ac, char **av)
{
	int		arr_size;
	int		*num_arr;
	t_info	*info;

	if (ac < 2)
		print_err(1);
	info = ft_info_new();
	arr_size = get_str_size(ac, av);
	num_arr = ft_av_to_arr(ac, av, arr_size);
	ft_arr_to_stack(info, num_arr, arr_size);
	ft_check_arr_sort(num_arr, arr_size, 0);
	info->arr = (int *)num_arr;
	ft_sort(info);
	return (0);
}
