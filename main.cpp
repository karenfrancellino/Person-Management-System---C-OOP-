#include <iostream>
#include <string>
using namespace std;

class Persona {
    protected:
    string nombre;
    string apellidos;

    public:
        Persona() : nombre(""), apellidos("") {}
        Persona(string nombre, string apellidos){
            this->nombre = nombre;
            this->apellidos = apellidos;
    }

    void setPersona(string nombre, string apellidos){
        this->nombre = nombre;
        this->apellidos = apellidos;
    }
};

class Empleado : public Persona {
    private:
        string categoria;

    public: 
        Empleado(string nombre, string apellidos, string categoria) : Persona(nombre, apellidos){
            this->categoria = categoria;
        }

    void setCategoria(string categoria){
        this->categoria = categoria;
    }

    void printEmpleado(){
        cout << "Nombre: " <<  nombre << endl;
        cout << "Apellidos: " << apellidos << endl;
        cout << "Categoria: " << categoria << endl; 
    }
};

class Paciente : public Persona {
    private: 
    string aseguradora;

    public: 
    Paciente(string nombre, string apellidos, string aseguradora) : Persona(nombre, apellidos) {
        this->aseguradora = aseguradora;
    }
    void setAseguradora(string aseguradora){
        this->aseguradora = aseguradora;
    }
    void printPaciente(){
        cout << "Nombre: " << nombre << endl;
        cout << "Apellidos: " << apellidos << endl;
        cout << "Aseguradora: " << aseguradora << endl;
    }
};

int main(){
    string nombre, apellidos, categoria, aseguradora;
    string tipoRegistro;

    cout << "¿Qué tipo de registro desea introducir? (E para empleado, P para paciente): ";
    getline(cin, tipoRegistro);

    if(tipoRegistro == "E" || tipoRegistro == "P"){
        cout << "Nombre: ";
        getline(cin >> ws, nombre);
        cout << "Apellidos: ";
        getline(cin, apellidos);
    } else{
        cout << "Opción no válida." << endl;
        return 0;
    }

    if  (tipoRegistro == "E"){
        cout<< "Categoria: ";
        getline(cin, categoria);

        Empleado empleado(nombre, apellidos, categoria);
        empleado.printEmpleado();
    } else if (tipoRegistro == "P") {
        cout << "Aseguradora: ";
        getline(cin, aseguradora);

        Paciente paciente(nombre, apellidos, aseguradora);
        paciente.printPaciente();
    }
    return 0;
}