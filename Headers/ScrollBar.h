#pragma once
#include"Headers/Screens/Screen.h"
class ScrollBarAbstract : public Scree_Adapter {
public:

	bool isScrollBarTouched = 0;
	int track_w = 0, track_h = 0;
	int thumb_w = 0, thumb_h = 0;
	Rectangle track, thumb;

	virtual void InitializeScrollBar(Point TrackWH, Point ThumbWH, Point TrackXY, Point ThumbXY) = 0;
	virtual void InitializeScrollBar(Point TrackWH, Point ThumbWH, Point TrackXY, Point ThumbXY, Point MousePos) = 0;
};

class ScrollBar : public ScrollBarAbstract {
public:
	Point MousePos = 0;
	void InitializeScrollBar(Point TrackWH, Point ThumbWH, Point TrackXY, Point ThumbXY, Point MousePos)override;
	void InitializeScrollBar(Point TrackWH, Point ThumbWH, Point TrackXY, Point ThumbXY) override {}
	void Render();
	void Update();
	void OnMouseDown();
	void OnMouseUp();
	void UpdateMousePos(Point Pos);

	ScrollBar();
};