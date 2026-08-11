#include"Headers/Behaviour.h"
#include"Headers/LevelDesigner.h"
#include"Headers/Point.h"
#include"Headers/Player.h"

class BlockModifier : public Behaviour_Adapter {
public:
	void Start();
	void Update();
	void OnMouseDown();
};