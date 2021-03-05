

#include "SDL_events.h"
#include "SDL_video.h"
#include "glm/fwd.hpp"
#include <iostream>

//#include <pthread.h>

#include <SDL.h>

#include <GL/glew.h>
#include <GL/GLU.h>
#include <SDL_opengl.h>

#include <glm/glm.hpp>




int main(int argc, char * argv[])
{
	//glewInit();
	//glm::vec3 v;
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);

	SDL_Window * w;
	SDL_GLContext g;
	w = SDL_CreateWindow("hey", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 1000, SDL_WINDOW_OPENGL);
	g = SDL_GL_CreateContext(w);

	int r = glewInit();

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	bool isr = true;
	SDL_Event e;

	while(isr)
	{
		while(SDL_PollEvent(&e))
		{
			if(e.type == SDL_QUIT)
			{
				isr = false;
			}
		}
	}

	SDL_GL_SwapWindow(w);

	std::cout << "hi" << std::endl;
	std::cout << "hey" << std::endl;
	return 0;
}

