#include "Color.hpp"

Color::Color( unsigned char r, unsigned char g, unsigned char b, unsigned char a ) : r(r), g(g), b(b), a(a) {
}

Color::Color(ColorName color) {
	switch(color){
		case ColorName::BLACK:
		    r = 0;
		    g = 0;
		    b = 0;
		    a = 255;
		    break;
  
		case ColorName::WHITE:
		    r = 255;
		    g = 255;
		    b = 255;
		    a = 255;
		    break;
		
		case ColorName::GRAY:
		    r = 127;
		    g = 127;
		    b = 127;
		    a = 255;
		    break;
		
		case ColorName::RED:
		    r = 255;
		    g = 0;
		    b = 0;
		    a = 255;
		    break;
  
		case ColorName::YELLOW:
		    r = 255;
		    g = 255;
		    b = 0;
		    a = 255;
		    break;
		
		case ColorName::BLUE:
		    r = 0;
		    g = 0;
		    b = 255;
		    a = 255;
		    break;
  
		case ColorName::GREEN:
		    r = 0;
		    g = 255;
		    b = 0;
		    a = 255;
		    break;
		
		case ColorName::CYAN:
		    r = 0;
		    g = 191;
		    b = 255;
		    a = 255;
		    break;
	 }
}

Color::operator SDL_Color() {
	SDL_Color c;
	c.r = r;
	c.g = g;
	c.b = b;
	c.a = a;
	return c;
}
