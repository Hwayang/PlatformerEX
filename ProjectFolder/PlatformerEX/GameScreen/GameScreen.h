#pragma once

#include <vector>

#include "../Player/Player.h"

#include "../Tile/Tile.h"
#include "../TileSpawner/TileSpawner.h"

#include "../Image/Image.h"
#include "../ImageSpawner/ImageSpawner.h"

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
    static void Add(Image* const targetTile);

private:
    int worldscore = 0;
    float spawnTime = 1;
    int spawnCount = 1;

    int worldTime = 0;

    player PC;

    Image* BIArr[2];
    TileSpawner * tileSpawner;
    ImageSpawner* imageSpawner;

    Engine::Rendering::Camera Camera;

    Engine::Rendering::Text::Component WorldTime;
    Engine::Rendering::Text::Component ScoreText;
    
    Engine::Rendering::Image::Component GameOver;

    static std::vector<Tile*> tileContainer;
    static std::vector<Image*> imageContainer;
};