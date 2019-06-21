/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 17:59:06 by ksticks           #+#    #+#             */
/*   Updated: 2019/06/20 17:59:07 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_UTILS_H

# define FILE_UTILS_H

void	display_error(char const *fn, char *msg);
int		get_fd(char const *fn);
int		get_fd_len(int fd, char const *fn);

#endif
