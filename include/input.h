/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 13:27:35 by avarnier          #+#    #+#             */
/*   Updated: 2021/03/03 18:05:16 by avarnier         ###   ########.fr       */
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
# define TURN_LEFT 113
# define TURN_RIGHT 100

int	movement_press(int key, t_game *game);
int	movement_released(int key, t_player *player);

#endif
