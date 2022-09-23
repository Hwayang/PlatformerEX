#pragma once

#include "../Engine/Physics.h"
#include "../Engine/Rendering.h"
#include "../Engine/Quadrangle.h"
#include "../Engine/Input.h"

class player;
class Tile
{
public:
	virtual bool meetPlayer(player* const target) abstract;
	virtual void setTile(float X, float Y) abstract;
	virtual void update(player* const target) abstract;
protected:
	Engine::Rendering::Image::Component tileSkin;
	Engine::Rendering::Image::Component bodySkin;
	Engine::Physics::Component<Quadrangle> Body;
};

class Ground : public Tile
{
public:
	bool meetPlayer(player* const target) override;
	void update(player* const target) override;

public:
	virtual void setTile(float X, float Y) abstract;
};

class GrassGround : public Ground
{
public:
	GrassGround();

	void setTile(float X, float Y) override;
};

class Obstacle : public Tile
{
public:
	Obstacle();

	bool meetPlayer(player* const target) override;
	void setTile(float X, float Y) override;
	void update(player* const target) override;
};