/*
	Tomás:
		uint step;						= the step of the integration the user is in, from welcome to input time to goodbye
		uint current input;				= current input being modified
		input {
			uint count = 0;				= the current input value
			uint lastInput[10] = {};	= all the numbers entered for this current input
			uint i = 0;					= lastInput's index
			char count_string[10];		= the input's resul for printing
		}
		uint font;						= the png with the fonts
*/

#include "p2Defs.h"
#include "p2Log.h"
#include "Globals.h"
#include "j1App.h"
#include "j1Input.h"
#include "j1Textures.h"
#include "j1Audio.h"
#include "j1Render.h"
#include "j1Window.h"
#include "j1Scene.h"
#include "ModuleFonts.h"
#include "VerletIntegrator.h"

object cube;

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
	screen_0 = App->tex->Load("textures/0.png");
	screen_1 = App->tex->Load("textures/1.png");
	screen_2 = App->tex->Load("textures/2.png");
	screen_3 = App->tex->Load("textures/3.png");
	screen_4 = App->tex->Load("textures/4.png");
	screen_5 = App->tex->Load("textures/5.png");
	screen_6 = App->tex->Load("textures/6.png");

	star = App->tex->Load("textures/star.png");
	ball_tex = App->tex->Load("textures/ball.png");
	objTex = App->tex->Load("textures/Square.png");
	font = App->fonts->Load("textures/Fonts_Numbers.png", "0123456789", 1);
	step = 2;
	num_star = 0;
	return true;
}

// Called each loop iteration
bool j1Scene::PreUpdate()
{
	return true;
}

