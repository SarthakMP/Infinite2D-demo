#include"raylib.h"

class TexturedRectangle
{
public:
	Rectangle rec;
	Texture2D texture;
	TexturedRectangle() = default;
	TexturedRectangle(int x, int y, int w, int h) : rec{ static_cast<float>(x),static_cast<float>(y),static_cast<float>(w),static_cast<float>(h)} {}
	TexturedRectangle(int x, int y, int w, int h,Texture2D text) : rec{ static_cast<float>(x),static_cast<float>(y),static_cast<float>(w),static_cast<float>(h)},texture(text) {}
};