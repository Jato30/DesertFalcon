#ifndef __FALCON_HPP__
#define __FALCON_HPP__

#include "GameObject.hpp"
#include "Vec2.hpp"
#include "Sprite.hpp"

#include <string>

/**
	\brief Classe referente ao jogador (falcão).

	Falcon herda de GameObject.
*/
class Falcon : public GameObject {
     public:
          /**
			\brief Cria um falcão.
			\param hitpoints Vida total do jogador.

               Uma instância de Falcon é criada. A posição inicial(X e Y) é um pequeno espaçamento à esquerda e no centro da tela em relação ao eixo Y.
               Sua rotação é iniciada com 0. Hp recebe a vida passada por parâmetro. Define sua velocidade inicial como (0, 0).
               Seta as informações básicas de box.
		*/
          Falcon(int hitpoints);
          /**
			\brief Apaga falcão.
               
               Destrutor padrão simplesmente deleta o objeto.
		*/
          ~Falcon();
          /**
			\brief Atualiza objeto por frame.
			\param dt Intervalo de tempo transcorrido desde a última atualização.

			Atualiza sprite. Verifica movimento, setando velocidade e posição. Verifica se está fora da tela e verifica se morreu e deve ser destruído.
		*/
          void Update(float);
          /**
			\brief Renderiza componentes.

			Chama o renderizador da sprite.
		*/
          void Render(void);
          /**
			\brief Verifica se objeto está morto.
			\param bool Informa se está morto (true) ou ainda vive (false).

			Verifica se o objeto deve ser deletado por estar morto retornando true para o caso de estar morto e false para o caso de estar vivo.
		*/
          bool IsDead(void);
          /**
			\brief Requere a exclusão do objeto.

			Define flag isDead como true para defini-lo como morto. Assim, quando a verificação dos objetos mortos chegar, este será eliminado.
		*/
          void RequestDelete(void);
          /**
			\brief Recebe a notificação de qual objeto colidiu com este.
			\param other Outro GameObject no qual colidiu a este.

			Recebe o objeto em que este colidiu e verifica quem foi através do método Is. Se foi um Hiero, recebe o dano que o Hiero dá.
		*/
          void NotifyCollision(GameObject&);
          /**
			\brief Informa se este é o GameObject informado.
               \param type Nome do objeto que deseja-se comparar a este.
               \return bool Informa se este é um GameObject do mesmo tipo que o informado.

			Compara "Falcon" com a string recebida. Retorna true se for igual e false se for diferente.
		*/
          bool Is(string);
          /**
			\brief Informa posição do Rect no mundo.
			\return Rect Rect renderizado no mundo.

			Retorna um Rect contendo a posição em que este está em relação ao mundo, não à tela.
		*/
          Rect GetWorldRenderedRect(void) const;
          /**
			\brief Dá dano a si mesmo.
			\param damage Quantidade de dano a ser aplicada.

			Decresce hp com a quantidade de damage recebido.
		*/
          void Damage(int);
		int height;/**< Altura do Falcon.*/
          
     private:
          Sprite sp;/**< Spritesheet de Falcon.*/
		Sprite spShade;/**< Spritesheet da sombra de Falcon.*/
          int hp;/**< Vida atual.*/
          Vec2 speed;/**< Velocidade de x e y (x, y) em que box deve se deslocar.*/
};

#include "GameDefines.hpp"
#include "ActionManager.hpp"
#include "Window.hpp"
#include "Hiero.hpp"
#include "InputManager.hpp"

#endif // __FALCON_HPP__

