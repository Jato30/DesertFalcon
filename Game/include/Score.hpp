#ifndef __SCORE_HPP__
#define __SCORE_HPP__

#include "Text.hpp"
#include "StageState.hpp"

class Score{
     public:
          ~Score();
          static void CreateInstance(void);
          static void DeleteInstance(void);
          static void Update(float);
          static void Render(void);
          static void SetScore(int);
          static int GetScore(void);
          static void Increase(int);
          static void Decrease(int);
          static void Show(void);
          static void Hide(void);

     private:
          Score();
          static Score* score;
          int totalScore;
          bool isToShow;
          Text* text;
};

#include "Window.hpp"
#include "Error.hpp"
#include <string>

#endif // __SCORE__HPP__