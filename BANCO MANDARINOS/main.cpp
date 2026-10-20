#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include "cuentadebito.h"
#include "cliente.h"

using namespace std;

string trim(string s) {
    size_t inicio = s.find_first_not_of(" \t");
    if (inicio == string::npos) return "";
    size_t fin = s.find_last_not_of(" \t");
    return s.substr(inicio, fin - inicio + 1);
}

void guardarArchivo(vector<Cliente>& clientes, vector<Cuenta_Debito>& cuentas, string nombreArchivo) {
    ofstream archivo(nombreArchivo);
    archivo << fixed << setprecision(2);    

    for (size_t i = 0; i < clientes.size(); i++) {
        Fecha f = clientes[i].getFecNac();
        archivo << clientes[i].getNombre() << ", "
                << clientes[i].getCURP() << ", "
                << clientes[i].getCorreo() << ", "
                << clientes[i].getTelefono() << ", "
                << f.dia << "/" << f.mes << "/" << f.anio << ", "
                << cuentas[i].getNumeroCuenta() << ", "
                << cuentas[i].getNIP() << ", "
                << cuentas[i].getSaldo() << endl;
    }
    archivo.close();
}

void cargarArchivo(vector<Cliente>& clientes, vector<Cuenta_Debito>& cuentas, string nombreArchivo) {
    ifstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        cout << "No se encontro el archivo, se creara uno nuevo." << endl;
        ofstream nuevo(nombreArchivo);
        nuevo.close();
        return;
    }

    string linea;
    while (getline(archivo, linea)) {
        if (linea.empty()) continue;

        stringstream ss(linea);
        string nombre, curp, correo, telefono, fecha, numero, nip, saldo;

        getline(ss, nombre, ',');
        getline(ss, curp, ',');
        getline(ss, correo, ',');
        getline(ss, telefono, ',');
        getline(ss, fecha, ',');
        getline(ss, numero, ',');
        getline(ss, nip, ',');
        getline(ss, saldo, ',');

        Cliente c;
        c.setNombre(trim(nombre));
        c.setCURP(trim(curp));
        c.setCorreo(trim(correo));
        c.setTelefono(trim(telefono));

        Fecha f;
        sscanf(trim(fecha).c_str(), "%d/%d/%d", &f.dia, &f.mes, &f.anio);
        c.setFecNac(f);

        Cuenta_Debito cuenta;
        cuenta.setNumeroCuenta(trim(numero));
        cuenta.setNIP(trim(nip));
        cuenta.setSaldo(atof(trim(saldo).c_str()));

        clientes.push_back(c);
        cuentas.push_back(cuenta);
    }
    archivo.close();
}

