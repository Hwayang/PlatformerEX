#include "Tile.h"

void Ground::meetPlayer(player* const target)
{
	if (Body.Collide(target->getBody()))
	{
		this->tileSkin.Name = "Image/RBB";
		target->getBody().Center.y = this->Body.Center.y + (this->Body.Length.y * 0.5f) + (target->getBody().Length.y * 0.5);
	}
}

void Ground::update(player* const target)
{
	meetPlayer(target);

	tileSkin.Render();
	/*bodySkin.Render();*/
}
