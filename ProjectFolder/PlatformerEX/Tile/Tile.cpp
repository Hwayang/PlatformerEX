#include "Tile.h"
#include "../Player/Player.h"

#include <random>
#include <ctime>

Tile::Tile()
{
	std::random_device rd;
	std::mt19937_64 gen(rd());
	std::uniform_int_distribution<int> dis(-300 + (tileSkin.Length[0]), 300 - (tileSkin.Length[0]));

	tileSkin.Location[0] = Body.Center.x = dis(gen);
	tileSkin.Location[1] = Body.Center.y = 360;
}

Tile::Tile(float X, float Y)
{
	tileSkin.Location[0] = Body.Center.x = X;
	tileSkin.Location[1] = Body.Center.y = Y;
}

bool Tile::update(player* const target)
{
	tileSkin.Render();

	meetPlayer(target);

	Body.Center.y =  tileSkin.Location[1] -= 500 * Engine::Time::Get::Delta();

	return tileSkin.Location[1] > -360 - tileSkin.Length[1] * 0.5f;
}
