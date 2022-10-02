#pragma once

#include "../Engine/Physics.h"
#include "../Engine/Rendering.h"
#include "../Engine/Quadrangle.h"
#include "../Engine/Input.h"

class player;
class Tile
{
public:
	Tile();
	Tile(float X, float Y);

	virtual bool meetPlayer(player* const target) abstract;
	bool update(player* const target);

protected:
	float const gravity = 9800.f;
	Engine::Rendering::Image::Component tileSkin;
	Engine::Physics::Component<Quadrangle> Body;
};

class Ground : public Tile
{
public:
	bool meetPlayer(player* const target) override;
};

class LongGround : public Ground
{
public:
	LongGround();
};

class Obstacle : public Tile
{
public:
	Obstacle();

	bool meetPlayer(player* const target) override;
};