/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 18:07:38 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/21 20:41:13 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "stdbool.h"
# include "command.h"
# include "lex.h"

typedef struct s_parser {
	t_command	*root;
	t_command	*cur_command;
}t_parser;

t_command	*parse(char *str);
bool		syntex_check(t_lex_list *lex_list);

#endif
