#ifndef ESTUDIANTE_HPP
#define ESTUDIANTE_HPP

#include <string>
#include <cstdint>

namespace Anahuac {

    // Carreras ofrecidas en la Anáhuac
    enum class Carrera {
        DERECHO = 1,
        ARQUITECTURA = 2,
        INGENIERIA = 3,
        ADMINISTRACION = 4,
        GASTRONOMIA = 5
    };

    std::string carrera_to_string(Carrera carrera);

    class Estudiante {
    private:
        // Atributos
        std::string nombre_;
        uint32_t id_;
        Carrera carrera_;
        unsigned int semestre_;
        std::string correo_;

    public:
        // Constructores
        Estudiante(std::string nombre, uint32_t id) : nombre_(nombre), id_(id) {}

        Estudiante(std::string nombre, uint32_t id, Carrera carrera, unsigned int semestre, std::string correo) : nombre_(nombre), id_(id) {
            set_carrera(carrera);
            set_semestre(semestre);
            set_correo(correo);
        }

        // Getters
        std::string nombre() { return nombre_; }

        uint32_t id() { return id_; }

        Carrera carrera() { return carrera_; }

        unsigned int semestre() { return semestre_; }

        std::string correo() { return correo_; }

        // Setters
        void set_carrera(Carrera carrera) { carrera_ = carrera; }

        void set_semestre(unsigned int semestre);

        void set_correo(std::string correo);

        friend std::ostream& operator<<(std::ostream& os, const Estudiante& estudiante);
    };
}

#endif
