//Scott Saunders
//March 2018

//A macro-only implmentation of newtons method.
//(Should be good-enough for GLSL)

//#include "center_defonly.cpp"

#define NAE 0.001
#define TOL NAE*10

#define NumDeriv1D(F,X) ((F(X+NAE) - F(X-NAE))/2*NAE)

//X - Guess,
#define NEWTONS1D(F,X) (X -   (F(X)/NumDeriv1D(F,X)))
#define NEWTONS1D2(F,X) NEWTONS1D(F,NEWTONS1D(F,X))
#define NEWTONS1D4(F,X) NEWTONS1D2(F,NEWTONS1D2(F,X))

double f(double x){
  return x*2;
}

#include <iostream>
int main(){
  
  std::cout << NEWTONS1D(f,1) << std::endl;

}
