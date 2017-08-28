#include "glew\glew.h"
#include "freeglut\freeglut.h"

#include "Utils.h"
#include "SceneManager.h"
#include "ShaderLoader.h"
#include "Camera.h"

GLuint program;

Camera g_Camera;

std::clock_t g_PreviousTicks;
std::clock_t g_CurrentTicks;

void MouseGL(int button, int state, int x, int y)
{
	CSceneManager& _rSceneManager = CSceneManager::GetInstance();
	_rSceneManager.GetScene()->Mouse(button, state, x, y);
}

void KeyboardGL(unsigned char c, int x, int y)
{
	CSceneManager& _rSceneManager = CSceneManager::GetInstance();
	_rSceneManager.GetScene()->KeyboardDown(c, x, y);
}

void KeyboardUpGL(unsigned char c, int x, int y)
{
	CSceneManager& _rSceneManager = CSceneManager::GetInstance();
	_rSceneManager.GetScene()->KeyboardUp(c, x, y);
}

bool init() 
{
	//Shaders
	ShaderLoader shaderLoader;
	program = shaderLoader.CreateProgram("Assets/Shaders/Shader.vert", "Assets/Shaders/Shader.frag");

	//Camera Set up
	//g_Camera.SetPosition(glm::vec3(0.0f, 15.0f, 10.0f)); //Set camera above the plane
	//g_Camera.SetEulerAngles(glm::vec3(-60, 0, 0));		//Set a 30 degree angle around its x axis, to point towards the plane

	g_Camera.SetPosition(glm::vec3(0.0f, 0.0f, 10.0f)); //Set camera above the plane
	//g_Camera.SetEulerAngles(glm::vec3(-60, 0, 0));		//Set a 30 degree angle around its x axis, to point towards the plane

	CSceneManager& _rSceneManager = CSceneManager::GetInstance();
	_rSceneManager.Initialise();


	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // GL_FILL, GL_LINE
	return true;
}

void render() 
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	CSceneManager& _rSceneManager = CSceneManager::GetInstance();
	_rSceneManager.GetScene()->Render(program, g_Camera);

	glUseProgram(program);
	glBindVertexArray(0);

	glutSwapBuffers();
}

void PassiveMotionGL(int x, int y)
{
	CSceneManager& _rSceneManger = CSceneManager::GetInstance();
	_rSceneManger.GetScene()->PassiveMotion(x, y);
}

void update()
{

	g_CurrentTicks = std::clock();
	float deltaTicks = (float)(g_CurrentTicks - g_PreviousTicks);
	g_PreviousTicks = g_CurrentTicks;

	float fDeltaTime = deltaTicks / (float)CLOCKS_PER_SEC;

	CSceneManager& _rSceneManager = CSceneManager::GetInstance();
	_rSceneManager.GetScene()->Update(fDeltaTime);
//	_rSceneManager.GetScene()->NetworkProcess();


	glutPostRedisplay(); //the render function is called 
}

void Reshape(int width, int height)
{
	if (height == 0)
	{
		height = 1;
	}

	g_Camera.SetViewPort(0, 0, width, height);
	g_Camera.SetProjection(60.0f, (float)(width / height), 0.1f, 100.0f);
	Utils::WIDTH = static_cast<float>(width);
	Utils::HEIGHT = static_cast<float>(height);
	CSceneManager& _rSceneManager = CSceneManager::GetInstance();
	_rSceneManager.GetScene()->Reshape(width, height);
}


int main(int argc, char **argv)
{
	// init glut
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(static_cast<int>(Utils::WIDTH), static_cast<int>(Utils::HEIGHT));
	glutCreateWindow("OpenGL 3D Pong Charmaine Lim");

	//init GLEW
	glewInit();
	init();

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	//glEnable(GL_CULL_FACE);

	// register callbacks
	glutDisplayFunc(render);
	glutIdleFunc(update);
	glutReshapeFunc(Reshape);
	glutKeyboardFunc(KeyboardGL);
	glutKeyboardUpFunc(KeyboardUpGL);
	glutPassiveMotionFunc(PassiveMotionGL);
	glutMouseFunc(MouseGL);
	glutMainLoop();

	return 0;
}