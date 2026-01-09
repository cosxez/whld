#include <iostream>
#include <SDL2/SDL.h>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	cout<<"Enter filename: ";
	string file_name;
	getline(cin,file_name);

	ifstream file(file_name);
	

	char ch;

	string str;
	string line;

	int width;
	int height;

	vector<int> x;
	vector<int> y;

	vector<int> red;
	vector<int> green;
	vector<int> blue;
	
	int check_line=0;
	while (getline(file,line))
	{
		line+=" ";
		int rgb=0;
		check_line++;
		for (int i=0;i<line.size();i++)
		{
			
			if (line.at(i)!=' ')
			{
				str+=line.at(i);
			}

			else
			{
				rgb++;
				
				if (str.empty())
				{
					break;
				}

				
				if (str.at(str.size()-1)=='W')
				{
					
					string width_string;
					for (int w_s=0;w_s<str.size()-1;w_s++)
					{
						width_string+=str.at(w_s);
					}
					
					width=stoi(width_string);
					
				}

				else if (str.at(str.size()-1)=='H')
				{
					
					string height_string;
					
					for (int h_s=0;h_s<str.size()-1;h_s++)
					{
						height_string+=str.at(h_s);
					}
					height=stoi(height_string);
					
				}

				if (check_line>1)
				{
					if (rgb==1)
					{
					
						string red_string;
						for (int r_s=0;r_s<str.size();r_s++)
						{
							red_string+=str.at(r_s);
						}
					
						int r_v=stoi(red_string);
						red.push_back(r_v);
					}

					else if (rgb==2)
					{
						string green_string;
						for (int g_s=0;g_s<str.size();g_s++)
						{
							green_string+=str.at(g_s);
						}
						int g_v=stoi(green_string);
						green.push_back(g_v);
					}

					else if (rgb==3)
					{
						string blue_string;
						for (int b_s=0;b_s<str.size();b_s++)
						{
							blue_string+=str.at(b_s);
						}
						int b_v=stoi(blue_string);
						blue.push_back(b_v);
					}
				}

				str="";
			}
		}
	}

	
	for (int i=0;i<height;i++)
	{
		for (int t=0;t<width;t++)
		{
			y.push_back(i);
			x.push_back(t);
		}
		
	}

	

	SDL_Window* window=SDL_CreateWindow(file_name.c_str(),SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,width,height,SDL_WINDOW_SHOWN);
	

	SDL_Renderer* ren=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

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
		
		
		for (int i=0;i<x.size()&& i<y.size();i++)
		{
			
			SDL_SetRenderDrawColor(ren,red.at(i),green.at(i),blue.at(i),255);
			
			SDL_RenderDrawPoint(ren,x.at(i),y.at(i));
			
				
		}
		
		SDL_RenderPresent(ren);
		
	}
	SDL_Quit();
	
}
