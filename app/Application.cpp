//
// Created by Zach Nelson on 8/1/24.
//

#include "Application.h"
#include "SDL.h"

#include "debug/FPSOverlay.h"
#include "debug/RendererInfo.h"

namespace app
{
namespace
{
constexpr int kWindowWidth = 1280;
constexpr int kWindowHeight = 720;

}    // anonymous namespace

Application::Application()
{
	SDL_Init(SDL_INIT_VIDEO);

	mWindow = SDL_CreateWindow("lightfoot", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, kWindowWidth, kWindowHeight,
							   SDL_WINDOW_SHOWN | SDL_WINDOW_ALLOW_HIGHDPI);

	mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

#ifndef NDEBUG
	const debug::RendererInfo rendererInfo{mRenderer};
	rendererInfo.Print();
#endif
}

Application::~Application()
{
	if (mWindow)
	{
		SDL_DestroyWindow(mWindow);
	}

	SDL_Quit();
}

int Application::Run()
{
#ifndef NDEBUG
	SDL_Color fpsColor = FC_MakeColor(255, 108, 0, 255);
	debug::ui::FPSOverlay fps{std::move(fpsColor), mRenderer};
#endif

	bool alive = true;
	while (alive)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event) > 0)
		{
			switch (event.type)
			{
				case SDL_QUIT:
				{
					alive = false;
					break;
				}
			}
		}

		fps.Update();
		fps.Draw(mRenderer);

		SDL_RenderPresent(mRenderer);
	}

	return 0;
}

}    // namespace app
