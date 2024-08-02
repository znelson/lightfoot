//
// Created by Zach Nelson on 8/1/24.
//

#pragma once

#include <string>
#include "SDL.h"

namespace debug
{

std::string GetTextureFormatDetailString(
	Uint32 inTextureFormat,
	const std::string &inIndent = std::string());

std::string GetPixelFormatDetailString(
	SDL_PixelFormat *inPixelFormat,
	const std::string &inIndent = std::string());

}    // namespace debug
