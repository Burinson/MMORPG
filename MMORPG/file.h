#ifndef FILE_H
#define FILE_H
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

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
    file.write(reinterpret_cast<const char *>(&val), sizeof(T));
}
// Write size
template<typename T>
void write_size(ostream& file, const T& value) {
    size_t size = sizeof(value);
    file.write(reinterpret_cast<char *>(&size), sizeof(size));
}
// Read
template<typename T>
void read(istream& file, T& value, size_t &len) {
    file.read(reinterpret_cast<char *>(&value), int(len));
}

// Write string
void write_string(ofstream& file, const string& value) {
    file.write(value.c_str(), int(value.size()));
}
// Write string size
void write_string_size(ofstream& file, const string& value) {
    size_t size = value.size();
    file.write(reinterpret_cast<char *>(&size), sizeof(size));
}

// Read size
void read_size(ifstream& file, size_t &len) {
    file.read(reinterpret_cast<char *>(&len), sizeof(len));
}

// Read string
void read_string(ifstream& file, string &attr, size_t len) {
    char *buffer = new char[len];
    file.read(buffer, int(len));
    attr = buffer;
    delete [] buffer;
}

void File::add()
{
    ofstream file("characters.bin", ios::out | ios::binary | ios::app);
    if (file.fail())
        cout << "Ocurrió un error escribiendo a este archivo" << endl;
    string str;
    size_t len;

    cout << "Nombre: ";
    cin >> str;
    len = str.size();
    write_string_size(file, str);
    write_string(file, str);

    cout << "Género: " ;
    cin >> str;
    len = str.size();
    write_string_size(file, str);
    write_string(file, str);

    cout << "Tipo: ";
    cin >> str;
    len = str.size();
    write_string_size(file, str);
    write_string(file, str);

    write_string_size(file, "NaN");
    write_string(file, "NaN");

    write_size(file, 0);
    write(file, 0);

    write_size(file, 1);
    write(file, 1);

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

    size_t len;
    string name;
    string gender;
    string type;
    string guild;
    size_t exp;
    size_t level;
    cout << endl << "----------------------------" << endl;
    while(true) {
        read_size(file, len);
        read_string(file, name, len);

        read_size(file, len);
        read_string(file, gender, len);

        read_size(file, len);
        read_string(file, type, len);

        read_size(file, len);
        read_string(file, guild, len);

        read_size(file, len);
        read(file, exp, len);

        read_size(file, len);
        read(file, level, len);

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
