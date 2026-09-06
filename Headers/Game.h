// WorldSpaceDemo.h : Include file for standard system include files,
// or project specific include files.

#pragma once
#include "Headers/Behaviour.h"
#include "Headers/CameraMovement.h"
#include "Headers/Point.h"
#include"Headers/Player.h"
#include"Headers/PlayerMovement.h"
#include"Headers/LevelDesigner.h"
#include"Headers/Physics2D.h"
#include"Headers/Collision2D.h"
#include"Headers/BlockModification.h"
#include"Headers/Screens/HomeScreen.h"
#include"Headers/Screens/Screen.h"
#include"Headers/Screens/PlayScreen.h"
#include"Headers/GUI/GUI.h"

#include<iostream>
#include<vector>
#include<memory>
#include<chrono>

#define COL_TRANSPARENT CLITERAL(Color){0,0,0,0}
#define COL_OPACITY CLITERAL(Color){255,255,255,80}
#define SOURCE_DIR "E:/Projects/Infinite2D-demo"
#define WORLD_DIR "E:/Projects/Infinite2D-demo/Worlds"


class Game {


	static inline int Scr_W = 800, Scr_H = 800;
	static inline Camera2D WorldCam;
	static inline std::vector<std::unique_ptr<Behaviour>> Objects;

	static inline float scl_top = 0, scl_left = 0, scl_bottom = 0, scl_right = 0;
	static inline std::shared_ptr<Point[4]> Bounding = std::make_shared<Point[4]>();
	
public:

	void SetCamera(Camera2D& cam);
	void AddObjects(std::unique_ptr<Behaviour> obj);
	void InitialBoudningPoints(std::shared_ptr<Point[4]>(&Points));
	void SetBoundingPoints(std::shared_ptr<Point[4]>(&Points), Point CameraPos);
	char KeyParser(int key);
	void run();
	Point CalculatePlayer(const Point& inPos); // Just calculate the Pos without the Vel factor;

	Game();


};


