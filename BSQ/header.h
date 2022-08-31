/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:10:34 by enrgarci          #+#    #+#             */
/*   Updated: 2022/08/31 13:35:52 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char	get_pos(char *map, int x, int y, int *size);
int		calc_max_sqr(char *map, char obs, int *origin, int *size);
int		dist(int a, int *size);
int		get_max_pos(int *sqr_vals, int *size);
void	print_sol(char *map, int *sol, char sqr_symb, int *size);
int		length(char *array, int i);
char	*array_dict(int size, char *filename);
int		size_dict(char *filename);
int		check_array(char *array, char *symbols, int *row);
int		check_symbols(char *symbols);
int		check_column(char *array, int *col, int *row);
char	*clean_map(char *array, int *dim);
void	loop(char *map, int *size, int *sqr_val, char *symbols);
void	ft_stdin(void);
int		ft_atoi(char *str);
void	create_symbols(char *symbols, char *array, int pos);

#endif
