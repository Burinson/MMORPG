#include "menu.h"
#include <file.h>
Menu::Menu()
{

}

void Menu::show()
{
    File f;
    string name;
    int op;
    int idx;
    do {
        cout << "~" << endl;
        cout << "1) Agregar nuevo personaje" << endl;
        cout << "2) Acceder a personaje" << endl;
        cout << "3) Mostrar todo" << endl;
        cout << "0) Salir" << endl;
        cin >> op;
        switch(op) {
        case 1:
            f.add();
            break;
        case 2:
            name = f.authenticate();
            if (name != "NULL") {
                int op2;
                do {
                    cout << endl << "~/" << name << endl << endl;
                    cout << "1) Modificar" << endl;
                    cout << "2) Eliminar personaje" << endl;
                    cout << "3) Mostrar personaje" << endl;
                    cout << "4) Completar misión" << endl;
                    cout << "5) Agregar arma" << endl;
                    cout << "6) Mostrar historial" << endl;
                    cout << "7) Mostrar inventario" << endl;
                    cout << "0) Regresar" << endl;
                    cin >> op2;
                    switch(op2) {
                    case 1:
                        int op3;
                        do {
                            cout << endl << "~/" << name << "/modificar" << endl << endl;
                            cout << "1) Modificar nombre" << endl;
                            cout << "2) Modificar género" << endl;
                            cout << "3) Modificar tipo" << endl;
                            cout << "4) Modificar gremio" << endl;
                            cout << "5) Modificar experiencia" << endl;
                            cout << "6) Modificar nivel" << endl;
                            cout << "7) Modificar dinero" << endl;
                            cout << "0) Regresar" << endl;
                            cin >> op3;
                            switch(op3) {
                            case 1:
                                f.modify(name, "name");
                                op3 = 0;
                                break;
                            case 2:
                                f.modify(name, "gender");
                                op3 = 0;
                                break;
                            case 3:
                                f.modify(name, "type");
                                op3 = 0;
                                break;
                            case 4:
                                f.modify(name, "guild");
                                op3 = 0;
                                break;
                            case 5:
                                f.modify(name, "exp");
                                op3 = 0;
                                break;
                            case 6:
                                f.modify(name, "level");
                                op3 = 0;
                                break;
                            case 7:
                                f.modify(name, "money");
                                op3 = 0;
                                break;
                            case 0:
                                break;
                            default:
                                cout << "Selección incorrecta" << endl;
                                break;
                            }
                        } while(op3);
                        break;
                    case 2:
                        f.remove(name);
                        op2 = 0;
                        break;
                    case 3:
                        f.show(name);
                        break;
                    case 4:
                        f.showQuests();
                        cout << "0) Regresar" << endl;
                        cin >> idx;
                        if (idx > 0) {
                            f.completeQuest(name, idx);
                        }
                        break;
                    case 5:
                        f.showWeapons();
                        cout << "0) Regresar" << endl;
                        int idx;
                        cin >> idx;
                        if (idx > 0) {
                            f.addWeapon(name, idx);
                        }
                        break;
                    case 6:
                        f.showLog(name);
                        break;
                    case 7:
                        f.showInv(name);
                        break;
                    case 0:
                        break;
                    default:
                        cout << "Selección incorrecta" << endl;
                    }
                } while (op2);
            }
            break;
        case 3:
            f.show();
            break;
        case 0:
            break;
        default:
            cout << "Selección incorrecta" << endl;


        }
    } while(op);
}
