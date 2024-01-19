/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marredon <marredon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:37:48 by marredon          #+#    #+#             */
/*   Updated: 2023/05/25 13:16:27 by marredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;

	if (s == NULL)
		return (NULL);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	if (start > ft_strlen(s))
		len = 0;
	substr = (char *) malloc (len + 1);
	if (substr == NULL)
		return (NULL);
	if (start > ft_strlen(s) || !len)
	{
		*substr = '\0';
		return ((substr));
	}
	ft_strlcpy(substr, &s[start], len + 1);
	return (substr);
}
