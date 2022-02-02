/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_for_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajirob@student.42.fr <ayajirob>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 13:12:45 by ayajirob@st       #+#    #+#             */
/*   Updated: 2022/02/02 20:43:56 by ayajirob@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strnew(size_t size)
{
	return (ft_memalloc(size + 1));
}

static	int	ft_count_char_number_u(unsigned int n)
{
	int	counter;

	counter = 0;
	if (n == 0)
		counter++;
	while (n != 0)
	{
		n = n / 10;
		counter++;
	}
	return (counter);
}

static	char	*ft_fill_str_u(char	*str, unsigned int n)
{
	*str = '\0';
	if (n == 0)
		*--str = '0';
	else
	{
		while (n != 0)
		{
			str--;
			*str = (n % 10) + '0';
			n = (n - (n % 10)) / 10;
		}
	}
	return (str);
}

char	*ft_itoa_u(unsigned int n)
{
	int		number_of_char;
	char	*str;

	number_of_char = ft_count_char_number_u(n);
	str = (char *)malloc((number_of_char + 1) * sizeof(char));
	if (!(str))
		return (NULL);
	str = str + number_of_char;
	str = ft_fill_str_u(str, n);
	return (str);
}

int	ft_otput_for_u(unsigned int number, t_list *data)
{
	char	*str;
	int		len;

	str = ft_itoa_u(number);
	if (str == NULL)
		return (1);
	len = ft_strlen(str);
	ft_print_spaces(data, 0, len, number);
	ft_print_zero(data, len);
	if (data->precis == 0 && number == 0)
	{
		str[0] = '\0';
		len = 0;
	}
	ft_put_del_str(str, data, 0);
	ft_print_spaces_right(data, len, 0);
	return (0);
}
