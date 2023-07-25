/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 20:27:34 by youjeong          #+#    #+#             */
/*   Updated: 2023/07/24 17:42:28 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse/type_parse.h"
#include "../../includes/parse/data.h"
#include "../../libft/includes/libft.h"

t_token	*get_token(void);
void	free_token(t_token *token);
t_token	*get_token_with_data(const char *word, t_type type);

t_token	*get_token(void)
{
	t_token	*new_token;

	new_token = (t_token *)malloc(1 * sizeof(t_token));
	if (!new_token)
		crash("", errno);
	new_token->word = 0;
	new_token->type = 0;
	return (new_token);
}

void	free_token(t_token *token)
{
	if (token->word)
		free(token->word);
	free(token);
}

t_token	*get_token_with_data(const char *word, t_type type)
{
	t_token	*new_token;

	new_token = get_token();
	if (!new_token)
		crash("", errno);
	if (word)
	{
		new_token->word = ft_strdup(word);
		if (!new_token->word)
			crash("", errno);
	}
	new_token->type = type;
	return (new_token);
}
