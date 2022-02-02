/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajirob@student.42.fr <ayajirob>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:59:04 by ayajirob          #+#    #+#             */
/*   Updated: 2022/02/02 20:50:44 by ayajirob@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_process_format(va_list argument, char format, t_list *data)
{
	if (format == 'c')
		ft_int_putchar(va_arg(argument, int), data);
	else if (format == 's')
		ft_otput_for_s(va_arg(argument, char *), data);
	else if (format == 'p')
		ft_output_for_px(va_arg(argument, unsigned long long), format, data);
	else if (format == 'x' || format == 'X')
	{
		if (ft_output_for_px(va_arg(argument, unsigned), format, data) == 1)
			return (1);
	}
	else if (format == 'd' || format == 'i')
	{
		if (ft_otput_for_d(va_arg(argument, int), data) == 1)
			return (1);
	}
	else if (format == 'u')
		ft_otput_for_u(va_arg(argument, unsigned int), data);
	else if (format == '%')
		ft_int_putchar('%', data);
	data->specifier_flag = 0;
	return (0);
}

void	ft_process_flags(t_list *data, int format)
{
	data->form++;
	if (format == '.')
	{
		data->precis = 0;
		if (ft_isdigit(*data->form) == 1)
			data->precis = ft_read_number(data);
		if (data->precis < 0)
			data->precis = data->precis * (-1);
	}
	else if (format == '0')
		data->zero_flag = ft_read_number(data);
	else if (format == '-')
		data->indent_right = ft_read_number(data);
	else if (format == '#')
		data->sharp = 1;
	else if (format == '+' || format == ' ')
	{
		while ((*data->form) == format)
			data->form++;
		if (format == '+')
			data->plus = 1;
		else
			data->space = 1;
	}
}

int	ft_format_detection(va_list argument, char format, t_list *data)
{
	int	output_chars;

	output_chars = 0;
	if (format == '.' || format == '0' || format == '-' || format == '#' \
	|| format == '+' || format == ' ')
		ft_process_flags(data, format);
	else if (ft_isdigit(format) == 1)
		data->indent = ft_read_number(data);
	else if (format == 'c' || format == 's' || format == 'p' || format == 'x' \
	|| format == 'X' || format == 'd' || format == 'i' || format == 'u' || \
	format == '%')
	{
		if (ft_process_format(argument, format, data) == 1)
			return (1);
	}
	else
	{
		data->specifier_flag = 0;
		ft_int_putchar('%', data);
		ft_int_putchar(format, data);
	}
	return (0);
}

int	ft_read_str(t_list *data, va_list argument)
{
	while (*data->form != '\0')
	{
		if (data->specifier_flag == 1)
		{
			if (ft_format_detection(argument, *data->form, data) == 1)
				return (1);
			if (data->indent_right > 2147483646 || data->zero_flag > 2147483646 \
			|| data->precis == 2147483647 || data->indent > 2147483646)
				return (1);
			if (data->specifier_flag == 0)
				data->form++;
		}
		else if (*data->form == '%')
		{
			data->specifier_flag = 1;
			data->form++;
		}
		else
			ft_int_putchar(*data->form++, data);
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		return_val;
	t_list	*data;
	va_list	argument;

	data = ft_lstnew(format);
	if (data == NULL)
		return (-1);
	va_start(argument, format);
	data->specifier_flag = 0;
	if (ft_read_str(data, argument) == 1)
	{
		free(data);
		return (-1);
	}
	return_val = data->output_chars;
	free(data);
	return (return_val);
}
