//
// Created by Zach Nelson on 8/1/24.
//

#include "debug/PixelFormat.h"
#include "debug/RendererInfo.h"

#include <iostream>

namespace debug
{

RendererInfo::RendererInfo(
	SDL_Renderer *inRenderer)
{
	const int result = SDL_GetRendererInfo(inRenderer, &mInfo);

	if (result < 0)
	{
		std::cout << "SDL_GetRendererInfo failed with error: " << SDL_GetError() << std::endl;
	}
}

void RendererInfo::Print() const
{
	std::cout << "Renderer name: " << mInfo.name << std::endl;
	std::cout << std::boolalpha << std::endl;
	std::cout << "Renderer software: " << ((mInfo.flags & SDL_RENDERER_SOFTWARE) > 0) << std::endl;
	std::cout << "Renderer accelerated: " << ((mInfo.flags & SDL_RENDERER_ACCELERATED) > 0) << std::endl;
	std::cout << "Renderer vsync: " << ((mInfo.flags & SDL_RENDERER_PRESENTVSYNC) > 0) << std::endl;
	std::cout << "Renderer target texture: " << ((mInfo.flags & SDL_RENDERER_TARGETTEXTURE) > 0) << std::endl;
	std::cout << std::noboolalpha << std::endl;

	std::cout << "Renderer supports " << mInfo.num_texture_formats << " texture formats" << std::endl;
	for (Uint32 i = 0; i < mInfo.num_texture_formats; ++i)
	{
		const auto textureFormat = mInfo.texture_formats[i];
		const auto formatDetail = GetTextureFormatDetailString(textureFormat, "  ");

		std::cout << formatDetail;
	}

	std::cout << "Renderer max texture size: " << mInfo.max_texture_width << " x " << mInfo.max_texture_height
			  << std::endl;
	std::cout << std::endl;
}

}    // namespace debug
