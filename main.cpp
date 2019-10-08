#include "Lenguaje.hpp"
#include <iostream>
#include <fstream>
#include <string>

int main(int argc,char* argv[])
{
  if(argc < 2){
	std::cout << "Debe de ejecutar escribiendo: ./ejecutable ficherodeentrada.txt ficharodesalida.txt" << std::endl;
	return 0;
		    }

  std::ifstream lectura; 
	lectura.open("fichero1.txt",std::ios::in); //lo abro en lectura
	std::ofstream escritura;
	escritura.open("fichero2.txt",std::ios::out);

  if((lectura.fail()) || (escritura.fail())){
		std::cout<<"No se puede abrir el archivo";
		exit(1);
  }

  int acabar = 0;
  Lenguaje a,b,c;

  while(acabar == 0)
  {
    if(a.Iniciar(lectura) != true)return 0;
    if(b.Iniciar(lectura) != true)acabar++;
    a.Recorrer();
    b.Recorrer();
    std::cout << "\n";
    //c.concatenacion(a,b);
    //c.recorrer();
    std::cout << "\n";
    //c.Union(a,b);
    //c.recorrer();
    std::cout << "\n";
    //c.clear();
    //c.Interseccion(a,b);
    //c.recorrer();
    std::cout << "Aqui" << "\n";
    //c.clear();
    //c.CierreP(a);
    //c.recorrer();

    c.Clear();
    c.CierreK(a);
    c.Recorrer();

    std::cout << "\n" ;
    //c.clear();
    //c.Diferencia(a,b);
    //c.recorrer();

    //c.clear();
    //std::cout << c.Igualdad(a,b) << "\n";
    //std::cout<<b.Sublenguaje(a)<<"\n";
    //c.clear();
    //c.Inversa(a);
    //std::cout << "s" << "\n";
    //c.recorrer();

    a.Clear();
    b.Clear();
  }
  return 0;
 
}
