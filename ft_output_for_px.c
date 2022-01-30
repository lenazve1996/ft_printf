/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_for_px.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajirob <ayajirob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:59:27 by ayajirob          #+#    #+#             */
/*   Updated: 2022/01/30 21:04:01 by ayajirob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memalloc(size_t size)
{
	void	*mem;

	mem = malloc(size);
	if (mem)
		ft_bzero(mem, size);
	return (mem);
}

char	*ft_strnew(size_t size)
{
	return (ft_memalloc(size + 1));
}

int	ft_count_char_number(unsigned long long n)
{
	int	counter;

	counter = 0;
	if (n == 0)
		counter++;
	while (n != 0)
	{
		n = n / 16;
		counter++;
	}
	return (counter);
}

char	*ft_itoa_xec(char *s, unsigned long long number, int len, char format)
{
	char	c;

	s[len] = '\0';
	while (len)
	{
		c = (number % 16);
		if (c >= 10 && c <= 15 && (format == 'x' || format == 'p'))
			c = c + 87;
		else if (c >= 10 && c <= 15 && format == 'X')
			c = c + 55;
		else
			c = c + '0';
		s[--len] = c;
		number /= 16;
	}
	return (s);
}

int	ft_output_for_px(unsigned long long n, char format, t_list *data)
{
	char	*str;
	int		len;
	int		char_numb;

	len = ft_count_char_number(n);
	if (format == 'p' || (data->sharp == 1 && format =='x' && n != 0) || (data->sharp == 1 && format == 'X' && n != 0))
		len = len + 2;
	str = ft_strnew(len);
	if (str == NULL)
		return (1);
	str = ft_itoa_xec(str, n, len, format);
	if (format == 'p' || (data->sharp == 1 && format =='x' && n != 0))
	{
		str[1] = 'x';
		str[0] = '0';
	}
	else if (data->sharp == 1 && format == 'X' && n != 0)
	{
		str[1] = 'X';
		str[0] = '0';
	}
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
		if (n == 0)
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
	if (data->precision == 0 && n == 0)
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
	return (0);
}
