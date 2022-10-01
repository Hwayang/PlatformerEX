#include "GameScreen.h"
#include <string>

std::vector<Tile*> GameScreen::tileContainer;

void GameScreen::Start()
{
	Camera.Sight = { 1280, 720 };

	playScreen.Name = "Image/Tile_GrassLongGround";
	playScreen.Location = { 0,0 };
	playScreen.Length = { 640,720 };

	WorldTime.Font.Name = "³ª´®¼Õ±Û¾¾ º×";
	WorldTime.Font.Size = 48;

	WorldTime.Length = { 1000,50 };
	WorldTime.Color = { 255,255,255 };
	WorldTime.Location = { 500, 25 };

	ScoreText = WorldTime;
	ScoreText.Location[1] += 50;

	spawner = new Spawner(Add);
}

void GameScreen::Update()
{
	Camera.Sight[0] += 16 * 4 * -Engine::Input::Get::Wheel::V();
	Camera.Sight[1] += 9 * 4 * -Engine::Input::Get::Wheel::V();

	Camera.Set();
	/*playScreen.Render();*/

	worldTime = (int)Engine::Time::Get::Elapsed();

	if (worldTime / spawnTime * spawnCount == 1)
	{
		tileContainer.push_back(spawner->Spawn());
		spawnCount++;
	}


	Vector<2> direction{};
	if (Engine::Input::Get::Key::Press(VK_LEFT))  direction[0] -= 1;
	if (Engine::Input::Get::Key::Press(VK_RIGHT)) direction[0] += 1;

	//PC.stateChange();

	std::vector<Tile*>::iterator i = tileContainer.begin();
	while (i != tileContainer.end())
	{
		if ((**i).update(&PC) != true)
		{
			delete(*i);

			i = tileContainer.erase(i);

			worldscore++;
		}
		else
		{
			i = i + 1;
		}
	}

	//PC.jump();

	//PC.move(direction[0]);
	//PC.Update();
	std::string world = "Áö³­ ½Ã°£ : " + std::to_string(worldTime) + "ÃÊ";
	std::string score = "Á¡¼ö : " + std::to_string(this->worldscore);

	WorldTime.Text = world.data();
	ScoreText.Text = score.data();

	WorldTime.Render();
	ScoreText.Render();
}

void GameScreen::End()
{

}

void GameScreen::Add(LongGround* targetTile)
{
	tileContainer.push_back(targetTile);
}