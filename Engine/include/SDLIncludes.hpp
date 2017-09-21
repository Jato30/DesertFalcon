/************************************************
*					SDL.h					  *
*************************************************/
#ifdef INCLUDE_SDL 
     // WINDOWS
	#ifdef _WIN32
          #include <SDL.h>
          
     // MAC
	#elif __APPLE__
		#include "TargetConditionals.h"
		#include <SDL2/SDL.h>
          
     //LINUX
	#elif __linux__
          #include <SDL2/SDL.h>
          
	#else
          #error "Unknown compiler"
          
	#endif
     #undef INCLUDE_SDL 
     
#endif // INCLUDE_SDL


/************************************************
*				 SDL_image.h				   *
*************************************************/
#ifdef INCLUDE_SDL_IMAGE 
     // WINDOWS
	#ifdef _WIN32
          #include <SDL_image.h>
          
     // MAC
	#elif __APPLE__
		#include "TargetConditionals.h"
		#include <SDL2/SDL_image.h>
          
     // LINUX
	#elif __linux__
          #include <SDL2/SDL_image.h>
          
	#else
          #error "Unknown compiler"
          
	#endif
	#undef INCLUDE_SDL_IMAGE 
#endif // INCLUDE_SDL_IMAGE


/************************************************
*				 SDL_mixer.h				   *
*************************************************/
#ifdef INCLUDE_SDL_MIXER 
     //WINDOWS
	#ifdef _WIN32
          #include <SDL_mixer.h>
          
     // MAC
	#elif __APPLE__
		#include "TargetConditionals.h"
		#include <SDL2/SDL_mixer.h>
          
     // LINUX
	#elif __linux__
          #include <SDL2/SDL_mixer.h>
          
	#else
          #error "Unknown compiler"
          
	#endif
	#undef INCLUDE_SDL_MIXER 
#endif // INCLUDE_SDL_MIXER


/************************************************
*				  SDL_ttf.h					*
*************************************************/
#ifdef INCLUDE_SDL_TTF 
     // WINDOWS
	#ifdef _WIN32
          #include <SDL_ttf.h>
          
     // MAC
	#elif __APPLE__
		#include "TargetConditionals.h"
		#include <SDL2/SDL_ttf.h>
          
     // LINUX
	#elif __linux__
          #include <SDL2/SDL_ttf.h>
          
	#else
          #error "Unknown compiler"
          
	#endif
	#undef INCLUDE_SDL_TTF 
#endif // INCLUDE_SDL_TTF


/************************************************
*				  SDL_net.h					*
*************************************************/
#ifdef INCLUDE_SDL_NET 
     // WINDOWS
	#ifdef _WIN32
          #include <SDL_net.h>
          
     // MAC
	#elif __APPLE__
		#include "TargetConditionals.h"
		#include <SDL2/SDL_net.h>
          
     // LINUX
	#elif __linux__
          #include <SDL2/SDL_net.h>
          
	#else
          #error "Unknown compiler"
          
	#endif
	#undef INCLUDE_SDL_NET 
#endif // INCLUDE_SDL_NET
