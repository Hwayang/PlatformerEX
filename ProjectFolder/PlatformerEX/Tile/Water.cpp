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

