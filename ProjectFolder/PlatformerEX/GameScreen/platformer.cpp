#include "GameScreen.h"
#include <string>

std::vector<Tile*> GameScreen::tileContainer;
std::vector<Image*> GameScreen::imageContainer;

void GameScreen::Start()
{
	Camera.Sight = { 1280, 720 };

	GameOver.Name = "Image/YOU DIED";
	GameOver.Location = { 0,0 };
	GameOver.Length = { 1280,720 };

	WorldTime.Font.Name = "³ª´®¼Õ±Û¾¾ º×";
	WorldTime.Font.Size = 48;

	WorldTime.Length = { 1000,50 };
	WorldTime.Color = { 255,255,255 };
	WorldTime.Location = { 500, 25 };

	ScoreText = WorldTime;
	ScoreText.Location[1] += 50;

	imageSpawner = new ImageSpawner(Add);
	tileSpawner = new TileSpawner(Add);

	imageContainer.push_back(imageSpawner->Spawn());
}

void GameScreen::Update()
{
	Camera.Set();

	std::vector<Image*>::iterator j = imageContainer.begin();
	while (j != imageContainer.end())
	{
		if ((**j).update() != true)
		{
			delete(*j);
			j = imageContainer.erase(j);
		}
		else
		{
			j = j + 1;
		}
	}

	worldTime = (int)Engine::Time::Get::Elapsed();
	
	if (worldTime - (spawnTime * spawnCount) >= 0)
	{
		tileContainer.push_back(tileSpawner->Spawn());
		spawnCount++;
	}

	Vector<2> direction{};
	if (Engine::Input::Get::Key::Press(VK_LEFT))  direction[0] -= 1;
	if (Engine::Input::Get::Key::Press(VK_RIGHT)) direction[0] += 1;

	PC.stateChange();

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

	PC.jump();

	PC.move(direction[0]);
	PC.Update();
	std::string world = "Time : " + std::to_string(worldTime) + "ÃÊ";
	std::string score = "Score : " + std::to_string(this->worldscore);

	WorldTime.Text = world.data();
	ScoreText.Text = score.data();

	WorldTime.Render();
	ScoreText.Render();

	if (PC.getState() == 4)
	{
		GameOver.Render();
	}

}

void GameScreen::End()
{

}

void GameScreen::Add(LongGround* targetTile)
{
	tileContainer.push_back(targetTile);
}

void GameScreen::Add(Image* Image)
{
	imageContainer.push_back(Image);
}