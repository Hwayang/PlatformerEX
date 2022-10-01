#pragma once

#include <vector>

#include "../Player/Player.h"
#include "../Tile/Tile.h"
#include "../Spawner/Spawner.h"

#include "../Engine/Game.h"
#include "../Engine/Rendering.h"

class GameScreen : public Engine::Game
{
public:
    void  Start() override;
    void Update() override;
    void    End() override;

private:
    static void Add(LongGround * const targetTile);

private:
    int worldscore = 0;
    int spawnTime = 3;
    int spawnCount = 1;

    int worldTime = 0;

    player PC;
    Spawner * spawner;
    Engine::Rendering::Camera Camera;

    Engine::Rendering::Text::Component WorldTime;
    Engine::Rendering::Text::Component ScoreText;

    Engine::Rendering::Image::Component playScreen;

    static std::vector<Tile*> tileContainer;
};