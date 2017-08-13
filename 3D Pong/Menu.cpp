//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2016 Media Design School
//
// File Name	: Menu.cpp
// Description	: Menu implementation file.
// Authors		: Charmaine Lim 
// Mail			: Charmaine.Lim6440@mediadesign.school.nz
//

#include "Menu.h"
#include "SceneManager.h"
#include "utils.h"

#include "Line.h"

#include <vector>;

std::vector<Line*> vec_lines;
Line* pline;



void CMenu::Init()
{

	m_pAllText.push_back(&m_pMainMenu);
	m_pAllText.push_back(&m_pPlayMenu);
	//m_pAllText.push_back(&m_pPlayerNames);
	m_pAllText.push_back(&m_pFindMenu);
	m_pAllText.push_back(&m_pGetNameMenu);
	//m_pAllText.push_back(&m_pLobbyMenu);
	//m_pAllText.push_back(&m_pServerBrowser);
	//m_pAllText.push_back(&m_pServerNames);


	/*MainMenu*/
	//Menu Text in order seen top to bottom.
	//Play button - Clicked to open the Play Menu
	m_pMainMenu.push_back(new TextLabel("Play", "Assets/Fonts/waltographUI.ttf"));
	m_pMainMenu[0]->setColor(glm::vec3(1.0f, 1.0f, 1.0f));

	//m_pMainMenu.push_back(new TextLabel("Multiplayer", "Assets/Fonts/waltographUI.ttf"));
	//m_pMainMenu[1]->setColor(glm::vec3(1.0f, 1.0f, 1.0f));

	//Quit Application Button - Click to glutLeaveMainLoop() and end application
	m_pMainMenu.push_back(new TextLabel("Quit", "Assets/Fonts/waltographUI.ttf"));
	m_pMainMenu[1]->setColor(glm::vec3(1.0f, 1.0f, 1.0f));

	m_pMainMenu.push_back(new TextLabel("PONG 3D", "Assets/Fonts/waltographUI.ttf"));
	m_pMainMenu[2]->setColor(glm::vec3(1.0f, 1.0f, 1.0f));
	m_pMainMenu[2]->setActive(false);
	m_pMainMenu[2]->setButton(false);

	//pline = new Line(glm::vec3(-1, 1, 0), glm::vec3(1, 1, 0));
	//pline = new Line(glm::vec3(-1, 1, 0.5), glm::vec3(1, 1, 0.5));
	pline = new Line(glm::vec3(-3, 3, 0), glm::vec3(3, 3, 0));
	pline = new Line(glm::vec3(-3, 3, 1), glm::vec3(3, 3, 1));

	vec_lines.push_back(new Line(glm::vec3(-3, 3, 0), glm::vec3(3, 3, 0)));
	vec_lines.push_back(new Line(glm::vec3(-3, 3, 0), glm::vec3(-3, -3, 0)));
	vec_lines.push_back(new Line(glm::vec3(3, 3, 0), glm::vec3(3, -3, 0)));
	vec_lines.push_back(new Line(glm::vec3(-3,-3, 0), glm::vec3(3, -3, 0)));

	vec_lines.push_back(new Line(glm::vec3(-3, 3, 1), glm::vec3(3, 3, 1)));
	vec_lines.push_back(new Line(glm::vec3(-3, 3, 1), glm::vec3(-3, -3, 1)));
	vec_lines.push_back(new Line(glm::vec3(3, 3, 1), glm::vec3(3, -3, 1)));
	vec_lines.push_back(new Line(glm::vec3(-3, -3, 1), glm::vec3(3, -3, 1)));

	vec_lines.push_back(new Line(glm::vec3(-3, 3, 0), glm::vec3(-3, 3, 1)));

	//m_pMainMenu.push_back(new TextLabel("Press IJKL to shoot", "Assets/Fonts/waltographUI.ttf"));
	//m_pMainMenu[4]->setColor(glm::vec3(1.0f, 1.0f, 1.0f));
	//m_pMainMenu[4]->setActive(false);
	//m_pMainMenu[4]->setButton(false);

	/*PlayMenu*/
	//Host Server Button - Click to name server 
	//m_pPlayMenu.push_back(new TextLabel("Host", "Assets/Fonts/waltographUI.ttf"));
	//m_pPlayMenu[0]->setColor(glm::vec3(1.0f, 1.0f, 1.0f));

	////Find Server Button - Click to bring up server browser
	//m_pPlayMenu.push_back(new TextLabel("Find", "Assets/Fonts/waltographUI.ttf"));
	//m_pPlayMenu[1]->setColor(glm::vec3(1.0f, 1.0f, 1.0f));

	////Exit Menu Button - Click to return to the previous menu
	//m_pPlayMenu.push_back(new TextLabel("Exit", "Assets/Fonts/waltographUI.ttf"));
	//m_pPlayMenu[2]->setColor(glm::vec3(1.0f, 1.0f, 1.0f));


	//Name: - static text 
	//m_pGetNameMenu.push_back(new TextLabel("Name:", "Assets/Fonts/waltographUI.ttf"));
	//m_pGetNameMenu[0]->setColor(glm::vec3(1.0f, 1.0f, 1.0f));
	//m_pGetNameMenu[0]->setActive(false);
	//m_pGetNameMenu[0]->setButton(false);

	////Blank Text Label - Constructed here for future concantenation when the user types in their desired username.
	//m_pName = new TextLabel("", "Assets/Fonts/waltographUI.ttf");
	//m_pName->setColor(glm::vec3(1.0f, 1.0f, 1.0f));
	//m_pGetNameMenu.push_back(m_pName);


	//m_pPlayMenu.push_back(m_pName);


	///*ServerExplorer*/
	//m_pServerBrowser.push_back(new TextLabel("BroadCasting...", "Assets/Fonts/waltographUI.ttf"));
	//m_pServerBrowser[0]->setColor(glm::vec3(1.0f, 1.0f, 1.0f));

	//m_pServerBrowser.push_back(new TextLabel("Exit", "Assets/Fonts/waltographUI.ttf"));
	//m_pServerBrowser[1]->setColor(glm::vec3(1.0f, 1.0f, 1.0f));

	///*LobbyMenu*/

	//m_pLobbyMenu.push_back(new TextLabel("Lobby", "Assets/Fonts/waltographUI.ttf"));
	//m_pLobbyMenu[0]->setColor(glm::vec3(1.0f, 1.0f, 1.0f));
	//m_pLobbyMenu[0]->setButton(false);
	//m_pLobbyMenu.push_back(new TextLabel("Start", "Assets/Fonts/waltographUI.ttf"));
	//m_pLobbyMenu[1]->setColor(glm::vec3(0.5f, 0.5f, 0.5f));
	//m_pLobbyMenu[1]->setActive(false);
	//m_pLobbyMenu.push_back(new TextLabel("Exit", "Assets/Fonts/waltographUI.ttf"));
	//m_pLobbyMenu[2]->setColor(glm::vec3(1.0f, 1.0f, 1.0f));

	/*********
	Models
	**********/
	//EditBox - To represent the text field in which the users character presses will appear.
	/*m_pEditBox = new Model(QUAD, "Assets/Textures/EditBox.png");
	m_pEditBox->Initialise();
	m_pEditBox->m_Scale = glm::vec3(10, 10, 0);
	m_pModels.push_back(m_pEditBox);*/

	//Current Menu State - Used to determine rendering and proccessing.
	m_strMenuName = "MainMenu";

	SetTextPositions();
}


