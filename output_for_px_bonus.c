/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_for_px_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajirob@student.42.fr <ayajirob>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:59:27 by ayajirob          #+#    #+#             */
/*   Updated: 2022/02/02 21:00:43 by ayajirob@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

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

char	*ft_add_x0(t_list *data, char format, int n, char *str)
{
	if (format == 'p' || (data->sharp == 1 && format == 'x' && n != 0))
	{
		str[1] = 'x';
		str[0] = '0';
	}
	else if (data->sharp == 1 && format == 'X' && n != 0)
	{
		str[1] = 'X';
		str[0] = '0';
	}
	return (str);
}

void	ft_print_x(t_list *data, char *str, char format, int n)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	if (format == 'p' || (data->sharp == 1 && format == 'x' && n != 0) || \
	(data->sharp == 1 && format == 'X' && n != 0))
	{
		while (i < 2)
		{
			write(1, &str[i++], 1);
			data->output_chars++;
		}
		ft_print_zero(data, len - 2);
	}
	else
		ft_print_zero(data, len);
	while (i < len)
	{
		write(1, &str[i++], 1);
		data->output_chars++;
	}
	free(str);
}

int	ft_output_for_px(unsigned long long n, char format, t_list *data)
{
	char	*str;
	int		len;

	len = ft_count_char_number(n);
	if (format == 'p' || (data->sharp == 1 && format == 'x' && n != 0) || \
	(data->sharp == 1 && format == 'X' && n != 0))
		len = len + 2;
	str = ft_strnew(len);
	if (str == NULL)
		return (1);
	str = ft_itoa_xec(str, n, len, format);
	str = ft_add_x0(data, format, n, str);
	len = ft_strlen(str);
	ft_print_spaces(data, 0, len, n);
	if (data->precis == 0 && n == 0)
	{
		str[0] = '\0';
		len = 0;
	}
	ft_print_x(data, str, format, n);
	ft_print_spaces_right(data, len, 0);
	return (0);
}
