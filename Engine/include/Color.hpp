#ifndef __COLOR_HPP__
#define __COLOR_HPP__

#define INCLUDE_SDL
#include "SDLIncludes.hpp"

/**
	\brief Informa cores pré definidas.

	Informa as cores para autodefinição na struct Color.
*/
typedef enum Colors{
	BLACK,/**< Cor preta*/
	WHITE,/**< Cor branca*/
	GRAY,/**< Cor cinza*/
	RED,/**< Cor vermelha*/
	YELLOW,/**< Cor amarela*/
	BLUE,/**< Cor azul*/
	GREEN,/**< Cor verde*/
	CYAN/**< Cor ciano*/
 } ColorName;

/**
	\brief Struct para armazenar informações de cor

	Cor é uma struct cujo único propósito é permitir o armazenamento de informações de cor em uma variável só.
*/
struct Color {
	public:
		unsigned char r;/**< Canal R */
		unsigned char g;/**< Canal G */
		unsigned char b;/**< Canal B */
		unsigned char a;/**< Canal A */
		/**
			\brief Cria um tipo para armazenar a cor [R,G,B,A]
			\param unsigned char r Intensidade do Canal Vermelho (Red) da cor
			\param unsigned char g Intensidade do Canal Verde (Green) da cor
			\param unsigned char b Intensidade do Canal Azul (Blue) da cor
			\param unsigned char a Intensidade do Canal Alfa (Alpha) da cor, ou seja, opacidade.

			Essa struct representa uma cor de 8 bits. Ou seja, cada canal pode receber um número entre 0 (inclusive) e 255 (inclusive).
		*/
		Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a = 255);
		/**
			\brief Cria um tipo para armazenar a cor [R,G,B,A] com cores pré definidas
			\param ColorNames color Informa o nome da cor para que seja definida.

			Essa struct representa uma cor de 8 bits. Ou seja, cada canal pode receber um número entre 0 (inclusive) e 255 (inclusive).
		*/
		Color(ColorName color);
		operator SDL_Color();
};

#endif // __COLOR_HPP__
