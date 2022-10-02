#include "Image.h"

bool Image::update()
{
	imageSkin.Render();
	imageSkin.Location[1] -= 500 * Engine::Time::Get::Delta();

	return imageSkin.Location[1] > -360 - imageSkin.Length[1] * 0.5f;
}
