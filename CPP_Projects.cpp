#include <iostream>
#include "Player.h"
void AnalizePlayerStats(Player player) {
	player.Show();
}
int main()
{
	Player player1("Bob", 10, 20);
	AnalizePlayerStats(player1);
}
