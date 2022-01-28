/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_for_csd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajirob <ayajirob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:59:35 by ayajirob          #+#    #+#             */
/*   Updated: 2022/01/28 17:42:01 by ayajirob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_int_putchar(char c, t_list *data)
{
	if (data->indent != 0)
		ft_print_indent(data->indent - 1, data);
	write(1, &c, 1);
	data->output_chars++;
	if (data->indent_right != 0)
		ft_print_indent(data->indent_right, data);
}

void	ft_put_del_str(char *s, t_list *data, int index)
{
	int	number_output_characters;
	int i;
	
	i = 0 + index;
	number_output_characters = ft_strlen(s);
	while (i <= number_output_characters)
	{
		write(1, &s[i], 1);
		i++;
	}
	data->output_chars = data->output_chars + number_output_characters - index;
	free(s);
	s = NULL;
}

void	ft_otput_for_d(long number, t_list *data)
{
	char	*str;
	int		char_numb;
	int		start_index;

	start_index = 0;
	str = ft_itoa(number);
	if (data->indent != 0)
	{
		if (data->precision != 0)
			ft_print_indent(data->indent - data->precision, data);
		else
			ft_print_indent(data->indent - ft_strlen(str), data);
	} 
	if (data->precision != 0)
	{
		char_numb = ft_strlen(str);
		if (str[0] == '-')
		{
			write(1, "-", 1);
			char_numb--;
			data->output_chars++;
			start_index = 1;
		}
		while (char_numb < data->precision)
		{
			write(1, "0", 1);
			char_numb++;
			data->output_chars++;
		}
	}
	if (data->zero_flag != 0)
	{
		char_numb = ft_strlen(str);
		data->zero_flag = data->zero_flag - char_numb; 
		if (str[0] == '-')
		{
			write(1, "-", 1);
			data->output_chars++;
			start_index = 1;
		}
		while (data->zero_flag > 0)
		{
			write(1, "0", 1);
			data->zero_flag--;
			data->output_chars++;
		}
	}
	ft_put_del_str(str, data, start_index);
	if (data->indent_right != 0)
		ft_print_indent(data->indent_right, data);
}

void	ft_otput_for_s(char *str, t_list *data)
{
	if (str == NULL)
	{
		if (data->indent != 0)
			ft_print_indent(data->indent - 6, data);
		ft_putstr_fd("(null)", 1);
		data->output_chars = data->output_chars + 6;
	}
	else
	{
		if (data->indent != 0)
			ft_print_indent(data->indent - ft_strlen(str), data);
		ft_putstr_fd(str, 1);
		data->output_chars = data->output_chars + ft_strlen(str);
	}
	if (data->indent_right != 0)
		ft_print_indent(data->indent_right, data);
}
