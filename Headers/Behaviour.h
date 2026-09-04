#pragma once
#include "raylib.h"
#include "rlgl.h"
#include "raymath.h"

class Behaviour {
public:
	static inline float deltatime=0;
	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;

	virtual void OnMouse2Down() = 0;
	virtual void OnMouseDown() = 0;
	virtual void OnMouseUp() = 0;

	virtual void OnMousePressed() = 0;
	virtual void OnMouseReleased() = 0;
};

class Behaviour_Adapter : public Behaviour {
public:
	void Start() override {};
	void Update() override {};
	void Render() override {};

	void OnMouse2Down() override {};
	void OnMouseDown() override {};
	void OnMouseUp() override {};

	void OnMousePressed() override {};
	void OnMouseReleased() override {};

};

