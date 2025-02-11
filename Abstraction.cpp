#include<iostream>

class Sword {
private:
	int damage;
	int durability;
	int armorPiercing;
public:
	Sword(int damage, int durability, int armorPiercing) : damage(damage), durability(durability), armorPiercing(armorPiercing) {}
	void GiveInfo() { std::cout << "sword info\n"; };
};
class Unit 
{
private:
	int health;

public:
	Unit(int health) : health(health) {}
	int GetHealth() { return health; }

	virtual void Move() = 0;

	virtual ~Unit() = 0;
};
Unit::~Unit() {}
class Ork : public Unit
{
private:
	Sword* sword = nullptr;
public:
	Ork(int health,Sword* sword) : Unit(health)
	{
		this->sword = sword;
	}
	virtual void Move() override
	{
		std::cout << "Moveeeee ORK!\n";
	}
	virtual ~Ork() override {
		
		delete sword;
		sword = nullptr;
	
	}
};

int main() {

	Sword* s = new Sword(5, 100, 0);
	Unit *unit = new Ork(20,s);
	s->GiveInfo();
	unit->Move();


	return 0;
}