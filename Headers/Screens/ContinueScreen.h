#pragma once
#include"Headers/Screens/Screen.h"
#include"Headers/Screens/StartScreen.h"
#include "Headers/LevelDesigner.h"
#include"Headers/ScrollBar.h"
#include "Headers/Rectangle.h"
#include <filesystem>

constexpr std::size_t  MaxObservableWorldCount = 6;

class ContinueScreen : public Scree_Adapter {
public:

	Font F = Font();
	static inline int Bkg_W = 600, Bkg_H = 600;
	static inline int OptionSelected = -1;
	static inline Rectangle ScreenBackground;
	static inline int WorldCount = 0;
	static inline std::vector<std::pair<ObservableRectangle,std::string>> WorldList;
	static inline std::vector<std::pair<ObservableRectangle, std::string>> ObservableWorldList{ MaxObservableWorldCount };
	static inline std::string LocWorldName;
	static inline float CountRatio =0;

private:
	static inline ScrollBar ScrlBar1;
	static inline ScrollBar ScrlBar2;

public:
	
	void InitializeChildern() override;
	void InitializeButtons() override;
	void Render() override;
	int GetButtonInfo() override;
	std::string GetButtonType() override;
	Screen* GetNextScreen() override;
	void GetScreenList();

	void Update() override;
	void OnMouseDown()override;
	void OnMouseUp()override;
	ContinueScreen(Camera2D& cam);

	void MoveAndInsertWorld(std::pair<ObservableRectangle, std::string> world, bool ShiftTowards);

};