#ifndef CUENTA_DEBITO_H
#define CUENTA_DEBITO_H
#include <string>

class Cuenta_Debito {

private:
    std::string numero_cuenta;
    std::string nip;
    double saldo;

public:
    void setNumeroCuenta(std::string numero_cuenta);
    std::string getNumeroCuenta();

    void setNIP(std::string nip);
    std::string getNIP();

    void setSaldo(double saldo);
    double getSaldo();

    std::string generarNumeroCuenta(std::string nombre, std::string CURP);

    // Métodos para depósito y retiro
    void depositar(double monto);
    bool retirar(double monto, std::string nipIngresado);
};

#endif