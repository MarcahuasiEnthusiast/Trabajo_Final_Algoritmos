#include <iostream>
#include <fstream>
#include <experimental/filesystem>
#include <string>
#include <stdlib.h>
#include <chrono>
#include <iomanip>
#include <vector>
#include "Archivo.hpp"

using namespace std;
namespace fs = std::experimental::filesystem;
using namespace std::chrono_literals;

int ConvertirMes(string fecha) {
	int mesNum = 0;
	if (fecha.substr(4, 3) == "Jan") mesNum = 01;
	if (fecha.substr(4, 3) == "Feb") mesNum = 02;
	if (fecha.substr(4, 3) == "Mar") mesNum = 03;
	if (fecha.substr(4, 3) == "Apr") mesNum = 04;
	if (fecha.substr(4, 3) == "May") mesNum = 05;
	if (fecha.substr(4, 3) == "Jun") mesNum = 06;
	if (fecha.substr(4, 3) == "Jul") mesNum = 07;
	if (fecha.substr(4, 3) == "Aug") mesNum = 8;
	if (fecha.substr(4, 3) == "Sep") mesNum = 9;
	if (fecha.substr(4, 3) == "Oct") mesNum = 10;
	if (fecha.substr(4, 3) == "Nov") mesNum = 11;
	if (fecha.substr(4, 3) == "Dec") mesNum = 12;

	else return mesNum;
}

string Imprimirfecha(string fecha) {

	int mess = ConvertirMes(fecha);

	if (mess == 8 || mess == 9) {
		string Fecha = fecha.substr(8, 2) + '0' + to_string(mess) + fecha.substr(20, 4);
		return Fecha;
	}

	else {
	string Fecha = fecha.substr(8, 2) + to_string(mess) + fecha.substr(20, 4);
	return Fecha;
	}
}

string ImprimirExtension(string nombre) {

	/*string ext = nombre.substr(nombre.length() - 4, 4);
	return ext;*/

	for (int i = 0; i < nombre.length(); i++) {
		if (nombre[i] == '.') return nombre.substr(i+1, nombre.length() - i);
	}
}

int main()
{

	vector <string> nombre;
	vector <string> extension;
	vector <int> tamano;
	vector <string> fecha;

	string path = "D:\\UPC\\arqui\\semana 1";
		for (auto entry : fs::directory_iterator(path)) {
			//NOMBRE
			cout << entry.path() << endl;

			string name = entry.path().filename().string();
			nombre.push_back(name);
			
			//TAMANO DE ARCHIVO. SI ES UN FOLDER ES 0 bytes
			try {
				std::cout << "File size = " << fs::file_size(entry.path()) << " bytes" << '\n';
			}
			catch (fs::filesystem_error& e) {
				std::cout << "folder = 0 bytes" << '\n';
			}
			int size = fs::file_size(entry.path());
			tamano.push_back(size);

			//FECHA DE ULTIMA MODIFICACION
			auto ftime = fs::last_write_time(entry.path());
			time_t cftime = decltype(ftime)::clock::to_time_t(ftime); // assuming system_clock
			//cout << ConvertirMes(asctime(localtime(&cftime)));
			//Imprimirfecha(asctime(localtime(&cftime)));
			string date = Imprimirfecha(asctime(localtime(&cftime)));
			cout << date << endl;
			fecha.push_back(date);

			//EXTENSION

			string ext;
				 ext = entry.path().filename().string();
				cout << ImprimirExtension(ext) << endl;
			extension.push_back(ImprimirExtension(ext));
			cout << endl;
		}

		//prueba de que se guardan los atributos
		for (int i; i < nombre.size(); i++) {
			cout << nombre[i] << endl;
			cout << extension[i] << endl;
			cout << tamano[i] << endl;
			cout << fecha[i] << endl;
		}
		vector <Archivo> files;
		for (int i; i < nombre.size(); i++) {
		files.push_back(Archivo(nombre[i], extension[i], tamano[i], stoi(fecha[i])));
		}



	system("pause");
	return 0;
}
