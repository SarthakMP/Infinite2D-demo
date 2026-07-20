// WorldSpaceDemo.h : Include file for standard system include files,
// or project specific include files.

#pragma once
#include "raylib.h"
#include "rlgl.h"
#include "Behaviour.h"
#include "CameraMovement.h"
#include "Point.h"
#include"Player.h"
#include"PlayerMovement.h"
#include"LevelDesigner.h"

#include <iostream>
#include<vector>

#define COL_TRANSPARENT CLITERAL(Color){0,0,0,0}
#define COL_OPACITY CLITERAL(Color){255,255,255,80}
#define SOURCE_DIR "E:/Projects/Infinite2D-demo/"



class Game {


	static inline int Scr_W = 800, Scr_H = 800;
	static inline Camera2D WorldCam;
	static inline std::vector<Behaviour*> Objects;

	static inline float scl_top = 0, scl_left = 0, scl_bottom = 0, scl_right = 0;
	static inline Point Bounding[4];
	
public:

	void SetCamera(Camera2D& cam);
	void AddObjects(Behaviour* obj);
	void InitialBoudningPoints(Point(&Points)[4]);
	void SetBoundingPoints(Point(&Points)[4], Vector2 CameraPos);
	void run();

	Game();


};


