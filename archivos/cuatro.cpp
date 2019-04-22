#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main() {
  //declaramos al vector
  vector<string> registros;
  //declaramos vectos de lista borrados
  vector<int> lista_borrados;
  string linea;
  ifstream archivo("data.txt");
  //recorremos el archivo
  if(archivo.is_open()){
      while(getline(archivo,linea)){
        //llenamos el vector con la info
        registros.push_back(linea);
      }
      archivo.close();
  } else {   cout << "No se puede leer"<< endl;   }
  //creamos el menu
  int opcion;
  do{
   int elemento_eliminar;
   char elemento_nuevo[100];
   cout<< " ************************* " << endl;
   cout<< "  \t Operaciones " << endl;
   cout<< "1. Mostrar registros" << endl;
   cout<< "2. Eliminar  registros" << endl;
   cout<< "3. Ingresar nuevo registro " << endl;
   cout<< "4. Mostrar Posiciones Borrados " << endl;
   cout<< "5. Salir " << endl;
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
                //le ponemos una marca en vez de borrarlo, le ponemos el -1 como empieza de cero
                registros.at((elemento_eliminar-1))="************";

                //Añadismos la posicion a la lista libre de borados
                lista_borrados.push_back(elemento_eliminar-1);

                //volvemos a mostrar los registros
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
        case 3:
            cout<< "Ingrese nuevo registro: ";
            cin >> elemento_nuevo;          
            if(!lista_borrados.empty()){
                //obtenemos la cabeza de la lista borrados (la posicion)
                //Actualimoz el registro con esa posicion
                registros.at(lista_borrados.front())=elemento_nuevo;
                //borramos la cabeza de lista borrados
                lista_borrados.erase(lista_borrados.begin());

                break;
             }else{
                //agregamos el nuevo elemento al final
                registros.push_back(elemento_nuevo);
                break;
             }
        case 4:
              //volvemos a mostrar los registros
              for(vector<int>::iterator it=lista_borrados.begin(); it != lista_borrados.end(); ++it){
                   cout << *it << '\n';
              }
              cout<< "------------------------"<< endl; 
              break;

   }


  }while(opcion!=5);

	return 0;
}