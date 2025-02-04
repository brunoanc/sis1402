#include <iostream>
#include <vector>
#include "estudiante.hpp"

int main(int argc, char **argv)
{
    std::vector<Anahuac::Estudiante> estudiantes;

    for (int i = 0; i < 5; i++) {
        // Crear estudiante con nombre ("Jorge{i + 1}") y ID i
        Anahuac::Estudiante estudiante("Jorge" + std::to_string(i + 1), i);

        // Agregar atributos faltantes mediante setters
        estudiante.set_carrera(static_cast<Anahuac::Carrera>(i + 1));
        estudiante.set_semestre(i + 1);
        estudiante.set_correo("jorge" + std::to_string(i + 1) + "@anahuac.mx");

        // Agregar estudiante al vector
        estudiantes.push_back(estudiante);
    }

    // Imprimir estudiantes usando el overload de <<
    for (const auto& estudiante : estudiantes) {
        std::cout << estudiante << "\n" << std::endl;
    }
}
