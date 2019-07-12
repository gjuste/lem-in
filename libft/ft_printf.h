/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjuste <gjuste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 15:25:03 by jpelleti          #+#    #+#             */
/*   Updated: 2019/05/25 22:21:45 by gjuste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>

# define SPC 1 << 0
# define PLS 1 << 1
# define MNS 1 << 2
# define ZER 1 << 3
# define HST 1 << 4
# define LLL 1 << 5
# define LER 1 << 6
# define HHH 1 << 7
# define HER 1 << 8
# define LNG 1 << 9

typedef struct			s_finfo
{
	unsigned long long	mantisse:52;
	unsigned short		exponent:11;
	unsigned char		sign:1;
}						t_finfo;

typedef union			u_f_bit
{
	double			nb;
	t_finfo			s;
}						t_f_bit;

typedef struct			s_ptf
{
	int				i;
	int				w;
	int				opt;
	int				lrg_cmp;
	int				prec;
	char			c;
	char			field;
	int				arglen;
	float			f;
}						t_ptf;

int						ft_printf(const char *fmt, ...);
int						ptf_parser(const char *fmt, t_ptf *stt);
void					ft_bzero_stt(t_ptf *stt);
void					find_fct(t_ptf *stt, va_list ap);
void					place_field(t_ptf *stt, int i);
int						find_alph(t_ptf *stt, va_list ap);
void					write_count(const char *fmt, t_ptf *stt, int len);
void					find_num1(t_ptf *stt, va_list ap);
long long int			d_conv_misc(t_ptf *stt, va_list ap);
unsigned long long int	u_conv_misc(t_ptf *stt, va_list ap);
long long int			o_conv_misc(t_ptf *stt, va_list ap);
void					find_num2(t_ptf *stt, va_list ap);
unsigned long long int	hex_conv_misc(t_ptf *stt, va_list ap);
long double				f_conv_misc(t_ptf *stt, va_list ap);
void					ft_calc_ent(char *str, t_f_bit u);
void					ft_calc_dec(char *str, t_f_bit u);
void					ft_add_string(char *str, char *add);
void					ft_add_string_dec(char *str, char *add, int offset);
void					f_prec(char *str, int i);
char					*ft_str_power_dec(char *str, int pow);
char					*ft_str_power(char *str, int pow);
int						ft_offset(int i);
void					unblank_offset(char *str, int offset);
int						check_float(t_ptf *stt, t_f_bit u);
void					ft_print_float(t_ptf *stt, t_f_bit u, char *str, int i);
void					ft_write_sign(int n, t_ptf *stt);

#endif
