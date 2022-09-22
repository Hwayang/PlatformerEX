#pragma once

#include "../Player/Player.h"

#include "../Engine/Physics.h"
#include "../Engine/Rendering.h"
#include "../Engine/Quadrangle.h"
#include "../Engine/Input.h"

class Tile
{
public:
	virtual void meetPlayer(player* const target) abstract;
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
	void meetPlayer(player* const target) override;
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

class Water : public Tile
{
public:
	Water();

	void meetPlayer(player* const target) override;
	void setTile(float X, float Y) override;
	void update(player* const target) override;
};