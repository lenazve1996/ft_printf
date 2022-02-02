/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajirob@student.42.fr <ayajirob>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 18:10:36 by ayajirob          #+#    #+#             */
/*   Updated: 2022/02/02 21:12:39 by ayajirob@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef struct s_list
{
	int				precis;
	int				indent;
	int				indent_right;
	int				zero_flag;
	int				sharp;
	int				plus;
	int				space;
	const char		*form;
	int				specifier_flag;
	int				output_chars;
	struct s_list	*next;
}					t_list;

t_list	*ft_lstnew(const char *format);
int		ft_printf(const char *format, ...);
int		ft_output_for_px(unsigned long long n, char format, t_list *data);
int		ft_otput_for_x(unsigned int n, char specification);
char	*ft_itoa_xec(char *s, unsigned long long number, int len, char format);
void	ft_int_putchar(char c, t_list *data);
int		ft_otput_for_d(long number, t_list *data);
void	ft_otput_for_s(char *str, t_list *data);
void	ft_put_del_str(char *s, t_list *data, int index);
char	*ft_strnew(size_t size);
int		ft_count_char_number(unsigned long long n);
void	ft_print_indent(int n, t_list *data, int flag);
void	ft_print_str(char *s, int start_index, int numb_to_print, t_list *data);
int		ft_otput_for_u(unsigned int number, t_list *data);
void	ft_print_spaces_right(t_list *data, int len, int minus);
void	ft_print_spaces(t_list *data, int minus, int len, int number);
void	ft_print_zero(t_list *data, int len);
void	ft_print_indent(int n, t_list *data, int flag);
int		ft_read_number(t_list *data);
void	*ft_memalloc(size_t size);
int		ft_printf_sign(t_list *data, int number);
void	ft_print_str(char *s, int start_index, int numb_to_print, t_list *data);
void	ft_int_putchar(char c, t_list *data);

#endif
