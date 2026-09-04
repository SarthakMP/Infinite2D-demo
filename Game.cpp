#include"Headers/Game.h"

void Game::SetCamera(Camera2D& cam) {
	cam.offset = Vector2(Scr_W / 2, Scr_H / 2);
	cam.rotation = 0;
	cam.target = Vector2{ 0,0 };
	cam.zoom = 1.0f;
}

void Game::AddObjects(std::unique_ptr<Behaviour> obj) {
	Objects.push_back(std::move(obj));
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

bool isCapitalized = false;
int count = 0;
char Game::KeyParser(int key)
{

	if (key >= KEY_KP_0 && key <= KEY_KP_9) {
		return char(key) - 320 + '0';
	}
	if (key >= KEY_A && key <= KEY_Z) {
		return char(key);
	}

	return char(key);

}


void Game::run() {

	InitWindow(Scr_W, Scr_H, "worldSpace");
	SetCamera(WorldCam);
	SetTargetFPS(60);

	InitialBoudningPoints(Bounding);


	std::unique_ptr < Home> HomeScreen = std::make_unique<Home>(WorldCam);
	Screen* CurrentScreen = HomeScreen.get();
	Screen* ParentScreen = nullptr;

	std::unique_ptr<Player> p = std::make_unique<Player>();

	AddObjects(std::move(p));
	AddObjects(std::make_unique<PlayerMovement>());
	AddObjects(std::make_unique < LevelDesigner>(p));
	AddObjects(std::make_unique < CameraMovement>(WorldCam));
	AddObjects(std::make_unique < BlockModifier > (WorldCam));

	std::string Text = "";
	bool isWorldLoaded = false;
	bool isStarted = false;
	bool isText = false;
	bool isTextLong = false;

	float Zoom = 1/ WorldCam.zoom;

	while (!WindowShouldClose()) {

		CurrentScreen->MousePos = Point(GetMousePosition().x - Scr_W / 2, (GetMousePosition().y - Scr_H / 2))* Zoom;
		Behaviour_Adapter::deltatime = GetFrameTime();
		
		BeginDrawing();

		//DEBUG ONLY Top,Bottom,Left,Right Scales for Line so they can extended infinitly where the camera perfers to move to.
		scl_top = Bounding[0].y;
		scl_bottom = Bounding[2].y;

		scl_left = Bounding[1].x;
		scl_right = Bounding[3].x;

		BeginMode2D(WorldCam);
		ClearBackground(BLACK);

		 
		//DEBUG ONLY
		//DrawCircleLines(Bounding[0].x, Bounding[0].y, 10, ORANGE);
		//DrawCircleLines(Bounding[1].x, Bounding[1].y, 10, ORANGE);
		//DrawCircleLines(Bounding[2].x, Bounding[2].y, 10, ORANGE);
		//DrawCircleLines(Bounding[3].x, Bounding[3].y, 10, ORANGE);

		//handling of Before game text Addition of text 
		if (isText && !isTextLong) {
			int key = GetKeyPressed();
			if (Text.size() > 30) { 
				isTextLong = true; 
			}
			
			if (key == KEY_SPACE) {
				Text += " " ;
			}

			if (key >= KEY_KP_0 && key <= KEY_KP_9) {
				Text += KeyParser(key);
				std::cout << "Number: " << Text << key << std::endl;
			}
			if (key >= KEY_A && key <= KEY_Z) {
				Text += KeyParser(key);
				std::cout << "TEXT: " << Text << std::endl;
			}
			if (key == KEY_BACKSPACE) {
				if(!Text.empty())
					Text.pop_back();
				
			}
			
		}
		
		//handling of multiple screens / Menus before the game is loaded
		if (!isWorldLoaded) {
			CurrentScreen->DrawButtons();
			if (IsMouseButtonPressed(0)) {
				
				int NextScreenOption = CurrentScreen->GetButtonInfo();
				if (NextScreenOption == -2) {
					if (ParentScreen == nullptr) CurrentScreen = HomeScreen.get();
					else CurrentScreen = ParentScreen;
				}

				if (NextScreenOption >= 0 ) {
					//Change of Screens
					if (!CurrentScreen->Children.empty()) {
						CurrentScreen->targetScreen = CurrentScreen->Children[NextScreenOption].get();

						Screen* tmp = CurrentScreen->targetScreen;
						CurrentScreen->parentScreen = ParentScreen;
						ParentScreen = std::move(CurrentScreen);

						CurrentScreen = nullptr;
						CurrentScreen = tmp;
					}
					else {
						//Change for buttons
						std::string type = CurrentScreen->GetButtonType();
						if (type._Equal("_Start")) {
							
							LevelDesigner::WorldName = Text;
							isWorldLoaded = true;
						}
						else if (type._Equal("_Textbox")) {
							isText = true;
						}
						else {
							p->isGameContinued = true;
							LevelDesigner::WorldName = type;
							isWorldLoaded = true;
						}
					}
				}

			}
			
			if (isText) {
				CurrentScreen->SetText(Text);
			}
		}
		
		//Start this seq only if the world is loaded
		if(isWorldLoaded){

			rlPushMatrix(); // This locks the coords to local space only allowing objects to be transformed in the local space
			rlScalef(1, -1, 1);
			
			rlEnableBackfaceCulling();
			SetBoundingPoints(Bounding, WorldCam.target);

			//DEBUG Axis & Gizmos
			DrawCircle(0, 0, 5, WHITE); //Origin
			DrawLine(0, scl_bottom, 0, scl_top, RED * COL_OPACITY); // Y AXIS
			DrawLine(scl_left, 0, scl_right, 0, GREEN * COL_OPACITY); // X AXIS

			if (isStarted == false) {
				isText = false;
				for (auto& obj : Objects) obj->Start();
				isStarted = true;
			}

			if (IsMouseButtonDown(0))
				for (auto& obj : Objects) obj->OnMouseDown();
			if (IsMouseButtonDown(1))
				for (auto& obj : Objects) obj->OnMouse2Down();

			if (IsMouseButtonUp(0))
				for (auto& obj : Objects) obj->OnMouseUp();

			for (auto& obj : Objects) obj->Update();

			for (auto& obj : Objects) obj->Render();



			rlDisableBackfaceCulling();
			rlPopMatrix();
		}

		EndMode2D();
		EndDrawing();

	}

	//Some Issue here
	if (isWorldLoaded) {
		p->Save();
		for (auto& chunk : LevelDesigner::ChunksArray) {
			chunk.save(LevelDesigner::WorldName);
		}
	}

	CloseWindow();
}

Game::Game() {
	WorldCam = Camera2D();
}


