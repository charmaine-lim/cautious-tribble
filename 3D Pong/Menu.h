//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2016 Media Design School
//
// File Name	: Menu.h
// Description	: Menu declaration file.
// Authors		: Charmaine Lim 
// Mail			: Charmaine.Lim6440@mediadesign.school.nz
//

#pragma once

#include "Scene.h"
//#include "Entity.h"

class Background;

class CMenu : public CScene
{
public:
	CMenu();
	~CMenu();
	void Init();
	void Render(GLuint program, Camera& camera);
	void Update(float fDeltaTime);
	//void NetworkProcess();
	void PassiveMotion(int x, int y);
	void Mouse(int button, int state, int x, int y);
	void KeyboardDown(unsigned char c, int x, int y);
	void KeyboardUp(unsigned char c, int x, int y);
	//bool FindGames();
	void Reshape(int width, int height);
	//void HostProcess();
	//void ClientProcess();
	void SetTextPositions();

	//std::vector<std::string> GetPlayers();

private:

	//bool m_bIsHost;
	std::string m_strMenuName;
	//std::string m_strServerName;

	std::vector<std::vector<TextLabel*>*> m_pAllText;
	//Vector for easier rendering, re-assigned according to menu depth
	std::vector<TextLabel*>* m_pCurrentMenu = &m_pMainMenu;

	//Vectors to seperate the different menu depths
	std::vector<TextLabel*> m_pMainMenu;
	//Play
	//Quit

	//std::vector<TextLabel*> m_pPlayMenu;
	//Host	
	//Find
	//Exit

	//std::vector<TextLabel*> m_pFindMenu;
	//std::vector<TextLabel*> m_pServerBrowser;
	//std::vector<TextLabel*> m_pServerNames; //[List]
	//										//Broadcasting...
	//										//Servers:
	//										//[list]

	//std::vector<TextLabel*> m_pLobbyMenu;
	//std::vector<TextLabel*> m_pPlayerNames; //[List]
	//										//Lobby:
	//										//PlayerNames[list]
	//										//Ready			  Start


	//std::vector<TextLabel*> m_pGetNameMenu;

	//const strings for easier code readablity
	TextLabel* m_pName;

	//Vector for easier rendering
	std::vector<Model*> m_pModels;
	//For dynamic control over individual elements, easier understood by name rather than by index number of the vector.
	//Model* m_pEditBox;
	//Vector for easier rendering
	//std::vector<CEntity*> m_pEntities;

	Background* m_pBackground;
};