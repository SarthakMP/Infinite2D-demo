#pragma once
#include"Behaviour.h"
#include"Point.h"
#include"Player.h"
#include"BoxCollider2D.h"

#include"Ray2D.h"

#include<queue>
#include <memory>

class PlayerMovement : public Behaviour_Adapter {
	static inline float PlayerSpeed = 5;
public:
	static inline std::queue<std::shared_ptr<BoxCollider2D>> Collision;
	static void AddCollisions(std::shared_ptr<BoxCollider2D>& col);

	void Move(Point& PlayerPos);

	void Update();
	void Render();
	PlayerMovement();

};