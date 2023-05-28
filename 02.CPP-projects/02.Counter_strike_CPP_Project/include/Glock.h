#ifndef GLOCK_H
#define GLOCK_H

#include "Player.h"

class Player;

class Glock : public Pistol
{
public:
	Glock();
	virtual bool fire(std::ostream& out, Player& other);
private:

};

#endif; /* GLOCK_H */
