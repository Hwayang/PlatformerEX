#include "Tile.h"
#include "../Player/Player.h"

bool Ground::meetPlayer(player* const target)
{
	if (Body.Collide(target->getBody()))
	{
		if (target->getState() == 1)
			if(target->getBody().Center.y - target->getBody().Length.y / 2 - this->Body.Center.y + (this->Body.Length.y * 0.5f) <= 0 )
				target->isGround = true;

		if(target->isGround == true and target->gamestart == true)
			target->getSkin().Location[1] = target->getBody().Center.y = this->Body.Center.y + (this->Body.Length.y * 0.5f) + (target->getBody().Length.y * 0.5);
		
		return true;
	}
	else
	{
		/*target->isGround = false;*/
		return false;
	}

}