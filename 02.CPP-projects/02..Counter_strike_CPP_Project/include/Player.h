#ifndef PLAYER_H
#define PLAYER_H

#include "Defines.h"
#include "PlayerVitalData.h"
#include "Pistol.h"

class Pistol;

class Player
{
public:
	Player();
	const PlayerVitalData& getPlayerVitalData() const;
	PlayerVitalData& getPlayerVitalData();
	const Pistol* getPlayerPistol() const;
	Pistol* getPlayerPistol();
	const int getPlayerId() const;

	void setPlayerVitalData(const int health, const int armor);
	void setPlayerPistol(Pistol* pistol);
	void setPlayerPistol(const PistolType type, const int size, const int damage, const int ammo, const int bullets = 0);
	void setPlayerPistol(const int ammo, const int bullets);
	void setPlayerId(const int id);

private:
  PlayerVitalData m_playerData;
  Pistol* m_playerPistol;
  int m_playerId;
};

#endif /* PLAYER_H */
