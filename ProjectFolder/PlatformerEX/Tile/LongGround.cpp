#include "Tile.h"

LongGround::LongGround()
{
	tileSkin.Name = "Image/Tile_GrassGround";
	BodySkin.Length = tileSkin.Length = { 220,72 };

	Body.Length = { 220,72 };
}