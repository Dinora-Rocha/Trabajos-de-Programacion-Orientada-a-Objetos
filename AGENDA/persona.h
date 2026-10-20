#ifndef PERSONA_H
#define PERSONA_H

#include <string>
#include <vector>

using namespace std;

struct FECHA
{
    int d, m, a;
};

class Persona
{
private:
    string nombre;
    string telefono;
    string CURP;
    FECHA nacimiento;

public:
    Persona();
      public:
    
    Persona(string N, string t, string c, FECHA f); 
    ~Persona();

   
    void mostrarDatos() const;
    void calcularEdadYCumpleanios() const;

    // Setters
    void setNombre(string n);
    void setTelefono(string t);
    void setCURP(string C);
    void setFec_na(FECHA f);

    // Getters
    string getNombre() const;
    string getTelefono() const;//const indica que no se puede alterar el contenido 
    string getCURP() const;
    FECHA getFec_na() const;
};

// Funciones auxiliares
string trim(string s);
void guardarArchivo(const vector<Persona>& lista, const string& nombreArchivo);

  #endif 
