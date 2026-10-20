#include "cuentadebito.h"

void Cuenta_Debito::setNumeroCuenta(std::string numero_cuenta) {
    this->numero_cuenta = numero_cuenta;
}
std::string Cuenta_Debito::getNumeroCuenta() {
    return numero_cuenta;
}

void Cuenta_Debito::setNIP(std::string nip) {
    this->nip = nip;
}
std::string Cuenta_Debito::getNIP() {
    return nip;
}

void Cuenta_Debito::setSaldo(double saldo) {
    this->saldo = saldo;
}
double Cuenta_Debito::getSaldo() {
    return saldo;
}

std::string Cuenta_Debito::generarNumeroCuenta(std::string nombre, std::string CURP) {
    std::string texto = nombre + CURP;
    long long suma = 0;

    for (size_t i = 0; i < texto.size(); i++) {
        suma += (unsigned char) texto[i] * (i + 1);
    }

    suma = suma % 100000000;
    std::string numero = std::to_string(suma);

    while (numero.size() < 8) {      // rellena con ceros a la izquierda
        numero = "0" + numero;
    }
    return numero;
}

void Cuenta_Debito::depositar(double monto) {
    if (monto > 0) {
        saldo += monto;
    }
}

bool Cuenta_Debito::retirar(double monto, std::string nipIngresado) {
    if (nipIngresado != nip) {
        return false; // NIP incorrecto
    }
    if (monto > 0 && monto <= saldo) {
        saldo -= monto;
        return true;  // Retiro exitoso
    }
    return false;     // Saldo insuficiente o monto inválido
}