#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Input.h"
#include "j1Textures.h"
#include "j1Audio.h"
#include "j1Render.h"
#include "j1Window.h"
#include "j1Scene.h"
#include "VerletIntegrator.h"

object Ball;

j1Scene::j1Scene() : j1Module()
{
	name.create("scene");
}

// Destructor
j1Scene::~j1Scene()
{}

// Called before render is available
bool j1Scene::Awake()
{
	LOG("Loading Scene");
	bool ret = true;
	return ret;
}

// Called before the first frame
bool j1Scene::Start()
{
	img = App->tex->Load("textures/0-0_Welcome.png");
	ball_tex = App->tex->Load("textures/ball.png");
	Ball.enterData();

	ball.x = 0;
	ball.y = 0;
	ball.w = 64;
	ball.h = 64;
	Ball.setX(0);
	Ball.setY(0);
	Ball.setAX(1);
	Ball.setAY(0);
	Ball.setDensity(5);
	Ball.setRadius(5);
	Ball.setVX(0.1);
	Ball.setVY(0);


	step = 0;
	return true;
}

// Called each loop iteration
bool j1Scene::PreUpdate()
{
	Ball.update(9, Ball, 1);
	return true;
}

// Called each loop iteration
bool j1Scene::Update(float dt)
{
	/*if (step == 0)
	App->render->Blit(img, 0, 0);*/

	/*if (App->input->GetKeyDown(SDLK_SPACE) && step == 0)
	{
		step++;
		Ball.enterData();
	}
	if (step == 1)
	{*/
	App->render->Blit(ball_tex, Ball.getX(), Ball.getY());

	//}
	return true;
}

// Called each loop iteration
bool j1Scene::PostUpdate()
{
	bool ret = true;
	if (App->input->GetKeyDown(SDLK_ESCAPE))
		ret = false;
	return ret;
}

// Called before quitting
bool j1Scene::CleanUp()
{
	LOG("Freeing scene");
	App->tex->UnLoad(img);
	App->tex->UnLoad(ball_tex);
	return true;
}
