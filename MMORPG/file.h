#ifndef FILE_H
#define FILE_H
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <sstream>
#include <character.h>
#include <map>
#include <vector>

using namespace std;

class File {
public:
    void modify(string &search, string attr);
    string authenticate();
    void add();
    void remove(string searchName);
    void show(string searchName);
    bool validate(const string attr, const string search);
    void completeQuest(string searchName, int idx);
    void showQuests();
    void showWeapons();
    void addWeapon(string searchName, int idx);
    void showLog(string searchName);
    void showInv(const string searchName);

    vector<Quest> quests = {
        // nombre, experiencia, nivel, recompensa
        Quest("Destruir el castillo de Notradamn", 500, 1, 10),
        Quest("Ayudar a Alf a encontrar su casa", 600, 2, 10),
        Quest("Regresar el anillo de Frodo", 700, 2, 20),
        Quest("Darle de comer al michi", 100, 3, 30),
        Quest("Derrotar a Trosvteskteski", 1000, 4, 100),
        Quest("Clasificar 500 rocas por su nombre", 500, 5, 200),
        Quest("Encontrar el conejo de la viejita", 2000, 10, 1000),
        Quest("Jugar canicas con el hermitaño", 2500, 13, 10000),
        Quest("Derrotar al gran yeti de las nieves", 5000, 20, 20000)
    };
    vector<Weapon> weapons = {
      // nombre, letalidad, nivel, precio
      Weapon("Palo de madera", 5, 1, 20),
      Weapon("Varita de metal", 10, 3, 300),
      Weapon("Daga de hierro", 20, 5, 500),
      Weapon("Boomerang", 50, 10, 2000),
      Weapon("Bomba", 100, 15, 10000),
      Weapon("Lanzallamas", 200, 20, 20000)
    };
private:
};
// Write
template<typename T>
void write(ostream& file, const T& value) {
    T val = value;
    int size = sizeof(value);
    file.write(reinterpret_cast<char *>(&size), sizeof(int));
    file.write(reinterpret_cast<const char *>(&val), sizeof(T));
}
// Read
template<typename T>
void read(istream& file, T& value) {
    int len;
    file.read(reinterpret_cast<char *>(&len), sizeof(int));
    file.read(reinterpret_cast<char *>(&value), len);
}

// Write string
void write_string(ofstream& file, const string& value) {
    int size = int(value.size());
    file.write(reinterpret_cast<char *>(&size), sizeof(int));
    file.write(value.c_str(), size);
}

// Read string
void read_string(ifstream& file, string &attr) {
    int len;
    file.read(reinterpret_cast<char *>(&len), sizeof(int));
    char *buffer = new char[len];
    file.read(buffer, len);
    attr = buffer;
    attr = attr.substr(0, len);
    delete [] buffer;
}
bool File::validate(const string attr, const string search)
{
    ifstream file("characters.bin", ios::binary | ios::in);
    if (file.fail())
        cout << "No existe este archivo" << endl;
    string name, gender, type, guild;
    int exp, level, money;
    while(true) {
        read_string(file, name);
        read_string(file, gender);
        read_string(file, type);
        read_string(file, guild);
        read(file, exp);
        read(file, level);
        read(file, money);

        if (file.eof())
            break;
        if (attr == "name" && search == name) {
            file.close();
            return false;
        }
    }
        file.close();
        return true;
}


void File::add()
{
    ofstream file("characters.bin", ios::out | ios::binary | ios::app);
    if (file.fail())
        cout << "Ocurrió un error escribiendo a este archivo" << endl;
    string name, gender, type;
    int exp = 0, level = 1, money = 0;

    cout << "Nombre: ";
    cin >> name;
    if (!validate("name", name)) {
        cout << "Este nombre ya existe" << endl;
        file.close();
        return;
    }
    cout << "Género: " ;
    cin >> gender;

    cout << "Tipo: ";
    cin >> type;

    write_string(file, name);
    write_string(file, gender);
    write_string(file, type);
    write_string(file, "NULL");
    write(file, exp);
    write(file, level);
    write(file, money);

    file.close();

}
void File::modify(string &search, string attr)
{
    string name, gender, type, guild;
    int exp, level, money;
    ifstream file("characters.bin", ios::binary | ios::in);
    if (file.fail())
        cout << "No existe este archivo" << endl;
    ofstream help("help.bin", ios::binary | ios::out | ios::app);

    while(true) {
        read_string(file, name);
        read_string(file, gender);
        read_string(file, type);
        read_string(file, guild);
        read(file, exp);
        read(file, level);
        read(file, money);
        if (search == name) {
            if (attr == "name") {
                cout << "Nombre nuevo: " << endl;
                cin >> name;
                if (!validate("name", name)) {
                    cout << "Este nombre ya existe" << endl;
                    help.close();
                    file.close();
                    std::remove("help.bin");
                    return;
                }
                string oldFile = search+"_log.bin";
                string newFile = name+"_log.bin";
                std::rename(oldFile.c_str(), newFile.c_str());
                oldFile = search+"_inv.bin";
                newFile = name+"_inv.bin";
                std::rename(oldFile.c_str(), newFile.c_str());
                search = name;
            } else if (attr == "gender") {
                cout << "Género nuevo: ";
                cin >> gender;
            } else if (attr == "type") {
                cout << "Tipo nuevo: " ;
                cin >> type;
            } else if (attr == "guild") {
                cout << "Gremio nuevo: ";
                cin >> guild;
            } else if (attr == "exp") {
                cout << "Experiencia nueva: ";
                cin >> exp;
                int i = 0, cnt = 0;
                while(exp >= cnt) {
                    i++;
                    cnt+=i*100;
                }
                level = i;
            } else if (attr == "level") {
                cout << "Nivel nuevo: ";
                cin >> level;
                int cnt = 0, i = 0;
                while(i < level) {
                    cnt += i*100;
                    ++i;
                }
                exp = cnt;
            } else if (attr == "money") {
                cout << "Dinero nuevo: $";
                cin >> money;
            }
        }

        if (file.eof())
            break;
        write_string(help, name);
        write_string(help, gender);
        write_string(help, type);
        write_string(help, guild);
        write(help, exp);
        write(help, level);
        write(help, money);
    }
    help.close();
    file.close();
    std::remove("characters.bin");
    std::rename("help.bin", "characters.bin");
}

