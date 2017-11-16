/* DEFINES DO JOGO */

// GameObjects
#define PLAYER_BASE_LIFE 1000
#define FALCON_INITIAL_POS Vec2(200, 400)
#define FALCON_DAMAGE 250
#define FALCON_SPEED_PROPORTION_Y 224/361.706 // Triângulo formado por canto inferior esquerdo da tela (0, window.y - box.h), posição mais a esquerda que o falcon pode assumir (0, window.y / 2) e a posição mais a direita que o falcon pode ir ((window.x / 2) - box.w, window.y - box.h). Este offset é o cateto (posição mais a esquerda) sobre a hipotenusa.
#define FALCON_SPEED_PROPORTION_X 284/361.706 // Veja descrição anterior. Este offset é o cateto (posição mais a direita) sobre a hipotenusa.
#define LINEAR_SPEED 300
#define HIERO_DAMAGE 1
#define HIERO_COOLDOWN 2

