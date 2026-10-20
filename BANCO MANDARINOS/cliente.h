#ifndef CLIENTE_H
#define CLIENTE_H
#include <string>

struct Fecha {
    int dia;
    int mes;
    int anio;
};

class Cliente {

private:
    std::string nombre;    // usuario
    std::string CURP;      // contrasena
    std::string correo;
    std::string telefono;
    Fecha fecNac;

public:
    void setNombre(std::string nombre);
    std::string getNombre();

    void setCURP(std::string CURP);
    std::string getCURP();

    void setCorreo(std::string correo);
    std::string getCorreo();

    void setTelefono(std::string telefono);
    std::string getTelefono();

    void setFecNac(Fecha fecNac);
    Fecha getFecNac();
};

#endif