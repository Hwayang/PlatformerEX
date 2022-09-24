#include <algorithm>

#include "Player.h"
#include "../Tile/Tile.h"

player::player()
{
	Skin.Length = { 270, 180 };
	Skin.Location = { 0, 0 };
	Skin.Duration = 0.5f;
	Skin.Repeatable = true;
	Skin.Flipped = false;

	Body.Length = { 270, 180 };
	Body.Center = { 0,0 };
}

void player::stateChange()
{

	//동시키 입력 금지
	//속도에 맞춰서 스프라이트 이동 구현할 수 있도록
	//플립 기준이 중앙이 아닌 오른쪽 or 왼쪽을 기준으로 바뀜

	//x축 이동방향에 맞춰 스프라이트의 플립 상태를 바꿔주는 코드
	if (Engine::Input::Get::Key::Press(VK_LEFT))
	{
		Skin.Flipped = true;
	}
	else if (Engine::Input::Get::Key::Press(VK_RIGHT))
	{
		Skin.Flipped = false;
	}

	//점프 상태가 아니고, X키를눌렀을 때 점프 상태가 될 수 있도록
	if (isJump != true and Engine::Input::Get::Key::Down('X'))
	{
		isJump = true;
	}

	//각 상태 변경 조건에 맞게 상태를 바꿔주는 코드
	if (isJump == true)
	{
		state = state_::STATE_JUMP;
	}
	else if (Engine::Input::Get::Key::Press(VK_LEFT) or Engine::Input::Get::Key::Press(VK_RIGHT))
	{
		state = state_::STATE_MOVE;
	}
	else if (Body.Center.y < -360)
	{
		state = state_::STATE_DEATH;
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

	if (!(state == state_::STATE_JUMP))
	{
		Body.Center.y = Skin.Location[1] -= gravity / 5000000;
	}
	else if (state == state_::STATE_JUMP)
	{
		Body.Center.y = Skin.Location[1] += jumpPower * Engine::Time::Get::Delta();
	}
}

void player::jump(Tile* target)
{
	/*
		TODO
		1. 플레이어가 누른 시간에 비례하여 점프력 증가(최대 1.5초)
		2.
	*/

	if (!(state == state_::STATE_JUMP) and !(state==state_::STATE_FALLEN))
	{
		return;
	}

	if (target->meetPlayer(this) == true)
	{
		jumpPower = 2500.f;
		isJump = false;
		return;
	}

	jumpPower -= gravity * Engine::Time::Get::Delta();
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
