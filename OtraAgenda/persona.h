//#pragma once

#ifndef PERSONA_H
#define PERSONA_H

#include <string>

struct Fecha {
    int dia;
    int mes;
    int anio;
};

class Persona {
private:
    std::string nombre;
    std::string tel;
    std::string CURP;
    Fecha fecNac; // Atributo encapsulado


    // 4.4 Método privado auxiliar para validar la lógica interna
    bool esFechaValida(int d, int m, int a);


public:
    // 4.5 Constructores
    Persona();
    Persona(std::string nom,std::string t,std::string c, int d, int m, int a);
    ~Persona();


    // 4.3 Métodos Getters y Setters
    void setNombre(std::string nom);
    std::string getNombre() const;
    void setTel(std::string t);
    std::string getTel() const;
    void setCURP(std::string c) ;
    std::string getCURP() const;


    // Mutador con validación
    bool setFecNac(int d, int m, int a);
    Fecha getFecNac() const;


    // El método estrella: calcula la edad dinámicamente
    int getEdad() const;
};

#endif
