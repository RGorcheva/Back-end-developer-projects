#include "../include/Glock.h"
#include "../include/Utility.h"
#include <iostream>

Glock::Glock()
	:Pistol() {}

bool Glock::fire(std::ostream& out, Player& other)
{
	for (int i = 0; i != ROUNDS_PER_FIRE; i++)
	{
		if (m_remainingAmmo == 0 and m_currClipBullets == 0)
		{
			out << "No ammo left" << std::endl;
			out << std::endl;
			return false;
		}
		if (m_currClipBullets == 0)
		{
			this->reloadPistol(out);
			out << std::endl;
			return false;
		}
		if (other.getPlayerVitalData().getArmor() == 0)
		{
			other.setPlayerVitalData(other.getPlayerVitalData().getHealth() - m_damagePerRound, 0);
		}
		else if (other.getPlayerVitalData().getArmor() < static_cast <int>(0.5 * m_damagePerRound))
		{
			other.setPlayerVitalData(other.getPlayerVitalData().getHealth() - (m_damagePerRound - other.getPlayerVitalData().getArmor()), 0);
		}
		else
		{
			other.setPlayerVitalData(other.getPlayerVitalData().getHealth() - static_cast < int>(0.5 * m_damagePerRound), max(other.getPlayerVitalData().getArmor() - static_cast < int>(0.5 * m_damagePerRound), 0));
		}
		m_currClipBullets--; 
		out << "Enemy left with " << other.getPlayerVitalData().getHealth() << " health and " << other.getPlayerVitalData().getArmor() << " armor" << std::endl;
		if (other.getPlayerVitalData().getHealth() <= 0)
		{
			out << std::endl;
			return true;
		}
	}
	out << std::endl;
	return false;
}
