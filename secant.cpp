//Scott Saunders
// March 2018

//A simple implementation of secant method for rootfinding.

#include <functional>
#include <math.h>

namespace numerical{
  
double  secant1D(double x1in, double x2in, double (*f)(double x), double tolerance=0.00000001, int maxIter=1000){
    double x1 = x1in;
    double x2 = x2in;
    do{
      double next = x1 - f(x1)*((x1-x2)/(f(x1)-(f(x2))));
      x2 = x1;
      if((x1 - next) < tolerance)
        return next;
      x1=next;
      maxIter--;
    }while (maxIter > 0);
    return x1;
  }


void secant3D(double x1,double y1, double z1, double x2, double y2, double z2, double (*f)(double x, double y, double z), double &x, double &y, double &z, int maxIter=1000, double tolerance=0.00000001){
  
  do{
    double nx,ny,nz;
    x = x1 - f(x1,y1,x1) * ( ((x1-x2) / (f(x1,y1,z1) - (f(x2,y1,z1)))));
    y = y1 - f(x1,y1,x1) * ( ((y1-y2) / (f(x1,y1,z1) - (f(x1,y2,z1)))));
    z = z1 - f(x1,y1,x1) * ( ((z1-z2) / (f(x1,y1,z1) - (f(x1,y1,z2)))));
    
    x2=x1;
    y2=y1;
    z2=z1;
    
    if ( sqrt( (x-x1)*(x-x1) + (y-y1)*(y-y1) + (z-z1)*(z-z1) ) < tolerance)
      return;

    x1=x;
    y1=y;
    z1=z;

    maxIter--;
  }while (maxIter > 0);
  return;

}

}

#ifdef SECANT_STANDALONE
#include <iostream>

//COMPILE LIKE SO (on linux): ` g++ center.cpp -D CENTER_STANDALONE `

double f_x2(double x){
  return x*x;
}

double implicitSphere(double x, double y, double z){
  return x*x + y*y + z*z - 1.0;
}


int main(){
  double x,y,z,x2,y2,z2;
  double dx,dy,dz;
  std::cout << "Enter a position" << std::endl;
  std::cin >> x >> y >> z;
  std::cout << "Enter another position" << std::endl;
  std::cin >> x2 >> y2 >> z2;

  numerical::secant3D(x,y,z,x2,y2,z2,implicitSphere,dx,dy,dz);
  std::cout << "3D: " << std::endl;
  std::cout << "\tPos:\t" << "(" << x << "," << y << "," << z << ")" << std::endl;
  std::cout << "\troot:\t" << "(" << dx << "," << dy << "," << dz << ")" << std::endl;

  dx = numerical::secant1D(x,x2,f_x2);
  std::cout << "1D: " << std::endl;
  std::cout << "\tx:\t" << x << std::endl;
  std::cout << "\tx_root:\t" << dx << std::endl;


}

#endif
