#include <iostream>
using namespace std;

void invertirFechaMenu(int& fechaMenu, float& dia, float& mes, float& anio){

    anio = fechaMenu / 10000;
    mes = (fechaMenu % 10000) / 100;
    dia = fechaMenu % 100;

    return;
}

void menuMayor(int& cantMenu, int& cantPersonas, int& fechaMenu, int& fecha){

    if(cantPersonas > cantMenu){
                
        cantMenu = cantPersonas;
        fechaMenu = fecha;
    }

    return;
}

void elegirMenu(int& fechaMenu1, int& fechaMenu2, int& cantidadMenu1, int& cantidadMenu2, int& cantidad, int& fecha){

    int opcion;

    cout << "1)Menú 1: " << endl;
    cout << "2)Menú 2: " << endl;
    cout << "Que opción de menú quiere?: ";
    cin >> opcion;
     
    switch(opcion){

        case 1: menuMayor(cantidadMenu1, cantidad, fechaMenu1, fecha);
        break;
        case 2: menuMayor(cantidadMenu2, cantidad, fechaMenu2, fecha);
        break;
    }

    return;
}

void invertirFechaPersonas(int& fechaMayorPersonas, float& diaMayorPersonas, float& mesMayorPersonas, float& anioMayorPersonas){
    
    anioMayorPersonas = fechaMayorPersonas / 10000;
    mesMayorPersonas = (fechaMayorPersonas % 10000) / 100;
    diaMayorPersonas = (fechaMayorPersonas % 100);

    return;
}

void cantidadDePersonas(int& cantidadMayor, int& fecha, int& fechaMayorPersonas, float& totalPersonas, int& cantidad, int& cantidadFiestas){
    
    cout << "Ingrese la cantidad de personas que asistirán a la fiesta: ";
    cin >> cantidad;

    if(cantidad > cantidadMayor){
        cantidadMayor = cantidad;
        fechaMayorPersonas = fecha;
    }

    totalPersonas = totalPersonas + cantidad;; 

    cantidadFiestas = cantidadFiestas + 1;

    return;
}

void tipoDeFiesta(int& fiestaC, int& fiestaS, int& fiestaO){

    char tipo;

    cout << "Ingrese el tipo de fiesta a realizar - 'C' - 'S' - 'O': ";
    cin >> tipo; 

    if (tipo == 'C'){
       fiestaC = fiestaC + 1;
    }

    if(tipo == 'S'){
        fiestaS = fiestaS + 1;
    }

    if(tipo == 'O'){
        fiestaO = fiestaO + 1;
    }

    return;
}

int ingresarFecha(int fecha, string mensaje){

    cout << mensaje;
    cin >> fecha;

    return fecha;
}

int main(){

   int fecha, fechaMayorPersonas = 0, fiestaC = 0, fiestaS = 0, fiestaO = 0, cantidad, cantidadMayor = 0;
   int cantidadFiestas = 0;
   float totalPersonas = 0;
   int fechaMenu1, fechaMenu2, cantidadMenu1 = 0, cantidadMenu2 = 0;
   float diaMenu1, mesMenu1, anioMenu1, diaMenu2, mesMenu2, anioMenu2;
   float diaMayorPersonas, mesMayorPersonas, anioMayorPersonas;
   float promedioTotalPersonas = 0;

   fecha = ingresarFecha(fecha, "Ingrese la fecha de la fiesta (AAAA/MM/DD): ");

   while(fecha > 0){

       tipoDeFiesta(fiestaC, fiestaS, fiestaO);
     
       cantidadDePersonas(cantidadMayor, fecha, fechaMayorPersonas, totalPersonas, cantidad, cantidadFiestas);

       invertirFechaPersonas(fechaMayorPersonas, diaMayorPersonas, mesMayorPersonas, anioMayorPersonas);
       
       elegirMenu(fechaMenu1, fechaMenu2, cantidadMenu1, cantidadMenu2, cantidad, fecha);

       cout << endl;

       fecha = ingresarFecha(fecha, "Ingrese la fecha de la fiesta (AAAA/MM/DD): ");
    }

    invertirFechaMenu(fechaMenu1, diaMenu1, mesMenu1, anioMenu1);
    invertirFechaMenu(fechaMenu2, diaMenu2, mesMenu2, anioMenu2);

    promedioTotalPersonas = (totalPersonas / cantidadFiestas);

    cout << endl;
    cout << "Total de fiestas C: " << fiestaC << endl;
    cout << "Total de fiestas S: " << fiestaS << endl;
    cout << "Total de fiestas O: " << fiestaO << endl;
    cout << "La fiesta con mayor cantidad de personas es el: " << diaMayorPersonas << "/" << mesMayorPersonas << "/" << anioMayorPersonas << endl;
    cout << "La fiesta con mayor cantidad de menu 1 es el: " << diaMenu1 << "/" << mesMenu1 << "/" << anioMenu1 << endl;
    cout << "La fiesta con mayor cantidad de menu 2 es el: " << diaMenu2 << "/" << mesMenu2 << "/" << anioMenu2 << endl;
    cout << "El promedio de personas es de " << promedioTotalPersonas << " personas por fiesta" << endl;

    return 0;
}
