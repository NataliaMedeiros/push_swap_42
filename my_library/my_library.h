/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   my_library.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/13 11:14:35 by nmedeiro      #+#    #+#                 */
/*   Updated: 2024/03/27 14:35:42 by nmedeiro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_LIBRARY_H
# define MY_LIBRARY_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <limits.h>
# include <stdint.h>

# define FD 1
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

size_t	ft_strlen(const char *c);

int		ft_atoi(const char *nptr);

char	*ft_substr(char const *s, unsigned int start, size_t len);

char	**ft_split(char const *s, char c);

int		count_words(char const *s, char c);

char	**free_words(char **new_word, int i);

int		ft_strcmp(const char *s1, const char *s2);

char	*get_next_line(int fd);

char	*ft_strchr(const char *s, char c);

char	*read_file_and_join(int fd, char *text, char *line);

void	update_text(char *text);

char	*create_line(char *text);

char	*ft_join_str(char *s1, char *s2);

void	ft_bzero(void *s, size_t n);

size_t	ft_strlen(const char *s);

size_t	find_nl(char *text);

char	*get_next_line(int fd);

char	*ft_strchr(const char *s, char c);

char	*read_file_and_join(int fd, char *text, char *line);

void	update_text(char *text);

char	*create_line(char *text);

char	*ft_join_str(char *s1, char *s2);

void	ft_bzero(void *s, size_t n);

size_t	ft_strlen(const char *s);

size_t	find_nl(char *text);

void	ft_putendl(char *s);

int		ft_isdigit(int c);

long	ft_atol(const char *s);

#endif