#include "ImageSpawner.h"

#include "../Image/Image.h"

ImageSpawner::ImageSpawner(void(* const way)(Image* const)) : Way{ way }
{

}

TowerImage* ImageSpawner::Spawn()
{
	return new(TowerImage){};
}
