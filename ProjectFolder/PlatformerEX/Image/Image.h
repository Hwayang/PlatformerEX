#pragma once

#include "../Engine/Rendering.h"
#include "../Engine/Time.h"

class Image
{
public:
	bool update();
protected:
	Engine::Rendering::Image::Component imageSkin;
};

class TowerImage : public Image
{
public:
	TowerImage();
};

class SkyImage : public Image
{
public:
	SkyImage();
};