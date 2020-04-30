/*	EJERCICIO #2	*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

void venta();
void reporte();

using namespace std;

struct ventas{
	string zona;
	char identi;
	string socio;
	float descuento;
	float precio;
	int nvoletos;
	float totalvta;
};

int main(){
	
	venta();
	reporte();
	
	return 0;
}
	
void venta(){
	string zona;
	char identi;
	char socio;
	float descuento;
	float precio;
	int nentradas;
	float totalvta;
	string s;
	cout<<"______________________________________"<<"\n"<<"\n";
	cout<<"	VENTA DE BOLETOS	"<<"\n";
	cout<<"______________________________________"<<"\n"<<"\n";
	cout<<"	TIPOS DE BOLETOS "<<"\n"<<"\n";
	cout<<"	VIP	= V " <<endl;
	cout<<"	PLATEA	= P "<<endl;
	cout<<"	POPULAR	= E "<<endl<<"\n";
	cout<<"Ingresa el boleto que deseas: ";
	cin>>identi;
	cout<<"Cantidad de entradas a comprar: ";
	cin>>nentradas;	
	cout<<"¿Usted es socio? Si = S | No = N : ";
	cin>>socio;
	cout<<"______________________________________"<<"\n"<<"\n";
	
	if (nentradas >= 3 || nentradas <= 6 ){
		switch(identi){
			case 'V':
					descuento = 0.05;
					precio = 350.00;
					totalvta = (precio - (descuento * precio) )* nentradas;
			break;
			case 'P':
					descuento = 0.05;
					precio = 130.00;
					totalvta = (precio - (descuento * precio) )* nentradas; 
			break;
			case 'E':
					descuento = 0.05;
					precio = 50.00;
					totalvta = (precio - (descuento * precio) )* nentradas;
			break;	
		}
	}
	else if (nentradas >= 7 || nentradas<=9 ){
		switch(identi){
			case 'V':
					descuento = 0.075;
					precio = 350.00;
					totalvta = (precio - (descuento * precio) )* nentradas;
			break;
			case 'P':
					descuento = 0.075;
					precio = 130.00;
					totalvta = (precio - (descuento * precio) )* nentradas; 
			break;
			case 'E':
					descuento = 0.075;
					precio = 50.00;
					totalvta = (precio - (descuento * precio) )* nentradas; 	
			break;	
		}
	} else if (nentradas > 9){
		switch(identi){
			case 'V':
					descuento = 0.10;
					precio = 350.00;
					totalvta = (precio - (descuento * precio) )* nentradas;
			break;
			case 'P':
					descuento = 0.10;
					precio = 130.00;
					totalvta = (precio - (descuento * precio) )* nentradas; 
			break;
			case 'E':
					descuento = 0.10;
					precio = 50.00;
					totalvta = (precio - (descuento * precio) )* nentradas; 	
			break;	
	}
}
	
	if(socio=='S'){
			descuento = 0.08;
			totalvta = totalvta * descuento;	
	}
	cout<<"______________________________________________________________________________________________________________________"<<"\n"<<"\n";
	cout<<"Tipo Zona: "<<identi<<"	Descuento: "<<descuento<<"	Precio: "<<precio<<"	Entradas: "<<nentradas<<"	Total de la venta: "<<totalvta<<"\n";
	cout<<"______________________________________________________________________________________________________________________"<<"\n"<<"\n";
	ofstream grabararchivo;
	try {
		grabararchivo.open("HT5_EJERCICIO_02.txt",ios::app);
		grabararchivo<<identi<<"\t"<<descuento<<"\t"<<precio<<"\t"<<nentradas<<"\t"<<totalvta<<endl;
		grabararchivo.close();
	}
	catch(exception X){
		cout<<"ERROR AL CARGAR EL ARCHIVO..."<<endl;
	}
	
	cout<<"__________________________________________"<<"\n"<<"\n";
	cout<<"	REGISTRO DE VENTAS"<<"\n";
	cout<<"__________________________________________"<<"\n"<<"\n";	
	cout<<"TIPO	DSC	PRC	ENT	TOTAL"<<endl;
	ifstream leerarchivo;
	cout<<"\n";
	try {
		leerarchivo.open("HT5_EJERCICIO_02.txt",ios::in);				
		while (getline(leerarchivo, s))
			cout<<s<<endl;		
		leerarchivo.close();
		
	cout<<"__________________________________________"<<"\n"<<"\n";
	}
	catch(exception X){
		cout<<"ERROR AL CARGAR EL ARCHIVO..."<<endl;
	}
	
}

void reporte(){
	ifstream db;
	float d,p,n,tv=0;
	char i;
	float sumatotal=0;
	float iV=0;
	float iP=0;
	float iE=0;	
	try{	
		db.open("HT5_EJERCICIO_02.txt",ios::in);
		
		while (db >>i >> d >>p>> n>>tv){
			sumatotal = tv + sumatotal;	
			if (i == 'V')
				iV+=tv;
			else if (i =='P')
				iP+=tv;
			else if (i =='E')
				iE+=tv;
		}	
		db.close();
		cout<<"______________________________________________________________"<<"\n"<<"\n";
		cout<<setprecision(5)<<"	TOTAL DE LAS VENTAS          "<<sumatotal<<endl;
		cout<<"______________________________________________________________"<<"\n"<<"\n";
		cout<<"	DETALLE DE BOLETOS  "<<"\n"<<"\n";
		cout<<setprecision(5)<<"  VIP "<<iV<<" - % sobre el total: "<<setprecision(3)<<iV*100/sumatotal<<endl;
		cout<<setprecision(5)<<"  PLATEA "<<iP<<" - % sobre el total: "<<setprecision(3)<<iP*100/sumatotal<<endl;
		cout<<setprecision(5)<<"  POPULAR "<<iE<<" - % sobre el total: "<<setprecision(3)<<iV*100/sumatotal<<endl;
		cout<<"______________________________________________________________"<<"\n"<<"\n";
	}
	catch (exception X){		
			cout<<"ERROR AL CARGAR EL ARCHIVO..."<<endl;			
			exit(1);
	}		
}
