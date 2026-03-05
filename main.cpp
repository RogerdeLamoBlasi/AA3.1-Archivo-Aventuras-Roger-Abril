#include <iostream>
#include <fstream>
#include <vector>
#include <string>

//Define for the player
#define Player 'P'

std::vector<std::vector<char>> map;
std::string line;
char input;
bool Continue = true;

struct Coordinates {
	int y;
	int x;
};

Coordinates player;

//Reads the map from the file (mapa.txt) and prints it into the vector (found above)
void mapPrinting() {
	std::ifstream getmaps;
	getmaps.open("mapa.txt");
	if (!getmaps.is_open()) {
		std::cout << "File could not be opened";
	}
	else {
		char spots;
		while (std::getline(getmaps, line)) {
			map.push_back(std::vector<char>(line.begin(), line.end()));
		}
	}
}

//Saves the map after each iteration of the game loop (aka each time the player moves)
void mapSave() {
	std::ofstream getmaps;
	getmaps.open("mapa.txt");
	if (!getmaps.is_open()) {
		std::cout << "File could not be opened";
	}
	else {
		for (size_t i = 0; i < map.size(); i++)
		{
			for (size_t j = 0; j < map[i].size(); j++)
			{
				getmaps << map[i][j];
			}
			getmaps << "\n";
		}
	}
	getmaps.close();
	std::cout << "Map data succesfuly saved! \n";
}

//Prints the map at the console at the beggining of the game
void roundStart() {
	for (size_t i = 0; i < map.size(); i++)
	{
		for (size_t j = 0; j < map[i].size(); j++)
		{
			std::cout << map[i][j];
		}
		std::cout << std::endl;
	}
}

//Handle's the players input and what happens after (aka. if they can move or not, where they land, etc.)
void playerInput() {
	std::cin >> input;
	switch (input) {
	case 'W':
		if (map[player.y - 1][player.x] != '#') {
			map[player.y][player.x] = ' ';
			player.y -= 1;
		}
		break;
	case 'A':
		if (map[player.y][player.x - 1] != '#') {
			map[player.y][player.x] = ' ';
			player.x -= 1;
		}
		break;
	case 'S':
		if (map[player.y + 1][player.x] != '#') {
			map[player.y][player.x] = ' ';
			player.y += 1;
		}
		break;
	case 'D':
		if (map[player.y][player.x + 1] != '#') {
			map[player.y][player.x] = ' ';
			player.x += 1;
		}
		break;
		map[player.y][player.x] = Player;
	}
}

void spaceCheck(int coordX, int coordY, std::vector<std::vector<char>> map) {
	switch (map[coordY][coordX]){
		//checks for objects
	case 'C':
		//fucking whatever man idk we havent declared the objects yet
		//the items would be added here
		break;
		//checks for enemies
	case 'E':
		//the battle system, it should probably go with a (float) probability check function that assigns each object a probability and then adds it all up
		//makes a random number, check if its superior to the number of the probability, and assign win or loss (win: number < probability). Include reduce health on this and increase gold on win
		break;
	case '.':
		return;
	}
}

int main()
{
	mapPrinting();
	//Sets the BASE player coordinate, this is important since we dont know where the player will be when they start the game
	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[i].size(); j++)
		{
			if (map[i][j] == Player) {
				player = { i , j };
			}
		}
	}

	//GameLoop (lacks win condition for now)
	do {
		roundStart();
		playerInput();
		mapSave();
	} while (true);

}