//
// Created by Zach Nelson on 8/1/24.
//

#pragma once

// SDL fwd
struct SDL_Window;
struct SDL_Renderer;

namespace app
{

class Application final
{
public:
	Application();

	~Application();

	int Run();

private:
	SDL_Window *mWindow{nullptr};
	SDL_Renderer *mRenderer{nullptr};
};

}    // namespace app
