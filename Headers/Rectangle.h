#pragma once
#include"raylib.h"

class TexturedRectangle
{
public:
	Rectangle rec;
	Texture2D texture;
	TexturedRectangle() = default;
	TexturedRectangle(Rectangle in_rec) : rec{ in_rec.x,in_rec.y ,in_rec.width,in_rec.height } {}
	TexturedRectangle(int x, int y, int w, int h) : rec{ static_cast<float>(x),static_cast<float>(y),static_cast<float>(w),static_cast<float>(h) } { texture = Texture2D(); }
	TexturedRectangle(int x, int y, int w, int h,Texture2D text) : rec{ static_cast<float>(x),static_cast<float>(y),static_cast<float>(w),static_cast<float>(h)},texture(text) {}
};

class ObservableRectangle {
public:
	Rectangle rec;
	bool isObservable = 0;

	ObservableRectangle() = default;
	ObservableRectangle(int x, int y, int w, int h,bool in_isObservable) : rec{ static_cast<float>(x),static_cast<float>(y),static_cast<float>(w),static_cast<float>(h) },isObservable(in_isObservable) {}
	ObservableRectangle(float x, float y, float w, float h, bool in_isObservable) : rec{ x,y,w,h }, isObservable(in_isObservable) {}
	ObservableRectangle(Rectangle in_rec, bool in_isObservable) : rec{ in_rec.x,in_rec.y ,in_rec.width,in_rec.height }, isObservable(in_isObservable) {}

};