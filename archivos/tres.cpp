#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main() {
  //declaramos al vector
  vector<string> registros;
  string linea;
  ifstream archivo("data.txt");
  //recorremos el archivo
  if(archivo.is_open()){
      while(getline(archivo,linea)){
        //llenamos el vector con la info
        registros.push_back(linea);
      }
      archivo.close();
  } else {
      cout << "No se puede leer"<< endl; 
  }
  // creamos el menu 
  int opcion;
  do{
   int elemento_eliminar;
   cout<< " ************************* " << endl;
   cout<< "  \t Operaciones " << endl;
   cout<< "1. Mostrar registros" << endl;
   cout<< "2. Eliminar  registros" << endl;
   cout<< "3. Salir " << endl;
   cout<< " ************************* " << endl;
   cout << "Opcion: " ;
   cin>> opcion; 

   switch(opcion){
      case 1:
         cout<< "Listado" << endl;
          //creamos un iterador y recorremos el vector       
          for(vector<string>::iterator it=registros.begin(); it != registros.end(); ++it){
              cout << *it << '\n';
          }
              cout<< "------------------------"<< endl; 
          break;
          
      case 2:
         cout<< " El vector tiene " << registros.size() << " elementos"<< endl;
         cout<< "Cual registro deseas eliminar: ";
         cin>> elemento_eliminar;
         if(elemento_eliminar <= registros.size()){
            //le asignamos el elemento de la posición final
            registros.at((elemento_eliminar-1))=registros.back();
            //eliminamos el ultimo registro
            registros.pop_back();
            //mostramos nuevamente los registros
            for(vector<string>::iterator it=registros.begin(); it != registros.end(); ++it){
                 cout << *it << '\n';
            }
            cout<< "------------------------"<< endl; 
            break;

         }else {
            cout << "No se encuentra ese elemento"<< endl; 
            cout<< "------------------------"<< endl; 
            break; 
         }      
   }
  }while(opcion!=3);

	return 0;
}