//Scott Saunders
//March 2018

//A macro-only attempt at center difference numerical approxmation of a derivative.
// (It should work in GLSL!)

#define NAE 0.00001
#define NumDeriv1D(Y,X,F) Y = (( F(X+NAE) - F(X_NAE))/(2*NAE))

#define NumDeriv3D(A,B,C,X,Y,Z,F) A = ((F(X+NAE,  Y,      Z)   - (F(X-NAE,  Y,     Z   )))/(2*NAE)) ;\
                                  B = ((F(X,    Y+NAE,    Z)   - (F(X,    Y-NAE,   Z   )))/(2*NAE)) ;\
                                  C = ((F(X,    Y,      Z+NAE) - (F(X,    Y,     Z-NAE )))/(2*NAE)) ;



#ifdef CENTER_STANDALONE
#include <iostream>

//COMPILE LIKE SO (on linux): ` g++ center.cpp -D CENTER_STANDALONE `

double implicitSphere(double x, double y, double z){
  return x*x + y*y + z*z - 1.0;
}


int main(){
  double x,y,z;
  double dx,dy,dz;
  std::cout << "Enter a position" << std::endl;
  std::cin >> x >> y >> z;
  NumDeriv3D(dx,dy,dz,x,y,z,implicitSphere);
  std::cout << "Pos:\t" << "(" << x << "," << y << "," << z << ")" << std::endl;
  std::cout << "Deriv:\t" << "(" << dx << "," << dy << "," << dz << ")" << std::endl;

}

#endif

