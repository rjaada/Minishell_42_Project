/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:28:03 by kmoundir          #+#    #+#             */
/*   Updated: 2025/01/14 18:39:57 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	echo(int ac, char **av, int fd)
{
	int	i;

	i = 0;
	if (ac == 0)
	{
		ft_putchar_fd('\n', fd);
		return (0);
	}
	while (av[i] && !ft_strcmp(av[i], "-n"))
		i++;
	while (i < ac - 1)
	{
		ft_putstr_fd(av[i], fd);
		if (av[i + 1])
			ft_putstr_fd(" ", fd);
		i++;
	}
	if (i != ac)
		ft_putstr_fd(av[i], fd);
	if (ft_strcmp(av[0], "-n") != 0)
	{
		ft_putchar_fd('\n', fd);
	}
	return (0);
}
/*
int	main(int ac, char **av)
{
	if (ac >= 1)
	{
		echo(ac, (av + 1), 1);
	}
	else
		ft_putchar_fd('\n', 1);
	return (0);
}
*/