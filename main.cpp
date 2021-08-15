#include <iostream>
using namespace std;
const int x = 4;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void dijkstra(int arreglo[][x], int);
void presentar(int dist[]);
int distancia_min(int dist[], bool sptSet[]);
int mayor = 2000000000;
void proceso(int array[x][x]);
int main(int argc, char** argv) {
	int op;
	int arreglo[4][4];
	do{
        cout<<"Menu"<<endl;
        cout<<"1) Iniciar"<<endl;
		cout<<"0) Salir"<<endl; cin>>op;
        cout<<endl;
        switch(op){
        	case 1: 
	        		proceso(arreglo);
					break;
			case 0: 
				op=-1; 
				break; 
			default: 	
			cout<<"Opcion no valida"<<endl;
			break;
        }
    }while(op!=-1);
	return 0;
}
void dijkstra(int arreglo[x][x], int src){
    int distancia[x]; 
    bool value[x]; // value[i] sera verdadero si el vertice i esta en el mas corto will be true if vertex 
    
    for (int i = 0; i < x; i++){
        distancia[i] = mayor, value[i] = false;
	}
    distancia[src] = 0; // distancia desde el inicio, siempre es 0
    
    // Encontrar el camino mas corto
    for(int z = 0; z<x-1; z++){
    	int i = distancia_min(distancia, value);
        value[i] = true; // marcamos como ya evaluado
 		cout<<"valor z "<<z<< endl;
        for (int j = 0; j < x; j++){
        	if (!value[j] && arreglo[i][j] && distancia[i] != mayor && distancia[i] + arreglo[i][j]<distancia[j])
                distancia[j] = distancia[i] + arreglo[i][j];
		}           
    }
    presentar(distancia);
}
void presentar(int dist[]){
    cout<<"  Vertice               Distancia desde el inicio" << endl;
    for (int i = 0; i < x; i++)
        cout<<"  "<<i<<"                        "<<dist[i]<< endl;
}
int distancia_min(int dist[], bool value[]){
	int min = mayor, menor;
 
    for (int v = 0; v < x; v++){
        if (value[v] == false && dist[v] <= min){
            min = dist[v], menor = v;
		}
	}
    return menor; // retorna el valor menor
}
void proceso(int array[x][x]){
	
	for(int i  = 0; i<x; i++){
		for(int j = 0; j <x; j++){
			cout<<"Ingrese el numero, ira pos: "<<i<<" "<<j<<endl;
			cin>>array[i][j];
		}
	}
	for(int i  = 0; i<x; i++){
		cout<<"Vertice "<<i<<" = ";
		for(int j = 0; j <x; j++){
			cout<<array[i][j]<<" ";
		}cout<<endl;
	}
	cout<<"El arreglo mostrado es el correcto/ esperado? "<<endl;
	cout<<"Ingrese 1, Si, es el correcto"<<endl;
	cout<<"Ingrese 2, No, quiero ingresar de nuevo"<<endl;
	int value2;
	cin>>value2;
	int value3;
	switch (value2){
		case 1: cout<<"Sea el inicio desde el vertice 0 "<<endl; 
				dijkstra(array, 0);
				cout<<"Desea cambiar el vertice de inicio?"<<endl;
				cout<<"Ingrese 1, Si, deseo cambiarlo"<<endl;
				cout<<"Ingrese 2, No, desde el 0 esta bien"<<endl;
				cin>>value3;
				switch(value3){
					case 1:	cout<<"Ingrese el nuevo valor del vertice"<<endl;
							int vertix;
							cin>> vertix;
							dijkstra(array, vertix);
							break;
					case 2: cout<<"Buen dia"<<endl;
							break;
					default: cout<<"Ingrese una numeracion de la indicada"<<endl;
				}
				break;
				
		case 2: proceso(array);
				break;
		default: cout<<"Ingrese una numeracion de la indicada"<<endl;
				break;
	}
}
