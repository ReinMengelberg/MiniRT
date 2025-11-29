/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rein <rein@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/08 20:10:52 by rein          #+#    #+#                 */
/*   Updated: 2025/11/29 14:24:51 by rmengelb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

// Libft
int			ft_isalpha(int i);
int			ft_isdigit(int i);
int			ft_isalnum(int i);
int			ft_isascii(int i);
int			ft_isprint(int i);
size_t		ft_strlen(const char *str);
void		*ft_memset(void *b, int c, size_t len);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
int			ft_toupper(int c);
int			ft_tolower(int c);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
long int	ft_atoi(const char *str);
void		*ft_calloc(size_t count, size_t size);
char		*ft_strdup(const char *s1);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strjoin_array(char **strings, int count, const char *separator);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);

// ft_printf
int			ft_printf(const char *format, ...);
int			ft_dprintf(int fd, const char *format, ...);
int			ft_ft_dprintf(int fd, const char *format, ...);
int			ft_which_dprint(int fd, char specifier, va_list args);
int			ft_dprint_c(int fd, int c);
int			ft_dprint_s(int fd, char *s);
int			ft_dprint_p(int fd, void *p);
int			ft_dprint_d(int fd, int d);
int			ft_dprint_i(int fd, int i);
int			ft_dprint_u(int fd, unsigned int u);
int			ft_dprint_x(int fd, unsigned int x);
int			ft_dprint_xupper(int fd, unsigned int x);
int			ft_dprint_procent(int fd);
int			ft_dprint_rev(int fd, char *str);

// get_next_line
char		*get_next_line(int fd);
int			contains_nl(char *str);
int			strlen_nl(char *str);
char		*allocate_result(char *line, char *buffer);

#endif