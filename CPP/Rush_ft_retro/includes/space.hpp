// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   space.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gfournie <gfournie@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/11/08 03:29:44 by gfournie          #+#    #+#             //
//   Updated: 2015/11/08 03:29:46 by gfournie         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SPACE_HPP
#define SPACE_HPP

#include <iostream>
#include "le.hpp"
#include "MovingStuff.class.hpp"

class space : public MovingStuff
{

	int mana;

public:

	space(void);
	space(space const & src);
	virtual ~space(void);

	int getation(void);
	virtual int	move(void);
	space & operator=(space const & src);
};

#endif
