/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 13:27:35 by avarnier          #+#    #+#             */
/*   Updated: 2021/03/05 03:59:59 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# include "struct.h"
# include "math.h"

/*# define UP 13
# define DOWN 1
# define TURN_LEFT 0
# define TURN_RIGHT 2*/

# define UP 122
# define DOWN 115
# define LEFT 113
# define RIGHT 100
# define TURN_LEFT 65361
# define TURN_RIGHT 65363
# define ESCAPE 65307

int	press_input(int key, t_game *game);
int	released_input(int key, t_player *player);

#endif
