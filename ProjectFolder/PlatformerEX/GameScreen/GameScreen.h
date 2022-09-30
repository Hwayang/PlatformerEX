#pragma once

#include <vector>

#include "../Player/Player.h"
#include "../Tile/Tile.h"

#include "../Engine/Game.h"
#include "../Engine/Rendering.h"

class GameScreen : public Engine::Game
{
public:
    void  Start() override;
    void Update() override;
    void    End() override;

private:
    player PC;
    GrassGround grassground;
    Engine::Rendering::Camera Camera;

    Engine::Rendering::Text::Component WorldTime;
    Engine::Rendering::Text::Component DeltaTime;

    std::vector<Tile*> tileContainer;
};