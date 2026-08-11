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
	static inline Point Gravity = Point(0,-98.1f);

	virtual void Update();
	


};