#include"Headers/Screens/PlayScreen.h"

void PlayScreen::InitializeGUIs() {

	GUIs.push_back(std::make_unique<HotbarGUI>(Cam));

}


PlayScreen::~PlayScreen() = default;