void CMenu::SetTextPositions()
{
	float centreX, centreY;
	centreX = Utils::WIDTH / 2;
	centreY = Utils::HEIGHT / 2;
	float maxItems = 8.0f;
	float spacing = Utils::HEIGHT / maxItems;
	float yTop = Utils::HEIGHT - spacing * 3;


	m_pMainMenu[0]->setPosition(glm::vec3(centreX / 2 + spacing * 2, yTop - spacing, 10));
	m_pMainMenu[1]->setPosition(glm::vec3(centreX / 2 + spacing * 2, yTop - spacing * 2, 10));
	//m_pMainMenu[2]->setPosition(glm::vec3(centreX / 2 + spacing * 2, yTop - spacing * 2, 10));
	m_pMainMenu[2]->setPosition(glm::vec3(centreX / 2 + spacing * 2, yTop + spacing * 1, 10));
	//m_pMainMenu[4]->setPosition(glm::vec3(centreX / 2 + spacing * 2, yTop - spacing * 4, 10));
	/*m_pPlayMenu[0]->setPosition(glm::vec3(centreX / 2, yTop, 10));
	m_pPlayMenu[1]->setPosition(glm::vec3(centreX / 2, yTop - spacing, 10));
	m_pPlayMenu[2]->setPosition(glm::vec3(centreX / 2, yTop - spacing * 2, 10));
	m_pGetNameMenu[0]->setPosition(glm::vec3(Utils::WIDTH / 2 - m_pGetNameMenu[0]->width / 2, centreY, 10));
	m_pName->setPosition(glm::vec3((Utils::WIDTH / 2), centreY - spacing, 10));*/
	//m_pServerBrowser[0]->setPosition(glm::vec3(100, 100, 10));
	//m_pServerBrowser[1]->setPosition(glm::vec3(Utils::WIDTH - m_pServerBrowser[1]->width - 50, 100, 10));
	////m_pLobbyMenu[0]->setPosition(glm::vec3(50, Utils::HEIGHT - 100, 10));
	//m_pLobbyMenu[1]->setPosition(glm::vec3((Utils::WIDTH) - 200, 50, 10));
	//m_pLobbyMenu[2]->setPosition(glm::vec3(200, 50, 10));
	//m_pEditBox->m_Position = glm::vec3(0, 0, 0);

}

