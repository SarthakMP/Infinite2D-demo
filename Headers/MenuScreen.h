#pragma once
#include"Behaviour.h"

class Menu : public Behaviour_Adapter {
public:
	static inline Rectangle ContiuneButton;
	static inline Rectangle StartNewButton;
	static inline Camera2D Cam;
public:
	static inline int OptionSelected = 0;
	void InitializeButtons();
	void DrawButtons();
	int GetButtonInfo();
	void Start();
	void Update();
	void Render();

	Menu(Camera2D& caWorldCameram);
	~Menu();
};