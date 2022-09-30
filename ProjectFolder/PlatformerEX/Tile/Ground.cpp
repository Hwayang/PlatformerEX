#include "Tile.h"
#include "../Player/Player.h"

bool Ground::meetPlayer(player* const target)
{
	if (Body.Collide(target->getBody()))
	{
		target->getBody().Center.y = this->Body.Center.y + (this->Body.Length.y * 0.5f) + (target->getBody().Length.y * 0.5);
		target->getSkin().Location[1] = this->Body.Center.y + (this->Body.Length.y * 0.5f) + (target->getSkin().Length[1] * 0.5);
		return true;
	}

	return false;
}

void Ground::update(player* const target)
{
	/*tileSkin.Location[1] = Body.Center.y -= 100;*/
	meetPlayer(target);
	tileSkin.Render();
}