int main() {
    vector<Cliente> clientes;
    vector<Cuenta_Debito> cuentas;
    string nombreArchivo = "banco.txt";
    int o;

    cargarArchivo(clientes, cuentas, nombreArchivo);

    cout << "BIENVENIDO AL BANCO MANDARINOS" << endl;
    do {
        cout << "\nSeleccione una opcion" << endl;
        cout << "1. Ya soy cliente" << endl;
        cout << "2. Registrarme como nuevo cliente" << endl;
        cout << "3. Salir" << endl;
        cin >> o;
        cin.ignore();    
        switch (o) {
        case 1: {
            string nombre, curp;
            cout << "Ingrese su usuario (NOMBRE COMPLETO):" << endl;
            getline(cin, nombre);
            cout << "Ingrese su contrasena (CURP COMPLETA)" << endl;
            getline(cin, curp);

            bool encontrado = false;
            for (size_t i = 0; i < clientes.size(); i++) {
                if (clientes[i].getNombre() == nombre && clientes[i].getCURP() == curp) {
                    encontrado = true;
                    cout << "\nBienvenido " << clientes[i].getNombre() << endl;
                    cout << "Numero de cuenta: " << cuentas[i].getNumeroCuenta() << endl;

                    int opcionSubmenu;
                    do {
                        cout << "\n--- MENU DE CUENTA ---" << endl;
                        cout << "1. Consultar saldo" << endl;
                        cout << "2. Depositar" << endl;
                        cout << "3. Retirar" << endl;
                        cout << "4. Cerrar sesion" << endl;
                        cout << "Seleccione una opcion: ";
                        cin >> opcionSubmenu;
                        cin.ignore();

                        switch (opcionSubmenu) {
                        case 1:
                            cout << "Saldo actual: $" << fixed << setprecision(2) << cuentas[i].getSaldo() << endl;
                            break;

                        case 2: {
                            double monto;
                            cout << "Ingrese el monto a depositar: $";
                            cin >> monto;
                            cin.ignore();
                            if (monto > 0) {
                                cuentas[i].depositar(monto);
                                guardarArchivo(clientes, cuentas, nombreArchivo);
                                cout << "Deposito realizado con exito. Nuevo saldo: $" << cuentas[i].getSaldo() << endl;
                            } else {
                                cout << "El monto debe ser mayor a 0." << endl;
                            }
                            break;
                        }

                        case 3: {
                            double monto;
                            string nipIngresado;
                            cout << "Ingrese el monto a retirar: $";
                            cin >> monto;
                            cin.ignore();
                            cout << "Ingrese su NIP (4 digitos): ";
                            getline(cin, nipIngresado);

                            if (cuentas[i].retirar(monto, nipIngresado)) {
                                guardarArchivo(clientes, cuentas, nombreArchivo);
                                cout << "Retiro exitoso. Nuevo saldo: $" << cuentas[i].getSaldo() << endl;
                            } else {
                                cout << "Error en el retiro. Verifique su NIP o que tenga saldo suficiente." << endl;
                            }
                            break;
                        }

                        case 4:
                            cout << "Cerrando sesion..." << endl;
                            break;

                        default:
                            cout << "Opcion no valida." << endl;
                        }
                    } while (opcionSubmenu != 4);

                    break;
                }
            }
            if (!encontrado) {
                cout << "Usuario o contrasena incorrectos" << endl;
            }
            break;
        }

        case 2: {
            string nombre, curp, correo, telefono, nip;
            Fecha f;

            cout << "Registrar Nombre completo TODO EN MAYUSCULAS" << endl;
            getline(cin, nombre);

            cout << "Registrar CURP" << endl;
            getline(cin, curp);

            cout << "Registrar correo" << endl;
            getline(cin, correo);

            cout << "Registrar telefono" << endl;
            getline(cin, telefono);

            cout << "Dia de nacimiento:" << endl;
            cin >> f.dia;
            cout << "Mes de nacimiento:" << endl;
            cin >> f.mes;
            cout << "Anio de nacimiento:" << endl;
            cin >> f.anio;
            cin.ignore();

            bool valido;
            do {
                valido = true;
                cout << "Elige tu NIP (4 digitos):" << endl;
                getline(cin, nip);
                if (nip.size() != 4) {
                    valido = false;
                }
                for (size_t i = 0; i < nip.size(); i++) {
                    if (nip[i] < '0' || nip[i] > '9') {
                        valido = false;
                    }
                }
                if (!valido) {
                    cout << "El NIP debe ser de 4 digitos" << endl;
                }
            } while (!valido);

            Cliente c;
            c.setNombre(nombre);
            c.setCURP(curp);
            c.setCorreo(correo);
            c.setTelefono(telefono);
            c.setFecNac(f);

            Cuenta_Debito cuenta;
            cuenta.setNumeroCuenta(cuenta.generarNumeroCuenta(nombre, curp));
            cuenta.setNIP(nip);
            cuenta.setSaldo(0);

            clientes.push_back(c);
            cuentas.push_back(cuenta);

            guardarArchivo(clientes, cuentas, nombreArchivo);

            cout << "Registro exitoso. Tu numero de cuenta es: " << cuenta.getNumeroCuenta() << endl;
            break;
        }

        case 3:
            cout << "Guardando y saliendo del programa..." << endl;
            guardarArchivo(clientes, cuentas, nombreArchivo);
            break;

        default:
            cout << "Opcion no valida" << endl;
        }

    } while (o != 3);

    return 0;
}