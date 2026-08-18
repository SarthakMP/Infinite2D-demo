#pragma once
#include"Behaviour.h"

class Menu : public Behaviour_Adapter {
public:
	static inline Rectangle ContiuneButton;
	static inline Rectangle StartNewButton;

public:
	static inline int OptionSelected = 0;
	void InitializeButtons();
	void DrawButtons();
	void Start();
	void Update();
	void Render();

	Menu();
	~Menu();
};