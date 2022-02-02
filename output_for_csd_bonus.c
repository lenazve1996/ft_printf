/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_for_csd_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajirob@student.42.fr <ayajirob>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:59:35 by ayajirob          #+#    #+#             */
/*   Updated: 2022/02/02 20:56:10 by ayajirob@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_put_del_str(char *s, t_list *data, int index)
{
	int	number_output_characters;
	int	i;

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

int	ft_process_prec_for_d(t_list *data, char *str)
{
	int	char_numb;
	int	start_index;

	start_index = 0;
	if (data->zero_flag != 0 && data->precis == -1)
	{
		char_numb = ft_strlen(str);
		data->zero_flag = data->zero_flag - char_numb;
		if (str[0] == '-' && data->zero_flag != 0 && data->precis == -1)
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
	return (start_index);
}

int	ft_print_zero_for_d(t_list *data, int len, char *str)
{
	int	char_numb;
	int	start_index;

	start_index = 0;
	if (data->precis != -1)
	{
		char_numb = len;
		if (str[0] == '-' && data->precis > 0)
		{
			write(1, "-", 1);
			char_numb--;
			data->output_chars++;
			start_index = 1;
		}
		while (char_numb < data->precis)
		{
			write(1, "0", 1);
			char_numb++;
			data->output_chars++;
		}
		if (start_index == 0)
		start_index = ft_process_prec_for_d(data, str);
	}
	return (start_index);
}

int	ft_otput_for_d(long number, t_list *data)
{
	char	*str;
	int		start_index;
	int		len;
	int		minus;

	str = ft_itoa(number);
	if (str == NULL)
		return (1);
	minus = 0;
	if (number < 0)
		minus = 1;
	len = ft_strlen(str);
	ft_print_spaces(data, minus, len, number);
	if (ft_printf_sign(data, number) == 0)
		minus = 1;
	start_index = ft_print_zero_for_d(data, len, str);
	if (data->precis == 0 && number == 0)
	{
		str[0] = '\0';
		len = 0;
	}
	ft_put_del_str(str, data, start_index);
	ft_print_spaces_right(data, len, minus);
	return (0);
}

void	ft_otput_for_s(char *str, t_list *data)
{
	int	len;

	if (str == NULL)
	{
		str = "(null)\0";
	}
	len = ft_strlen(str);
	if (data->precis != -1)
	{
		if (data->precis > len)
			len = ft_strlen(str);
		else if (data->precis < len)
			len = data->precis;
	}
	if (data->indent != 0)
		ft_print_indent(data->indent - len, data, 0);
	ft_print_str(str, 0, len, data);
	if (data->indent_right != 0)
		ft_print_indent(data->indent_right - len, data, 1);
	data->precis = -1;
	data->sharp = 0;
	data->space = 0;
}
