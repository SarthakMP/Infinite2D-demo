#include"Headers/Behaviour.h"
#include"Headers/LevelDesigner.h"
#include"Headers/Point.h"
#include"Headers/Player.h"

class BlockModifier : public Behaviour_Adapter {
	Camera2D LocCam;
	float zoom =0;
public:
	void Start();
	void Update();
	void OnMouseDown();
	void OnMouse2Down();

	BlockModifier(Camera2D& cam);
};