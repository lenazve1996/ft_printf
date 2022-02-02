/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajirob@student.42.fr <ayajirob>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 13:26:47 by ayajirob@st       #+#    #+#             */
/*   Updated: 2022/02/02 16:30:40 by ayajirob@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_spaces(t_list *data, int minus, int len, int number)
{
	if (data->space == 1 && number >= 0)
	{
		write(1, " ", 1);
		data->output_chars++;
	}
	if (data->indent != 0)
	{
		if ((data->precis != -1 && data->precis > len) || data->precis == 0)
			ft_print_indent(data->indent - data->precis - minus, data, 0);
		else
			ft_print_indent(data->indent - len, data, 0);
	}
	if (data->zero_flag != 0 && data->precis != -1)
	{
		if (number == 0)
			len = 0;
		if (data->precis < len)
			ft_print_indent(data->zero_flag - len, data, 0);
		else
			ft_print_indent(data->zero_flag - data->precis - minus, data, 0);
		data->zero_flag = 0;
	}
}

int	ft_printf_sign(t_list *data, int number)
{
	if (data->plus == 1 && number >= 0)
	{
		write(1, "+", 1);
		data->output_chars++;
		return (0);
	}
	return (1);
}

void	ft_print_spaces_right(t_list *data, int len, int minus)
{
	if (data->indent_right != 0)
	{
		if (data->precis != -1 && len <= data->precis)
			ft_print_indent(data->indent_right - data->precis - minus, data, 1);
		else
			ft_print_indent(data->indent_right - len, data, 1);
	}
	data->precis = -1;
	data->sharp = 0;
	data->space = 0;
}

void	ft_print_zero(t_list *data, int len)
{
	int	char_numb;

	char_numb = len;
	if (data->precis != -1)
	{
		while (char_numb < data->precis)
		{
			write(1, "0", 1);
			char_numb++;
			data->output_chars++;
		}
	}
	if (data->zero_flag != 0 && data->precis == -1)
	{
		data->zero_flag = data->zero_flag - len;
		while (data->zero_flag > 0)
		{
			write(1, "0", 1);
			data->zero_flag--;
			data->output_chars++;
		}
	}
}
