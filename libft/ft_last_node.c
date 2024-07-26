/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_last_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiepark <jiepark@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 17:18:16 by jiepark           #+#    #+#             */
/*   Updated: 2024/07/26 17:18:18 by jiepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../includes/push_swap.h"

t_node	*ft_lst_node(t_node *node)
{
	if (!node)
		return (NULL);
	while (node->right)
		node = node->right;
	return (node);
}
