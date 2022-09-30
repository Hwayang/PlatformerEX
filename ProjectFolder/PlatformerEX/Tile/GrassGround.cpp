#include "Tile.h"

GrassGround::GrassGround()
{
	tileSkin.Name = "Image/Tile_GrassGround";
	tileSkin.Length = { 300,100 };

	bodySkin.Name = "Image/Tile_GBC";
	bodySkin.Length = { 300,100 };

	Body.Length = { 100,100 };
}

void GrassGround::setTile(float X, float Y)
{
	tileSkin.Location = bodySkin.Location = { X, Y };
	Body.Center = { X, Y };
}
