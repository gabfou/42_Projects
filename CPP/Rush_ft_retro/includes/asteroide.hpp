// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   asteroide.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gfournie <gfournie@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/11/08 03:29:44 by gfournie          #+#    #+#             //
//   Updated: 2015/11/08 03:29:46 by gfournie         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ASTEROIDE_HPP
#define ASTEROIDE_HPP

#include <iostream>
#include "le.hpp"
#include "MovingStuff.class.hpp"

class asteroide : public MovingStuff
{

public:

	asteroide(void);
	asteroide(int x, int y, int x2, int y2);
	asteroide(asteroide const & src);
	virtual ~asteroide(void);
	void getation(void);

	asteroide & operator=(asteroide const & src);
};

#endif
