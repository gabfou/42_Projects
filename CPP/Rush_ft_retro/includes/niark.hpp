// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   niark.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gfournie <gfournie@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/11/08 03:29:44 by gfournie          #+#    #+#             //
//   Updated: 2015/11/08 03:29:46 by gfournie         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef NIARK_HPP
#define NIARK_HPP

#include <iostream>
#include "le.hpp"
#include "MovingStuff.class.hpp"

class niark : public MovingStuff
{

public:

	niark(void);
	niark(niark const & src);
	virtual ~niark(void);

	virtual int	move(void);
	niark & operator=(niark const & src);
};

#endif
