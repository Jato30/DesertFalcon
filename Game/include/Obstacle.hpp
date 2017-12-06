#ifndef __Obstacle_HPP__
#define __Obstacle_HPP__

#include "GameObject.hpp"
#include "Vec2.hpp"
#include "Sprite.hpp"

#include <string>

/**
	\brief Classe referente aos obstáculos.

	Obstacle herda de GameObject.
*/
class Obstacle : public GameObject {
     public:
          /**
			\brief Cria um obstáculo.
			\param pos Posição em que o obstáculos deve ser criado.

               Uma instância de Obstacle é criada.
			A posição inicial(X e Y) é uma posição aleatória entre fora da tela, em que X e Y devem estar fora da tela apenas entre as posições de Y = 0 até Y = (altura da tela / 2)
			de X = (largura da tela / 2) até X = (largura da tela)
               Sua rotação é iniciada com 0. Define sua velocidade inicial como (0, 0).
               Seta as informações básicas de box.
		*/
          Obstacle(Vec2 pos);
          /**
			\brief Apaga obstáculo.
               
               Destrutor padrão simplesmente deleta o objeto.
		*/
          ~Obstacle();
          /**
			\brief Atualiza objeto por frame.
			\param dt Intervalo de tempo transcorrido desde a última atualização.

			Atualiza sprite. Define velocidade e posição. Verifica se está fora da tela e deve ser destruído.
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

			Recebe o objeto em que este colidiu e verifica quem foi através do método Is. Se foi um Falcon, sua velocidade é 0 até que passe a colisão.
		*/
          void NotifyCollision(GameObject&);
          /**
			\brief Informa se este é o GameObject informado.
               \param type Nome do objeto que deseja-se comparar a este.
               \return bool Informa se este é um GameObject do mesmo tipo que o informado.

			Compara "Obstacle" com a string recebida. Retorna true se for igual e false se for diferente.
		*/
          bool Is(string);
          
     private:
		Sprite sp;/**< Spritesheet de obstáculo.*/
		Vec2 speed;/**< Velocidade de x e y (x, y) em que box deve se deslocar.*/
};

#include "GameDefines.hpp"
#include "Window.hpp"

#endif // __Obstacle_HPP__