void File::completeQuest(string searchName, int idx)
{
    int rewardExp = quests[idx-1].getExp();
    int unlockLvl = quests[idx-1].getUnlock_level();
    int reward = quests[idx-1].getReward();
    string questName = quests[idx-1].getName();

    string name, gender, type, guild;
    int exp, level, money;
    ifstream file("characters.bin", ios::binary | ios::in);
    if (file.fail())
        cout << "No existe este archivo" << endl;
    ofstream help("help.bin", ios::binary | ios::out | ios::app);
    string fileName = searchName+"_log.bin";
    ofstream log_file(fileName, ios::binary | ios::out | ios::app);

    while(true) {
        read_string(file, name);
        read_string(file, gender);
        read_string(file, type);
        read_string(file, guild);
        read(file, exp);
        read(file, level);
        read(file, money);
        if (searchName == name) {
            if (level >= unlockLvl) {
                write_string(log_file, questName);
                write(log_file, rewardExp);
                write(log_file, unlockLvl);
                write(log_file, money);
                exp += rewardExp;
                money += reward;
                int i = 0, cnt = 0;
                while(exp >= cnt) {
                    i++;
                    cnt+=i*100;
                }
                level = i;
            } else {
                cout << "No tienes el nivel suficiente para completar esta misión" << endl;
                help.close();
                file.close();
                std::remove("help.bin");
                return;
            }
        }

        if (file.eof())
            break;
        write_string(help, name);
        write_string(help, gender);
        write_string(help, type);
        write_string(help, guild);
        write(help, exp);
        write(help, level);
        write(help, money);
    }
    help.close();
    file.close();
    log_file.close();
    std::remove("characters.bin");
    std::rename("help.bin", "characters.bin");
    cout << searchName << " ha obtenido " << rewardExp <<" exp" << endl;
}

void File::showQuests()
{
    for(int i = 0; i < quests.size(); ++i) {
        cout << i+1 << ") " << quests[i].getName() << endl
             << " \t nivel: " << quests[i].getUnlock_level()
             << " \t exp: " << quests[i].getExp()
             << " \t recompensa: $" << quests[i].getReward() << endl << endl;
    }
}

void File::showWeapons()
{
    for(int i = 0; i < weapons.size(); ++i) {
        cout << i+1 << ") " << weapons[i].getName() << endl
             << " \t letalidad: " << weapons[i].getLethality()
             << " \t nivel: " << weapons[i].getLevel()
             << " \t precio: $" << weapons[i].getPrice() << endl << endl;
    }
}

