#pragma once

#include <algorithm>

#include "../Engine/Physics.h"
#include "../Engine/Rendering.h"
#include "../Engine/Quadrangle.h"
#include "../Engine/Input.h"
#include "../Engine/Time.h"

class player
{
public:
	player();
	void stateChange();
	void move(float const direction);
	void jump();
	void Update();

	Engine::Physics::Component<Quadrangle>& getBody();

private:
	float weight = 50.f;
	float moveSpeed = 500;

	float const gravity = 9800.f/*1000px : 1m*/;
	float  jumpPower = 2500.f;

	bool isJump = false;

	Vector<2> const boundary{ (1280 - Skin.Length[0]) * 0.5f, (720 - Skin.Length[1]) * 0.5f };

	Engine::Physics::Component<Quadrangle> Body;
	Engine::Rendering::Animation::Component Skin;

	enum class state_
	{
		STATE_IDLE,
		STATE_JUMP,
		STATE_FALLEN,
		STATE_MOVE,
		STATE_DEATH
	};

	state_ state = state_::STATE_IDLE;
};