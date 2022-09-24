#pragma once

#include<vector>

#include "../Engine/Physics.h"
#include "../Engine/Rendering.h"
#include "../Engine/Quadrangle.h"
#include "../Engine/Input.h"

class TileGroup
{
public:
	void tileAdd(Tile* target);

private:
	std::vector<Tile*> tileGroup;
};