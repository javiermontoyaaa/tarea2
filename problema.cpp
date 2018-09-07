#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

struct Persona{
    char nombre[64];
    Persona* siguiente;
};

void lanzarMenu();
Persona* crearNodo(char nombre[]);
Persona* obtenerGanador(int saltos);
void imprimirLista(Persona* actual);

Persona* raiz;
Persona* actual;
Persona* ultimo;

int main(){
    int opcion, saltos;
    char nombre[64];
    raiz = NULL;
    ultimo = NULL;

    lanzarMenu();
    cin>>opcion;

    while(opcion >= 1 && opcion < 5){
        switch(opcion){
            case 1:
            cout<<"Introduce el nombre de la persona: "<<endl;
            cin>>nombre;

            actual = crearNodo(nombre);
            if(raiz == NULL){
                raiz = actual;
            }else{
                ultimo->siguiente = actual;
            }
            ultimo = actual;
            ultimo->siguiente = raiz;
            break;
            case 2:
            cout<<"Introduce el numero de saltos: "<<endl;
            cin>>saltos;
            break;
            case 3:
            if(raiz == NULL){
                cout<<"Lista vacia"<<endl;
            }else if(ultimo == raiz){
                cout<<"Nodo unico: "<<endl;
                imprimirLista(raiz);
            }else{
                actual = obtenerGanador(saltos);
                cout<<"\t\t\tGanador"<<endl;
                imprimirLista(actual);
            }
            break;
            case 4:
            if(raiz == NULL){
                cout<<"La lista esta vacia"<<endl;
            }else{
                imprimirLista(raiz);
            }
            break;
        }

        lanzarMenu();
        cin>>opcion;
    }
    
    return 0;
}

void lanzarMenu(){
    cout<<"\t\t\tProblema de Flavio Josefo"<<endl;
    cout<<"1.-Introducir persona"<<endl;
    cout<<"2.-Introducir el numero de saltos"<<endl;
    cout<<"3.-Obtener al ganador"<<endl;
    cout<<"4.-Imprimir lista"<<endl;
    cout<<"5.-Salir"<<endl;
    cout<<"Introduce una opcion: "<<endl;
}

Persona* crearNodo(char nombre[]){
    Persona* temp = (Persona*)malloc(sizeof(Persona));
    strcpy(temp->nombre, nombre);
    temp->siguiente = NULL;

    return temp;
}

Persona* obtenerGanador(int saltos){
    Persona* temp = NULL;
    Persona* ganador;
    int i = 0;

    while(ultimo != raiz){
        while(i < saltos){
            raiz = raiz->siguiente;
            ultimo = ultimo->siguiente;
            i++;
        }
        temp = raiz;
        raiz = raiz->siguiente;
        ultimo->siguiente = raiz;
        delete temp;
        i = 0;
    }
    ganador = raiz;
    return ganador;
}

void imprimirLista(Persona* actual){
    do{
        cout<<"Nombre de la persona: "<<actual->nombre<<endl;
        actual = actual->siguiente;
    }while(actual != raiz);
}