#include "menu.h"
#include <file.h>
Menu::Menu()
{

}

void Menu::show()
{
    File f;
    int op;
    do {
        cout << "Menú" << endl;
        cout << "1) Agregar nuevo personaje" << endl;
        cout << "2) Acceder a personaje" << endl;
        cout << "3) Modificar" << endl;
        cout << "4) Mostrar todo" << endl;
        cout << "0) Salir" << endl;
        cin >> op;
        switch(op) {
        case 1:
            f.add();
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            f.show();


        }
    } while(op != 0);
}
