#include <iostream>
#include <fstream>
#include <vector>
#include <SDL2/SDL.h>
#include <string>

using namespace std;

struct Image
{
	uint8_t red;
	uint8_t green;
	uint8_t blue;
};

int main()
{
	string path;
	cout<<"Enter filename: ";
	getline(cin,path);
	ifstream file(path,ios::binary);
	Image img;
	unsigned int width;
	unsigned int height;

	vector<uint8_t> r_c;
	vector<uint8_t> g_c;
	vector<uint8_t> b_c;

	vector<int> x;
	vector<int> y;
	
	file.read(reinterpret_cast<char*>(&width),sizeof(width));
	file.read(reinterpret_cast<char*>(&height),sizeof(height));
	
	while (!file.eof())
	{
		file.read(reinterpret_cast<char*>(&img),sizeof(img));
		r_c.push_back(static_cast<uint8_t>(img.red));
		g_c.push_back(static_cast<uint8_t>(img.green));
		b_c.push_back(static_cast<uint8_t>(img.blue));
	}
	file.close();

	for (int i=0;i<height;i++)
	{
		for (int j=0;j<width;j++)
		{
			x.push_back(j);
			y.push_back(i);
		}
	}
	
	SDL_Window* win=SDL_CreateWindow(path.c_str(),SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,width,height,SDL_WINDOW_SHOWN);

	SDL_Renderer* ren=SDL_CreateRenderer(win,-1,SDL_RENDERER_ACCELERATED);
	bool run=true;
	SDL_Event event;

	while (run)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type==SDL_QUIT)
			{
				run=false;
			}
		}
		
		SDL_SetRenderDrawColor(ren,0,0,0,255);
		SDL_RenderClear(ren);

		for (int i=0;i<x.size() &&i< y.size();i++)
		{
			SDL_SetRenderDrawColor(ren,r_c.at(i),g_c.at(i),b_c.at(i),255);
			SDL_RenderDrawPoint(ren,x.at(i),y.at(i));

		}
		SDL_RenderPresent(ren);
	}
	SDL_Quit();	
	SDL_DestroyWindow(win);
	return 0;
}
