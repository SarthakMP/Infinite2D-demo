#include"Headers/Game.h"

void Game::SetCamera(Camera2D& cam) {
	cam.offset = Vector2(Scr_W / 2, Scr_H / 2);
	cam.rotation = 0;
	cam.target = Vector2{ 0,0 };
	cam.zoom = 0.1f;
}

void Game::AddObjects(Behaviour* obj) {
	Objects.push_back(obj);
}

void Game::InitialBoudningPoints(Point(&Points)[4]) {
	Points[0] = Point(0, 400);
	Points[1] = Point(-400, 0);
	Points[2] = Point(0, -400);
	Points[3] = Point(400, 0);

}


void Game::SetBoundingPoints(Point(&Points)[4], Vector2 CameraPos) {
	//TOP Clamp
	Points[0].x = CameraPos.x;
	Points[0].y = 400 - CameraPos.y;

	//LEFT Clamp
	Points[1].x = CameraPos.x - 400;
	Points[1].y = -CameraPos.y;

	//Bottom Clamp
	Points[2].x = CameraPos.x;
	Points[2].y = -CameraPos.y - 400;

	//RIGHT Clamp
	Points[3].x = CameraPos.x + 400;
	Points[3].y = -CameraPos.y;
}

void Game::run() {

	InitWindow(Scr_W, Scr_H, "worldSpace");
	SetCamera(WorldCam);
	SetTargetFPS(60);

	InitialBoudningPoints(Bounding);

	Player p;
	PlayerMovement Pm(p);
	LevelDesigner Ld(p);
	Physics2D p2D;

	AddObjects(&p);
	AddObjects(&Pm);
	AddObjects(&Ld);
	AddObjects(&p2D);

	CameraMovement Cam = CameraMovement(WorldCam);

	for (auto obj : Objects) obj->Start();

	while (!WindowShouldClose()) {
		BeginDrawing();

		WorldCam = Cam.MoveCamera();
		SetBoundingPoints(Bounding, WorldCam.target);

		//Top,Bottom,Left,Right Scales for Line so they can extended infinitly where the camera perfers to move to.
		scl_top = Bounding[0].y;
		scl_bottom = Bounding[2].y;

		scl_left = Bounding[1].x;
		scl_right = Bounding[3].x;

		BeginMode2D(WorldCam);
		ClearBackground(BLACK);


		rlPushMatrix(); // This locks the coords to local space only allowing objects to be transformed in the local space
		rlScalef(1, -1, 1);
		rlEnableBackfaceCulling();

		//DEBUG
		//DrawCircleLines(Bounding[0].x, Bounding[0].y, 10, ORANGE);
		//DrawCircleLines(Bounding[1].x, Bounding[1].y, 10, ORANGE);
		//DrawCircleLines(Bounding[2].x, Bounding[2].y, 10, ORANGE);
		//DrawCircleLines(Bounding[3].x, Bounding[3].y, 10, ORANGE);

		//Axis & Gizmos
		DrawCircle(0, 0, 5, WHITE); //Origin
		DrawLine(0, scl_bottom, 0, scl_top, RED * COL_OPACITY); // Y AXIS
		DrawLine(scl_left, 0, scl_right, 0, GREEN * COL_OPACITY); // X AXIS

		//TEST Scene rectangle outside the visible area 
		//DrawRectangle(500, 500, 100, 100, GREEN);
		//DrawCircle(-1000, 0, 100, WHITE);



		for (auto obj : Objects) obj->Update();

		rlDisableBackfaceCulling();

		rlPopMatrix();
		EndMode2D();


		EndDrawing();
	}

	CloseWindow();
}

Game::Game() {
	WorldCam = Camera2D();
}