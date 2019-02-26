
#include <list>
#include <iostream>
#include <string>
using namespace std;


class Cancion{
    public:
    //constructor
    Cancion(int posicionlista,string autorcancion,string nombreCancion);
    
   
    
    
    void imprimirCancion();
    private:

    string autorCancion;
    string nombreCancion;
    int posicionLista;
   
}
;
Cancion::Cancion(int posicionlista,string autorcancion,string nombrecancion)
{
        posicionLista = posicionlista;
        nombreCancion = nombrecancion;
        autorCancion  = autorcancion;
        
}
void Cancion::imprimirCancion()
{
    printf("%d,%s,%s\n",posicionLista,nombreCancion.c_str(),autorCancion.c_str());
}

class ListaExito{
    public:
   
    list<Cancion>::iterator encontrarCancion(const Cancion & cancion);
    //encuentra una cancion y devuelve el iterador donde la encontro.
    void agregarCancion();
    void borrarCancion(list<Cancion>::iterator indice);
    void imprimirListaExito();
    bool verificarContenido();
    private:
    list<Cancion> listaCanciones;
};
void ListaExito::imprimirListaExito()
{
    for(Cancion item :listaCanciones)
    {
        item.imprimirCancion();
    }
    cout<< "___________________________"<<endl;
    cout<<endl;
}
void ListaExito::agregarCancion()
{   string nombreCancionTmp;
    string autorCancionTmp;
    int posicionListaTmp;
    cout<< endl;
    cout<<"Menu crear cancion"<<endl;
    cout<<"ingrese nombre cancion:";
    cin>>nombreCancionTmp;
    cout<<endl;
    cout<<"ingrese autor de la cancion:";
    cin>>autorCancionTmp;
    cout<<endl;
    cout<<"ingrese posicion en el ranking:";
    cin>>posicionListaTmp;
    Cancion cancionTmp(posicionListaTmp,autorCancionTmp,nombreCancionTmp);

    listaCanciones.push_back(cancionTmp);
}
bool ListaExito::verificarContenido()
{
    
    if(!listaCanciones.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

//funcion encontrarCancion para poder borrar
/*
list<Cancion>::iterator ListaExito::encontrarCancion(const Cancion & cancion) 
{  
    list<Cancion>::iterator I;  
    for(I = listaCanciones.begin(); I != listaCanciones.end(); I++)  
    {    
        if( *I == cancion )
        {
            return I; // devuelve el indice o iterador donde esta la cancion en la lista
        }
    }
    return I = NULL; // no existe
}
*/


void imprimirMenu()
{
    cout<<"___MENU OPCIONES_____"<<endl;
    cout<<"1 para agregar cancion"<<endl<<
            "2 para borrar cancion"<<endl<<
            "0 para salir."<<endl;
}

int main()
{

    ListaExito miLista;
    int salida;
    int opcion;
    cout<<"BIENVENIDO"<<endl;
    do{
        imprimirMenu();
        cout<<"ingrese una opcion valida:"<<endl;
        scanf("%d",&opcion);
        switch (opcion){
            case 1:
                miLista.agregarCancion();
                break;
            case 2:
                break;
            case 0:
                cout<<"ha salido de la aplicacion...\n";
                salida = 0;
                break;
            default:
                cout<<"opcion invalida";
                salida = 0;
                break;
        }


        if( miLista.verificarContenido())
        {
            cout<<"_______________________________"<<endl;
            cout<<"LISTA ACTUALIZADA  TOP 50."<<endl;
            cout<<"TOP|NOMBRE|AUTOR"<<endl;
            miLista.imprimirListaExito();

        }
        else
        {
            printf("No se ha agregado ninguna Cancion\n");
        }



    }while(salida != 0);



    

   


}



