#ifndef __GAME_HPP__
#define __GAME_HPP__

#include <string>
#include <stack>
#include "State.hpp"
#include "InputManager.hpp"
#include "Vec2.hpp"
#include "Window.hpp"

#ifdef _WIN32
	typedef uint8_t u_int8_t;
	typedef uint16_t u_int16_t;
	typedef uint32_t u_int32_t;
#endif

#define INCLUDE_SDL 
#define INCLUDE_SDL_IMAGE 
#define INCLUDE_SDL_MIXER 
#define INCLUDE_SDL_TTF 
#include "SDLIncludes.hpp"

#define MIXER_CHUCK_SIZE 1024
#define INITIAL_FRAMERATE 60

/**
	\brief Classe que modela todo o Jogo
	
	Contém o loop principal do jogo, gerencia a pilha de estados do jogo, responsável por gerenciar a janela (no momento apenas informa as dimensões da janela).
	Também é o que calcula o delta time que é enviado ao update de várias entidades do jogo.
*/
class Game {
	public:
		/**
			\brief Construtor
			\param std::string title Nome da janela.
			\param int width Largura da janela em pixels.
			\param int height Altura da janela em pixels
			
			Para fins de detecção de problemas futuros, a versão da SDL para a qual o jogo foi compilado e a versão na qual a SDL está sendo linkada no carregamento.
			A deferença entre essas versões podem ser a causa de alguns bugs.
			As seguintes tarefas são feitas:
				- O contador de ticks é inicado.
				- Verifica-se se já existe algum outra instância de jogo, se existir o jogo é fechado. Só deve haver uma instância do jogo (Singleton).
				- A SDL é iniciada.
				- A janela é criada com o o títlulo title, com dimensões width x height.
				- O SDL_Renderer é inicializado.
				- O mixer é inicializado.
				- O sistema de áudio é inicializado (é uma inicialização diferente do mixer)
				- O subsistema de fontes é inicializado.
				- A variável storedState é inicializada com nullptr.
		*/
		Game(std::string title, int width, int height);
		/**
			\brief Destrutor
			
			A pilha de estados é esvaziada. Se tiver algum estado em storedState ele será deletado.
			O ClearResources é chamado e os sistemas da SDL que foram inicializados são destruídos na ordem inversa em que foram inicializados. Par garantir que primeiro os subsistemas que não tem dependêntes sejam desalocados primeiros.
		*/
		~Game();
		/**
			\brief Obtém referência do Game
			\return Referência para Game

			Esquema básico do singleton. Retorna instância do singleton. Não se faz a chegagem da existência da instancia por motivos cronológicos (a primeira linha da main deve criar uma instância de Game).
		*/
		static Game& GetInstance(void);
		/**
			\brief Obtém estado corrente do jogo.
			\return Estado corrente do jogo.

			Retorna o Estado que está no topo da pilha de estados.
		*/
		State& GetCurrentState(void) const;
		/**
			\brief Empilha um estado na pilha
			\param State* state estado a ser empilhado.

			O estado recebido como parâmetro é atribuído à storedState. Para que se torne o corrente no início do próximo frame.
			Isso não é feito no exato momento da chamada pois pode gerar inconsistência no processamento do frame atual.
		*/
		void Push(State*);
		/**
			\brief Realiza o loop principal.

			As seguintes oerações são feitas:
				-# Se o storedState tiver algum estado para empilhar, esse estado é empilhado.
				-# Se a pilha estiver vazia, o método retorna. É necessário ter algum estado para ser rodado.
				-# Enquanto a pilha de estados não estiver vazia(loop principal):
					- Se o estado no topo da pilha pedir para o programa seja encerrado, esse loop é interrompido.
					- Calcula-se o intervalo de tempo entre o últimoframe e o frame atual.
					- O estado do inputManager é atualizado.
					- O estado do State é atualizado.
					- Renderiza-se o estado corrente.
					- Força que o que foi renderizado apareça na tela
					- Atualiza a pilha de estados.
				-# Desempilha todos os estados da pilha de estados. Nesse ponto o jogo já terminou e estamos desalocando o que já foi alocado.
				-# O ClearResources é chamado. Espera-se que nesse ponto não haja nenhuma outra referência para qualquer recurso gerenciado pelo Resources.
		*/
		void Run(void);
		/**
			\brief Retorna do tempo passado desde o último frame.
			\return Veja a descrição.

			Retorna o intervalo de tempo do último frame ao atual calculado anteriormente pelo CalculateDeltaTime.
		*/
		float GetDeltaTime(void) const;
		/**
			\brief Altera o valor do limite de framerate
			\param signed long int newMaxFramerate o novo valor máximo a ser usado controle de framerate

			Altera as variáveis do controle de framerate de acordo com o argumento passado. Se o valor informado for menor que 1, o frame rate máximo será 1.
		*/
		void SetMaxFramerate(signed long int);
		/**
			\brief Obtêm o valor de framerate máximo do controle de framerate
			\return Veja a descrição.

			Retorna o valor que está sendo utilizado pelo controle de framerate como quantidade máxima de frames por segundo.
		*/
		unsigned int GetMaxFramerate(void) const;
		/**
			\brief Obtêm o fps atual do jogo
			\return Veja a descrição

			Retorna a quantos frames por segundo o jogo está rodando. Se a limitação de framerate estiver ativada, o retorno dessa função será no máximo o valor obtido por GetMaxFramerate().
		*/
		float GetCurrentFramerate(void) const;
		/**
			\brief Seta se o framerate máximo deve ser utilizado ou não
			\param bool limit true para limitar. false para desbloquear

			Seta se o controle de framerate deve garantir que o framerate não passe do máximo ou não.
		*/
		void LimitFramerate(bool);
		/**
			\brief Retorna se o framerate está sendo limitado ou não
			\return Veja descrição

			Retorna se o controle de framerate está limitando o framerate a um máximo ou não.
		*/
		bool IsFramerateLimited(void) const;
		/**
			\brief Obtém timeStamp atual.

			Retorna o timestamp atual. 
		*/
		unsigned int GetTicks(void);
	private:
		/**
			\brief Calcula o tempo transcorrido desde a última chamada a essa função

			Ela é chamada a cada frame para que seja calculado o tempo transcorrido desde o útimo frame.
			Esse cálculo é feito a partir da diferença entre o valor retornado em SDL_GetTicks com o valor em frameStart. Atribui-se ao dt o resultado dessa operação dividida por mil (os ticks contam milésimos).
			Depois atualiza-se o valor de frameStart com o que foi obitdo em SDL_GetTicks.
		*/
		void CalculateDeltaTime(void);
		/**
			\brief Atualiza a pilha de estados.

			Primeiro verifica-se o estado no topo da pilha pediu para ser desempilhado e se tiver solicitado, essa ação é feita e o ClearResources é chamado.
			Depois verifica-se se tem algum estado esperando para ser empilhado em storedState, se tiver, ele é empilhado.
		*/
		void UpdateStack(void);

		unsigned int frameStart;/**< Armazena a quantidade de ticks no momento do início do frame. Usado para calcular intervalos de tempo através de diferença da quantidade de ticks atual com o valor armazenado nessa variável.*/
		float dt;/**< Armazena o intervalo de tempo em segundos desde o último frame. Esse valor é calculado a partir da diferença entre o frameStart com o SDL_GetTicks.*/
		static Game* instance;/**< Instância estática do Game. Esquema básico de singleton.*/
		State* storedState;/**< Armazena o estado que deve ser empilhado no fim do frame atual. Isso não pode acontecer no meio do frame para não gerar inconsistências.*/
		std::stack<std::unique_ptr<State>> stateStack;/**< Pilha de estados.*/
		InputManager &inputManager;/**< Gerenciador de entradas do usuário.*/
		unsigned int maxFramerate;/**< Armazena o limite superior do framerate*/
		float frameDuration;/**< Duração mínima de cada frame*/
		bool capFramerate;/**< Flag para decidir se o framerate do jogo será limitado a um valor máximo ou não.*/
		Window window;
};

#endif // __GAME_HPP__
