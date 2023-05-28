#include "../include/Player.h"

Player::Player()
	:m_playerId(0)
	,m_playerPistol(nullptr)
{};

const PlayerVitalData& Player::getPlayerVitalData() const
{
	return m_playerData;
};
PlayerVitalData& Player::getPlayerVitalData()
{
	return m_playerData;
};
const Pistol* Player::getPlayerPistol() const
{
	return m_playerPistol;
};
Pistol* Player::getPlayerPistol()
{
	return m_playerPistol;
};
const int Player::getPlayerId() const
{
	return m_playerId;
}
void Player::setPlayerVitalData(const int health, const int armor)
{
	m_playerData.setHealth(health);
	m_playerData.setArmor(armor);
};
void Player::setPlayerPistol(Pistol* pistol)
{
	m_playerPistol = pistol;
}
void Player::setPlayerPistol(const PistolType type, const int size, const int damage, const int ammo, const int bullets)
{
	m_playerPistol->setPistolType(type);
	m_playerPistol->setClipSize(size);
	m_playerPistol->setDamagePerRound(damage);
	m_playerPistol->setRemainingAmmo(ammo);
	m_playerPistol->setCurrClipBullets(bullets);
};
void Player::setPlayerPistol(const int ammo, const int bullets)
{
	m_playerPistol->setRemainingAmmo(ammo);
	m_playerPistol->setCurrClipBullets(bullets);
};
void Player::setPlayerId(const int id)
{
	m_playerId = id;
};

