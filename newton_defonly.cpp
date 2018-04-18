//Scott Saunders
//March 2018

//A macro-only implmentation of newtons method.
//(Should be good-enough for GLSL)

//IF YOU ARE USING THIS, YOU NEED SOME LEVEL OF COMPILER OPTIMIZATION. THIS IS REDICULOUS ALREADY.
#pragma once

#ifndef NAE
#define NAE 0.001
#endif

#define NumDeriv1D(F,X) ((F(X+NAE) - F(X-NAE))/(2*NAE))

//X - Guess,
#define NEWTONS1D(F,X) ((NumDeriv1D(F,X)*NumDeriv1D(F,X) > NAE*NAE)? X -   (F(X)/NumDeriv1D(F,X)) : X)
#define NEWTONS1D2(F,X) NEWTONS1D(F,NEWTONS1D(F,X))
#define NEWTONS1D4(F,X) NEWTONS1D2(F,NEWTONS1D2(F,X))

//Expanded out.. this needed at least 12Gb of ram for the 8-iterations. You have been warned.
// #define NEWTONS1D8(F,X) NEWTONS1D4(F,NEWTONS1D4(F,X))
// #define NEWTONS1D16(F,X) NEWTONS1D8(F,NEWTONS1D8(F,X))
// #define NEWTONS1D32(F,X) NEWTONS1D16(F,NEWTONS1D16(F,X))


#ifdef NEWTON_STANDALONE

double f (double x){
  return x*2;
};


#include <iostream>
int main(){
 
  double x = 10;
  std::cout << NEWTONS1D32(f,x) << std::endl;

}
#endif
