#include "TileSpawner.h"

#include "../Tile/Tile.h"

TileSpawner::TileSpawner(void(* const way)(LongGround* const)) : Way{ way }
{

}

LongGround* TileSpawner::Spawn()
{
	return new(LongGround){};
}
