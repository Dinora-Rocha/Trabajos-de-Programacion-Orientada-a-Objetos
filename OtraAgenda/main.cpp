#include <iostream>
#include <vector>
#include "Persona.h"

// Se usa "Persona &p" (referencia) para modificar el objeto original
void RegistraCTE(Persona &p) {
    std::cout << "Registrando al cliente: " << p.getNombre() << std::endl;
    p.setNombre("Frank");
}

int main() {
    std::vector<Persona> Agenda;

    Persona nuevaPersona("Pancho", "123456789", "MOLL730608HDF", 8, 6, 1973);

    RegistraCTE(nuevaPersona);

    
    std::cout << "Nombre actualizado: " << nuevaPersona.getNombre() << std::endl;

    
    Agenda.push_back(nuevaPersona);

    std::cout << "\nPersonas en mi agenda:" << std::endl;
    for (const auto &p : Agenda) {
        std::cout << "- " << p.getNombre() << std::endl;
    }

    return 0;
}
