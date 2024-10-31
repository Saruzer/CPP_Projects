#include "Player.h"
#include "iostream"

Player::Player() : health(1),damage(1)
{
	std::cout << "Default Constructor" << std::endl;
	name = new char[maxNameLength] {(const char)"Unnamed"};
}

Player::Player(const Player& player)
{
	std::cout << "Copy Constructor" << std::endl;
	if (name != nullptr && health > 0 && damage > 0) {
		name = new char[maxNameLength];
		strcpy_s(name, maxNameLength, player.name);
		health = player.health;
		damage = player.damage;
	}
}

Player::Player(const char Name[], int Health, int Damage) : Player()
{
	if (Name != nullptr && Health > 0 && Damage > 0) {
		strcpy_s(name, maxNameLength, Name);
		health = Health;
		damage = Damage;
	}
}

Player::Player(const char Name[]) : Player(Name,1,1)
{
}

Player::Player(int Health, int Damage) : Player("Unnamed", Health, Damage)
{
}


Player::~Player()
{
	std::cout << "Default Destructor" << std::endl;
	delete[] name;
}

void Player::Show()
{
	std::cout << "Name: " << name << std::endl;
	std::cout << "Health: " << health << std::endl;
	std::cout << "Damage: " << damage << std::endl;
}