// Called each loop iteration
bool j1Scene::Update(float dt)
{
	if (step == 0) // WELCOME
	{
		App->render->Blit(screen_0, 0, 0);

		if (App->input->GetKeyDown(SDLK_RETURN))
		{
			step++;
		}
	}
	else if (step == 1) // TUTORIAL
	{
		App->render->Blit(screen_1, 0, 0);

		if (App->input->GetKeyDown(SDLK_RETURN))
		{
			step++;
		}
		else if (App->input->GetKeyDown(SDLK_b))
		{
			step--;
		}
	}
	else if (step == 2) // INPUT
	{
		App->render->Blit(screen_2, 0, 0);

		App->render->Blit(star, 30, star_position[num_star]);

		if (App->input->GetKeyDown(SDLK_w) && num_star > 0 && currentInput > 0)
		{
			num_star--;
			currentInput--;
		}

		else if (App->input->GetKeyDown(SDLK_s) && num_star < 11 && currentInput < 13)
		{
			num_star++;
			currentInput++;
		}

		if (App->input->GetKeyDown(SDLK_RETURN))
		{
			step++;
			num_star = 0;
			currentInput = 1;

			// ENTER DATA
			cube.setX(x0.count);
			cube.setY(y0.count);
			cube.setVX(vx0.count);
			cube.setVY(vy0.count);
			cube.setAX(ax0.count);
			cube.setAY(ay0.count);
			/*
			cube.setL(L.count);
			cube.setFX(fx0.count);
			cube.setFY(fy0.count);
			cube.setMu(mu.count);
			cube.setCollision(collision.count);
			cube.setT(time.count);*/
			return true;
		}
		else if (App->input->GetKeyDown(SDLK_b))
		{
			step--;
		}

		// INPUT x0
		if (currentInput == 1)
		{
			if (x0.count < 100000000)
			{
				if (App->input->GetKeyDown(SDLK_0))
				{
					x0.lastInput[x0.i] = 0;
					x0.count = x0.count * 10;
					x0.i++;
				}
				if (App->input->GetKeyDown(SDLK_1))
				{
					x0.lastInput[x0.i] = 1;
					x0.count = x0.count * 10 + x0.lastInput[x0.i];
					x0.i++;
				}
				if (App->input->GetKeyDown(SDLK_2))
				{
					x0.lastInput[x0.i] = 2;
					x0.count = x0.count * 10 + x0.lastInput[x0.i];
					x0.i++;
				}
				if (App->input->GetKeyDown(SDLK_3))
				{
					x0.lastInput[x0.i] = 3;
					x0.count = x0.count * 10 + x0.lastInput[x0.i];
					x0.i++;
				}
				if (App->input->GetKeyDown(SDLK_4))
				{
					x0.lastInput[x0.i] = 4;
					x0.count = x0.count * 10 + x0.lastInput[x0.i];
					x0.i++;
				}
				if (App->input->GetKeyDown(SDLK_5))
				{
					x0.lastInput[x0.i] = 5;
					x0.count = x0.count * 10 + x0.lastInput[x0.i];
					x0.i++;
				}
				if (App->input->GetKeyDown(SDLK_6))
				{
					x0.lastInput[x0.i] = 6;
					x0.count = x0.count * 10 + x0.lastInput[x0.i];
					x0.i++;
				}
				if (App->input->GetKeyDown(SDLK_7))
				{
					x0.lastInput[x0.i] = 7;
					x0.count = x0.count * 10 + x0.lastInput[x0.i];
					x0.i++;
				}
				if (App->input->GetKeyDown(SDLK_8))
				{
					x0.lastInput[x0.i] = 8;
					x0.count = x0.count * 10 + x0.lastInput[x0.i];
					x0.i++;
				}
				if (App->input->GetKeyDown(SDLK_9))
				{
					x0.lastInput[x0.i] = 9;
					x0.count = x0.count * 10 + x0.lastInput[x0.i];
					x0.i++;
				}
			}
			if (x0.count != 0)
			{
				if (App->input->GetKeyDown(SDLK_BACKSPACE))
				{
					x0.i--;
					x0.count = x0.count - x0.lastInput[x0.i];
					x0.count = x0.count / 10;
				}
			}
		}

		// INPUT y0
		else if (currentInput == 2)
		{
			if (y0.count < 100000000)
			{
				if (App->input->GetKeyDown(SDLK_0))
				{
					y0.lastInput[y0.i] = 0;
					y0.count = y0.count * 10;
					y0.i++;
				}
				if (App->input->GetKeyDown(SDLK_1))
				{
					y0.lastInput[y0.i] = 1;
					y0.count = y0.count * 10 + y0.lastInput[y0.i];
					y0.i++;
				}
				if (App->input->GetKeyDown(SDLK_2))
				{
					y0.lastInput[y0.i] = 2;
					y0.count = y0.count * 10 + y0.lastInput[y0.i];
					y0.i++;
				}
				if (App->input->GetKeyDown(SDLK_3))
				{
					y0.lastInput[y0.i] = 3;
					y0.count = y0.count * 10 + y0.lastInput[y0.i];
					y0.i++;
				}
				if (App->input->GetKeyDown(SDLK_4))
				{
					y0.lastInput[y0.i] = 4;
					y0.count = y0.count * 10 + y0.lastInput[y0.i];
					y0.i++;
				}
				if (App->input->GetKeyDown(SDLK_5))
				{
					y0.lastInput[y0.i] = 5;
					y0.count = y0.count * 10 + y0.lastInput[y0.i];
					y0.i++;
				}
				if (App->input->GetKeyDown(SDLK_6))
				{
					y0.lastInput[y0.i] = 6;
					y0.count = y0.count * 10 + y0.lastInput[y0.i];
					y0.i++;
				}
				if (App->input->GetKeyDown(SDLK_7))
				{
					y0.lastInput[y0.i] = 7;
					y0.count = y0.count * 10 + y0.lastInput[y0.i];
					y0.i++;
				}
				if (App->input->GetKeyDown(SDLK_8))
				{
					y0.lastInput[y0.i] = 8;
					y0.count = y0.count * 10 + y0.lastInput[y0.i];
					y0.i++;
				}
				if (App->input->GetKeyDown(SDLK_9))
				{
					y0.lastInput[y0.i] = 9;
					y0.count = y0.count * 10 + y0.lastInput[y0.i];
					y0.i++;
				}
			}
			if (y0.count != 0)
			{
				if (App->input->GetKeyDown(SDLK_BACKSPACE))
				{
					y0.i--;
					y0.count = y0.count - y0.lastInput[y0.i];
					y0.count = y0.count / 10;
				}
			}
		}

		// INPUT vx0
		else if (currentInput == 3)
		{
			if (vx0.count < 100000000)
			{
				if (App->input->GetKeyDown(SDLK_0))
				{
					vx0.lastInput[vx0.i] = 0;
					vx0.count = vx0.count * 10;
					vx0.i++;
				}
				if (App->input->GetKeyDown(SDLK_1))
				{
					vx0.lastInput[vx0.i] = 1;
					vx0.count = vx0.count * 10 + vx0.lastInput[vx0.i];
					vx0.i++;
				}
				if (App->input->GetKeyDown(SDLK_2))
				{
					vx0.lastInput[vx0.i] = 2;
					vx0.count = vx0.count * 10 + vx0.lastInput[vx0.i];
					vx0.i++;
				}
				if (App->input->GetKeyDown(SDLK_3))
				{
					vx0.lastInput[vx0.i] = 3;
					vx0.count = vx0.count * 10 + vx0.lastInput[vx0.i];
					vx0.i++;
				}
				if (App->input->GetKeyDown(SDLK_4))
				{
					vx0.lastInput[vx0.i] = 4;
					vx0.count = vx0.count * 10 + vx0.lastInput[vx0.i];
					vx0.i++;
				}
				if (App->input->GetKeyDown(SDLK_5))
				{
					vx0.lastInput[vx0.i] = 5;
					vx0.count = vx0.count * 10 + vx0.lastInput[vx0.i];
					vx0.i++;
				}
				if (App->input->GetKeyDown(SDLK_6))
				{
					vx0.lastInput[vx0.i] = 6;
					vx0.count = vx0.count * 10 + vx0.lastInput[vx0.i];
					vx0.i++;
				}
				if (App->input->GetKeyDown(SDLK_7))
				{
					vx0.lastInput[vx0.i] = 7;
					vx0.count = vx0.count * 10 + vx0.lastInput[vx0.i];
					vx0.i++;
				}
				if (App->input->GetKeyDown(SDLK_8))
				{
					vx0.lastInput[vx0.i] = 8;
					vx0.count = vx0.count * 10 + vx0.lastInput[vx0.i];
					vx0.i++;
				}
				if (App->input->GetKeyDown(SDLK_9))
				{
					vx0.lastInput[vx0.i] = 9;
					vx0.count = vx0.count * 10 + vx0.lastInput[vx0.i];
					vx0.i++;
				}
			}
			if (vx0.count != 0)
			{
				if (App->input->GetKeyDown(SDLK_BACKSPACE))
				{
					vx0.i--;
					vx0.count = vx0.count - vx0.lastInput[vx0.i];
					vx0.count = vx0.count / 10;
				}
			}
		}

		// INPUT vy0
		else if (currentInput == 4)
		{
			if (vy0.count < 100000000)
			{
				if (App->input->GetKeyDown(SDLK_0))
				{
					vy0.lastInput[vy0.i] = 0;
					vy0.count = vy0.count * 10;
					vy0.i++;
				}
				if (App->input->GetKeyDown(SDLK_1))
				{
					vy0.lastInput[vy0.i] = 1;
					vy0.count = vy0.count * 10 + vy0.lastInput[vy0.i];
					vy0.i++;
				}
				if (App->input->GetKeyDown(SDLK_2))
				{
					vy0.lastInput[vy0.i] = 2;
					vy0.count = vy0.count * 10 + vy0.lastInput[vy0.i];
					vy0.i++;
				}
				if (App->input->GetKeyDown(SDLK_3))
				{
					vy0.lastInput[vy0.i] = 3;
					vy0.count = vy0.count * 10 + vy0.lastInput[vy0.i];
					vy0.i++;
				}
				if (App->input->GetKeyDown(SDLK_4))
				{
					vy0.lastInput[vy0.i] = 4;
					vy0.count = vy0.count * 10 + vy0.lastInput[vy0.i];
					vy0.i++;
				}
				if (App->input->GetKeyDown(SDLK_5))
				{
					vy0.lastInput[vy0.i] = 5;
					vy0.count = vy0.count * 10 + vy0.lastInput[vy0.i];
					vy0.i++;
				}
				if (App->input->GetKeyDown(SDLK_6))
				{
					vy0.lastInput[vy0.i] = 6;
					vy0.count = vy0.count * 10 + vy0.lastInput[vy0.i];
					vy0.i++;
				}
				if (App->input->GetKeyDown(SDLK_7))
				{
					vy0.lastInput[vy0.i] = 7;
					vy0.count = vy0.count * 10 + vy0.lastInput[vy0.i];
					vy0.i++;
				}
				if (App->input->GetKeyDown(SDLK_8))
				{
					vy0.lastInput[vy0.i] = 8;
					vy0.count = vy0.count * 10 + vy0.lastInput[vy0.i];
					vy0.i++;
				}
				if (App->input->GetKeyDown(SDLK_9))
				{
					vy0.lastInput[vy0.i] = 9;
					vy0.count = vy0.count * 10 + vy0.lastInput[vy0.i];
					vy0.i++;
				}
			}
			if (vy0.count != 0)
			{
				if (App->input->GetKeyDown(SDLK_BACKSPACE))
				{
					vy0.i--;
					vy0.count = vy0.count - vy0.lastInput[vy0.i];
					vy0.count = vy0.count / 10;
				}
			}
		}

		// INPUT ax0
		else if (currentInput == 5)
		{
			if (ax0.count < 100000000)
			{
				if (App->input->GetKeyDown(SDLK_0))
				{
					ax0.lastInput[ax0.i] = 0;
					ax0.count = ax0.count * 10;
					ax0.i++;
				}
				if (App->input->GetKeyDown(SDLK_1))
				{
					ax0.lastInput[ax0.i] = 1;
					ax0.count = ax0.count * 10 + ax0.lastInput[ax0.i];
					ax0.i++;
				}
				if (App->input->GetKeyDown(SDLK_2))
				{
					ax0.lastInput[ax0.i] = 2;
					ax0.count = ax0.count * 10 + ax0.lastInput[ax0.i];
					ax0.i++;
				}
				if (App->input->GetKeyDown(SDLK_3))
				{
					ax0.lastInput[ax0.i] = 3;
					ax0.count = ax0.count * 10 + ax0.lastInput[ax0.i];
					ax0.i++;
				}
				if (App->input->GetKeyDown(SDLK_4))
				{
					ax0.lastInput[ax0.i] = 4;
					ax0.count = ax0.count * 10 + ax0.lastInput[ax0.i];
					ax0.i++;
				}
				if (App->input->GetKeyDown(SDLK_5))
				{
					ax0.lastInput[ax0.i] = 5;
					ax0.count = ax0.count * 10 + ax0.lastInput[ax0.i];
					ax0.i++;
				}
				if (App->input->GetKeyDown(SDLK_6))
				{
					ax0.lastInput[ax0.i] = 6;
					ax0.count = ax0.count * 10 + ax0.lastInput[ax0.i];
					ax0.i++;
				}
				if (App->input->GetKeyDown(SDLK_7))
				{
					ax0.lastInput[ax0.i] = 7;
					ax0.count = ax0.count * 10 + ax0.lastInput[ax0.i];
					ax0.i++;
				}
				if (App->input->GetKeyDown(SDLK_8))
				{
					ax0.lastInput[ax0.i] = 8;
					ax0.count = ax0.count * 10 + ax0.lastInput[ax0.i];
					ax0.i++;
				}
				if (App->input->GetKeyDown(SDLK_9))
				{
					ax0.lastInput[ax0.i] = 9;
					ax0.count = ax0.count * 10 + ax0.lastInput[ax0.i];
					ax0.i++;
				}
			}
			if (ax0.count != 0)
			{
				if (App->input->GetKeyDown(SDLK_BACKSPACE))
				{
					ax0.i--;
					ax0.count = ax0.count - ax0.lastInput[ax0.i];
					ax0.count = ax0.count / 10;
				}
			}
		}

		// INPUT ay0
		else if (currentInput == 6)
		{
			if (ay0.count < 100000000)
			{
				if (App->input->GetKeyDown(SDLK_0))
				{
					ay0.lastInput[ay0.i] = 0;
					ay0.count = ay0.count * 10;
					ay0.i++;
				}
				if (App->input->GetKeyDown(SDLK_1))
				{
					ay0.lastInput[ay0.i] = 1;
					ay0.count = ay0.count * 10 + ay0.lastInput[ay0.i];
					ay0.i++;
				}
				if (App->input->GetKeyDown(SDLK_2))
				{
					ay0.lastInput[ay0.i] = 2;
					ay0.count = ay0.count * 10 + ay0.lastInput[ay0.i];
					ay0.i++;
				}
				if (App->input->GetKeyDown(SDLK_3))
				{
					ay0.lastInput[ay0.i] = 3;
					ay0.count = ay0.count * 10 + ay0.lastInput[ay0.i];
					ay0.i++;
				}
				if (App->input->GetKeyDown(SDLK_4))
				{
					ay0.lastInput[ay0.i] = 4;
					ay0.count = ay0.count * 10 + ay0.lastInput[ay0.i];
					ay0.i++;
				}
				if (App->input->GetKeyDown(SDLK_5))
				{
					ay0.lastInput[ay0.i] = 5;
					ay0.count = ay0.count * 10 + ay0.lastInput[ay0.i];
					ay0.i++;
				}
				if (App->input->GetKeyDown(SDLK_6))
				{
					ay0.lastInput[ay0.i] = 6;
					ay0.count = ay0.count * 10 + ay0.lastInput[ay0.i];
					ay0.i++;
				}
				if (App->input->GetKeyDown(SDLK_7))
				{
					ay0.lastInput[ay0.i] = 7;
					ay0.count = ay0.count * 10 + ay0.lastInput[ay0.i];
					ay0.i++;
				}
				if (App->input->GetKeyDown(SDLK_8))
				{
					ay0.lastInput[ay0.i] = 8;
					ay0.count = ay0.count * 10 + ay0.lastInput[ay0.i];
					ay0.i++;
				}
				if (App->input->GetKeyDown(SDLK_9))
				{
					ay0.lastInput[ay0.i] = 9;
					ay0.count = ay0.count * 10 + ay0.lastInput[ay0.i];
					ay0.i++;
				}
			}
			if (ay0.count != 0)
			{
				if (App->input->GetKeyDown(SDLK_BACKSPACE))
				{
					ay0.i--;
					ay0.count = ay0.count - ay0.lastInput[ay0.i];
					ay0.count = ay0.count / 10;
				}
			}
		}

		// INPUT fx0
		else if (currentInput == 8)
		{
			if (fx0.count < 100000000)
			{
				if (App->input->GetKeyDown(SDLK_0))
				{
					fx0.lastInput[fx0.i] = 0;
					fx0.count = fx0.count * 10;
					fx0.i++;
				}
				if (App->input->GetKeyDown(SDLK_1))
				{
					fx0.lastInput[fx0.i] = 1;
					fx0.count = fx0.count * 10 + fx0.lastInput[fx0.i];
					fx0.i++;
				}
				if (App->input->GetKeyDown(SDLK_2))
				{
					fx0.lastInput[fx0.i] = 2;
					fx0.count = fx0.count * 10 + fx0.lastInput[fx0.i];
					fx0.i++;
				}
				if (App->input->GetKeyDown(SDLK_3))
				{
					fx0.lastInput[fx0.i] = 3;
					fx0.count = fx0.count * 10 + fx0.lastInput[fx0.i];
					fx0.i++;
				}
				if (App->input->GetKeyDown(SDLK_4))
				{
					fx0.lastInput[fx0.i] = 4;
					fx0.count = fx0.count * 10 + fx0.lastInput[fx0.i];
					fx0.i++;
				}
				if (App->input->GetKeyDown(SDLK_5))
				{
					fx0.lastInput[fx0.i] = 5;
					fx0.count = fx0.count * 10 + fx0.lastInput[fx0.i];
					fx0.i++;
				}
				if (App->input->GetKeyDown(SDLK_6))
				{
					fx0.lastInput[fx0.i] = 6;
					fx0.count = fx0.count * 10 + fx0.lastInput[fx0.i];
					fx0.i++;
				}
				if (App->input->GetKeyDown(SDLK_7))
				{
					fx0.lastInput[fx0.i] = 7;
					fx0.count = fx0.count * 10 + fx0.lastInput[fx0.i];
					fx0.i++;
				}
				if (App->input->GetKeyDown(SDLK_8))
				{
					fx0.lastInput[fx0.i] = 8;
					fx0.count = fx0.count * 10 + fx0.lastInput[fx0.i];
					fx0.i++;
				}
				if (App->input->GetKeyDown(SDLK_9))
				{
					fx0.lastInput[fx0.i] = 9;
					fx0.count = fx0.count * 10 + fx0.lastInput[fx0.i];
					fx0.i++;
				}
			}
			if (fx0.count != 0)
			{
				if (App->input->GetKeyDown(SDLK_BACKSPACE))
				{
					fx0.i--;
					fx0.count = fx0.count - fx0.lastInput[fx0.i];
					fx0.count = fx0.count / 10;
				}
			}
		}

		// INPUT fy0
		else if (currentInput == 9)
		{
			if (fy0.count < 100000000)
			{
				if (App->input->GetKeyDown(SDLK_0))
				{
					fy0.lastInput[fy0.i] = 0;
					fy0.count = fy0.count * 10;
					fy0.i++;
				}
				if (App->input->GetKeyDown(SDLK_1))
				{
					fy0.lastInput[fy0.i] = 1;
					fy0.count = fy0.count * 10 + fy0.lastInput[fy0.i];
					fy0.i++;
				}
				if (App->input->GetKeyDown(SDLK_2))
				{
					fy0.lastInput[fy0.i] = 2;
					fy0.count = fy0.count * 10 + fy0.lastInput[fy0.i];
					fy0.i++;
				}
				if (App->input->GetKeyDown(SDLK_3))
				{
					fy0.lastInput[fy0.i] = 3;
					fy0.count = fy0.count * 10 + fy0.lastInput[fy0.i];
					fy0.i++;
				}
				if (App->input->GetKeyDown(SDLK_4))
				{
					fy0.lastInput[fy0.i] = 4;
					fy0.count = fy0.count * 10 + fy0.lastInput[fy0.i];
					fy0.i++;
				}				if (App->input->GetKeyDown(SDLK_5))
				{
					fy0.lastInput[fy0.i] = 5;
					fy0.count = fy0.count * 10 + fy0.lastInput[fy0.i];
					fy0.i++;
				}
				if (App->input->GetKeyDown(SDLK_6))
				{
					fy0.lastInput[fy0.i] = 6;
					fy0.count = fy0.count * 10 + fy0.lastInput[fy0.i];
					fy0.i++;
				}
				if (App->input->GetKeyDown(SDLK_7))
				{
					fy0.lastInput[fy0.i] = 7;
					fy0.count = fy0.count * 10 + fy0.lastInput[fy0.i];
					fy0.i++;
				}
				if (App->input->GetKeyDown(SDLK_8))
				{
					fy0.lastInput[fy0.i] = 8;
					fy0.count = fy0.count * 10 + fy0.lastInput[fy0.i];
					fy0.i++;
				}
				if (App->input->GetKeyDown(SDLK_9))
				{
					fy0.lastInput[fy0.i] = 9;
					fy0.count = fy0.count * 10 + fy0.lastInput[fy0.i];
					fy0.i++;
				}
			}
			if (fy0.count != 0)
			{
				if (App->input->GetKeyDown(SDLK_BACKSPACE))
				{
					fy0.i--;
					fy0.count = fy0.count - fy0.lastInput[fy0.i];
					fy0.count = fy0.count / 10;
				}
			}
		}

		// INPUT L
		else if (currentInput == 7)
		{
			if (SideLength.count < 100000000)
			{
				if (App->input->GetKeyDown(SDLK_0))
				{
					SideLength.lastInput[SideLength.i] = 0;
					SideLength.count = SideLength.count * 10;
					SideLength.i++;
				}
				if (App->input->GetKeyDown(SDLK_1))
				{
					SideLength.lastInput[SideLength.i] = 1;
					SideLength.count = SideLength.count * 10 + SideLength.lastInput[SideLength.i];
					SideLength.i++;
				}
				if (App->input->GetKeyDown(SDLK_2))
				{
					SideLength.lastInput[SideLength.i] = 2;
					SideLength.count = SideLength.count * 10 + SideLength.lastInput[SideLength.i];
					SideLength.i++;
				}
				if (App->input->GetKeyDown(SDLK_3))
				{
					SideLength.lastInput[SideLength.i] = 3;
					SideLength.count = SideLength.count * 10 + SideLength.lastInput[SideLength.i];
					SideLength.i++;
				}
				if (App->input->GetKeyDown(SDLK_4))
				{
					SideLength.lastInput[SideLength.i] = 4;
					SideLength.count = SideLength.count * 10 + SideLength.lastInput[SideLength.i];
					SideLength.i++;
				}
				if (App->input->GetKeyDown(SDLK_5))
				{
					SideLength.lastInput[SideLength.i] = 5;
					SideLength.count = SideLength.count * 10 + SideLength.lastInput[SideLength.i];
					SideLength.i++;
				}
				if (App->input->GetKeyDown(SDLK_6))
				{
					SideLength.lastInput[SideLength.i] = 6;
					SideLength.count = SideLength.count * 10 + SideLength.lastInput[SideLength.i];
					SideLength.i++;
				}
				if (App->input->GetKeyDown(SDLK_7))
				{
					SideLength.lastInput[SideLength.i] = 7;
					SideLength.count = SideLength.count * 10 + SideLength.lastInput[SideLength.i];
					SideLength.i++;
				}
				if (App->input->GetKeyDown(SDLK_8))
				{
					SideLength.lastInput[SideLength.i] = 8;
					SideLength.count = SideLength.count * 10 + SideLength.lastInput[SideLength.i];
					SideLength.i++;
				}
				if (App->input->GetKeyDown(SDLK_9))
				{
					SideLength.lastInput[SideLength.i] = 9;
					SideLength.count = SideLength.count * 10 + SideLength.lastInput[SideLength.i];
					SideLength.i++;
				}
			}
			if (SideLength.count != 0)
			{
				if (App->input->GetKeyDown(SDLK_BACKSPACE))
				{
					SideLength.i--;
					SideLength.count = SideLength.count - SideLength.lastInput[SideLength.i];
					SideLength.count = SideLength.count / 10;
				}
			}
		}

		// INPUT colision
		else if (currentInput == 11)
		{
			if (collision.count < 100000000)
			{
				if (App->input->GetKeyDown(SDLK_0))
				{
					collision.lastInput[collision.i] = 0;
					collision.count = collision.count * 10;
					collision.i++;
				}
				if (App->input->GetKeyDown(SDLK_1))
				{
					collision.lastInput[collision.i] = 1;
					collision.count = collision.count * 10 + collision.lastInput[collision.i];
					collision.i++;
				}
				if (App->input->GetKeyDown(SDLK_2))
				{
					collision.lastInput[collision.i] = 2;
					collision.count = collision.count * 10 + collision.lastInput[collision.i];
					collision.i++;
				}
				if (App->input->GetKeyDown(SDLK_3))
				{
					collision.lastInput[collision.i] = 3;
					collision.count = collision.count * 10 + collision.lastInput[collision.i];
					collision.i++;
				}
				if (App->input->GetKeyDown(SDLK_4))
				{
					collision.lastInput[collision.i] = 4;
					collision.count = collision.count * 10 + collision.lastInput[collision.i];
					collision.i++;
				}
				if (App->input->GetKeyDown(SDLK_5))
				{
					collision.lastInput[collision.i] = 5;
					collision.count = collision.count * 10 + collision.lastInput[collision.i];
					collision.i++;
				}
				if (App->input->GetKeyDown(SDLK_6))
				{
					collision.lastInput[collision.i] = 6;
					collision.count = collision.count * 10 + collision.lastInput[collision.i];
					collision.i++;
				}
				if (App->input->GetKeyDown(SDLK_7))
				{
					collision.lastInput[collision.i] = 7;
					collision.count = collision.count * 10 + collision.lastInput[collision.i];
					collision.i++;
				}
				if (App->input->GetKeyDown(SDLK_8))
				{
					collision.lastInput[collision.i] = 8;
					collision.count = collision.count * 10 + collision.lastInput[collision.i];
					collision.i++;
				}
				if (App->input->GetKeyDown(SDLK_9))
				{
					collision.lastInput[collision.i] = 9;
					collision.count = collision.count * 10 + collision.lastInput[collision.i];
					collision.i++;
				}
			}
			if (collision.count != 0)
			{
				if (App->input->GetKeyDown(SDLK_BACKSPACE))
				{
					collision.i--;
					collision.count = collision.count - collision.lastInput[collision.i];
					collision.count = collision.count / 10;
				}
			}
		}

		// INPUT time
		else if (currentInput == 12)
		{
			if (time.count < 100000000)
			{
				if (App->input->GetKeyDown(SDLK_0))
				{
					time.lastInput[time.i] = 0;
					time.count = time.count * 10;
					time.i++;
				}
				if (App->input->GetKeyDown(SDLK_1))
				{
					time.lastInput[time.i] = 1;
					time.count = time.count * 10 + time.lastInput[time.i];
					time.i++;
				}
				if (App->input->GetKeyDown(SDLK_2))
				{
					time.lastInput[time.i] = 2;
					time.count = time.count * 10 + time.lastInput[time.i];
					time.i++;
				}
				if (App->input->GetKeyDown(SDLK_3))
				{
					time.lastInput[time.i] = 3;
					time.count = time.count * 10 + time.lastInput[time.i];
					time.i++;
				}
				if (App->input->GetKeyDown(SDLK_4))
				{
					time.lastInput[time.i] = 4;
					time.count = time.count * 10 + time.lastInput[time.i];
					time.i++;
				}
				if (App->input->GetKeyDown(SDLK_5))
				{
					time.lastInput[time.i] = 5;
					time.count = time.count * 10 + time.lastInput[time.i];
					time.i++;
				}
				if (App->input->GetKeyDown(SDLK_6))
				{
					time.lastInput[time.i] = 6;
					time.count = time.count * 10 + time.lastInput[time.i];
					time.i++;
				}
				if (App->input->GetKeyDown(SDLK_7))
				{
					time.lastInput[time.i] = 7;
					time.count = time.count * 10 + time.lastInput[time.i];
					time.i++;
				}
				if (App->input->GetKeyDown(SDLK_8))
				{
					time.lastInput[time.i] = 8;
					time.count = time.count * 10 + time.lastInput[time.i];
					time.i++;
				}
				if (App->input->GetKeyDown(SDLK_9))
				{
					time.lastInput[time.i] = 9;
					time.count = time.count * 10 + time.lastInput[time.i];
					time.i++;
				}
			}
			if (mu.count != 0)
			{
				if (App->input->GetKeyDown(SDLK_BACKSPACE))
				{
					mu.i--;
					mu.count = mu.count - mu.lastInput[mu.i];
					mu.count = mu.count / 10;
				}
			}
		}

		// INPUT mu
		else if (currentInput == 10)
		{
			if (mu.count < 100000000)
			{
				if (App->input->GetKeyDown(SDLK_0))
				{
					mu.lastInput[mu.i] = 0;
					mu.count = mu.count * 10;
					mu.i++;
				}
				if (App->input->GetKeyDown(SDLK_1))
				{
					mu.lastInput[mu.i] = 1;
					mu.count = mu.count * 10 + mu.lastInput[mu.i];
					mu.i++;
				}
				if (App->input->GetKeyDown(SDLK_2))
				{
					mu.lastInput[mu.i] = 2;
					mu.count = mu.count * 10 + mu.lastInput[mu.i];
					mu.i++;
				}
				if (App->input->GetKeyDown(SDLK_3))
				{
					mu.lastInput[mu.i] = 3;
					mu.count = mu.count * 10 + mu.lastInput[mu.i];
					mu.i++;
				}
				if (App->input->GetKeyDown(SDLK_4))
				{
					mu.lastInput[mu.i] = 4;
					mu.count = mu.count * 10 + mu.lastInput[mu.i];
					mu.i++;
				}
				if (App->input->GetKeyDown(SDLK_5))
				{
					mu.lastInput[mu.i] = 5;
					mu.count = mu.count * 10 + mu.lastInput[mu.i];
					mu.i++;
				}
				if (App->input->GetKeyDown(SDLK_6))
				{
					mu.lastInput[mu.i] = 6;
					mu.count = mu.count * 10 + mu.lastInput[mu.i];
					mu.i++;
				}
				if (App->input->GetKeyDown(SDLK_7))
				{
					mu.lastInput[mu.i] = 7;
					mu.count = mu.count * 10 + mu.lastInput[mu.i];
					mu.i++;
				}
				if (App->input->GetKeyDown(SDLK_8))
				{
					mu.lastInput[mu.i] = 8;
					mu.count = mu.count * 10 + mu.lastInput[mu.i];
					mu.i++;
				}
				if (App->input->GetKeyDown(SDLK_9))
				{
					mu.lastInput[mu.i] = 9;
					mu.count = mu.count * 10 + mu.lastInput[mu.i];
					mu.i++;
				}
			}
			if (mu.count != 0)
			{
				if (App->input->GetKeyDown(SDLK_BACKSPACE))
				{
					mu.i--;
					mu.count = mu.count - mu.lastInput[mu.i];
					mu.count = mu.count / 10;
				}
			}
		}
	}
	else if (step == 3) // SELECT MODE
	{
		App->render->Blit(screen_3, 0, 0);

		if (App->input->GetKeyDown(SDLK_1))
		{
			step++;
		}
		else if (App->input->GetKeyDown(SDLK_2))
		{
			step += 2;
			cube.setX(x0.count);
			cube.setY(y0.count);
			cube.setVX(vx0.count);
			cube.setVY(vy0.count);
			cube.setAX(ax0.count);
			cube.setAY(ay0.count);
			//cube.setSideLength(SideLength.count);
			cube.setFX(fx0.count);
			cube.setFY(fy0.count);
		}
		else if (App->input->GetKeyDown(SDLK_b))
		{
			step--;
		}
	}
	else if (step == 4) // INTEGRATOR TEST
	{
		App->render->Blit(screen_4, 0, 0);

		if (App->input->GetKeyDown(SDLK_RETURN))
		{
			step += 2;
		}
		else if (App->input->GetKeyDown(SDLK_b))
		{
			step--;
		}
	}
	else if (step == 5) // FINAL DATA
	{
		App->render->Blit(screen_5, 0, 0);
		if (App->input->GetKeyDown(SDLK_1))
		{
			first_time = true;
			draw = true;
			step++;
		}
		if (App->input->GetKeyDown(SDLK_RETURN))
		{
			step = 0;
		}
		if (App->input->GetKeyDown(SDLK_b))
		{
			step -= 2;
		}
	}
	
	else if (step == 6) // GRAPHICAL REPRESENTATION
	{
		App->render->Blit(screen_6, 0, 0);
		if (first_time)
		{
			quad.h = quad.w = SideLength.count;
			quad.x = x0.count;
			quad.y = GROUND_POS - quad.h - y0.count;
			first_time = false;
		}

		// Run integrator
		App->physics->Update(dt);

		if (App->input->GetKeyDown(SDLK_b))
		{
			step--;
			draw = false;
		}
	}
	return true;
}

