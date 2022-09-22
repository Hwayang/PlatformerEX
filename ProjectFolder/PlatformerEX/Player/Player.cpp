#include "Player.h"

player::player()
{
	Skin.Length = { 480, 320 };
	Skin.Location = { 0, 0 };
	Skin.Duration = 0.5f;
	Skin.Repeatable = true;
	Skin.Flipped = false;

	Body.Length = { 480, 320 };
	Body.Center = { 0,0 };
}

void player::stateManager()
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

	//점프 상태가 아니고, X키를눌렀을 때
	if (isJump != true and Engine::Input::Get::Key::Down('X'))
	{
		isJump = true;
		isGround = false;
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

void player::moveManager(float const direction)
{

	Body.Center.x = Skin.Location[0] = std::clamp(Skin.Location[0] + direction * moveSpeed * Engine::Time::Get::Delta(), -boundary[0], boundary[0]);

	if (!(state == state_::STATE_JUMP))
	{
		/*Body.Center.y = Skin.Location[1] -= weight * Engine::Time::Get::Delta();*/
	}
	else if (state == state_::STATE_JUMP)
	{
		Body.Center.y = Skin.Location[1] += (jumpDirection * jumpDistance) / 100;
	}
}

void player::jumpManager()
{
	if (!(state == state_::STATE_JUMP))
	{
		return;
	}

	if (jumpDirection == -1 and jumpTime >= jumpDefaultTime)
	{
		jumpTime = jumpDefaultTime;
		jumpDistance = 0;
		jumpDirection = 1;
		isJump = false;
		isGround = true;

		return;
	}

	if (jumpDirection == 1 and jumpTime > 0)
	{
		jumpTime -= jumpValue;
	}
	else if (/*jumpDirection == -1 and */jumpTime <= 0)
	{
		//더해지면 어디에도 걸리지 않음
		jumpDirection = -1;
		jumpTime += jumpValue;
	}

	jumpDistance = jumpTime * jumpSpeed;

	/*if (jumpTime <= 0)
	{

	}*/


}


void player::Update()
{
	Skin.Render();
}

Engine::Physics::Component<Quadrangle>& player::getBody()
{
	return this->Body;
}
