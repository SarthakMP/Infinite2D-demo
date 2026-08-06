#pragma once
#include"Headers/Point.h"
#include"Headers/BoxCollider2D.h"
#include"Headers/Chunk.h"
#include"Headers/LevelDesigner.h"

#include<queue>
#include <memory>

class Physics2D : public Behaviour_Adapter{
public:
	static inline std::queue<std::shared_ptr<BoxCollider2D>> Collision;
	inline static float Gravity = -9.81f;

	void AddGravity(Point& Pos);

	virtual void Update();
	


};