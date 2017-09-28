#ifndef __WINDOW_HPP__
#define __WINDOW_HPP__

#include "Error.hpp"
#include "Vec2.hpp"
#include <string>

#define INCLUDE_SDL 
#include "SDLIncludes.hpp"

#define CLEAR_COLOR 0,0,0,255

class Window{
     public:
          Window();
          Window(std::string title, int width, int height);
          ~Window();
          /**
			\brief Obtém referência da Window
			\return Referência para Window

			Esquema básico do singleton. Retorna instância do singleton. Não se faz a chegagem da existência da instancia por motivos cronológicos (o construtor de Game deve criar uma instância de Window).
		*/
          static Window& GetInstance(void);
          /**
			\brief Obtém referência do SDL_Renderer
			\return Referência para SDL_Renderer

			Retorna a referência do SDL_Renderer da Window
		*/
		SDL_Renderer* GetRenderer(void) const;
          /**
			\brief Informa as dimensões da janela corrente
			\return Veja a descrição.

			Retorna o um Vec2 contendo as dimensões da janela (float width, float height).
		*/
		Vec2 GetWindowDimensions(void) const;
          /**
			\brief Obtém referência do SDL_Window
			\return Referncia para SDL_Window

			Retorna a referência do SDL_Window de Window
		*/
		SDL_Window* GetWindow(void) const;
		/**
			\brief Define as dimensões da janela corrente
			\param Vec2 size Vec2(x, y) que representa os novos tamanhos da janela.

			Altera as dimensões da janela de acordo com o tamanho (width, height) recebido.
		*/
		void SetWindowDimensions(Vec2);
		/**
			\brief Define a janela como tela cheia
			\param bool isFullScreen Flag que determina se a janela deve ser fullscreen ou windowed.

			Define a janela como tela cheia (true) ou windowed (false) dependendo da flag recebida.
		*/
		void SetWindowFullscreen(bool);
		/**
			\brief Define se a janela deve ser maximizada

			Define se a janela deve ter seu tamanho máximo sem torná-la tela cheia.
		*/
		void SetWindowMaximized(void);
		/**
			\brief Define se a janela deve ter bordas
			\param bool isBorderless Flag que determina se a janela deve ter ou não bordas.

			Define se a janela deve ter bordas (false) ou não (true) de acordo com a flag recebida.
		*/
		void SetWindowBorderless(bool);
		/**
			\brief Reposiciona a janela

			Posiciona a janela no centro da tela.
		*/
		void SetWindowCentered(void);
		/**
			\brief Informa se a janela está em tela cheia.
			\return bool True para sim e false para não.

			Retorna true se a janela estiver no modo tela cheia ou false se a janela não estiver em tela cheia.
		*/
		bool GetWindowFullscreen(void) const;
		/**
			\brief Informa se a janela está em seu tamanho máximo.
			\return bool True para sim e false para não.

			Retorna true se a janela maximizada ou false se não estiver maximizada.
		*/
		bool GetWindowMaximized(void) const;
		/**
			\brief Informa se a janela tem bordas.
			\return bool True para sim e false para não.

			Retorna true se a janela estiver sem bordas ou false se estiver com bordas.
		*/
          bool GetWindowBorderless(void) const;
          void ReDoRenderer(void);
          
     private:
          static Window* instance;/**< Instância estática da Window. Esquema básico de singleton.*/
          SDL_Window* window;/**< Ponteiro para SDL_Window do game.*/
		SDL_Renderer* renderer;/**< Ponteiro para o SDL_renderer do jogo.*/
};

#endif // __WINDOW_HPP__

