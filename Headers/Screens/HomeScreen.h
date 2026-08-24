#include"Headers/Screens/Screen.h"
#include"Headers/Screens/OptionsScreen.h"
#include"Headers/Screens/StartScreen.h"
#include"Headers/Screens/ContinueScreen.h"
class Home : public Screen {
public:

	static inline Rectangle ContiuneButton, StartNewButton, OptionsButton;
	static inline  std::unique_ptr<Options> OptionPtr;
	static inline std::unique_ptr<StartScreen> StartScreenPtr;
	static inline std::unique_ptr< ContinueScreen> ContinueScreenPtr;

public:
	void InitializeChildern() override;
	void InitializeButtons() override;
	void DrawButtons() override;
	int GetButtonInfo() override;
	std::string GetButtonType() override;
	Screen* GetNextScreen() override;

	Home(Camera2D& in_cam) : Screen(in_cam) {
		InitializeButtons();
		InitializeChildern();
	}

};