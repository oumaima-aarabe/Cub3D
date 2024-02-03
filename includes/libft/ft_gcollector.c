/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gcollector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaiq <ichaiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 20:06:45 by ichaiq            #+#    #+#             */
/*   Updated: 2023/07/27 19:51:19 by ichaiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	**get_gcollector(void)
{
	static t_list	**gcollector;

	if (!gcollector)
	{
		gcollector = malloc(1 * sizeof(t_list *));
		ft_bzero(gcollector, sizeof(t_list *));
	}
	return (gcollector);
}

void	set_gcollector(t_list *gcol)
{
	t_list	**gcollector;

	gcollector = get_gcollector();
	*gcollector = gcol;
}

void	add_gcol(void *ptr)
{
	t_list	*node;
	t_list	**gcol;
	t_list	*tmp;

	gcol = get_gcollector();
	node = malloc(sizeof(t_list));
	if (!node)
		return ;
	node->content = ptr;
	node->next = NULL;
	tmp = *gcol;
	if (!tmp)
		return (set_gcollector(node));
	while (tmp && tmp->next)
		tmp = tmp->next;
	tmp->next = node;
}

void	free_node(t_list *node)
{
	free(node->content);
	free(node);
}

void	ft_free(void *ptr)
{
	t_list	*last;
	t_list	**gcol;
	t_list	*tmp;
	t_list	*first;

	gcol = get_gcollector();
	first = *gcol;
	last = *gcol;
	tmp = *gcol;
	while (tmp)
	{
		if (tmp->content == ptr)
		{
			if (last && last != first)
				last->next = tmp->next;
			else if (first == last)
				first = tmp->next;
			set_gcollector(first);
			free_node(tmp);
			return ;
		}
		last = tmp;
		tmp = tmp->next;
	}
	free(ptr);
}
