/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:08:37 by rjaada            #+#    #+#             */
/*   Updated: 2025/01/17 12:41:48 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_special_char(char c)
{
	return (c == '|' || c == '<' || c == '>');
}

void	checker_input(char *input, int *i)
{
	while (input[*i])
	{
		if (input[*i] == ' ')
		{
			(*i)++;
			continue ;
		}
		if (is_special_char(input[*i]))
		{
			*i = handle_redirection(input, *i);
			continue ;
		}
		if (input[*i] == '$')
		{
			*i = handle_variable(input, *i);
			continue ;
		}
		if (input[*i] == '\'' || input[*i] == '\"')
		{
			*i = handle_quotes(input, *i);
			continue ;
		}
		break ;
	}
}