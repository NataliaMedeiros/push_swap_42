/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_errors.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmedeiro <nmedeiro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/27 11:40:14 by nmedeiro      #+#    #+#                 */
/*   Updated: 2024/03/27 14:37:12 by nmedeiro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(void)
{
	write (1, "Error\n", 6);
	exit (1);
}

/*1 true 0 false*/
int	error_syntax(char **argv)
{
	int		i;
	int		j;
	char	*c;

	i = 0;
	while (argv[i] != NULL)
	{
		j = 0;
		c = argv[i];
		while (c[j] != '\0')
		{
			if (!(c[j] == '+' || c[j] == '-' || (c[j] >= '0' && c[j] <= '9')))
				return (1);
			if ((c[j] == '+' || c[j] == '-')
				&& !(c[j + 1] >= '0' && c[j + 1] <= '9'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_doubles(char **argv)
{
	int		i;
	int		j;

	i = 0;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (argv[i][0] == '+' || argv[j][0] == '+')
			{
				if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
					return (1);
			}
			if (ft_strcmp(argv[i], argv[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/*1 true 0 false*/
int	is_valid(char **argv)
{
	long	n;
	int		i;
	char	**temp;

	if (error_syntax(argv))
		return (0);
	temp = argv;
	i = 0;
	while (temp[i])
	{
		n = ft_atol(temp[i]);
		if (n > INT_MAX || n < INT_MIN)
			return (0);
		i++;
	}
	if (check_doubles(temp) == 1)
		return (0);
	return (1);
}
