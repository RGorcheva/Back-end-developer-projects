#ifndef BATTLEFIELD_H
#define BATTLEFIELD_H

#include <vector>
#include <iostream>
#include "Player.h"

class BattleField
{
public:
	//std::vector<Player>players[PLAYERS_COUNT];
	Player m_players[PLAYERS_COUNT];

	void createPlayers(std::istream& in);
	void buyPistols(std::istream& in);
	void reload(std::ostream& out);
	void startBattle(std::ostream& out);
};

#endif /* BATTLEFIELD_H */
