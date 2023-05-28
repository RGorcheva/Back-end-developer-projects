#include "../include/PlayerVitalData.h"

PlayerVitalData::PlayerVitalData()
	:m_health(0)
	,m_armor(0)
{}
const int PlayerVitalData::getHealth() const
{
	return m_health;
};
const int PlayerVitalData::getArmor() const
{
	return m_armor;
};
void PlayerVitalData::setHealth(int new_health)
{
	m_health = new_health;
};
void PlayerVitalData::setArmor(int new_armor)
{
	m_armor = new_armor;
};

