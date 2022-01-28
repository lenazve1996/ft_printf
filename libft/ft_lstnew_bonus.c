/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajirob <ayajirob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:33:14 by ayajirob          #+#    #+#             */
/*   Updated: 2022/01/28 17:36:29 by ayajirob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(const char *format)
{
	t_list	*new_element;

	new_element = (t_list *)malloc(sizeof(t_list));
	if (!new_element)
		return (NULL);
	new_element->form = format;
	new_element->precision = 0;
	new_element->output_chars = 0;
	new_element->indent = 0;
	new_element->indent_right = 0;
	new_element->zero_flag = 0;
	new_element->next = NULL;
	return (new_element);
}
