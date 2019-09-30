#ifndef FILE_H
#define FILE_H
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <sstream>

using namespace std;

class File {
public:
    void modify(string &search, string attr);
    string authenticate();
    void add();
    void remove(string searchName);
    void show(string searchName);
    bool validate(const string attr, const string search);
private:
};
// Write
template<typename T>
void write(ostream& file, const T& value) {
    T val = value;
    int size = sizeof(value);
    file.write(reinterpret_cast<char *>(&size), sizeof(size));
    file.write(reinterpret_cast<const char *>(&val), sizeof(T));
}
// Read
template<typename T>
void read(istream& file, T& value) {
    int len;
    file.read(reinterpret_cast<char *>(&len), sizeof(len));
    file.read(reinterpret_cast<char *>(&value), int(len));
}

// Write string
void write_string(ofstream& file, const string& value) {
    int size = int(value.size());
    file.write(reinterpret_cast<char *>(&size), sizeof(size));
    file.write(value.c_str(), size);
}

// Read string
void read_string(ifstream& file, string &attr) {
    int len;
    file.read(reinterpret_cast<char *>(&len), sizeof(len));
    char *buffer = new char[len];
    file.read(buffer, len);
    attr = buffer;
    delete [] buffer;
}
bool File::validate(const string attr, const string search)
{
    ifstream file("characters.bin", ios::binary | ios::in);
    if (file.fail())
        cout << "No existe este archivo" << endl;
    string name, gender, type, guild;
    int exp, level;
    while(true) {
        read_string(file, name);
        read_string(file, gender);
        read_string(file, type);
        read_string(file, guild);
        read(file, exp);
        read(file, level);

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
    int exp = 0, level = 1;

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

    file.close();

}
void File::modify(string &search, string attr)
{
    string name, gender, type, guild;
    int exp, level;
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
                search = name;
            } else if (attr == "gender") {
                cout << "Género nuevo: " << endl;
                cin >> gender;
            } else if (attr == "type") {
                cout << "Tipo nuevo: " << endl;
                cin >> type;
            } else if (attr == "guild") {
                cout << "Gremio nuevo: " << endl;
                cin >> guild;
            } else if (attr == "exp") {
                cout << "Experiencia nueva: " << endl;
                cin >> exp;
            } else if (attr == "level") {
                cout << "Nivel nuevo: " << endl;
                cin >> level;
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
    }
    help.close();
    file.close();
    std::remove("characters.bin");
    std::rename("help.bin", "characters.bin");
}

string File::authenticate()
{
    string search, name, gender, type, guild;
    int exp, level;
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
    int exp, level;
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
        if (file.eof())
            break;
        if (searchName != name) {
            write_string(help, name);
            write_string(help, gender);
            write_string(help, type);
            write_string(help, guild);
            write(help, exp);
            write(help, level);
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
    int exp, level;
    cout << endl << "----------------------------" << endl;
    while(true) {
        read_string(file, name);
        read_string(file, gender);
        read_string(file, type);
        read_string(file, guild);
        read(file, exp);
        read(file, level);


        if (file.eof())
            break;
        if (searchName == "default" || searchName == name) {
            cout << "Nombre: " << name << endl
                 << "Género: " << gender << endl
                 << "Tipo: " << type << endl
                 << "Gremio: " << guild << endl
                 << "Experiencia: " << exp << endl
                 << "Nivel: " << level << endl;
            cout << "----------------------------" << endl;
        }

    }
    file.close();

}



#endif // FILE_H
