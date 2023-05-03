# include <iostream>
#include <stdlib.h>


using namespace std;

class Personaje {

    private:
    string nombre;
    string tipo;
    int niveldepelea;
    string ubicacion;

    public:
        void setNombre(string n){
            nombre = n;
            }
        void setTipo(string t){
            tipo = t;
            }
        void setNiveldepelea(int ndp){
            niveldepelea = ndp;
            }
        void setUbicacion(string u){
            ubicacion = u;
            }
        string getNombre(){
            return nombre;
            }
        string getTipo(){
            return tipo;
            }
        int getNiveldepelea(){
            return niveldepelea;
            }
        string getUbicacion(){
            return ubicacion;
            }
};
class Cambios{

    private:

        int size;
        Personaje *p;

    public:

        Cambios(){
            this -> size = 0;
            this -> p = new Personaje[0];
        }

        Cambios(Personaje arr[], int size){
            this -> size = size;
            this -> p = new Personaje[size];
            for (int i = 0; i < size; i++){
                p[i] = arr[i];
            }
        }

        void resize(int &size, int n){
            size+= n;
            Personaje *arr = new Personaje[size];
            for (int i = 0; i < size; i++){
                arr[i] = p[i];
            }
            delete[] p;
            p = arr;
        }


        void insertLast(Personaje p1){
            resize(size, 1);
            p[size-1] = p1;
        }

        void insert(Personaje p1, int pos){
            resize(size, 1);
            for(int i = size-1; i > pos; i--){
                p[i] = p[i-1];
            }
            p[pos] = p1;
        }

        void remove(int pos){
            if(pos >= 0 && pos < size){
                for(int i = pos; i < size; i++){
                    p[i] = p[i+1];
                }
            }
            resize(size, -1);
        }
         void imprimir(){
            for(int i = 0; i < size; i++){
                cout << "Personaje N " << i+1 << ":" << endl;
                cout<<"Su nombre es: "<<p[i].getNombre()<<","<<" es de tipo: "<<p[i].getTipo() <<","<<" tiene: "<<p[i].getNiveldepelea() <<" de nivel de pelea y se ubica en: "<<p[i].getUbicacion() <<"."<<endl;
            }
        }
};
int main()
{
    Personaje per1,per2,per3,per4;
    string nombre1,nombre2,nombre3,nombre4;
    string tipo1, tipo2,tipo3,tipo4;
    int ndp1,ndp2,ndp3,ndp4;
    string ubi1,ubi2,ubi3,ubi4;
    Personaje arr[] = {per1, per2};
    Cambios A(arr, 2);

    cout<<"Comenzaremos este proyecto con 2 personajes: "<<endl;

    cout<<"Ingrese los datos del primer personaje: "<<endl;
    cout<<"Nombre: ";cin>>nombre1;
    cout<<"Tipo: ";cin>>tipo1;
    cout<<"Nivel de pelea: ";cin>>ndp1;
    cout<<"Ubicacion: ";cin>>ubi1;
    cout<<"Personaje creado!!!"<<endl;

    cout<<"Ingrese los datos del segundo personaje: "<<endl;
    cout<<"Nombre: ";cin>>nombre2;
    cout<<"Tipo: ";cin>>tipo2;
    cout<<"Nivel de pelea: ";cin>>ndp2;
    cout<<"Ubicacion: ";cin>>ubi2;
    cout<<"Personaje creado!!!"<<endl;

    per1.setNombre(nombre1);
    per1.setTipo(tipo1);
    per1.setNiveldepelea(ndp1);
    per1.setUbicacion(ubi1);

    per2.setNombre(nombre2);
    per2.setTipo(tipo2);
    per2.setNiveldepelea(ndp2);
    per2.setUbicacion(ubi2);

    cout<<"Mostrando lista de Personajes: " << endl;
    A.imprimir();

    cout<<"Agregamos un personaje con nuestra funcion insertLast: ";
    cout<<"Ingrese los datos del tercer personaje: "<<endl;
    cout<<"Nombre: ";cin>>nombre3;
    cout<<"Tipo: ";cin>>tipo3;
    cout<<"Nivel de pelea: ";cin>>ndp3;
    cout<<"Ubicacion: ";cin>>ubi3;
    cout<<"Personaje creado!!!"<<endl;

    per3.setNombre(nombre3);
    per3.setTipo(tipo3);
    per3.setNiveldepelea(ndp3);
    per3.setUbicacion(ubi3);
    A.insertLast(per3);
    cout<<"Imprimiendo el nuevo arreglo: " << endl;
    A.imprimir();

    int pos;
    cout<<"Ahora usaremos el remove, escoga la posicion: ";
    cin>>pos;
    A.remove(pos-1);
    cout<<"Arreglo actualizado: " << endl;
    A.imprimir();

    int pos1;
    cout<<"Agregamos un personaje con nuestra funcion insert: ";
    cout<<"Ingrese los datos del cuarto personaje: "<<endl;
    cout<<"Nombre: ";cin>>nombre4;
    cout<<"Tipo: ";cin>>tipo4;
    cout<<"Nivel de pelea: ";cin>>ndp4;
    cout<<"Ubicacion: ";cin>>ubi4;
    cout<<"Personaje creado!!!"<<endl;
    cout<<"Ingrese la posicion para colocar al personaje: ";
    cin>> pos1;

    per4.setNombre(nombre4);
    per4.setTipo(tipo4);
    per4.setNiveldepelea(ndp4);
    per4.setUbicacion(ubi4);
    A.insert(per4,pos1-1);
    cout<<"Imprimiendo arreglo final: " << endl;
    A.imprimir();

    return 0;
}
