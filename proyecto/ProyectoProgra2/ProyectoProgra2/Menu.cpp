//prueba menu.cpp
#include "Menu.h"

Menu::Menu(const string& titulo, const vector<Opcion>& opciones) : ppio(nullptr), dynamicallyAllocated(false),
titulo(titulo) {
    for (auto i = opciones.rbegin(); i != opciones.rend(); i++) {
        ingresarOpcion(i->numero, i->nombre, i->submenu);
    }
} //el auto es para identificar automaticamente el tipo
  //la i funciona coma la variable como un "it" pues

Menu::Menu() {
    Menu subMenuManteIngresarProd("Ingresar Producto", {
            {1, "1-Tipo Conserva",nullptr},
            {2, "2-Tipo Abarrote",nullptr},
            {3, "3-Tipo Embutido",nullptr},
            {4, "4-Retornar",nullptr},
            {0, "0-Volver al Menu anterior",nullptr}
        });

    Menu subMenuMantenimiento("Menu Mantenimiento", { //como una lista "lineal/vertical" con mas listas al "lado"
        //ingresar prod tiene otro submenu adentro
        {1, "1-Ingresar producto",&subMenuManteIngresarProd},
        {2, "2-Eliminar producto",nullptr},
        {3, "3-Actualizar producto",nullptr},
        {4, "4-Retornar",nullptr},
        {0, "0-Volver al Menu anterior",nullptr}
        });

    //cambiar porque Ventas debe llevar inmediatamente 
    //generar una factura de lo solicitado por un cliente
    Menu subMenuVentas("Ventas", {
            {1, "1-Insert Grade",nullptr}
        });

    Menu subMenuReportes("Menu Reportes", {
            {1, "1-Reportar todos los productos del minisuper",nullptr},
            {2, "2-Reportar solo los productos de una determinada categoria",nullptr},
            {3, "3-Reportar los productos por debajo del minimo de su existencia",nullptr},
            {4, "4-Reportar las facturas de cliente por su cedula",nullptr}, //hacerlo con un map<>
            {5, "5-Reportar cedulas de los mejores 5 clientes",nullptr},
            {0, "0-Volver al Menu principal", nullptr}
        });

    Menu menuPrincipal("Menu Principal", {
            {1, "1-Mantenimiento",&subMenuMantenimiento},
            {2, "2-Ventas",&subMenuVentas},
            {3, "3-Reportes",&subMenuReportes},
            {0, "0-Salir",nullptr}
        });

    menuPrincipal.manejarEntradaUsuario();
}

Menu::~Menu() {
    clear();
}

void Menu::ingresarOpcion(const int& op, const string& nom, Menu* submenu) {
    Nodo* newNodo = new Nodo{ op, nom, submenu, ppio };
    ppio = newNodo;
}


void Menu::mostrarMenu() const {
    Nodo* external = ppio;
    while (external != nullptr) {
        cout << external->nombre << endl;
        external = external->siguiente;
    }

}

//maneja los eventos
void Menu::manejarEntradaUsuario() const {
    int opciUsuario;

    do {
        cout << endl;
        cout << "----" << titulo << "----" << endl;
        cout << endl;
        mostrarMenu();

        cout << "\nDigite el numero de su eleccion: " << endl;
        cin >> opciUsuario;

        // Limpiar el buffer
        //cin.ignore(numeric_limits<streamsize>::max(), '\n');

        //limpiar pantalla
        system("cls");

        Nodo* external = ppio;
        bool opcionManejada = false;

        while (external != nullptr) {
            if (external->opcion == opciUsuario) {
                if (external->submenu != nullptr) {
                    external->submenu->manejarEntradaUsuario();

                    //submenu dentro del submenu
                    Nodo* externalSubMenu = external->submenu->ppio;
                    while (externalSubMenu != nullptr) {
                        if (externalSubMenu->opcion == opciUsuario) {
                            if (externalSubMenu->submenu != nullptr) {
                                externalSubMenu->submenu->manejarEntradaUsuario();
                                break;
                            }
                        }
                    }
                }
                else {
                    manejarOpcion(external);
                }
                opcionManejada = true;
                break;
            }
            external = external->siguiente;
        }
        if (!opcionManejada) {
            cout << "Opcion invalidada. Intente de nuevo." << endl;
        }
    } while (opciUsuario != 0);
}

void Menu::manejarOpcion(Nodo* nod) const {
    int opcion = nod->opcion;
    string nombre = nod->nombre;

    /* contenedores
    StudentContainer& studentRef = const_cast<StudentContainer&>(student);
    CourseContainer& courseRef = const_cast<CourseContainer&>(course);*/

    //mantenimiento
    if (nombre == "1-Ingresar producto" && opcion == 1) { //adaptarlo a que tiene otro submenu
        //studentRef.addStudent(); // .agregarProducto();
    }
    else if (nombre == "2-Eliminar producto" && opcion == 2) {
        //studentRef.erase(); // .eliminar();
    }
    else if (nombre == "3-Actualizar producto" && opcion == 3) {
        //studentRef.showStudentInformation(); // .actualizarProducto();
    }
    else if (nombre == "4-Retornar" && opcion == 4) {
        //metodo // ->string.toString() o  .mostrarInfoProducto();
    }
    //ventas
    else if (nombre == "Ventas" && opcion == 1) {
        //metodo que genera la factura
    }
    //Reportes
    else if (nombre == "1-Reportar todos los productos del minisuper" && opcion == 1) {
        //metodo
    }
    else if (nombre == "2-Reportar solo los productos de una determinada categoria" && opcion == 2) {
        //metodo
    }
    else if (nombre == "3-Reportar los productos por debajo del minimo de su existencia" && opcion == 3) {
        //metodo
    }
    else if (nombre == "4-Reportar las facturas de cliente por su cedula" && opcion == 4) {
        //metodo
    }
    else if (nombre == "5-Reportar cedulas de los mejores 5 clientes" && opcion == 5) {
        //metodo
    }
    else if (nombre == "6-Volver al Menu principal" && opcion == 6) {
        //metodo
    }
    else {
        cout << "Opcion invalidada. Intente de nuevo." << endl;
    }
}

bool Menu::isDynamicallyAllocated() const {
    return dynamicallyAllocated;
}

void Menu::setDynamicallyAllocated(bool dynamicallyAllocated) {
    Menu::dynamicallyAllocated = dynamicallyAllocated;
}

void Menu::clear() {
    Nodo* external = ppio;
    while (external != nullptr) {
        Nodo* next = external->siguiente;
        if (external->submenu && external->submenu->isDynamicallyAllocated()) {
            delete external->submenu;
        }
        delete external;
        external = next;
    }
    ppio = nullptr;
}