// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   boss.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gfournie <gfournie@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/11/08 03:29:44 by gfournie          #+#    #+#             //
//   Updated: 2015/11/08 03:29:46 by gfournie         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef boss_HPP
#define boss_HPP

#include <iostream>
#include "le.hpp"
#include "MovingStuff.class.hpp"

class boss : public MovingStuff
{

public:

	boss(void);
	boss(boss const & src);
	virtual ~boss(void);

	virtual int	move(void);
	boss & operator=(boss const & src);
};

#endif
