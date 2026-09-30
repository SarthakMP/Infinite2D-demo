#include"Headers/ScrollBar.h"

void ScrollBar::OnMouseUp() {
	if (isScrollBarTouched) {
		isScrollBarTouched = false;
	}
}

void ScrollBar::UpdateMousePos(Point Pos)
{
	MousePos = Pos;
}

void ScrollBar::OnMouseDown() {
	isScrollBarTouched = true;
}

void ScrollBar::Update() {

	//Only Change the position if isScrollBarTouched is true.

	if (isScrollBarTouched) {

		thumb.y = MousePos.y;

		if (thumb.y < track.y) {
			thumb.y = track.y;
		}
		if ((thumb.y + thumb_h) > (track.y + track_h) ){
			thumb.y = track.y + track_h - thumb_h;
		}
		
	}
}

void ScrollBar::Render() {


	DrawRectanglePro(track, { 0,0 }, 0, RED);
	DrawRectanglePro(thumb, { 0,0 }, 0, BLACK);

}

ScrollBar::ScrollBar() {
	
}



