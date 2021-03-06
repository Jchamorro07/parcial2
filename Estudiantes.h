#include <mysql.h>
#include <iostream>
#include "ConexionBD.h"
#include <string>

using namespace std;

class Estudiantes
{
	//atributos
private: string carnet, nombres, apellidos, direccion, genero, email, fecha_nacimiento;
	   int telefono;
	   //contructor 
public:
	Estudiantes() {}
	Estudiantes( string car, string nom, string ape, string dir, int tel, string gen, string em, string fn)

	{
		carnet = car;
		nombres = nom;
		apellidos = ape;
		direccion = dir;
		telefono = tel;
		genero = gen;
		email = em;
		fecha_nacimiento = fn;
	}

	//metodos
public:
	
	void setCarnet(string car) { carnet = car; }
	void setNombres(string nom) { nombres = nom; }
	void setApellidos(string ape) { apellidos = ape; }
	void setDireccion(string dir) { direccion = dir; }
	void setTelefono(int tel) { telefono = tel; }
	void setGenero(string gen) { genero = gen; }
	void setEmail(string em) { email = em; }
	void setFecha_nacimiento(string fn) { fecha_nacimiento = fn; }


	
	string getCarnet() { return carnet; }
	string getNombres() { return nombres; }
	string getApellidos() { return apellidos; }
	string getDireccion() { return direccion; }
	string getTelefono() { return telefono; }
	string getGenero() { return genero; }
	string getEmail() { return email; }
	string getFecha_nacimiento() { return fecha_nacimiento; }


	//inicia leer
	void leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {
			string t = to_string(telefono);
			cout << "informacion del estudiante" << endl;
			string consulta = "SELECT *FROM Estudiantes";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << " , " << fila[1] << " , " << fila[2] << " , " << fila[3] << " , " << fila[4] << " , " << fila[5] << "," << fila[6] << "," << fila[7] << "," << endl;
				}

			}
			else {
				cout << "* Error *" << endl;
			}

		}
		else {
			cout << "Error al conectar " << endl;
		}
		cn.cerrar_conexion();
	}
	//inicia crear
	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string t = to_string(telefono);
			string insert = "INSERT INTO Estudiantes(carnet, nombres, apellidos, direccion, telefono, genero, email, fecha_nacimiento) VALUES('" + carnet + "','" + nombres + "','" + apellidos + "','" + direccion + "','" + telefono + "','" + genero + "','" + email + "','" + fecha_nacimiento + "')";
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "se inserto correctamente" << endl;
			}
			else {
				cout << "Error al insertar" << endl;
			}
		}
		else {
			cout << "Error al conectar" << endl;
		}
		cn.cerrar_conexion();

	}
	//inicia actualizar
	void actualizar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string t = to_string(telefono);
			string update = "UPDATE Estudiantes SET carnet='" + carnet + "', nombres='" + nombres + "', apellidos='" + apellidos + "', direccion='" + direccion + "' , telefono='" + telefono + "', genero='" + genero + "', email='" + email + "', fecha_nacimiento='" + fecha_nacimiento + "',WHERE idestudiante=";
			string id_estudiante;
			cout << "Ingrese el id del estudiante" << endl;
			cin >> id_estudiante;
			update = id_estudiante;
			const char* u = update.c_str();
			q_estado = mysql_query(cn.getConectar(), u);
			if (!q_estado) {
				cout << "Datos actualizados" << endl;
			}
			else {
				cout << "Error al actualizar" << endl;
			}
		}
		else {
			cout << "Error al conectar" << endl;
		}
		cn.cerrar_conexion();

	}

	//inicia eliminar

	void eliminar()
	{

		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string t = to_string(telefono);
			string delete_ = "DELETE FROM Estudiantes WHERE id_estudiante=";
			string id_estudiante;
			cout << "Ingrese el id del estudiante que desea eliminar" << endl;
			cin >> id_estudiante;
			delete_ += id_estudiante;
			const char* d = delete_.c_str();
			q_estado = mysql_query(cn.getConectar(), d);
			if (!q_estado) {
				cout << "se elimino correctamente" << endl;
			}
			else {
				cout << "Error al eliminar" << endl;
			}
		}
		else {
			cout << "Error al conectar" << endl;
		}
		cn.cerrar_conexion();
	}

};