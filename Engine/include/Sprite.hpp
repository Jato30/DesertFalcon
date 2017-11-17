#ifndef __SPRITE_HPP__
#define __SPRITE_HPP__

#define INCLUDE_SDL 
#define INCLUDE_SDL_IMAGE 
#include "SDLIncludes.hpp"

#include <string>
#include <memory>

#include "Color.hpp"
#include "Rect.hpp"

#define ALPHA_BLEND SDL_BLENDMODE_BLEND
#define ADDITIVE SDL_BLENDMODE_ADD
#define COLOR_MODULATION SDL_BLENDMODE_MOD

/**
	\brief Classe que modela uma sprite.

	Sprite é uma imagem carregada na memória. Essa classe também traz uma séria de funcionalidades além disso, como escala, animações de sprite sheets e exibição na tela da imagem.
*/
class Sprite {
	public:
		/**
			\brief Cria um sprite não associado a uma imagem.
			\todo verificar a real necessidade disso.

			Uma instância de sprite é criada. A escala inicial(X e Y) é 1.0, supondo-se que não é um sprite sheet(frameCount=1, frameTime=0), o campo texture é inicializado com nullptr.
		*/
		Sprite(void);
		/**
			\brief Cria um sprite válida.
			\param string file Arquivo que contém a imagem.
			\param bool highlighted Checa se a sprite deve alterar a cor (highlight) quando o mouse passar em cima.
			\param float frameTime Tempo em segundos que cada imagem de um sprite sheet deve durar.
			\param int frameCount Quantas imagens tem no sprite sheet. Caso o valor seja 1 significa que é um sprite não animado.

			Uma instância de sprite é criada. A escala inicial(X e Y) é 1.0. o método Open é chamado para carregar a imagem.
		*/
		Sprite(std::string file, bool highlighted = false, float frameTime = 1, int frameCount = 1);
		/**
			\brief Destrutor

			Como a desalocação a imagem é feita automaticamente pelo shared_ptr/Resources e todos os outros atritutos são alocados estaticamente, nada precisa ser feito.
		*/
		~Sprite();
		/**
			\brief Carrega uma imagem.
			\param string file Arquivo que contém a imagem.

			Faz uso da classe Resources para obter o ponteiro para a imagem em memória, verifica o tamanho da imagem carregada para atribuir a width e height e chama o método SetClip da imagem, levando em consideração, caso seja uma sprite animada, quantas sprites fazem parte da animação.
		*/
		void Open(std::string);
		/**
			\brief Seleciona o recorte da imagem que deve ser renderizado.
			\param int x Ponto x inicial da imagem deve ser exibida.
			\param int y Ponto y inicial da imagem deve ser exibida.
			\param int w Largura em pixels da imagem.
			\param int h Altura em pixels da imagem.

			Atribui a clipRect os valores informados.
		*/
		void SetClip(int, int, int, int);
		/**
			\brief Renderiza a imagem.
			\param Rect world Região a partir do qual a imagem deve ser renderizada.
			\param float angle Ângulo de rotação da imagem.

			Renderiza o corte da imagem existente em clipRect nas posições (x, y) da informada nos argumentos.
			A imagem será rotacionada de acordo com o argumento angle.
			É realizado uma otimização para que, se a Sprite não possuir nenhuma coordenada na tela, ela não será renderizada.
		*/
		void Render(Rect, float = 0) const;
		/**
			\brief Informa a largura do sprite

			Retorna a largura do sprite, no caso do sprite sheet é retornado a largura de um único sprite do sprite sheet.
			De qualquer forma essa largura leva em consideração a escala do sprite.
		*/
		int GetWidth(void) const;
		/**
			\brief Informa a altura do sprite

			Retorna a largura do sprite.
			De qualquer forma essa altura leva em consideração a escala do sprite.
		*/
		int GetHeight(void) const;
		/**
			\brief Obtém a textura armazenada na Sprite.

			Com grandes poderes vêm grandes responsabilidades.
		*/
		std::shared_ptr<SDL_Texture> GetTexture(void) const;
		/**
			\brief Verifica se tem uma imagem carregada.
			\return Verdadeiro se a instância da Sprite contém uma imagem carregada, falso caso contrário.

			Isso é feito verificando se o atributo texture é diferente de nullptr.
		*/
		bool IsOpen(void) const;
		/**
			\brief Atualiza o estado da sprite.
			\param float dt Intervalo de tempo desde a última chamada a Update.

			Verifica se o sprite carregado deve ser atualizado se for um sprite sheet.
			As seguintes operações são feitas:
				- Adiciona dt ao timeElapsed.
				- Se o timeElapsed for maior que o tempo em que cada frame deve estar na tela(frametime) atribuimos ao currentFrame o valor do próximo frame e alteramos o valor x do clipRect para refletir essa operação. Colocando-o para o próximo sprite.
		*/
		void Update(float);
		/**
			\brief Força a animação a ficar num frame específico.
			\param int frame Frame que deve ser colocado.

			Atribui o frame informado ao currentFrame, usando a operação módulo para garantir que esse frame é válido. O campo x do clipRect é alterado para refletir essa mudança.
		*/
		void SetFrame(int);
		/**
			\brief Altera a quantidade de frames do sprite animado.
			\param int frameCount Novo valor para a quantidade de frames.
			\todo verificar a necessidade de existir SetFrameCount.

			O atribuito frameCount recebe o valor informado o width é recalculado usando o novo valor.
		*/
		void SetFrameCount(int);
		/**
			\brief Altera o ritmo dos sprites animados.
			\param float frameTime Intervalo no qual se deveja que os sprites sejam trocados

			Atribui o argumento a frameTime.
		*/
		void SetFrameTime(float);
		/**
			\brief Força um valor para a escala horizontal do sprite.
			\param float scale Valor desejado para a escala.

			Atribui o argumento a scaleX.
		*/
		void SetScaleX(float);
		/**
			\brief Força um valor para a escala vertical do sprite.
			\param float scale Valor desejado para a escala.

			Atribui o argumento a scaleY.
		*/
		void SetScaleY(float);
		/**
			\brief Força um valor para a escala horizontal e vertical da sprite.
			\param float scale Valor desejado para a escala.

			Atribui o argumento a scaleY e scaleX.
		*/
		void SetScale(float);
		/**
			\brief Altera a escala horizontal do sprite.
			\param float scale Valor no qual a escala horizontal deve ser alterada.

			Atribui a scaleX produto de scaleX pelo argumento.
		*/
		void ScaleX(float);
		/**
			\brief Altera a escala vertical do sprite.
			\param float scale Valor no qual a escala vertical deve ser alterada.

			Atribui a scaleY produto de scaleY pelo argumento.
		*/
		void ScaleY(float);
		/**
			\brief Altera a escala vertical e horizontal do sprite.
			\param float scale Valor no qual a escala vertical e horizontal devem ser alteradas.

			Atribui a scaleY produto de scaleX pelo argumento e atribui a scaleX produto de scaleX pelo argumento.
		*/
		void Scale(float);
		Color colorMultiplier;/**< A cor a ser usada para multiplicar a sprite.*/
		SDL_BlendMode blendMode;/**< O modo de mistura da sprite com as inferiores.*/
	private:
		std::shared_ptr<SDL_Texture> texture;/**< Ponteiro para a textura manejada pelo sprite.*/
		int width;/**< Largura da textura em pixels.*/
		int height;/**< Altura da textura em pixels.*/
		int frameCount;/**< Quantidade de "subsprites" de um sprite animado.*/
		int currentFrame;/**< Indica qual "subsprite" de uma sprite animada está em exbição no momento.*/
		float timeElapsed;/**< Quantidade de tempo em segundos que o "subsprite" atual está sendo renderizados.*/
		float frameTime;/**< Tempo em segundos que cada "subsprite" deve aparecer na tela.*/
		SDL_Rect clipRect;/**< Recorte do sprite que será exibido na tela.*/
		float scaleX;/**< Escala horizontal do sprite.*/
		float scaleY;/**< Escala vertical do sprite.*/
		bool highlightable;/**< Flag que determina se a sprite deve sofrer highlight*/
};

#include "InputManager.hpp"

#endif // __SPRITE_HPP__

