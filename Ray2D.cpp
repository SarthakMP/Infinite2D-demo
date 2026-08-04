#include"Headers/Ray2D.h"

void Ray2D::DrawRay2D()
{
	DrawLine(Origin.x, Origin.y, To.x, To.y, clr);
}