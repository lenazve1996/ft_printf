/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajirob@student.42.fr <ayajirob>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 13:08:28 by ayajirob@st       #+#    #+#             */
/*   Updated: 2022/02/02 19:27:37 by ayajirob@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_print_indent(int n, t_list *data, int flag)
{
	while (n > 0)
	{
		write(1, " ", 1);
		n--;
		data->output_chars++;
	}
	if (flag == 0)
		data->indent = 0;
	else if (flag == 1)
		data->indent_right = 0;
}

int	ft_read_number(t_list *data)
{
	char	*str;
	int		i;
	int		number;

	i = 0;
	while (ft_isdigit(*data->form) == 1)
	{
		data->form++;
		i++;
	}
	str = ft_strnew(i);
	data->form = data->form - i;
	i = 0;
	while (ft_isdigit(*data->form) == 1)
		str[i++] = *data->form++;
	str[i] = '\0';
	number = ft_atoi(str);
	free(str);
	return (number);
}

void	*ft_memalloc(size_t size)
{
	void	*mem;

	mem = malloc(size);
	if (mem)
		ft_bzero(mem, size);
	return (mem);
}

void	ft_print_str(char *s, int start_index, int numb_to_print, t_list *data)
{
	while (start_index < numb_to_print)
	{
		write(1, &s[start_index++], 1);
		data->output_chars++;
	}
}

void	ft_int_putchar(char c, t_list *data)
{
	if (data->indent != 0)
		ft_print_indent(data->indent - 1, data, 0);
	while (data->zero_flag > 1)
	{
		write(1, "0", 1);
		data->zero_flag--;
	}
	write(1, &c, 1);
	data->output_chars++;
	if (data->indent_right != 0)
		ft_print_indent(data->indent_right - 1, data, 1);
}
