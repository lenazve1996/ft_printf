/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajirob <ayajirob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:59:04 by ayajirob          #+#    #+#             */
/*   Updated: 2022/01/28 17:36:51 by ayajirob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>


void	ft_print_indent(int n, t_list *data)
{
	while (n > 0)
	{
		write(1, " ", 1);
		n--;
		data->output_chars++;
	}
}

void	ft_format_detection(va_list argument, char format, t_list *data)
{
	int	output_chars;
	char	str[1000];
	int		i;

	output_chars = 0;
	i = 0;
	if (format == '.')
	{
		data->form++;
		while (ft_isdigit(*data->form) == 1)
			str[i++] = *data->form++;
		str[i] = '\0';
		data->precision = ft_atoi(str);
	}
	else if (format == '0')
	{
		data->form++;
		while (ft_isdigit(*data->form) == 1)
			str[i++] = *data->form++;
		str[i] = '\0';
		data->zero_flag = ft_atoi(str);
	}
	else if (ft_isdigit(format) == 1)
	{
		while (ft_isdigit(*data->form) == 1)
			str[i++] = *data->form++;
		str[i] = '\0';
		data->indent = ft_atoi(str);
	}
	else if (format == '-')
	{
		data->form++;
		while (ft_isdigit(*data->form) == 1)
			str[i++] = *data->form++;
		str[i] = '\0';
		data->indent_right = ft_atoi(str);
	}
	else if (format == 'c')
	{
		ft_int_putchar(va_arg(argument, int), data);
		data->specifier_flag = 0;
	}
	else if (format == 's')
	{
		ft_otput_for_s(va_arg(argument, char *), data);
		data->specifier_flag = 0;
	}
	else if (format == 'p')
	{
		data->specifier_flag = 0;
		ft_output_for_px(va_arg(argument, unsigned long long), format, data);
	}
	else if (format == 'x' || format == 'X')
	{
		data->specifier_flag = 0;
		ft_output_for_px(va_arg(argument, unsigned), format, data);
	}
	else if (format == 'd' || format == 'i')
	{
		ft_otput_for_d(va_arg(argument, int), data);
		data->specifier_flag = 0;
	}
	else if (format == 'u')
	{
		ft_otput_for_d(va_arg(argument, unsigned int), data);
		data->specifier_flag = 0;
	}
	else if (format == '%')
	{
		data->specifier_flag = 0;
		ft_int_putchar('%', data);
	}
	else
	{
		data->specifier_flag = 0;
		ft_int_putchar('%', data);
		ft_int_putchar(format, data);
	}
}

int	ft_printf(const char *format, ...)
{
	int		return_val;
	t_list	*data;
	va_list	argument;

	data = ft_lstnew(format);
	va_start(argument, format);
	data->specifier_flag = 0;
	while (*data->form != '\0')
	{
		if (data->specifier_flag == 1)
		{
			ft_format_detection(argument, *data->form, data);
		}
		else if (*data->form == '%')
		{
			data->specifier_flag = 1;
			data->form++;
		}
		else
			ft_int_putchar(*data->form, data);
		if (data->specifier_flag == 0)
			data->form++;
	}
	return_val = data->output_chars;
	free(data);
	return (return_val);
}
