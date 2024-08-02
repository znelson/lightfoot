//
// Created by Zach Nelson on 8/1/24.
//

#include "FPSOverlay.h"

#include <iomanip>
#include <iostream>
#include <sstream>

namespace debug::ui
{
namespace
{
constexpr size_t kFramesToCount{75};
}

FPSCalculator::FPSCalculator(size_t inFramesToCount)
	:
	mFramesToCount{inFramesToCount}
{
}

void FPSCalculator::Update()
{
	if (mFrameTimes.size() >= mFramesToCount)
	{
		mFrameTimes.pop_front();
	}
	mFrameTimes.push_back(std::chrono::steady_clock::now());
}

float FPSCalculator::GetFPS() const
{
	if (mFrameTimes.size() >= mFramesToCount)
	{
		const auto &timeOne = mFrameTimes.front();
		const auto &timeTwo = mFrameTimes.back();
		const std::chrono::milliseconds duration = std::chrono::duration_cast<std::chrono::milliseconds>(
			timeTwo - timeOne);

		const float fps = static_cast<float>(mFrameTimes.size()) / static_cast<float>(duration.count()) * 1000.f;

		return fps;
	}
	return 0.f;
}

FPSOverlay::FPSOverlay(
	const SDL_Color &inColor,
	SDL_Renderer *inRenderer)
	:
	mFPSCalculator{kFramesToCount},
	mFont{FC_CreateFont()}
{
	Uint8 fontResult = FC_LoadFont(mFont, inRenderer, "res/FiraCode-Regular.ttf", 12, inColor, TTF_STYLE_NORMAL);
	std::cout << "Font result: " << static_cast<std::uint32_t>(fontResult) << std::endl;

	if (!mFont || fontResult < 0)
	{
		std::cout << "Failed to create font" << std::endl;
		std::cout << "SDL2 Error: " << SDL_GetError() << std::endl;
	}
}

FPSOverlay::~FPSOverlay()
{
	if (mFont)
	{
		FC_FreeFont(mFont);
	}
}

void FPSOverlay::Update()
{
	mFPSCalculator.Update();
}

void FPSOverlay::Draw(SDL_Renderer *inRenderer)
{
	const float fps = mFPSCalculator.GetFPS();
	if (fps > 0.f)
	{
		std::stringstream stream;
		stream << std::fixed << std::setprecision(2);
		stream << fps << " fps";
		const auto fpsStr = stream.str();

		FC_Draw(mFont, inRenderer, 0, 0, fpsStr.c_str());
	}
}

}    // namespace debug::ui
