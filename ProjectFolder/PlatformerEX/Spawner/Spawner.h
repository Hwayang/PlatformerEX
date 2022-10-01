#pragma once

#include "../Engine/Physics.h"
#include "../Engine/Rendering.h"
#include "../Engine/Quadrangle.h"
#include "../Engine/Input.h"
#include "../Engine/Time.h"

class LongGround;

class Spawner
{
public:
	Spawner(void(* const way)(LongGround* const));
	LongGround* Spawn();

private:
	int timeCount = 0;
	int spawnCount = 0;

	void(* const Way)(LongGround* const);
};
