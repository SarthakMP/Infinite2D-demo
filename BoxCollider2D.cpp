#include "Headers/BoxCollider2D.h"
#include <array>

void BoxCollider2D::DrawBox(Vector2 a, Vector2 b)
{
	Vector2 c = Vector2(a.x, b.y);
	Vector2 d = Vector2(b.x, a.y);

	const std::array<Vector2, 4> points = { a,c,d,b };
	DrawTriangleStrip(points.data(), 4, WHITE);

}

const bool BoxCollider2D::isEmpty()
{
	return Rec.width == 0 || Rec.height == 0 ? true :  false;
}

const Rectangle BoxCollider2D::GetHitBox() {
	return Rec;
}

bool BoxCollider2D::CheckBoxCollision(BoxCollider2D HB_A, BoxCollider2D HB_B)
{
	float dx = HB_A.Origin.x - HB_B.Origin.x;
	float dy = HB_A.Origin.y - HB_B.Origin.y;


	float halfW = (HB_A.Rec.width + HB_B.Rec.width) * 0.5f;
	float halfH = (HB_A.Rec.height + HB_B.Rec.height) * 0.5f;

	return (dx <= halfW) && (dy<= halfH);
}

bool BoxCollider2D::CheckRayCollision(BoxCollider2D HB_A, BoxCollider2D HB_B, Raycast2D& rayhit)
{

	return false;

}

BoxCollider2D::BoxCollider2D()
{
	Rec = Rectangle(0);
	Origin = Point(0, 0);
	clr = Color();
	id = 0;
}

BoxCollider2D::BoxCollider2D(Rectangle rec) {
	Rec = rec;
	Origin = Point(Rec.x + Rec.width / 2, Rec.y + Rec.height / 2);
	clr = Color();
	id = 0;
}

BoxCollider2D::BoxCollider2D(Rectangle rec, Color in_clr)
{
	Rec = rec;
	Origin = Point(Rec.x + Rec.width / 2, Rec.y + Rec.height / 2);
	clr = in_clr;
	id = 0;
	
}

void BoxCollider2D::SetHitBox(Point Org, Point WH, Color in_clr) {


	Rec.width = WH.x;
	Rec.height = WH.y;

	Rec.x = Org.x - WH.x / 2;
	Rec.y = Org.y - WH.y / 2;

	Origin = Org;
	clr = in_clr;
}

const Point BoxCollider2D::GetHitBoxPos()
{

	return Point(Rec.x,Rec.y);
}

const Point BoxCollider2D::GetHitBoxOrigin()
{
	return Point(Origin.x,Origin.y);
}


