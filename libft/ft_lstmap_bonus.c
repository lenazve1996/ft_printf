/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajirob <ayajirob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 23:12:46 by ayajirob          #+#    #+#             */
/*   Updated: 2022/01/28 15:59:08 by ayajirob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(const char *), void (*del)(const char *))
{
	t_list	*new_lst;
	t_list	*start;
	char	*new_content;

	new_lst = ft_lstnew(f(lst->form));
	if (new_lst == NULL)
		return (NULL);
	start = new_lst;
	lst = lst->next;
	while (lst)
	{
		new_content = f(lst->form);
		new_lst->next = ft_lstnew(new_content);
		if (new_lst->next == NULL)
		{
			ft_lstclear(&start, del);
			return (NULL);
		}
		lst = lst->next;
		new_lst = new_lst->next;
	}
	return (start);
}
