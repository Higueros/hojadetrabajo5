/*	EJERCICIO 1	*/

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

void venta();
void reporte();

using namespace std;

struct terrenos{
	char categoria[30];
	char zona;
	int tipo;
	float precio, largo , ancho, area; 
	float total;
};

int main(){
	
	venta();
	reporte();
	
	return 0;
}

 void venta(){
	char categoria[30];
	char zona;
	int tipo;
	float precio, largo , ancho, area; 
	float total;
	
	cout<<"________________________________________________________"<<"\n"<<"\n";
	cout<<"			VENTA DE TERRENOS"<<"\n";
	cout<<"________________________________________________________"<<"\n"<<"\n";
	cout<<"Ingresa categoria: ";
	cin>>categoria;
	if(categoria[0] == 'r'){
		cout<<"Ingresa zona = | A | B | C | :";
		cin>>zona;
	}
	else{
		cout<<"Digite zona = | A | B | :  ";
		cin>>zona;
	}
	cout<<"Digite tipo = | 1. Terreno | 2. Casa | 3. Departamento | : ";
	cin>>tipo;
	cout<<"Digite largo del terreno: "; 
	cin>>largo;
	cout<<"Digite ancho del terreno: "; 
	cin>>ancho;
	cout<<"________________________________________________________"<<"\n"<<"\n";
	
	
	if(categoria[0]='c' && zona == 'A'){
		switch(tipo){
			case 1:
				precio = 2200; 
				total = (2200 * (largo*ancho)); 
			break;
			case 2:
				precio = 2500;
				total = (2500 * (largo*ancho)); 
			break;
			case 3:
				precio = 2100;
				total = (2100 * (largo*ancho));
			break;
		}
	}
	else if(categoria[0]=='c' && zona=='B'){
		switch(tipo){
			case 1:
				precio = 1300;
				total = (1300 * (largo*ancho));
			break;
			case 2:
				precio = 1500;
				total = (1500 * (largo*ancho)); 
			break;
			case 3:
				precio = 1200;
				total = (1200 * (largo*ancho));
			break;
		}
	}
	
	if(categoria[0]=='r' && zona=='A'){
		switch(tipo){
			case 1:
				precio = 2100;
				total = (2100 * (largo*ancho)); 
			break;
			case 2:
				precio = 2500;
				total = (2500 * (largo*ancho));
			break;
			case 3:
				precio = 2100;
				total = (2100 * (largo*ancho));
			break;
		}
	}
	else if(categoria[0]=='r' && zona=='B'){
		switch(tipo){
			case 1:
				precio = 1500;
				total = (1500 * (largo*ancho));
			break;
			case 2:
				precio = 1600;
				total = (1600 * (largo*ancho));
			break;
			case 3:
				precio = 1300;
				total = (1300 * (largo*ancho)); 
			break;
		}
	}
	else if(categoria[0]=='r' && zona=='C'){
		switch(tipo){
			case 1:
				precio = 1100;
				total = (1100 * (largo*ancho));
			break;
			case 2:
				precio = 1300;
				total = (1300 * (largo*ancho));
			break;
			case 3:
				precio = 1000;
				total = (1000 * (largo*ancho));
			break;
		}
	}

}

void reporte(){
	char categoria[30], zona;
	float tipo, precio, total ;

	cout<<"_______________________________________________"<<"\n"<<"\n";
	cout<<"		REPORTE DE VENTA	"<<"\n";
	cout<<"_______________________________________________"<<"\n"<<"\n";

	cout<<"	Precio x metro cuadrado: "<<precio<<endl;
	cout<<"	Total: "<<total<<endl;
	cout<<"_______________________________________________"<<"\n";
}
