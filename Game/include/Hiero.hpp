#ifndef __HIERO_HPP__
#define __HIERO_HPP__

#include "GameObject.hpp"
#include "Sprite.hpp"
#include "Vec2.hpp"

#include <string>

/**
	\brief Classe referente aos Hieros (coletáveis).

	Hiero herda de GameObject.
*/
class Hiero : public GameObject {
	public:
		/**
			\brief Cria um hiero.
			\param pos Posição em que o hiero deve ser criado.

			Uma instância de Hiero é criada e colocada em objectArray.
			Sua sprite é carregada. Sua velocidade inicial é setada como (0, 0).
			A posição inicial em Y é definida pelo parâmetro recebido.
               Sua rotação é iniciada com 0. Hp recebe a vida passada por parâmetro.
               Seta as informações básicas de box.
		*/
		Hiero(Vec2 pos);
		/**
			\brief Apaga hiero.
               
               Destrutor padrão simplesmente deleta o objeto.
		*/
		~Hiero();
		/**
			\brief Atualiza objeto por frame.
			\param dt Intervalo de tempo transcorrido desde a última atualização.

			Atualiza sprite. Define velocidade e posição. Verifica se está fora da tela e deve ser destruído.
		*/
		void Update(float);
		/**
			\brief Renderiza componentes.

			Chama o renderizador da sprite na posição de box.
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

			Recebe o objeto em que este colidiu e verifica quem foi através do método Is. Se foi um Falcon, seta como morto.
		*/
		void NotifyCollision(GameObject&);
		/**
			\brief Informa se este é o GameObject informado.
               \param type Nome do objeto que deseja-se comparar a este.
               \return bool Informa se este é um GameObject do mesmo tipo que o informado.

			Compara "Hiero" com a string recebida. Retorna true se for igual e false se for diferente.
		*/
		bool Is(string);
	
	private:
		Sprite sp;/**< Spritesheet de Hiero.*/
		Vec2 speed;/**< Velocidade de x e y (x, y) em que box deve se deslocar.*/
};

#include "GameDefines.hpp"
#include "Window.hpp"

#endif // __HIERO_HPP__

