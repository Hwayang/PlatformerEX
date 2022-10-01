#include "Tile.h"
#include "../Player/Player.h"

bool Ground::meetPlayer(player* const target)
{
	if (Body.Collide(target->getBody()))
	{
		target->getSkin().Location[1] = target->getBody().Center.y = this->Body.Center.y + (this->Body.Length.y * 0.5f) + (target->getBody().Length.y * 0.5);
		return true;
	}

	return false;
}