void CMenu::Render(GLuint program, Camera& camera)
{


	for (auto itr : m_pModels)
	{
		itr->Render(program, camera);
	}

	for (auto itr : *m_pCurrentMenu)
	{
		itr->Render(camera);
	}

	for (auto itr : vec_lines)
	{
		itr->Render(camera);
	}

	/*if (m_strMenuName == "LobbyMenu")
	{
		for (auto itr : m_pPlayerNames)
		{
			itr->Render(camera);
		}
	}*/

	//pline->Render(camera);
}


void CMenu::PassiveMotion(int x, int y)
{
	y = glutGet(GLUT_WINDOW_HEIGHT) - y;

	for (auto itr : *m_pCurrentMenu)
	{
		if (itr->isActive() && itr->isButton())
		{
			if (x > itr->position.x && x < itr->position.x + itr->width && y > itr->position.y && y < itr->position.y + itr->height)
			{

				itr->setHighlighted(true);
				itr->setHighlight(glm::vec3(0, 0, 1));
			}
			else
			{
				if (itr->isHighlighted())
				{
					itr->setHighlighted(false);
				}
			}
		}
	}
}


void CMenu::Mouse(int button, int state, int x, int y)
{
	y = glutGet(GLUT_WINDOW_HEIGHT) - y;
	//Dp Nothing
	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_DOWN)
		{
			for (auto itr : *m_pCurrentMenu)
			{
				if (x > itr->position.x && x < itr->position.x + itr->width && y > itr->position.y && y < itr->position.y + itr->height)
				{
					std::string text = itr->getText();
					if (text == "Play")
					{
						CSceneManager& _rSceneManager = CSceneManager::GetInstance();
						_rSceneManager.SelectScene("Game");
					}

					if (text == "Multiplayer")
					{
						//CSceneManager& _rSceneManager = CSceneManager::GetInstance();
						////_rSceneManager.SelectScene("Game");
						//m_pCurrentMenu = &m_pPlayMenu;
						//Utils::g_Play = true;
						//m_pName->setText("");
						//m_pName->setPosition(glm::vec3((Utils::WIDTH / 2), Utils::HEIGHT / 8 + Utils::HEIGHT / 2, 10));
						//m_strMenuName = "PlayMenu";
					}
					else if (text == "Exit")
					{
						m_bIsHost = false;
						/*CNetwork& _rNetwork = CNetwork::GetInstance();
						_rNetwork.GetNetworkEntity()->SetHost(false);
						_rNetwork.GetNetworkEntity()->Suspend();*/
						m_pCurrentMenu = &m_pMainMenu;
						m_pName->setText("");
						m_pName->setPosition(glm::vec3((Utils::WIDTH / 2), Utils::HEIGHT / 8 + Utils::HEIGHT / 2, 10));

						m_strMenuName = "MainMenu";

					}
					else if (text == "Quit")
					{
						glutLeaveMainLoop();
						//Utils::g_Play = false;
					}
					else if (text == "Host")
					{
						/*CNetwork& _rNetwork = CNetwork::GetInstance();
						_rNetwork.GetNetworkEntity()->SetHost(true);
						_rNetwork.GetNetworkEntity()->Resume();
						m_bIsHost = true;
						m_strMenuName = "GetName";
						m_pCurrentMenu = &m_pGetNameMenu;*/
					}
					else if (text == "Find")
					{
						/*m_pFindMenu.clear();
						for (auto itr : m_pServerBrowser)
						{
							m_pFindMenu.push_back(itr);
						}
						CNetwork& _rNetwork = CNetwork::GetInstance();
						_rNetwork.GetNetworkEntity()->SetHost(false);
						_rNetwork.GetNetworkEntity()->Resume();
						m_bIsHost = false;
						m_strMenuName = "FindMenu";
						m_pCurrentMenu = &m_pFindMenu;
						FindGames();*/
					}
					else if (m_strMenuName == "FindMenu")
					{
						m_strMenuName = "GetName";
						m_pCurrentMenu = &m_pGetNameMenu;
						m_strServerName = itr->getText();
						/*CNetwork& _rNetwork = CNetwork::GetInstance();
						if (_rNetwork.GetNetworkEntity()->SelectServer(itr->getText()))
						{
						}
						*/
					}
					itr->setHighlighted(false);
					break;
				}
			}
		}
	}
}

