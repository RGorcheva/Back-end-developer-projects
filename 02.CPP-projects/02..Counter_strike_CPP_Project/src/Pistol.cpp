#include "../include/Pistol.h"
#include "../include/Utility.h"
#include <iostream>

Pistol::Pistol()
	:m_pistolType(GLOCK)
	, m_damagePerRound(0)
	, m_clipSize(0)
	, m_currClipBullets(0)
	, m_remainingAmmo(0)
{};
const PistolType Pistol::getPistolType() const
{
	return m_pistolType;
};
const int Pistol::getDamagePerRound() const
{
	return m_damagePerRound;
};
const int Pistol::getClipSize() const
{
	return m_clipSize;
};
const int Pistol::getCurrClipBullets() const
{
	return m_currClipBullets;
};
const int Pistol::getRemainingAmmo() const
{
	return m_remainingAmmo;
}

void Pistol::setPistolType(const PistolType new_type)
{
	m_pistolType = new_type;
};
void Pistol::setDamagePerRound(const int new_damage)
{
	m_damagePerRound = new_damage;
};
void Pistol::setClipSize(const int new_size)
{
	m_clipSize = new_size;
};
void Pistol::setCurrClipBullets(const int new_currClipBullets)
{
	m_currClipBullets = new_currClipBullets;
};
void Pistol::setRemainingAmmo(const int new_ammo)
{
	m_remainingAmmo = new_ammo;
};
void Pistol::reloadPistol(std::ostream& out)
{
	out << "Reloading..." << std::endl;
	m_currClipBullets = min(m_remainingAmmo, m_clipSize);
	m_remainingAmmo = m_remainingAmmo - m_currClipBullets;
	out << "currClipBullets: " << m_currClipBullets << " remainingAmmo: " << m_remainingAmmo << std::endl;
}