/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bonus_error_check.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/31 12:20:54 by nmedeiro      #+#    #+#                 */
/*   Updated: 2024/04/02 16:59:20 by natalia       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
