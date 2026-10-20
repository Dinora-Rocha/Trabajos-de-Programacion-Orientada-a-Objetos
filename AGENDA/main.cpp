#include "persona.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <clocale>

using namespace std;

int main()
{
    int opcion, i;
    vector<Persona> lista;
    string nombreArchivo = "datos.txt";
    setlocale(LC_ALL, "spanish");

    // Carga inicial de datos desde el archivo
    ifstream Listado(nombreArchivo);
    if (!Listado.is_open())
    {
        cout << "No se encontro el archivo!\n";
        ofstream NuevoListado(nombreArchivo);
        NuevoListado.close();
    }
    else
    {
        string linea;
        while (getline(Listado, linea))
        {
            if (linea.empty()) continue;

            stringstream ss(linea);
            string nombreTem, telefonoTem, CURPTem, fechaTem;

            getline(ss, nombreTem, ',');
            getline(ss, telefonoTem, ',');
            getline(ss, CURPTem, ',');
            getline(ss, fechaTem, ',');

            Persona nuevo;
            nuevo.setNombre(trim(nombreTem));
            nuevo.setTelefono(trim(telefonoTem));
            nuevo.setCURP(trim(CURPTem));

            FECHA f;
            sscanf(trim(fechaTem).c_str(), "%d/%d/%d", &f.d, &f.m, &f.a);
            nuevo.setFec_na(f);

            lista.push_back(nuevo);
        }
        Listado.close();
    }

    // Menú principal e interacción con el usuario
    do
    {
        system("cls");
        cout << "\n\033[1m---------- Menu personas ----------\033[0m\n" << endl;
        cout << "1. Nueva Persona" << endl;
        cout << "2. Mostrar lista de personas" << endl;
        cout << "3. Mostrar datos de una persona" << endl;
        cout << "4. Edad y Cuantos dias faltan para el cumpleanos" << endl;
        cout << "5. Borrar Persona" << endl;
        cout << "6. Salir del programa" << endl;
        cout << "\nElija una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
        {
            cin.ignore();
            string nombreTem, telefonoTem, CURPTem;
            FECHA fecTem;
            Persona nuevo;
            cout << "\n\nIngrese el nombre: ";
            getline(cin, nombreTem);
            cout << "Ingrese telefono: ";
            cin >> telefonoTem;
            cout << "Ingrese CURP: ";
            cin >> CURPTem;
            cout << "Ingrese la fecha de nacimiento (dd mm aaaa): ";
            cin >> fecTem.d >> fecTem.m >> fecTem.a;

            nuevo.setNombre(nombreTem);
            nuevo.setTelefono(telefonoTem);
            nuevo.setCURP(CURPTem);
            nuevo.setFec_na(fecTem);

            lista.push_back(nuevo);
            cout << "\nPresione enter para continuar..." << endl;
            cin.ignore();
            cin.get();
            break;
        }

        case 2:
        {
            cout << "\n\033[34m---------- Listado de Personas---------- \033[0m\n" << endl;
            for (i = 0; i < lista.size(); i++)
            {
                cout << i + 1 << ". " << lista.at(i).getNombre() << endl;
            }
            cout << "\nPresione enter para continuar..." << endl;
            cin.ignore();
            cin.get();
            break;
        }

        case 3:
        {
            if (lista.empty())
            {
                cout << "No hay personas guardadas." << endl;
            }
            else
            {
                cout << "\n\033[34m---------- Listado de Personas ---------- \033[0m\n" << endl;
                for (i = 0; i < lista.size(); i++)
                {
                    cout << i + 1 << ". " << lista.at(i).getNombre() << endl;
                }

                int indice = 0;
                cout << "\nElija el indice de la persona: ";
                cin >> indice;

                if (indice >= 1 && indice <= lista.size())
                {
                    cout << "\n\033[34m---------- Datos de la Persona ---------- \033[0m\n" << endl;
                    lista.at(indice - 1).mostrarDatos();
                }
                else
                {
                    cout << "\033[31mNúmero invalido.\033[0m" << endl;
                }
            }
            cout << "\nPresione enter para continuar..." << endl;
            cin.ignore();
            cin.get();
            break;
        }

        case 4:
        {
            if (lista.empty())
            {
                cout << "No hay personas guardadas" << endl;
            }
            else
            {
                cout << "\n\033[34m---------- Listado de Personas ---------- \033[0m\n" << endl;
                for (i = 0; i < lista.size(); i++)
                {
                    cout << i + 1 << ". " << lista.at(i).getNombre() << endl;
                }

                int indice = 0;
                cout << "\nIngrese el indice de la persona: ";
                cin >> indice;

                if (indice >= 1 && indice <= lista.size())
                {
                    lista.at(indice - 1).calcularEdadYCumpleanios();
                }
                else
                {
                    cout << "\033[31mNúmero invalido.\033[0m" << endl;
                }
            }
            cout << "\nPresione enter para continuar..." << endl;
            cin.ignore();
            cin.get();
            break;
        }

        case 5:
        {
            int indice = 0;
            cout << "\n\033[34m---------- Listado de Personas ---------- \033[0m\n" << endl;
            for (i = 0; i < lista.size(); i++)
            {
                cout << i + 1 << ". " << lista.at(i).getNombre() << endl;
            }

            if (lista.empty())
            {
                cout << "No hay personas para borrar" << endl;
            }
            else
            {
                cout << "Ingrese el indice del estudiante a borrar: ";
                cin >> indice;
            }

            if (indice >= 1 && indice <= lista.size())
            {
                lista.erase(lista.begin() + (indice - 1));
                cout << "\nPersona eliminada correctamente" << endl;
            }
            else if (!lista.empty())
            {
                cout << "\033[31m\nNúmero invalido\033[0m" << endl;
            }

            cout << "\nPresione enter para continuar..." << endl;
            cin.ignore();
            cin.get();
            break;
        }

        case 6:
        {
            cout << "\nGuardando y saliendo del programa..." << endl;
            guardarArchivo(lista, nombreArchivo);
            break;
        }

        default:
            cout << "\033[31m\nOpcion no valida\033[0m" << endl;
            cout << "\nPresione enter para continuar..." << endl;
            cin.ignore();
            cin.get();
            break;
        }
    } while (opcion != 6);

    return 0;
}