void CMenu::KeyboardDown(unsigned char c, int x, int y)
{

}

void CMenu::KeyboardUp(unsigned char c, int x, int y)
{
	if (m_strMenuName == "GetName")
	{
		if (c == '\r')
		{
			/*if (m_pName->getText().length() >= 3)
			{
				m_pPlayerNames.push_back(m_pName);
				CNetwork& _rNetwork = CNetwork::GetInstance();
				_rNetwork.GetNetworkEntity()->SetName(m_pPlayMenu[3]->getText());
				if (_rNetwork.GetNetworkEntity()->IsHost())
				{
					m_strMenuName = "LobbyMenu";
					m_pCurrentMenu = &m_pLobbyMenu;
				}
				else
				{
					_rNetwork.GetNetworkEntity()->SetName(m_pName->getText());
					_rNetwork.GetNetworkEntity()->SelectServer(m_strServerName);


				}

			}*/
		}
		else if (m_pName->getText().length() < 12)
		{
			m_pName->AddText(c);
		}
	}
}

void CMenu::Reshape(int width, int height)
{
	SetTextPositions();
}
bool CMenu::FindGames()
{
	/*CNetwork& _rNetwork = CNetwork::GetInstance();
	return(_rNetwork.GetNetworkEntity()->BeginBroadcast());*/
	return false;
}

void CMenu::Update(float fDeltaTime)
{

}

void CMenu::NetworkProcess()
{
	if (m_bIsHost)
	{
		HostProcess();
	}
	else
	{
		ClientProcess();
	}
}

