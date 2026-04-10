#include <iostream>
#include <string>

// ==================== CLASSE BASE ====================
class Persona {
protected:
    std::string nombre;
    std::string apellidos;

public:
    Persona() : nombre(""), apellidos("") {}

    Persona(const std::string& nombre, const std::string& apellidos)
        : nombre(nombre), apellidos(apellidos) {}

    void setPersona(const std::string& nombre, const std::string& apellidos) {
        this->nombre = nombre;
        this->apellidos = apellidos;
    }
};

// ==================== EMPLEADO ====================
class Empleado : public Persona {
private:
    std::string categoria;

public:
    Empleado(const std::string& nombre, const std::string& apellidos,
             const std::string& categoria)
        : Persona(nombre, apellidos), categoria(categoria) {}

    void setCategoria(const std::string& categoria) {
        this->categoria = categoria;
    }

    void printEmpleado() const {
        std::cout << "Nombre: " << nombre << "\n";
        std::cout << "Apellidos: " << apellidos << "\n";
        std::cout << "Categoria: " << categoria << "\n";
    }
};

// ==================== PACIENTE ====================
class Paciente : public Persona {
private:
    std::string aseguradora;

public:
    Paciente(const std::string& nombre, const std::string& apellidos,
             const std::string& aseguradora)
        : Persona(nombre, apellidos), aseguradora(aseguradora) {}

    void setAseguradora(const std::string& aseguradora) {
        this->aseguradora = aseguradora;
    }

    void printPaciente() const {
        std::cout << "Nombre: " << nombre << "\n";
        std::cout << "Apellidos: " << apellidos << "\n";
        std::cout << "Aseguradora: " << aseguradora << "\n";
    }
};

// ==================== MAIN ====================
int main() {
    std::string nombre, apellidos, categoria, aseguradora;
    std::string tipoRegistro;

    std::cout << "¿Qué tipo de registro desea introducir?\n";
    std::cout << "E - Empleado\nP - Paciente\n";
    std::getline(std::cin, tipoRegistro);

    // normalizar entrada
    if (tipoRegistro == "e") tipoRegistro = "E";
    if (tipoRegistro == "p") tipoRegistro = "P";

    if (tipoRegistro != "E" && tipoRegistro != "P") {
        std::cout << "Opción no válida.\n";
        return 1;
    }

    std::cout << "Nombre: ";
    std::getline(std::cin >> std::ws, nombre);

    std::cout << "Apellidos: ";
    std::getline(std::cin, apellidos);

    if (tipoRegistro == "E") {
        std::cout << "Categoria: ";
        std::getline(std::cin, categoria);

        Empleado empleado(nombre, apellidos, categoria);
        empleado.printEmpleado();

    } else {
        std::cout << "Aseguradora: ";
        std::getline(std::cin, aseguradora);

        Paciente paciente(nombre, apellidos, aseguradora);
        paciente.printPaciente();
    }

    return 0;
}
