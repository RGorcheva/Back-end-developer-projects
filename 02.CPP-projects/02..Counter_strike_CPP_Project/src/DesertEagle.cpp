#include "../include/DesertEagle.h"
#include "../include/Utility.h"
#include <iostream>

DesertEagle::DesertEagle()
	: Pistol() {}

bool DesertEagle::fire(std::ostream& out, Player& other)
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
	else if (other.getPlayerVitalData().getArmor() < static_cast<int>(0.5 * m_damagePerRound))
	{
		other.setPlayerVitalData(other.getPlayerVitalData().getHealth() - (m_damagePerRound - other.getPlayerVitalData().getArmor()), 0);
	}
	else
	{
		other.setPlayerVitalData(other.getPlayerVitalData().getHealth() - static_cast<int>(0.75 * m_damagePerRound), max(other.getPlayerVitalData().getArmor() - static_cast<int>(0.25 * m_damagePerRound), 0));
	}	
	m_currClipBullets--;
	out << "Enemy left with " << other.getPlayerVitalData().getHealth() << " health and " << other.getPlayerVitalData().getArmor() << " armor" << std::endl;
	out << std::endl;
	return (other.getPlayerVitalData().getHealth() <= 0) ? true : false;
}

