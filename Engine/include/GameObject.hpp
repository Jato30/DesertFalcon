#ifndef __GAMEOBJECT_HPP__
#define __GAMEOBJECT_HPP__

#define INCLUDE_SDL 
#define INCLUDE_SDL_IMAGE 
#include "SDLIncludes.hpp"

#include <vector>
#include <memory>
#include <string>
#include <vector>

#include "Rect.hpp"

using std::string;
using std::unique_ptr;

#define GAME_OBJECT
/**
	\brief Classe virtual que especifica o funcionamento de um GameObject.
	
	Especifica quais métodos um gameObject deve ter para conseguir ser manipulado corretamente pela engine.
*/
class GameObject{
	public:
		/**
			\brief Construtor
			
			Não é virtual, sua implementação inicializa a rotação com o valor zero. Pode ser usado pelos herdeiros.
		*/
		GameObject(void);
		/**
			\brief Destrutor
			
			Basicamente é para obrigar quem implementar de usar um destrutor.
		*/
		virtual ~GameObject(void);
		/**
			\brief Atualizar estado.
			\param dt tempo transcorrido desde a última chamada ao método.
			
			No corpo método o GameObject deve atualizar seu estado, utilizando o argumento passado e quaisquer outras funcionalidades que necessitar.
		*/
		virtual void Update(float dt);
		/**
			\brief Renderiza o GameObject.
			
			Esse método deve ter a lógica necessário para ser renderizado na tela.
		*/
		virtual void Render(void);
		/**
			\brief Informa se esse gameObject não precisa mais existir.
			\return Verdadeiro se esse GameObject não é mais necessário, false caso contrário.
			
			Deve ser usado no State que o contém para o eliminar da sua estrutura de manipulação de gameObject e destruí-lo.
		*/
		virtual bool IsDead(void);
		/**
			\brief Solicita que o GameObject seja destruído.
			
			Uma vez que esse método é chamado, futuras chamadas ao IsDead devem retornar verdadeiro.
		*/
		virtual void RequestDelete(void);
		/**
			\brief Notifica Colisão
			\param other Referência para o gameobject com o qual se colidiu.
			
			Deve realizar as ações para tratamento da colisão.
		*/
		virtual void NotifyCollision(GameObject &other);
		/**
			\brief Informa que tipo de GameObject é.
			\param type Tipo com o qual quer se verificar que esse GameObject é.
			\return Verdadeiro se for do tipo perguntado, falso caso contrário;
			
			É usado no tratamento de colisão para que se identifique com quem colidiu.
		*/
		virtual bool Is(string type);
		Rect box;/**< Posição do GameObject na tela.*/
		float rotation;/**< Rotação do GameObject.*/

	protected:
		int height;/**< Altura do Falcon.*/
		bool dead;/**<Booleano informado se o GameObject deve ser destruído. Faz-se necessário para que a mecânia de RequestDelete e IsDead funcione em um GameObject. */
};

#endif // __GAMEOBJECT_HPP__
