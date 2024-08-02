//
// Created by Zach Nelson on 8/1/24.
//

#pragma once

#include "SDL.h"

namespace debug
{

class RendererInfo
{
public:
	RendererInfo(SDL_Renderer* inRenderer);

	void Print() const;

private:
	SDL_RendererInfo mInfo;
};

}	// namespace debug
