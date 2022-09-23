#include "GameScreen.h"

void GameScreen::Start()
{
	Camera.Sight = { 1920, 1080 };
}

void GameScreen::Update()
{
	Camera.Set();

	Camera.Sight[0] += 16 * 4 * -Engine::Input::Get::Wheel::V();
	Camera.Sight[1] += 9 * 4 * -Engine::Input::Get::Wheel::V();

	Camera.Set();

	Vector<2> direction{};
	if (Engine::Input::Get::Key::Press(VK_LEFT))  direction[0] -= 1;
	if (Engine::Input::Get::Key::Press(VK_RIGHT)) direction[0] += 1;

	PC.stateChange();
	PC.jump();
	PC.move(direction[0]);

	PC.Update();
}

void GameScreen::End()
{

}