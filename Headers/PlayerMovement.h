#pragma once
#include"Behaviour.h"
#include"Point.h"
#include"Player.h"
#include"Collision2D.h"

#include"Ray2D.h"

#include<queue>
#include <memory>

class PlayerMovement : public Behaviour_Adapter {
	static inline float PlayerSpeed = 5;
public:
	std::queue<std::shared_ptr<Collision2D>> Collision;
	void AddCollisions(std::shared_ptr<Collision2D> col);

	void Move(Point& PlayerPos);

	void Update();
	void Render();
	PlayerMovement();

};