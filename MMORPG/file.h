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
    void modify(string attr);
    void add();
    void remove();
    void show();
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
    int size = value.size();
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

void File::add()
{
    ofstream file("characters.bin", ios::out | ios::binary | ios::app);
    if (file.fail())
        cout << "Ocurrió un error escribiendo a este archivo" << endl;
    string str;
    int len;

    cout << "Nombre: ";
    cin >> str;
    len = str.size();
    write_string(file, str);

    cout << "Género: " ;
    cin >> str;
    len = str.size();
    write_string(file, str);

    cout << "Tipo: ";
    cin >> str;
    len = str.size();
    write_string(file, str);

    write_string(file, "NaN");
    int exp = 0, level = 1;
    write(file, exp);
    write(file, level);

    file.close();

}
void File::modify(string attr)
{

}


void File::remove()
{

}

void File::show()
{
    ifstream file("characters.bin", ios::binary | ios::in);
    if (file.fail())
        cout << "No existe este archivo" << endl;

    string name;
    string gender;
    string type;
    string guild;
    int exp;
    int level;
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

        cout << "Nombre: " << name << endl
             << "Género: " << gender << endl
             << "Tipo: " << type << endl
             << "Gremio: " << guild << endl
             << "Experiencia: " << exp << endl
             << "Nivel: " << level << endl;

        cout << "----------------------------" << endl;

    }
    file.close();

}
#endif // FILE_H
