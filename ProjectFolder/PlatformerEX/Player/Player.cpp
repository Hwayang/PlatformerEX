#include <algorithm>

#include "Player.h"
#include "../Tile/Tile.h"

player::player()
{
	Skin.Length = { 270, 180 };
	Skin.Location = { 0, -270 };
	Skin.Duration = 0.5f;
	Skin.Repeatable = true;
	Skin.Flipped = false;

	Body.Length = { 270, 180 };
	Body.Center = { 0,-270 };
}

void player::stateChange()
{
	//x축 이동방향에 맞춰 스프라이트의 플립 상태를 바꿔주는 코드
	if (Engine::Input::Get::Key::Press(VK_LEFT) and Engine::Input::Get::Key::Press(VK_RIGHT))
	{
		Skin.Flipped = Skin.Flipped;
	}
	else if (Engine::Input::Get::Key::Press(VK_LEFT))
	{
		Skin.Flipped = true;
	}
	else if (Engine::Input::Get::Key::Press(VK_RIGHT))
	{
		Skin.Flipped = false;
	}

	//점프 상태가 아니고, X키를눌렀을 때 점프 상태가 될 수 있도록
	if (isGround == true)
	{
		if (Engine::Input::Get::Key::Press('X'))
		{
			gamestart = true;

			if (isJump == false)
			{
				isJump = true;
				isGround = false;
			}
		}
	}

	//각 상태 변경 조건에 맞게 상태를 바꿔주는 코드
	
	if (Body.Center.y < -360)
	{
		state = state_::STATE_DEATH;
	}
	else if (isJump == true)
	{
		state = state_::STATE_JUMP;
	}
	else if (Engine::Input::Get::Key::Press(VK_LEFT) and Engine::Input::Get::Key::Press(VK_RIGHT))
	{
		state = state_::STATE_IDLE;
	}
	else if (Engine::Input::Get::Key::Press(VK_LEFT) or Engine::Input::Get::Key::Press(VK_RIGHT))
	{
		state = state_::STATE_MOVE;
	}
	else
	{
		state = state_::STATE_IDLE;
	}

	//각 상태에 맞게 스킨을 변경해주는 코드
	switch (state)
	{
	case(state_::STATE_IDLE):
		this->Skin.Name = "Animation/Player_Idle";
		break;
	case(state_::STATE_JUMP):
		this->Skin.Name = "Animation/Player_Jump";
		break;
	case(state_::STATE_MOVE):
		this->Skin.Name = "Animation/Player_Run";
		break;
	case(state_::STATE_DEATH):
		this->Skin.Name = "Animation/Player_Death";
		break;
	case(state_::STATE_FALLEN):
		this->Skin.Name = "Animation/Player_Fallen";
		break;
	}
}

void player::move(float const direction)
{

	Body.Center.x = Skin.Location[0] = std::clamp(Skin.Location[0] + direction * moveSpeed * Engine::Time::Get::Delta(), -boundary[0], boundary[0]);

	if (state == state_::STATE_JUMP)
	{
		Body.Center.y = Skin.Location[1] += jumpPower * Engine::Time::Get::Delta();
	}
	else if (state != state_::STATE_JUMP and gamestart == true)
	{
		Body.Center.y = Skin.Location[1] -= gravity / 10 * Engine::Time::Get::Delta();
	}
}

void player::jump()
{
	/*
		TODO
		1. 플레이어가 누른 시간에 비례하여 점프력 증가(최대 1.5초)
	*/

	if (state != state_::STATE_JUMP and state != state_::STATE_FALLEN)
	{
		return;
	}

	jumpPower -= 8000 * Engine::Time::Get::Delta();

	if (isGround == true)
	{
		jumpPower = 2500.f;
		isJump = false;
		return;
	}
}

void player::Update()
{
	Skin.Render();
}

Engine::Physics::Component<Quadrangle>& player::getBody()
{
	return this->Body;
}

Engine::Rendering::Animation::Component& player::getSkin()
{
	return this->Skin;
}

int player::getState()
{
	return (int)state;
}
