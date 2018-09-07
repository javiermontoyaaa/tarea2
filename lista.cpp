#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

struct Libro{
    char titulo[64];
    int anioDePublicacion;
    Libro *siguiente;
    Libro *anterior;
};

void lanzarMenu();
Libro* crearNodo(char titulo[], int anioDePublicacion);
Libro* buscarNodo(Libro* actual, char titulo[]);
void actualizarNodo(Libro* actual, char titulo[], int anioDePublicacion);
void eliminarNodo(Libro* actual);
void imprimirLista(Libro* actual);

Libro* raiz;
Libro* actual;
Libro* ultimo;
int main(){
    int opcion, anioDePublicacion;
    char titulo[64];
    raiz = NULL;
    ultimo = NULL;

    lanzarMenu();
    cin>>opcion;
    
    while(opcion >= 1 && opcion < 6){
        switch(opcion){
            case 1:
            cout<<"Introduce el titulo: "<<endl;
            cin>>titulo;
            cout<<"Introduce la fecha de publicacion: "<<endl;
            cin>>anioDePublicacion;

            actual = crearNodo(titulo, anioDePublicacion);
            if(raiz == NULL){
                raiz = actual;
            }else{
                ultimo->siguiente = actual;
                actual->anterior = ultimo;
            }
            ultimo = actual;
            break;
            case 2:
            cout<<"Introduce el nombre del libro a buscar: "<<endl;
            cin>>titulo;
            actual = buscarNodo(raiz, titulo);
            if(actual == NULL){
                cout<<"El elemento no existe"<<endl;
            }else{
                cout<<"Titulo del libro: "<<actual->titulo<<endl;
                cout<<"Fecha de publicacion: "<<actual->anioDePublicacion<<endl;
            }
            break;
            case 3:
            cout<<"Introduce el nombre del libro a actualizar: "<<endl;
            cin>>titulo;

            actual = buscarNodo(raiz, titulo);
            if(actual == NULL){
                cout<<"El elemento no existe"<<endl;
            }else{
                cout<<"Introduce el titulo: "<<endl;
                cin>>titulo;
                cout<<"Introduce la fecha de publicacion: "<<endl;
                cin>>anioDePublicacion;
                actualizarNodo(actual, titulo, anioDePublicacion);
            }
            break;
            case 4:
            cout<<"Introduce el nombre del libro a eliminar"<<endl;
            cin>>titulo;
            
            actual = buscarNodo(raiz, titulo);
            if(actual == NULL){
                cout<<"El elemento no existe"<<endl;
            }else{
                eliminarNodo(actual);
            }
            break;
            case 5:
            if(raiz == NULL){
                cout<<"Lista vacia"<<endl;
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
    cout<<"\t\t\tLista doblemente enlazada"<<endl;
    cout<<"1.-Crear nodo"<<endl;
    cout<<"2.-Buscar nodo"<<endl;
    cout<<"3.-Actualizar nodo"<<endl;
    cout<<"4.-Eliminar nodo"<<endl;
    cout<<"5.-Imprimir lista"<<endl;
    cout<<"6.-Salir"<<endl;
    cout<<"Introduce una opcion:"<<endl;
}

Libro* crearNodo(char titulo[], int anioDePublicacion){
    Libro *actual = (Libro*) malloc(sizeof(Libro));
    strcpy(actual->titulo, titulo);
    actual->anioDePublicacion = anioDePublicacion;
    actual->siguiente = NULL;
    actual->anterior = NULL;

    return actual;
}

Libro* buscarNodo(Libro* actual, char titulo[]){
    Libro* temp = NULL;

    while(actual != NULL){
        if(strcmp(actual->titulo, titulo) == 0){
            temp = actual;
            break;
        }else{
            actual = actual->siguiente;
        }
    }

    return temp;
}

void actualizarNodo(Libro* actual, char titulo[], int anioDePublicacion){
    strcpy(actual->titulo, titulo);
    actual->anioDePublicacion = anioDePublicacion;
    cout<<"Actualizado!"<<endl;
}

void eliminarNodo(Libro* actual){
    Libro* tempA = actual->anterior;
    Libro* tempS = actual->siguiente;

    if(tempA != NULL && tempS == NULL){
        tempA->siguiente = NULL;
        ultimo = tempA;
        delete actual;
    }else if(tempA == NULL && tempS != NULL){
        tempS->anterior = NULL;
        raiz = tempS;
        delete actual;
    }else if(tempA == NULL && tempS == NULL){
        raiz = NULL;
        delete actual;
    }else{
        tempA->siguiente = tempS;
        tempS->anterior = tempA;
        delete actual;
    }
}

void imprimirLista(Libro* actual){
    while(actual != NULL){
        cout<<"Titulo: "<<actual->titulo<<endl;
        cout<<"Fecha de publicacion: "<<to_string(actual->anioDePublicacion)<<endl;
        actual = actual->siguiente;
    }
}