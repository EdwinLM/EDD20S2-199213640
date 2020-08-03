#include <iostream>
using namespace std;

// Estructura del Nodo del Estudiante
struct nodo{
       int carnet;
       string nombre;
       struct nodo *siguiente;
};

typedef struct nodo *Tlista;

// Procedimiento que Inserta un Estudiante en la Lista Simple
void insertar(Tlista &lista, int carnet, string nombre)
{
    Tlista t, q = new(struct nodo);
 
    q->carnet = carnet;
    q->nombre = nombre;
    q->siguiente = NULL;
 
    if(lista==NULL)
    {
        lista = q;
    }
    else
    {
        t = lista;
        while(t->siguiente!=NULL)
        {
            t = t->siguiente;
        }
        t->siguiente = q;
    }
}

// Procedimiento que Busca un Estudiante en la Lista Simples
void buscar(Tlista lista, int carnet)
{
    Tlista q = lista;
    int i = 1, encontrado = 0;
 
    while(q!=NULL)
    {
        if(q->carnet==carnet)
        {
            cout<<endl<<" Encontrado en posicion "<< i <<endl;
            cout<<endl<< q->nombre <<endl;
            encontrado = 1;
        }
        q = q->siguiente;
        i++;
    }
 
    if(encontrado==0)
        cout<<"\n\n Estudiante no encontrado..!"<< endl;
}

// Procedimiento que Lista todos los Estudiantes en la Lista Simple
void listado(Tlista lista)
{
     int i = 0;
 
 	 if (lista!=NULL)
 	 {
	
    	 while(lista != NULL)
	     {
    	      cout <<' '<< i+1 <<") " << lista->carnet << " - " << lista->nombre << endl;
        	  lista = lista->siguiente;
	          i++;
    	 }
	}
	else
        cout<<" Lista vacia..!";
}

// Procedimiento que Elimina un Estudiante en la Lista Simple
void eliminar(Tlista &lista, int carnet)
{
    Tlista p, ant;
    p = lista;
 
    if(lista!=NULL)
    {
        while(p!=NULL)
        {
            if(p->carnet==carnet)
            {
                if(p==lista)
                    lista = lista->siguiente;
                else
                    ant->siguiente = p->siguiente;
 
                cout << "Estudiante: " << p->nombre << " ha sido eliminado." << endl;
				delete(p);
                return;
            }
            ant = p;
            p = p->siguiente;
        }
    }
    else
        cout<<" Lista vacia..!";
}

// Menú Principal del Programa
void menu()
{
    cout<<"\n\t\tLISTA ENLAZADA SIMPLE\n\n";
    cout<<" 1. INSERTAR ESTUDIANTE "<<endl;
    cout<<" 2. BUSCAR ESTUDIANTE   "<<endl;
    cout<<" 3. ELIMINAR ESTUDIANTE "<<endl;
	cout<<" 4. LISTADO DE ESTUDIANTES "<<endl;
    cout<<" 5. SALIR               "<<endl;
 
    cout<<"\n INGRESE OPCION: ";
}

// Procedimiento que pide presionar una tecla para continuar
void pausa()
{
  string tecla = "";
  cout << "\n\nPresione una tecla para continuar...";
  getline(cin, tecla);
}

// Procedimiento Principal del Programa
int main ()
{
    Tlista lista = NULL;
    int op;     // Opción del menú
    int carnet;  // Carnet a ingresar
    string nombre = ""; // Nombre a ingresar
 
    system("color 0b");
 
    do
    {
        menu();  cin>> op; cin.ignore();
 
        switch(op)
        {
            case 1:
                 cout<< "\n CARNET DEL ESTUDIANTE: "; cin>> carnet; cin.ignore();
                 cout<< "\n NOMBRE DEL ESTUDIANTE: ";
				 getline(cin, nombre);
                 insertar(lista, carnet, nombre);
            break;
 
            case 2:
                 cout<< "\n CARNET DEL ESTUDINTE A BUSCAR: "; cin>> carnet; cin.ignore();
                 buscar(lista, carnet);
            break;
 
            case 3:
                cout<<"\n CARNET DEL ESTUDIANTE A ELIMINAR: "; cin>> carnet; cin.ignore();
                eliminar(lista, carnet);
            break;
 
            case 4:
                listado(lista);
            break;
 
        }
 
        cout<<endl<<endl;
        pausa();
 
    }while(op!=5);
 
 
   pausa();
   return 0;
}
