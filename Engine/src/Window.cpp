#include "Window.hpp"

using std::string;

Window* Window::instance = nullptr;

Window::Window(string title, int width, int height) {

     if(0 != SDL_Init(SDL_INIT_VIDEO)) {
		Error(SDL_GetError());
     }
     REPORT_I_WAS_HERE;

     if(Window::instance != nullptr) {
		Error("Second instantion of the window!");
	}
	Window::instance = this;

     REPORT_I_WAS_HERE;
     window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_RESIZABLE);
     REPORT_I_WAS_HERE;
     if(nullptr == window) {
		Error(SDL_GetError());
     }
     REPORT_I_WAS_HERE;

     renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
     REPORT_I_WAS_HERE;
     if(nullptr == renderer) {
		Error(SDL_GetError());
     }
}

Window::~Window(){
     SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}

Window& Window::GetInstance(void) {
	return *(Window::instance);
}

SDL_Renderer* Window::GetRenderer(void) const {
	return renderer;
}

void Window::ReDoRenderer(void) {
     REPORT_I_WAS_HERE;
     if(-1 == SDL_SetRenderDrawColor(renderer, CLEAR_COLOR)) {
          Error(SDL_GetError());
     }
     SDL_RenderClear(renderer);
}

Vec2 Window::GetWindowDimensions(void) const {
	Vec2 ret;
	int x = 0;
	int y = 0;
	SDL_GetWindowSize(window, &x, &y);
	ret.x = x;
	ret.y = y;
	return ret;
}

SDL_Window* Window::GetWindow(void) const {
	return window;
}

void Window::SetWindowDimensions(Vec2 size){
	SDL_SetWindowSize(window, size.x, size.y);
	SetWindowCentered();
}

void Window::SetWindowFullscreen(bool isFullScreen){
	SDL_SetWindowFullscreen(window, isFullScreen ? SDL_WINDOW_FULLSCREEN : 0);
	SetWindowCentered();
}

void Window::SetWindowMaximized(void){
	SDL_MaximizeWindow(window);
	SetWindowCentered();
}

void Window::SetWindowBorderless(bool isBorderless){
	SDL_SetWindowBordered(window, isBorderless ? SDL_FALSE : SDL_TRUE);
	SetWindowCentered();
}

void Window::SetWindowCentered(void){
	SDL_SetWindowPosition(window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
}

bool Window::GetWindowFullscreen(void) const{
	return SDL_GetWindowFlags(window) & SDL_WINDOW_FULLSCREEN;
}

bool Window::GetWindowMaximized(void) const{
	return SDL_GetWindowFlags(window) & SDL_WINDOW_MAXIMIZED;
}

bool Window::GetWindowBorderless(void) const{
	return SDL_GetWindowFlags(window) & SDL_WINDOW_BORDERLESS;
}

