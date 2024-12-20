/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/26 14:45:23 by mgolubev      #+#    #+#                 */
/*   Updated: 2024/12/17 13:37:27 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <curses.h>
# include <signal.h>
# include <term.h>
# include "ast.h"
# include "lexer.h"
# include "parser.h"
# include "env.h"
# include "executer.h"

# define RESET	"\033[0m"
# define ORANGE	"\033[38;5;214m"
# define BLUE	"\033[34m"
# define GREEN	"\033[32m"
# define RED	"\033[31m"

# define PROMT_SIZE 1024

typedef enum e_minishell_state
{
	MINISHELL_START,
	MINISHELL_READLINE,
	MINISHELL_LEXER,
	MINISHELL_PARSER,
	MINISHELL_EXECUTER,
	MINISHELL_CLEAN,
	MINISHELL_EXIT
}	t_minishell_state;

typedef struct s_minishell
{
	char		*input;
	t_token		*tokens;
	t_ast_node	*ast;
	t_executer	exec;
	char		promt[PROMT_SIZE];
}	t_minishell;

typedef t_minishell_state	(*t_minishell_fn)(t_minishell *mshell);

t_minishell_state	fn_mshell_start(t_minishell *mshell, char **envp);
t_minishell_state	fn_mshell_redline(t_minishell *mshell);
t_minishell_state	fn_mshell_lexer(t_minishell *mshell);
t_minishell_state	fn_mshell_parser(t_minishell *mshell);
t_minishell_state	fn_mshell_executer(t_minishell *mshell);
t_minishell_state	fn_mshell_clean(t_minishell *mshell);

void				print_token(t_token *token);
void				print_ast_node(int depth, t_ast_node *node);

#endif
