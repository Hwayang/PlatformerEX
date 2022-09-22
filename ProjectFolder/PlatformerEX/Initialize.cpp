#pragma comment(linker, "/Subsystem:Windows")

#pragma comment(lib, "D3D11.lib")
#pragma comment(lib, "FreeImage.lib")
#pragma comment(lib, "Engine.lib")

#include "Engine/Initialize.h"

#include "GameScreen/GameScreen.h"

namespace Engine
{
    Game * Initialize()
    {
        return new GameScreen;
    }
}