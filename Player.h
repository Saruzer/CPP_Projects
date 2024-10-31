#pragma once
class Player
{
private:
	const int maxNameLength = 30;
	int health;
	int damage;
	char* name;
public:
	Player();
	Player(const Player& player);
	Player(const char Name[],int health, int damage);
	Player(const char Name[]);
	Player(int health, int damage);
	~Player();

	void Show();
};

