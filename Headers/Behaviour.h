#pragma once
#include "raylib.h"
#include "rlgl.h"
#include "raymath.h"
#include<unordered_map>
#include<string>
#include<iostream>
#include<filesystem>

class Behaviour {
public:
	static inline float deltatime=0;
	virtual void Start() = 0;
	virtual void Update() = 0;

	virtual void Render() = 0;


	virtual void OnMouse2Down() = 0;
	virtual void OnMouseDown() = 0; 

	virtual void OnMouseUp() = 0;

	virtual void OnMousePressed() = 0;
	virtual void OnMouseReleased() = 0;
	
};
static inline bool isLoaded = false;
class Behaviour_Adapter : public Behaviour {
public:
	void Start() override {};
	void Update() override {};

	void Render() override {};

	void OnMouse2Down() override {};
	void OnMouseDown() override {};
	
	void OnMouseUp() override {};

	void OnMousePressed() override {};
	void OnMouseReleased() override {};

	static inline int SelectedBlock = 0;
	static inline std::unordered_map<int, Texture2D> TexturesMap;
	static inline void m_LoadTexture();
};


void Behaviour_Adapter::m_LoadTexture()
{
	int count = 0;
	std::string path = std::string(SOURCE_DIR) + "/Textures/";
	if (std::filesystem::exists(path) && std::filesystem::is_directory(path)) {

		for (const auto& entry : std::filesystem::directory_iterator(path)) {
			std::string path_holder = entry.path().string();
			size_t underscore_pos = path_holder.find_last_of('_');

			if (underscore_pos != std::string::npos) {
				count = path_holder[underscore_pos + 1] - '0';
			}

			const char* png_path = path_holder.c_str();

			Behaviour_Adapter::TexturesMap[count] = LoadTextureFromImage(LoadImage(png_path));
		}
	}

}