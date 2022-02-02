/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajirob@student.42.fr <ayajirob>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:33:14 by ayajirob          #+#    #+#             */
/*   Updated: 2022/02/02 16:30:34 by ayajirob@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list	*ft_lstnew(const char *format)
{
	t_list	*new_element;

	new_element = (t_list *)malloc(sizeof(t_list));
	if (!new_element)
		return (NULL);
	new_element->form = format;
	new_element->precis = -1;
	new_element->output_chars = 0;
	new_element->indent = 0;
	new_element->indent_right = 0;
	new_element->zero_flag = 0;
	new_element->sharp = 0;
	new_element->plus = 0;
	new_element->space = 0;
	new_element->next = NULL;
	return (new_element);
}
