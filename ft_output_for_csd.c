/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_for_csd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajirob <ayajirob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:59:35 by ayajirob          #+#    #+#             */
/*   Updated: 2022/01/30 21:39:38 by ayajirob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_str(char *str, int start_index, int numb_to_print, t_list *data)
{
	while (start_index < numb_to_print)
	{
		write(1, &str[start_index++], 1);
		data->output_chars++;
	}
}

void ft_int_putchar(char c, t_list *data)
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

void	ft_put_del_str(char *s, t_list *data, int index)
{
	int	number_output_characters;
	int i;
	
	i = 0 + index;
	number_output_characters = ft_strlen(s);
	while (i < number_output_characters)
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
	int		len;
	int		minus;

	start_index = 0;
	str = ft_itoa(number);
	minus = 0;
	if (number < 0)
		minus = 1;
	len = ft_strlen(str);
	if (data->space == 1 && number >= 0)
	{
		write(1, " ", 1);
		data->output_chars++;
	}
	if (data->indent != 0)
	{
		if ((data->precision != -1 && data->precision > len) || data->precision == 0)
			ft_print_indent(data->indent - data->precision - minus, data, 0);
		else
			ft_print_indent(data->indent - len, data, 0);
	}
	if (data->zero_flag != 0 && data->precision != -1)
	{
		if (number == 0)
			len = 0;
		if (data->precision < len)
			ft_print_indent(data->zero_flag - len, data, 0);
		else
			ft_print_indent(data->zero_flag - data->precision - minus, data, 0);
		data->zero_flag = 0;
		len = ft_strlen(str);
	}
	if (data->plus == 1 && number >= 0)
	{
		write(1, "+", 1);
		data->output_chars++;
		minus = 1;
	}
	if (data->precision != -1)
	{
		char_numb = len;
		if (str[0] == '-' && data->precision > 0)
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
	if (data->zero_flag != 0 && data->precision == -1)
	{
		char_numb = ft_strlen(str);
		data->zero_flag = data->zero_flag - char_numb; 
		if (str[0] == '-' && data->zero_flag != 0 && data->precision == -1)
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
	if (data->precision == 0 && number == 0)
	{
		str[0] = '\0';
		len = 0;
	}
	ft_put_del_str(str, data, start_index);
	if (data->indent_right != 0)
	{
		if (data->precision != -1 && len <= data->precision)
			ft_print_indent(data->indent_right - data->precision - minus, data, 1);
		else
			ft_print_indent(data->indent_right - len, data, 1);
	}
	data->precision = -1;
	data->sharp = 0;
	data->space = 0;
}

void	ft_otput_for_u(unsigned int number, t_list *data)
{
	char	*str;
	int		char_numb;
	int		len;

	str = ft_itoa_u(number);
	len = ft_strlen(str);
	if (data->indent != 0)
	{
		if ((data->precision != -1 && data->precision > len) || data->precision == 0)
			ft_print_indent(data->indent - data->precision, data, 0);
		else
			ft_print_indent(data->indent - len, data, 0);
	}
	if (data->zero_flag != 0 && data->precision != -1)
	{
		if (number == 0)
			len = 0;
		if (data->precision < len)
			ft_print_indent(data->zero_flag - len, data, 0);
		else
			ft_print_indent(data->zero_flag - data->precision, data, 0);
		data->zero_flag = 0;
		len = ft_strlen(str);
	}
	if (data->precision != -1)
	{
		char_numb = len;
		while (char_numb < data->precision)
		{
			write(1, "0", 1);
			char_numb++;
			data->output_chars++;
		}
	}
	if (data->zero_flag != 0 && data->precision == -1)
	{
		char_numb = ft_strlen(str);
		data->zero_flag = data->zero_flag - char_numb; 
		while (data->zero_flag > 0)
		{
			write(1, "0", 1);
			data->zero_flag--;
			data->output_chars++;
		}
	}
	if (data->precision == 0 && number == 0)
	{
		str[0] = '\0';
		len = 0;
	}
	ft_put_del_str(str, data, 0);
	if (data->indent_right != 0)
	{
		if (data->precision != -1 && len < data->precision)
			ft_print_indent(data->indent_right - data->precision, data, 1);
		else
			ft_print_indent(data->indent_right - len, data, 1);
	}
	data->precision = -1;
	data->sharp = 0;
	data->space = 0;
}

void	ft_otput_for_s(char *str, t_list *data)
{
	int len;

	if (str == NULL)
	{
		str = "(null)\0";
	}
	len = ft_strlen(str);
	if (data->precision != -1)
	{
		if (data->precision > len)
			len = ft_strlen(str);
		else if (data->precision < len)
			len = data->precision;
	}
	if (data->indent != 0)
		ft_print_indent(data->indent - len, data, 0);
	ft_print_str(str, 0, len, data);
	if (data->indent_right != 0)
		ft_print_indent(data->indent_right - len, data, 1);
	data->precision = -1;
	data->sharp = 0;
	data->space = 0;
}
