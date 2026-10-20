#include <iostream>
#include <vector>
#include "Persona.h"


void RegistraCTE( Persona p){
    std::cout << "Registrando al cliente: " << p.getNombre() << std::endl;
    p.setNombre("Frank");
    return;
}


int main()
{
    std::vector <Persona> Agenda;

    Persona nuevaPersona("Pancho","123456789","MOLL730608HDF",8,6,1973);

    RegistraCTE(nuevaPersona);

    std::cout << nuevaPersona.getNombre() << std::endl;


/*    Agenda.emplace_back("Pancho","123456789","MOLL730608HDF",8,6,1973);

    Agenda.emplace_back();
    //Agenda.emplace_back();

    //Agenda.emplace_back();

    //nuevaPersona.setNombre("Francisco");


    std::cout << "Personas en mi agenda: \n" ;
    for (auto const &p : Agenda){
        std::cout << p.getNombre() << std::endl;
    }

    std::cin.get();
*/
    return 0;
}







/*
    Agenda.emplace_back("Pancho",8,6,1973);
    Agenda.emplace_back();

    for (auto p : Agenda){
        std::cout << p.getNombre() << std::endl;
    }
*/
