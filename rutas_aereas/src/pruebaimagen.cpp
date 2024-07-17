#include "../include/imagen.h"
#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char * argv[]){

  Imagen I;
  I.LeerImagen(argv[1]);
  Imagen sub;
  sub.LeerImagen(argv[2]);
  I.LimpiarTransp();
  I.EscribirImagen("prueba6limpi.ppm");

  I.PutImagen(40,40,sub,OPACO);
  I.EscribirImagen("prueba67limpi.ppm");
}