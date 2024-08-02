//
// Created by Zach Nelson on 8/1/24.
//

#pragma once

#include "third_party/SDL_FontCache.h"

#include <deque>

namespace debug::ui
{

class FPSCalculator final
{
public:
	explicit FPSCalculator(size_t inFramesToCount);

	void Update();

	float GetFPS() const;

private:
	const size_t mFramesToCount{2};
	std::deque <std::chrono::steady_clock::time_point> mFrameTimes;
};

class FPSOverlay final
{
public:
	FPSOverlay(
		const SDL_Color &inColor,
		SDL_Renderer *inRenderer);

	~FPSOverlay();

	void Update();

	void Draw(SDL_Renderer *inRenderer);

private:
	FPSCalculator mFPSCalculator;
	FC_Font *mFont{nullptr};
};

}    // namespace debug::ui
