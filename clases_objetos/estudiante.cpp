#include <stdexcept>
#include <algorithm>
#include <ostream>
#include "estudiante.hpp"

namespace Anahuac {
    // Convertir Anahuac::Carrera (enum) a su representación en string
    std::string carrera_to_string(Carrera carrera) {
        switch(carrera) {
            case Carrera::DERECHO:
                return "Derecho";
            case Carrera::ARQUITECTURA:
                return "Arquitectura";
            case Carrera::INGENIERIA:
                return "Ingeniería";
            case Carrera::ADMINISTRACION:
                return "Administración";
            case Carrera::GASTRONOMIA:
                return "Gastronomía";
            default:
                throw std::invalid_argument("La carrera proporcionada no es válida.");
        }
    }

    // Implementación de setters
    void Estudiante::set_semestre(unsigned int semestre) {
        // Validar semestre (debe estar entre 1 y 10)
        if (semestre > 10 || semestre < 1) {
            throw std::invalid_argument("El semestre proporcionado no es válido.");
        }

        semestre_ = semestre;
    }

    void Estudiante::set_correo(std::string correo) {
        // Asegurar que el correo tenga una @
        if (std::count(correo.begin(), correo.end(), '@') != 1) {
            throw std::invalid_argument("El correo proporcionado no es válido.");
        }

        // Extraer los componentes del correo, usuario y domain
        auto indexArroba = correo.find("@");
        std::string usuario = correo.substr(0, indexArroba);
        std::string dominio = correo.substr(indexArroba + 1);

        // Asegurar que el usuario exista
        if (usuario.empty()) {
            throw std::invalid_argument("El correo proporcionado no es válido.");
        }

        // Verificar que el dominio sea de la Anáhuac Mayab
        if (dominio != "anahuac.mx" && dominio != "anahuacmayab.edu.mx") {
            throw std::invalid_argument("El correo proporcionado no es institucional.");
        }

        correo_ = correo;
    }

    // Overload de << para imprimir fácilmente
    std::ostream& operator<<(std::ostream& os, const Estudiante& estudiante) {
        os << "Nombre: " << estudiante.nombre_
            << "\nID: " << estudiante.id_
            << "\nCarrera: " << carrera_to_string(estudiante.carrera_)
            << "\nSemestre: " << estudiante.semestre_
            << "\nCorreo: " << estudiante.correo_;

        return os;
    }
}
