#include "Lenguaje.hpp"

//Constructor por defecto 
Lenguaje::Lenguaje()
{}

//Funcion para Rellenar el atributo de alfabeto de cada objeto
void Lenguaje::Rellenar(std::string a)
{
  std::string letra,palabra;
  for(int i = 0; i < a.length(); i++)
  {
    letra = a[i];
    palabra.clear(); 
    vacio = false;   
    if((letra != "{") && (letra != "}") && (letra != " ") && (letra != ",") && (letra != "\n"))
    {
      do
      {
        palabra = palabra + letra;
        i ++;
        letra = a[i];
      }while((letra != "{") && (letra != "}") && (letra != " ") && (letra != ",") && (letra != "\n"));
        if (palabra == "&")
        {
          vacio = true;
        } 
      alfabeto.insert(palabra);
    }
  }
}


//Funcion de comprobacion y lectura por lineas
bool Lenguaje::Iniciar(std::ifstream& lectura)
{
  std::string linea;
  std::getline(lectura,linea);

  if(lectura.eof()) return false;

  Rellenar(linea);
  
  return true;

}

//Funcion de escritura¿?
void Lenguaje::Recorrer(void)
{
  for (std::set<std::string>::iterator it=alfabeto.begin(); it!=alfabeto.end(); ++it)
  {
	  std::cout << ' ' << *it;
	  std::cout<<"\n";
  }
}

void Lenguaje::Clear()
{
  alfabeto.clear();
}

//Funcion de concatenacion
void Lenguaje::Concatenacion( Lenguaje& a, Lenguaje& b)
{
  std::set<std::string>::iterator it1,it2;
  for(it1 = a.alfabeto.begin(); it1 != a.alfabeto.end(); ++it1){ 
    for(it2 = b.alfabeto.begin(); it2 != b.alfabeto.end(); ++it2)
    {
      //Condicionales de busqueda de lenguaje vacio
      if (a.vacio == true)
      {
        insertar(*it2);
        return;
      }
      if (b.vacio == true)
      {
        insertar(*it1);
        return;
      }

      std::string suma;
      suma = *it1 + *it2;
      insertar(suma);
    }
  }
}

//Potencia recursiva
void Lenguaje::PotenciaR(Lenguaje& a, Lenguaje& b, int vuelta)
{
  vuelta--;
  if(vuelta > 0)
  {
    PotenciaR(a,b,vuelta);
    Concatenacion(a,b);
    a.alfabeto.clear();
    swap(a.alfabeto,alfabeto);
  }
}

//Potencia 
void Lenguaje::Potencia(Lenguaje& a, int vuelta)
{
  if (vuelta == 0)
  {
    insertar("&");
    return;
  }
  Lenguaje b = a;
  PotenciaR(a,b,vuelta);
  swap(a.alfabeto,alfabeto);
}


//Funcion de union de lenguajes
void Lenguaje::Union(const Lenguaje& a, const Lenguaje& b)
{
  std::set<std::string>::iterator it, search;

  for(it = a.alfabeto.begin(); it != a.alfabeto.end(); ++it)
  {
     alfabeto.insert(*it);
  }

  for(it = b.alfabeto.begin(); it != b.alfabeto.end(); ++it)
  {
     alfabeto.insert(*it);
  }
}

//Funcion de interseccion de lenguajes 
void Lenguaje::Interseccion(const Lenguaje& a, const Lenguaje& b)
{
  std::set<std::string>::iterator it, search;

  for(it = a.alfabeto.begin(); it != a.alfabeto.end(); ++it)
  {
   search = b.alfabeto.find(*it);
    if (search != b.alfabeto.end())
    {
      alfabeto.insert(*it);
    }
  }
}

//Funcion 
void Lenguaje::Diferencia(const Lenguaje& a, const Lenguaje& b)
{
  Lenguaje aux1, aux2;
  aux1.Union(a, b);
  aux2.Interseccion(a, b);

  std::set<std::string>::iterator it, search;

  for(it = aux1.alfabeto.begin(); it != aux1.alfabeto.end(); ++it)
  {
    search = aux2.alfabeto.find(*it);
    if (search == aux2.alfabeto.end())
    {
      alfabeto.insert(*it);
    }
  }
}

//Funcion de igualdad de lenguajes
bool Lenguaje::Igualdad(const Lenguaje& a, const Lenguaje& b)
{
  std::set<std::string>::iterator it, search;

  for(it = a.alfabeto.begin(); it != a.alfabeto.end(); ++it)
  {
    search = b.alfabeto.find(*it);
    if (search == b.alfabeto.end())
    {
      return false;
    }
  }
  return true;
}

//Funcion de verificacion de sublenguajes
bool Lenguaje::Sublenguaje(const Lenguaje& a)
{

  std::set<std::string>::iterator it,search;

  for(it = a.alfabeto.begin(); it != a.alfabeto.end(); ++it){
    search = alfabeto.find(*it);
    if (search == alfabeto.end()){
      return false;
    }
  }
    return true;
}

//Funcion de inversa de cadenas
void Lenguaje::Inversa(const Lenguaje& a)
{
  std::set<std::string>::iterator it;
  std::string character, word;
  for(it = a.alfabeto.begin(); it != a.alfabeto.end(); ++it)
  {
    word = *it;
    std::cout << word << std::endl;

    for(int j  = word.size(); j > 0;  j-- )
    {
      character += word[j];
    }
    alfabeto.insert(character);
  }
}

//Funcion de cierre positivo
void Lenguaje::CierreP(Lenguaje& a)
{
  Potencia(a, 3);
}

//Funcion de el cierre de Kleene
void Lenguaje::CierreK(Lenguaje& a)
{
  Potencia(a, 3);
  alfabeto.insert("&");
}