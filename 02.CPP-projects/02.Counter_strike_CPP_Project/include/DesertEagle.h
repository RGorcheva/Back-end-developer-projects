#ifndef DESERT_EAGLE_H
#define DESERT_EAGLE_H

#include "Player.h"
#include <iostream>

class DesertEagle : public Pistol
{
public:
	DesertEagle();
	virtual bool fire(std::ostream& out, Player& other);
private:

};

#endif; /* DESERT_EAGLE_H */

