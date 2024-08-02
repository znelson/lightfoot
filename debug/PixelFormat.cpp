//
// Created by Zach Nelson on 8/1/24.
//

#include <sstream>

#include "debug/PixelFormat.h"

namespace debug
{
namespace
{

static std::string GetPixelTypeString(
	const unsigned int inTextureFormat)
{
	const auto pixelType = SDL_PIXELTYPE(inTextureFormat);

	switch (pixelType)
	{
		case SDL_PIXELTYPE_UNKNOWN:
		{
			return "SDL_PIXELTYPE_UNKNOWN";
		}
		case SDL_PIXELTYPE_INDEX1:
		{
			return "SDL_PIXELTYPE_INDEX1";
		}
		case SDL_PIXELTYPE_INDEX4:
		{
			return "SDL_PIXELTYPE_INDEX4";
		}
		case SDL_PIXELTYPE_INDEX8:
		{
			return "SDL_PIXELTYPE_INDEX8";
		}
		case SDL_PIXELTYPE_PACKED8:
		{
			return "SDL_PIXELTYPE_PACKED8";
		}
		case SDL_PIXELTYPE_PACKED16:
		{
			return "SDL_PIXELTYPE_PACKED16";
		}
		case SDL_PIXELTYPE_PACKED32:
		{
			return "SDL_PIXELTYPE_PACKED32";
		}
		case SDL_PIXELTYPE_ARRAYU8:
		{
			return "SDL_PIXELTYPE_ARRAYU8";
		}
		case SDL_PIXELTYPE_ARRAYU16:
		{
			return "SDL_PIXELTYPE_ARRAYU16";
		}
		case SDL_PIXELTYPE_ARRAYU32:
		{
			return "SDL_PIXELTYPE_ARRAYU32";
		}
		case SDL_PIXELTYPE_ARRAYF16:
		{
			return "SDL_PIXELTYPE_ARRAYF16";
		}
		case SDL_PIXELTYPE_ARRAYF32:
		{
			return "SDL_PIXELTYPE_ARRAYF32";
		}
	}
	return "???";
}

static std::string GetPixelOrderString(
	const unsigned int inTextureFormat)
{
	const auto pixelOrder = SDL_PIXELORDER(inTextureFormat);

	if (SDL_ISPIXELFORMAT_PACKED(inTextureFormat))
	{
		switch (pixelOrder)
		{
			case SDL_PACKEDORDER_NONE:
			{
				return "SDL_PACKEDORDER_NONE";
			}
			case SDL_PACKEDORDER_XRGB:
			{
				return "SDL_PACKEDORDER_XRGB";
			}
			case SDL_PACKEDORDER_RGBX:
			{
				return "SDL_PACKEDORDER_RGBX";
			}
			case SDL_PACKEDORDER_ARGB:
			{
				return "SDL_PACKEDORDER_ARGB";
			}
			case SDL_PACKEDORDER_RGBA:
			{
				return "SDL_PACKEDORDER_RGBA";
			}
			case SDL_PACKEDORDER_XBGR:
			{
				return "SDL_PACKEDORDER_XBGR";
			}
			case SDL_PACKEDORDER_BGRX:
			{
				return "SDL_PACKEDORDER_BGRX";
			}
			case SDL_PACKEDORDER_ABGR:
			{
				return "SDL_PACKEDORDER_ABGR";
			}
			case SDL_PACKEDORDER_BGRA:
			{
				return "SDL_PACKEDORDER_BGRA";
			}
		}
	}
	else if (SDL_ISPIXELFORMAT_ARRAY(inTextureFormat))
	{
		switch (pixelOrder)
		{
			case SDL_ARRAYORDER_NONE:
			{
				return "SDL_ARRAYORDER_NONE";
			}
			case SDL_ARRAYORDER_RGB:
			{
				return "SDL_ARRAYORDER_RGB";
			}
			case SDL_ARRAYORDER_RGBA:
			{
				return "SDL_ARRAYORDER_RGBA";
			}
			case SDL_ARRAYORDER_ARGB:
			{
				return "SDL_ARRAYORDER_ARGB";
			}
			case SDL_ARRAYORDER_BGR:
			{
				return "SDL_ARRAYORDER_BGR";
			}
			case SDL_ARRAYORDER_BGRA:
			{
				return "SDL_ARRAYORDER_BGRA";
			}
			case SDL_ARRAYORDER_ABGR:
			{
				return "SDL_ARRAYORDER_ABGR";
			}
		}
	}
	else
	{
		switch (pixelOrder)
		{
			case SDL_BITMAPORDER_NONE:
			{
				return "SDL_BITMAPORDER_NONE";
			}
			case SDL_BITMAPORDER_4321:
			{
				return "SDL_BITMAPORDER_4321";
			}
			case SDL_BITMAPORDER_1234:
			{
				return "SDL_BITMAPORDER_1234";
			}
		}
	}

	return "???";
}

static std::string GetPixelLayoutString(
	const unsigned int inTextureFormat)
{
	if (SDL_ISPIXELFORMAT_PACKED(inTextureFormat))
	{
		const auto pixelLayout = SDL_PIXELLAYOUT(inTextureFormat);

		switch (pixelLayout)
		{
			case SDL_PACKEDLAYOUT_NONE:
			{
				return "SDL_PACKEDLAYOUT_NONE";
			}
			case SDL_PACKEDLAYOUT_332:
			{
				return "SDL_PACKEDLAYOUT_332";
			}
			case SDL_PACKEDLAYOUT_4444:
			{
				return "SDL_PACKEDLAYOUT_4444";
			}
			case SDL_PACKEDLAYOUT_1555:
			{
				return "SDL_PACKEDLAYOUT_1555";
			}
			case SDL_PACKEDLAYOUT_5551:
			{
				return "SDL_PACKEDLAYOUT_5551";
			}
			case SDL_PACKEDLAYOUT_565:
			{
				return "SDL_PACKEDLAYOUT_565";
			}
			case SDL_PACKEDLAYOUT_8888:
			{
				return "SDL_PACKEDLAYOUT_8888";
			}
			case SDL_PACKEDLAYOUT_2101010:
			{
				return "SDL_PACKEDLAYOUT_2101010";
			}
			case SDL_PACKEDLAYOUT_1010102:
			{
				return "SDL_PACKEDLAYOUT_1010102";
			}
		}
		return "???";
	}

	return "N/A";
}

}	// anonymous namespace

std::string GetTextureFormatDetailString(
	Uint32 inTextureFormat,
	const std::string& inIndent)
{
	std::stringstream stream;
	stream << inIndent << "Texture format: " << inTextureFormat << std::endl;

	const auto bitsPerPixel = SDL_BITSPERPIXEL(inTextureFormat);
	const auto bytesPerPixel = SDL_BYTESPERPIXEL(inTextureFormat);

	stream << inIndent << "Pixel format: " << SDL_GetPixelFormatName(inTextureFormat) << std::endl;
	stream << inIndent << "Pixel type: " << GetPixelTypeString(inTextureFormat) << std::endl;
	stream << inIndent << "Pixel order: " << GetPixelOrderString(inTextureFormat) << std::endl;
	stream << inIndent << "Pixel layout: " << GetPixelLayoutString(inTextureFormat) << std::endl;
	stream << inIndent << "Bits per pixel: " << bitsPerPixel << std::endl;
	stream << inIndent << "Bytes per pixel: " << bytesPerPixel << std::endl;

	const auto isIndexed = SDL_ISPIXELFORMAT_INDEXED(inTextureFormat);
	const auto isAlpha = SDL_ISPIXELFORMAT_ALPHA(inTextureFormat);
	const auto isFourCC = SDL_ISPIXELFORMAT_FOURCC(inTextureFormat);
	const auto isPacked = SDL_ISPIXELFORMAT_PACKED(inTextureFormat);
	const auto isArray = SDL_ISPIXELFORMAT_ARRAY(inTextureFormat);

	stream << std::boolalpha;
	stream << inIndent << "Is indexed: " << isIndexed << std::endl;
	stream << inIndent << "Is alpha: " << isAlpha << std::endl;
	stream << inIndent << "Is fourCC: " << isFourCC << std::endl;
	stream << inIndent << "Is packed: " << isPacked << std::endl;
	stream << inIndent << "Is array: " << isArray << std::endl;
	stream << std::noboolalpha << std::endl;

	return stream.str();
}

std::string GetPixelFormatDetailString(
	SDL_PixelFormat* inPixelFormat,
	const std::string& inIndent)
{
	return GetTextureFormatDetailString(inPixelFormat->format, inIndent);
}

}	// namespace debug