void CMenu::HostProcess()
{
	/*CNetwork& _rNetwork = CNetwork::GetInstance();
	if (!_rNetwork.GetNetworkEntity()->GetWorkQueue()->empty())
	{
		char* package = 0;
		std::pair<std::string, char*> _package;
		_rNetwork.GetNetworkEntity()->GetWorkQueue()->pop(_package);

		TPacket packet;
		packet.Deserialize(_package.second);
		switch (packet.MessageType)
		{
		case BROADCAST:
		{
			std::cout << "Broadcast recv" << std::endl;
			_rNetwork.GetNetworkEntity()->SendServerInfo(_package.first);
			break;
		}

		case HANDSHAKE:
		{
			std::cout << "Handshake recv" << std::endl;

			TClientDetails player;
			ToSockaddr_in(_package.first, player.m_ClientAddress);
			player.m_strName = packet.Sender;

			if (_rNetwork.GetNetworkEntity()->AddClient(player))
			{
				_rNetwork.GetNetworkEntity()->AcceptHandshake(_package.first, true);
				TextLabel* player = new TextLabel(packet.Sender, "Assets/Fonts/waltographUI.ttf");
				player->setPosition(m_pPlayerNames[m_pPlayerNames.size() - 1]->position + glm::vec3(0, -50, 0));
				m_pPlayerNames.push_back(player);
				m_pLobbyMenu.push_back(player);
				std::cout << "Handshake recv" << std::endl;
			}
			else
			{
				_rNetwork.GetNetworkEntity()->AcceptHandshake(_package.first, false);
			}
			break;
		}


		default:
			break;
		}
	}*/
}


void CMenu::ClientProcess()
{
	/*CNetwork& _rNetwork = CNetwork::GetInstance();

	if (!_rNetwork.GetNetworkEntity()->GetWorkQueue()->empty())
	{
		char* package = 0;
		std::pair<std::string, char*> _package;
		_rNetwork.GetNetworkEntity()->GetWorkQueue()->pop(_package);

		TPacket packet;
		packet.Deserialize(_package.second);
		switch (packet.MessageType)
		{
		case BROADCAST:
		{

			_rNetwork.GetNetworkEntity()->AddServer(packet.Sender, _package.first);
			TextLabel* label = new TextLabel(packet.Sender, "Assets/Fonts/waltographUI.ttf");
			label->setPosition(glm::vec3(Utils::WIDTH / 2 - 100, Utils::HEIGHT - 200 - (50 * m_pServerNames.size()), 0));
			label->setColor(glm::vec3(1.0f, 1.0f, 1.0f));
			m_pServerNames.push_back(label);
			m_pFindMenu.push_back(label);
			break;
		}

		case HANDSHAKE:
		{
			m_pCurrentMenu = &m_pLobbyMenu;
			m_strMenuName = "LobbyMenu";
			std::cout << "Handshake recv" << std::endl;
			m_pPlayerNames.push_back(m_pName);
			TextLabel* player = new TextLabel(packet.Sender, "Assets/Fonts/waltographUI.ttf");
			player->setPosition(m_pPlayerNames[m_pPlayerNames.size() - 1]->position + glm::vec3(0, -50, 0));
			m_pLobbyMenu.push_back(player);
			std::string playerName;
			for (int i = 0; i < packet.m_MessageContents.length(); i++)
			{
				char c = packet.m_MessageContents.at(i);
				if (c == ' ')
				{
					TextLabel* playerInLobby = new TextLabel(playerName, "Assets/Fonts/waltogrphUI.ttf");
					playerInLobby->setPosition(m_pLobbyMenu[m_pLobbyMenu.size() - 1]->position + glm::vec3(0, -50, 0));
					m_pLobbyMenu.push_back(playerInLobby);
					playerName.clear();
				}
				else
				{
					playerName += c;
				}
			}
			break;
		}

		case PLAYERJOINED:
		{

		}

		case DENIED:
		{

			break;
		}
		default:
			break;
		}


	}*/
}