void File::addWeapon(string searchName, int idx)
{
    int unlockLvl = weapons[idx-1].getLevel();
    int price = weapons[idx-1].getPrice();
    int lethality = weapons[idx-1].getLethality();
    string weaponName = weapons[idx-1].getName();

    string name, gender, type, guild;
    int exp, level, money;
    ifstream file("characters.bin", ios::binary | ios::in);
    if (file.fail())
        cout << "No existe este archivo" << endl;
    ofstream help("help.bin", ios::binary | ios::out | ios::app);

    ofstream inv_file(searchName+"_inv.bin", ios::binary | ios::out | ios::app);

    while(true) {
        read_string(file, name);
        read_string(file, gender);
        read_string(file, type);
        read_string(file, guild);
        read(file, exp);
        read(file, level);
        read(file, money);
        if (searchName == name) {
            if (level >= unlockLvl) {
                if (money >= price) {
                    write_string(inv_file, weaponName);
                    write(inv_file, lethality);
                    write(inv_file, unlockLvl);
                    write(inv_file, price);
                    money -= price;
                } else {
                    cout << "No tienes el dinero suficiente para comprar esta arma" << endl;
                    help.close();
                    file.close();
                    std::remove("help.bin");
                    return;
                }
            } else {
                cout << "No tienes el nivel suficiente para utilizar esta arma" << endl;
                help.close();
                file.close();
                std::remove("help.bin");
                return;
            }
        }

        if (file.eof())
            break;
        write_string(help, name);
        write_string(help, gender);
        write_string(help, type);
        write_string(help, guild);
        write(help, exp);
        write(help, level);
        write(help, money);
    }
    help.close();
    file.close();
    inv_file.close();
    std::remove("characters.bin");
    std::rename("help.bin", "characters.bin");
    cout << searchName << " ha comprado un " << weaponName << endl;
}

void File::showLog(string searchName)
{
    string fileName = searchName+"_log.bin";
    ifstream file(fileName, ios::binary | ios::in);
    if (file.fail())
        cout << "No existe este archivo" << endl;

    string name;
    int exp, unlock_level, reward;
    cout << endl << "----------------------------" << endl;
    while(true) {
        read_string(file, name);
        read(file, exp);
        read(file, unlock_level);
        read(file, reward);

        if (file.eof())
            break;
        cout << "Nombre: " << name << endl
             << "Experiencia: " << exp << endl
             << "Nivel de desbloqueo: " << unlock_level << endl
             << "Recompensa: $" << reward << endl;
        cout << "----------------------------" << endl;

    }
    file.close();
}

void File::showInv(const string searchName)
{
    string fileName = searchName+"_inv.bin";
    ifstream file(fileName, ios::binary | ios::in);
    if (file.fail())
        cout << "No existe este archivo" << endl;

    string name;
    int lethality, level, price;
    cout << endl << "----------------------------" << endl;
    while(true) {
        read_string(file, name);
        read(file, lethality);
        read(file, level);
        read(file, price);

        if (file.eof())
            break;
        cout << "Nombre: " << name << endl
             << "Letalidad: " << lethality << endl
             << "Nivel de desbloqueo: " << level << endl
             << "Precio: $" << price << endl;
        cout << "----------------------------" << endl;

    }
    file.close();
}

string File::authenticate()
{
    string search, name, gender, type, guild;
    int exp, level, money;
    ifstream file("characters.bin", ios::binary | ios::in);
    if (file.fail())
        cout << "No existe este archivo" << endl;
    cout << "Nombre a buscar: ";
    cin >> search;

    while(true) {
        read_string(file, name);
        read_string(file, gender);
        read_string(file, type);
        read_string(file, guild);
        read(file, exp);
        read(file, level);
        read(file, money);

        if (search == name) {
            file.close();
            return search;
        }
        if (file.eof())
            break;
    }
    file.close();
    cout << "No existe este personaje" << endl;
    return "NULL";
}


void File::remove(string searchName)
{
    string name, gender, type, guild;
    int exp, level, money;
    ifstream file("characters.bin", ios::binary | ios::in);
    if (file.fail())
        cout << "No existe este archivo" << endl;
    ofstream help("help.bin", ios::binary | ios::out | ios::app);

    while(true) {
        read_string(file, name);
        read_string(file, gender);
        read_string(file, type);
        read_string(file, guild);
        read(file, exp);
        read(file, level);
        read(file, money);
        if (file.eof())
            break;
        if (searchName != name) {
            write_string(help, name);
            write_string(help, gender);
            write_string(help, type);
            write_string(help, guild);
            write(help, exp);
            write(help, level);
            write(help, money);
        }

    }
    help.close();
    file.close();
    std::remove("characters.bin");
    std::rename("help.bin", "characters.bin");
}

void File::show(string searchName = "default")
{
    ifstream file("characters.bin", ios::binary | ios::in);
    if (file.fail())
        cout << "No existe este archivo" << endl;

    string name, gender, type, guild;
    int exp, level, money;
    cout << endl << "----------------------------" << endl;
    while(true) {
        read_string(file, name);
        read_string(file, gender);
        read_string(file, type);
        read_string(file, guild);
        read(file, exp);
        read(file, level);
        read(file, money);

        if (file.eof())
            break;
        if (searchName == "default" || searchName == name) {
            cout << "Nombre: " << name << endl
                 << "Género: " << gender << endl
                 << "Tipo: " << type << endl
                 << "Gremio: " << guild << endl
                 << "Experiencia: " << exp << endl
                 << "Nivel: " << level << endl
                 << "Dinero: $" << money << endl;
            cout << "----------------------------" << endl;
        }

    }
    file.close();

}



#endif // FILE_H
