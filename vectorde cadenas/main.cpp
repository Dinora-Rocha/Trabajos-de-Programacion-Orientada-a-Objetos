#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int o;

    cout << "******AGENDA DE PROGRAMACION ORIENTADA A OBJETOS******" << endl;
    vector<string> nombre = {"PABLO ISSAC AGUILAR FLORES", "CRISTIAN ALEJANDRO ALFEREZ GARCIA", "IVAN SANTIAGO ALVAREZ GONZALEZ"};

    do {
        cout << "MENU DE OPERACIONES" << endl;
        cout << "1.CONSULTAR LA LISTA DE NOMBRES "<< endl;
        cout << "2. AGREGAR UN NUEVO NOMBRE "<< endl;
        cout << "3. ENCONTRAR UN NOMBRE "<< endl;
        cout << "4. ORDENAR LISTA"<< endl;
        cout << "5. SALIR"<< endl;
        cout << "Ingrese la operacion a realizar"<< endl;
        cin >> o;

        switch(o){
            case 1:
            cout << "1.CONSULTAR LA LISTA DE NOMBRES "<< endl;
            if (nombre.empty()) {
        cout << "La lista esta vacia." << endl;
    } else {
        for (size_t i = 0; i < nombre.size(); i++) {

            cout << i + 1 << ". " << nombre.at(i) << endl;
        }
    }
                break;

            case 2:
             cout << "2. AGREGAR UN NUEVO NOMBRE "<< endl;

                break;

            case 3:
            cout << "3. ENCONTRAR UN NOMBRE "<< endl;
                break;

            case 4:
             cout << "4. ORDENAR LISTA"<< endl;
                break;

            case 5:
                 cout << "5. SALIR"<< endl;
                break;

            default:
                cout << "Opcion invalida, intente de nuevo" << endl;
                break;
        }
    } while(o != 5);

    return 0;
}
