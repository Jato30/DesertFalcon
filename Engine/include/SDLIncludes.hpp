// Windows
#ifdef _WIN32
     #include "SDL.h"
     #include "SDL_image.h"

// Mac
#elif __APPLE__
     #include "TargetConditionals.h"

// Linux
#elif __linux__
     #include <SDL2/SDL.h>
     #include <SDL2/SDL_image.h>

#else
     #error "Unknown compiler"
     
#endif