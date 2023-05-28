#ifndef PISTOL_H
#define PISTOL_H

#include "Player.h"
#include <iostream>

class Player;

class Pistol
{
public:
	const PistolType getPistolType() const;
	const int getDamagePerRound() const;
	const int getClipSize() const;
	const int getCurrClipBullets() const;
	const int getRemainingAmmo() const;

	void setPistolType(const PistolType new_type);
	void setDamagePerRound(const int new_damage);
	void setClipSize(const int new_size);
	void setCurrClipBullets(const int new_currClipBullets);
	void setRemainingAmmo(const int new_ammo);

	void reloadPistol(std::ostream& out);

	virtual bool fire(std::ostream& out, Player& other) = 0;

protected:
  PistolType m_pistolType;
  int m_damagePerRound;
  int m_clipSize;
  int m_currClipBullets;
  int m_remainingAmmo;
  Pistol();
};

#endif /* PISTOL_H */
