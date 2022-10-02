#pragma once

#include "../Engine/Physics.h"
#include "../Engine/Rendering.h"
#include "../Engine/Quadrangle.h"
#include "../Engine/Input.h"
#include "../Engine/Time.h"

class Image;
class TowerImage;

class ImageSpawner
{
public:
	ImageSpawner(void(* const way)(Image* const));
	TowerImage* Spawn();

private:
	void(* const Way)(Image* const);
};
