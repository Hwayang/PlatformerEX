#include "Spawner.h"

#include "../Tile/Tile.h"

Spawner::Spawner(void(* const way)(LongGround* const)) : Way{ way }
{

}

LongGround* Spawner::Spawn()
{
	return new(LongGround){};
}
