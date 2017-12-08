#ifndef __STAGE_STATE_HPP__
#define __STAGE_STATE_HPP__

#include <memory>
#include <vector>

#include "ActionManager.hpp"
#include "GameObject.hpp"
#include "InputManager.hpp"
#include "Sprite.hpp"
#include "State.hpp"
#include "Timer.hpp"
#include "Score.hpp"
#include "Music.hpp"
#include "Falcon.hpp"

using std::vector;

/**
	\brief Classe que herda de state que modela o estado de estágio do jogo

	StageState é o jogo em si. São definidos todas as características do jogo principal.
*/
class StageState: public State {
	public:
		/**
			\brief Construtor

			Inicializa timer de aparição de um novo Hiero. Cria um novo player (Falcon). E seta flag de saída (quitRequested) como false.
		*/
		StageState(void);
		/**
			\brief Destrutor

			Limpa todo o array de objetos.
		*/
		~StageState(void);
		/**
			\brief Atualiza os estado do jogo
			\param dt Intervalo de tempo transcorrido desde a última atualização.

			Atualiza objetos de objectArray.
			Atualiza cooldown de aparição de um novo Hiero, se transcorrido o tempo, cria-se um em posição aleatória à direita da tela e coloca em objectArray.
			Confere e notifica colisão entre todos os GOs do objectArray.
			Verifica se a saída do jogo foi requisitada.
			Verifica se o encerramento do estado foi solicitado.
		*/
		void Update(float);
		/**
			\brief Renderiza os elmentos do estado

			Renderiza todo o array de objetos.
		*/
		void Render(void) const;
		void Finish(void);
		/**
			\brief Pausa o estado

			Esse método realiza as ações necessárias para pausar o estado para que outro estado seja empilhado sobre ele.
		*/
		void Pause(void);
		/**
			\brief Despausa o estado

			Esse método realizar as ações necessárias para o estado seja despausado pois o estado que estava sobre ele na pilha foi desempilhado.
		*/
		void Resume(void);
		/** 
			\brief Carrega os assets do estado
			
			Carrega todos os assets do estado chamando métodos do Resources.
		*/
		void LoadAssets(void) const;

	private:
		Sprite bg;/**< Sprite de background*/
		Timer newHiero;/**< Temporizador (cooldown) para aparição de um novo Hiero*/
		Timer newObstacle;/**< Temporizador (cooldown) para aparição de um novo Obstáculo*/
		Timer newEnemy;/**< Temporizador (cooldown) para aparição de um novo Inimigo*/
		Music music;/**< Música de fundo do jogo.*/
		Falcon* player;/**< Instância do jogador*/
		Timer toEnd;/**< Temporizador (cooldown) para terminar o jogo.*/
};

#include "Vec2.hpp"
#include "Hiero.hpp"
#include "Collision.hpp"
#include "Enemy.hpp"
#include "Obstacle.hpp"
#include "Window.hpp"
#include "Game.hpp"
#include "InputManager.hpp"
#include "Falcon.hpp"
#include "GameDefines.hpp"
#include "EndState.hpp"

#endif // __STAGE_STATE_HPP__
