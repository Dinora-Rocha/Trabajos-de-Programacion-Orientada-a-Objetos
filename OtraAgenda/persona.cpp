#include "Persona.h"
#include <ctime>   // Para obtener el tiempo real del sistema
#include <iostream>


// Constructor sin parámetros (Valores por defecto seguros)
Persona::Persona() {
    nombre = "Sin Nombre";
    tel = "0000000000";
    CURP = "SIN CURP";
    fecNac = {1, 1, 2000};
    std::cout << "Persona creada sin datos." << std::endl;
}


// Constructor parametrizado utilizando el setter para garantizar integridad
Persona::Persona(std::string nom,std::string t,std::string c, int d, int m, int a) {
    nombre = nom;
    tel = t;
    CURP = c;
    // Si la fecha es inválida, se fuerza un estado consistente por defecto
    if (!setFecNac(d, m, a)) {
        fecNac = {1, 1, 2000};
    }
    std::cout << "Persona " << this->nombre << " creada ." << std::endl;

}

    Persona::~Persona(){
        std::cout << this->nombre << " destruido." << std::endl;

    }



void Persona::setNombre(std::string nom) { nombre = nom; }
std::string Persona::getNombre() const { return nombre; }
void Persona::setTel(std::string t) { tel = t; }
std::string Persona::getTel() const { return tel; }
void Persona::setCURP(std::string c) { CURP = c; }
std::string Persona::getCURP() const { return CURP; }
Fecha Persona::getFecNac() const { return fecNac; }


// 4.1 y 4.3 Protección de información mediante filtrado en el Setter
bool Persona::setFecNac(int d, int m, int a) {
    if (esFechaValida(d, m, a)) {
        fecNac.dia = d;
        fecNac.mes = m;
        fecNac.anio = a;
        return true; // Asignación exitosa
    }
    std::cerr << "Error: Fecha de nacimiento invalida.\n";
    return false; // Rechazado
}


// 4.4 Método Privado: El usuario no necesita saber CÓMO se valida, solo que funciona
bool Persona::esFechaValida(int d, int m, int a) {
    if (a < 1900 || m < 1 || m > 12 || d < 1) return false;


    int diasPorMes[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };


    // Validar año bisiesto para Febrero
    if ((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0)) {
        diasPorMes[1] = 29;
    }


    return d <= diasPorMes[m - 1];
}


// Cálculo dinámico de la edad usando <ctime>
int Persona::getEdad() const {
    std::time_t tiempoActual = std::time(nullptr);
    std::tm* ahora = std::localtime(&tiempoActual);


    int anioActual = ahora->tm_year + 1900;
    int mesActual = ahora->tm_mon + 1;
    int diaActual = ahora->tm_mday;


    int edad = anioActual - fecNac.anio;


    // Ajuste si aún no ha pasado su cumpleaños este año
    if (mesActual < fecNac.mes ||
       (mesActual == fecNac.mes && diaActual < fecNac.dia)) {
        edad--;
    }


    return edad;
}
