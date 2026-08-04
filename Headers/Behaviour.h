#pragma once
#include "raylib.h"
#include "rlgl.h"
#include "raymath.h"

class Behaviour {
public:
	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
};

class Behaviour_Adapter : public Behaviour {
public:
	void Start() override {};
	void Update() override {};
	void Render() override {};

};

