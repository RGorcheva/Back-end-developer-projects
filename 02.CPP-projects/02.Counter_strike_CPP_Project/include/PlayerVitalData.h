#ifndef PLAYER_VITAL_DATA_H
#define PLAYER_VITAL_DATA_H

class PlayerVitalData
{
public:
	PlayerVitalData();
	const int getHealth() const;
	const int getArmor() const;

	void setHealth(const int new_health);
	void setArmor(const int new_armor);

private:
	int m_health;
	int m_armor;
};

#endif /* PLAYER_VITAL_DATA_H */
