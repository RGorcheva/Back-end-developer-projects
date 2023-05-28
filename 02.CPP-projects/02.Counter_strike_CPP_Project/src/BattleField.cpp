#define _CRT_SECURE_NO_WARNINGS

#include "../include/BattleField.h"
#include "../include/Glock.h"
#include "../include/DesertEagle.h"
#include "../include/Utility.h"
#include <math.h>

void BattleField::createPlayers(std::istream& in)
{
  int playerHealth = 0;
  int playerArmor = 0;

  for (int i = 0; i < PLAYERS_COUNT; ++i) 
  {
      in >> playerHealth >> playerArmor;
      m_players[i].setPlayerVitalData(playerHealth, playerArmor);
      m_players[i].setPlayerId(i);
  }
}

void BattleField::buyPistols(std::istream& in)
{
  int pistolId = 0;
  PistolType pistolType = GLOCK;
  int pistolClipSize = 0;
  int pistolDamagePerRound = 0;
  int pistolRemainingAmmo = 0;
  for (int i = 0; i < PLAYERS_COUNT; ++i) 
  {
      in >> pistolId >> pistolDamagePerRound >> pistolClipSize >> pistolRemainingAmmo;
      switch (pistolId)
      {
      case 0: pistolType = GLOCK; break;
      case 1: pistolType = DESERT_EAGLE; break;
      default: break;
      };
      if (pistolType == GLOCK)
      {
          Pistol* glock = new Glock();
          m_players[i].setPlayerPistol(glock);
      }
      else if (pistolType == DESERT_EAGLE)
      {
          Pistol* eagle = new DesertEagle();
          m_players[i].setPlayerPistol(eagle);
      }
      m_players[i].setPlayerPistol(pistolType, pistolClipSize, pistolDamagePerRound, pistolRemainingAmmo, pistolClipSize);
  }
}

void BattleField::reload(std::ostream& out)
{
    for (int i = 0; i < PLAYERS_COUNT; ++i)
    {
        m_players[i].getPlayerPistol()->reloadPistol(out);
    }
}

void BattleField::startBattle(std::ostream& out)
{
	bool isEnemyDead = false;
    int winnerId = -1;
	while (isEnemyDead != true)
	{
		for (int i = 0; i < PLAYERS_COUNT; ++i)
		{
			out << "PlayerID " << i << " turn:" << std::endl;
			isEnemyDead = m_players[i].getPlayerPistol()->fire(out, this->m_players[abs(i-1)]);
            winnerId = i;
            if (isEnemyDead == true) break;
		}
	}
    out << "Player with ID: " << winnerId << " wins!" << std::endl;
}