// Called each loop iteration
bool j1Scene::PostUpdate()
{
	if (step == 2)
	{ // x0
		sprintf_s(x0.count_string, 10, "%1d", x0.count);
		App->fonts->BlitText(450, star_position[0] + 1, font, x0.count_string);

		sprintf_s(y0.count_string, 10, "%1d", y0.count);
		App->fonts->BlitText(450, star_position[1] + 1, font, y0.count_string);

		sprintf_s(vx0.count_string, 10, "%1d", vx0.count);
		App->fonts->BlitText(450, star_position[2] + 1, font, vx0.count_string);

		sprintf_s(vy0.count_string, 10, "%1d", vy0.count);
		App->fonts->BlitText(450, star_position[3] + 1, font, vy0.count_string);

		sprintf_s(ax0.count_string, 10, "%1d", ax0.count);
		App->fonts->BlitText(450, star_position[4] + 1, font, ax0.count_string);

		sprintf_s(ay0.count_string, 10, "%1d", ay0.count);
		App->fonts->BlitText(450, star_position[5] + 1, font, ay0.count_string);

		sprintf_s(SideLength.count_string, 10, "%1d", SideLength.count);
		App->fonts->BlitText(450, star_position[6] + 1, font, SideLength.count_string);

		sprintf_s(fx0.count_string, 10, "%1d", fx0.count);
		App->fonts->BlitText(450, star_position[7] + 1, font, fx0.count_string);

		sprintf_s(fy0.count_string, 10, "%1d", fy0.count);
		App->fonts->BlitText(450, star_position[8] + 1, font, fy0.count_string);

		sprintf_s(mu.count_string, 10, "%1d", mu.count);
		App->fonts->BlitText(450, star_position[9] + 1, font, mu.count_string);

		sprintf_s(collision.count_string, 10, "%1d", collision.count);
		App->fonts->BlitText(450, star_position[10] + 1, font, collision.count_string);

		sprintf_s(time.count_string, 10, "%1d", time.count);
		App->fonts->BlitText(450, star_position[11] + 1, font, time.count_string);
	}
	if (step == 5)
	{ // FIRST COLUMN ---------------------------------------------------------------------
		sprintf_s(x0.count_string, 10, "%1d", x0.count);
		App->fonts->BlitText(450, star_position[0] + 1, font, x0.count_string);

		sprintf_s(y0.count_string, 10, "%1d", y0.count);
		App->fonts->BlitText(450, star_position[1] + 1, font, y0.count_string);

		sprintf_s(vx0.count_string, 10, "%1d", vx0.count);
		App->fonts->BlitText(450, star_position[2] + 1, font, vx0.count_string);

		sprintf_s(vy0.count_string, 10, "%1d", vy0.count);
		App->fonts->BlitText(450, star_position[3] + 1, font, vy0.count_string);

		sprintf_s(ax0.count_string, 10, "%1d", ax0.count);
		App->fonts->BlitText(450, star_position[4] + 1, font, ax0.count_string);

		sprintf_s(ay0.count_string, 10, "%1d", ay0.count);
		App->fonts->BlitText(450, star_position[5] + 1, font, ay0.count_string);

		sprintf_s(SideLength.count_string, 10, "%1d", SideLength.count);
		App->fonts->BlitText(450, star_position[6] + 1, font, SideLength.count_string);

		sprintf_s(fx0.count_string, 10, "%1d", fx0.count);
		App->fonts->BlitText(450, star_position[7] + 1, font, fx0.count_string);

		sprintf_s(fy0.count_string, 10, "%1d", fy0.count);
		App->fonts->BlitText(450, star_position[8] + 1, font, fy0.count_string);

		sprintf_s(mu.count_string, 10, "%1d", mu.count);
		App->fonts->BlitText(450, star_position[9] + 1, font, mu.count_string);

		sprintf_s(collision.count_string, 10, "%1d", collision.count);
		App->fonts->BlitText(450, star_position[10] + 1, font, collision.count_string);

		sprintf_s(time.count_string, 10, "%1d", time.count);
		App->fonts->BlitText(450, star_position[11] + 1, font, time.count_string);

	  // SECOND COLUMN ---------------------------------------------------------------------
		// INTEGRATOR
		sprintf_s(x0.count_string, 10, "%1d", cube.getX());
		App->fonts->BlitText(760, star_position[1] - 6, font, x0.count_string);

		sprintf_s(y0.count_string, 10, "%1d", cube.getY());
		App->fonts->BlitText(760, star_position[2] - 6, font, y0.count_string);

		sprintf_s(vx0.count_string, 10, "%1d", cube.getVX());
		App->fonts->BlitText(760, star_position[3] - 6, font, vx0.count_string);

		sprintf_s(vy0.count_string, 10, "%1d", cube.getVY());
		App->fonts->BlitText(760, star_position[4] - 6, font, vy0.count_string);

		sprintf_s(ax0.count_string, 10, "%1d", cube.getAX());
		App->fonts->BlitText(760, star_position[5] - 6, font, ax0.count_string);

		sprintf_s(ay0.count_string, 10, "%1d", cube.getAY());
		App->fonts->BlitText(760, star_position[6] - 6, font, ay0.count_string);

		// NEWTON'S LAWS
		sprintf_s(x0.count_string, 10, "%1d", cube.getX());
		App->fonts->BlitText(760, star_position[8] - 8, font, x0.count_string);

		sprintf_s(y0.count_string, 10, "%1d", cube.getY());
		App->fonts->BlitText(760, star_position[9] - 8, font, y0.count_string);

		sprintf_s(vx0.count_string, 10, "%1d", cube.getVX());
		App->fonts->BlitText(760, star_position[10] - 24, font, vx0.count_string);

		sprintf_s(vy0.count_string, 10, "%1d", cube.getVY());
		App->fonts->BlitText(760, star_position[11] - 42, font, vy0.count_string);

		sprintf_s(ax0.count_string, 10, "%1d", cube.getAX());
		App->fonts->BlitText(760, star_position[11] - 10, font, ax0.count_string);

		sprintf_s(ay0.count_string, 10, "%1d", cube.getAY());
		App->fonts->BlitText(760, star_position[11] + 21, font, ay0.count_string);
	}

	if (App->input->GetKeyDown(SDLK_c))
	{
		x0.count = 0; 
		x0.i = 0; 
		for (int i = 0; i < 10; i++) x0.lastInput[i] = 0;

		y0.count = 0;
		y0.i = 0;
		for (int i = 0; i < 10; i++) y0.lastInput[i] = 0;

		vx0.count = 0;
		vx0.i = 0;
		for (int i = 0; i < 10; i++) vx0.lastInput[i] = 0;

		vy0.count = 0;
		vy0.i = 0;
		for (int i = 0; i < 10; i++) vy0.lastInput[i] = 0;

		ax0.count = 0;
		ax0.i = 0;
		for (int i = 0; i < 10; i++) ax0.lastInput[i] = 0;

		ay0.count = 0;
		ay0.i = 0;
		for (int i = 0; i < 10; i++) ay0.lastInput[i] = 0;

		fx0.count = 0;
		fx0.i = 0;
		for (int i = 0; i < 10; i++) fx0.lastInput[i] = 0;

		fy0.count = 0;
		fy0.i = 0;
		for (int i = 0; i < 10; i++) fy0.lastInput[i] = 0;

		SideLength.count = 0;
		SideLength.i = 0;
		for (int i = 0; i < 10; i++) SideLength.lastInput[i] = 0;

		mu.count = 0;
		mu.i = 0;
		for (int i = 0; i < 10; i++) mu.lastInput[i] = 0;

		collision.count = 0;
		collision.i = 0;
		for (int i = 0; i < 10; i++) collision.lastInput[i] = 0;

		time.count = 0;
		time.i = 0;
		for (int i = 0; i < 10; i++) time.lastInput[i] = 0;
	}
	bool ret = true;
	if (App->input->GetKeyDown(SDLK_ESCAPE))
		ret = false;

	return ret;
}

// Called before quitting
bool j1Scene::CleanUp()
{
	LOG("Freeing scene");
	App->tex->UnLoad(screen_0);
	App->tex->UnLoad(ball_tex);
	App->tex->UnLoad(objTex);
	App->fonts->UnLoad(font);
	return true;
}

void j1Scene::Draw(float x, float y)
{
	App->render->DrawQuad(quad, 255, 0, 0);

	//Blit current x and y pos of the square

}
