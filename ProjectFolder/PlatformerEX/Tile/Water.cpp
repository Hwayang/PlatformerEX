#include "Tile.h"

Obstacle::Obstacle()
{
	tileSkin.Name = "Image/Tile_Obstacle";
	tileSkin.Length = { 16,16 };

	Body.Length = { 16,16 };
}

bool Obstacle::meetPlayer(player* const target)
{
	return false;
}

void Obstacle::setTile(float X, float Y)
{

	tileSkin.Location = { X, Y };
}

void Obstacle::update(player* const target)
{
}

