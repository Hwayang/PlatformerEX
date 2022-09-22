#include "Tile.h"

Water::Water()
{
	tileSkin.Name = "Image/Tile_Water";
	tileSkin.Length = { 16,16 };

	Body.Length = { 16,16 };
}

void Water::meetPlayer(player* const target)
{

}

void Water::setTile(float X, float Y)
{

	tileSkin.Location = { X, Y };
}

void Water::update(player* const target)
{
}

