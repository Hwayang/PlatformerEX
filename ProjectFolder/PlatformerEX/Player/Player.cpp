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

	//����Ű �Է� ����
	//�ӵ��� ���缭 ��������Ʈ �̵� ������ �� �ֵ���
	//�ø� ������ �߾��� �ƴ� ������ or ������ �������� �ٲ�

	//x�� �̵����⿡ ���� ��������Ʈ�� �ø� ���¸� �ٲ��ִ� �ڵ�
	if (Engine::Input::Get::Key::Press(VK_LEFT))
	{
		Skin.Flipped = true;
	}
	else if (Engine::Input::Get::Key::Press(VK_RIGHT))
	{
		Skin.Flipped = false;
	}

	//���� ���°� �ƴϰ�, XŰ�������� �� ���� ���°� �� �� �ֵ���
	if (isJump != true and Engine::Input::Get::Key::Down('X'))
	{
		isJump = true;
	}

	//�� ���� ���� ���ǿ� �°� ���¸� �ٲ��ִ� �ڵ�
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

	//�� ���¿� �°� ��Ų�� �������ִ� �ڵ�
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
		1. �÷��̾ ���� �ð��� ����Ͽ� ������ ����(�ִ� 1.5��)
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
