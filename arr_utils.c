/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwichoi <hwichoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 20:19:47 by hwichoi           #+#    #+#             */
/*   Updated: 2022/11/06 16:24:00 by hwichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_size_spl_str(char **spl_str)
{
	int	i;

	i = 0;
	while (spl_str[i])
		i++;
	return (i);
}

void	ft_free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	ft_atoll(const char *str)
{
	long long	res;
	int			sign;
	int			checker;

	res = 0;
	sign = 1;
	checker = 0;
	while (*str == ' ')
		str++;
	if (*str == '-')
		sign = -1;
	while (*str == '+' || *str == '-')
		str++;
	while (ft_isdigit(*str))
	{
		res = res * 10 + (*str - '0');
		str++;
		checker++;
	}
	res = res * sign;
	if (*str != '\0' || checker > 10 || res > 2147483647 || res < -2147483648)
		print_err(1);
	return ((int)res);
}

void	set_str_to_arr(int *arr, int *arr_i, char **str)
{
	int	tmp_num;
	int	i;

	i = 0;
	while (str[i])
	{
		tmp_num = ft_atoll(str[i]);
		arr[*arr_i] = tmp_num;
		(*arr_i)++;
		i++;
	}
}
