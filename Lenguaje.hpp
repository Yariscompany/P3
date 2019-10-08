#include <iostream>
#include <fstream>
#include <set>
#include <string>

class Lenguaje
{
  private:
    std::set<std::string> alfabeto;
    bool vacio;

  public:
    Lenguaje();
    ~Lenguaje(){}
    void insertar(std::string a)
    {alfabeto.insert(a); }
    void Rellenar(std::string);
    bool Iniciar(std::ifstream& in);
    void Recorrer(void); 
    void Concatenacion(Lenguaje&, Lenguaje&);
    void PotenciaR( Lenguaje&,Lenguaje&, int);  
    void Potencia( Lenguaje&,int);    
    void Union(const Lenguaje& ,const Lenguaje& );
    void Interseccion(const Lenguaje&, const Lenguaje&);
    void Clear();
    void Diferencia(const Lenguaje&, const Lenguaje&);
    bool Igualdad(const Lenguaje&, const Lenguaje&);
    bool Sublenguaje(const Lenguaje& );
    void Inversa(const Lenguaje&);
    void CierreK(Lenguaje&);
    void CierreP(Lenguaje&);

};