#include "cliente.h"

void Cliente::setNombre(std::string nombre) {
    this->nombre = nombre;
}
std::string Cliente::getNombre() {
    return nombre;
}

void Cliente::setCURP(std::string CURP) {
    this->CURP = CURP;
}
std::string Cliente::getCURP() {
    return CURP;
}

void Cliente::setCorreo(std::string correo) {
    this->correo = correo;
}
std::string Cliente::getCorreo() {
    return correo;
}

void Cliente::setTelefono(std::string telefono) {
    this->telefono = telefono;
}
std::string Cliente::getTelefono() {
    return telefono;
}

void Cliente::setFecNac(Fecha fecNac) {
    this->fecNac = fecNac;
}
Fecha Cliente::getFecNac() {
    return fecNac;
}