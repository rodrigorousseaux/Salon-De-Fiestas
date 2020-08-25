#include <stdio.h>

void invertirFechaMenu(int *fechaMenu, int *dia, int *mes, int *anio){

    *anio = *fechaMenu / 10000;
    *mes = (*fechaMenu % 10000) / 100;
    *dia = *fechaMenu % 100;

    return;
}

void menuMayor(int *cantMenu, int *cantPersonas, int *fechaMenu, int *fecha){

    if(*cantPersonas > *cantMenu){
                
        *cantMenu = *cantPersonas;
        *fechaMenu = *fecha;
    }

    return;
}

void elegirMenu(int *fechaMenu1, int *fechaMenu2, int *cantidadMenu1, int *cantidadMenu2, int *cantidad, int *fecha){

    int opcion;

    printf("1)Menú 1: \n");
    printf("2)Menú 2: \n");
    printf("Que opción de menú quiere?: ");
    scanf("%i", &opcion);
     
    switch(opcion){

        case 1: menuMayor(&*cantidadMenu1, &*cantidad, &*fechaMenu1, &*fecha);
        break;
        case 2: menuMayor(&*cantidadMenu2, &*cantidad, &*fechaMenu2, &*fecha);
        break;
    }

    return;
}

void invertirFechaPersonas(int *fechaMayorPersonas, int *diaMayorPersonas, int *mesMayorPersonas, int *anioMayorPersonas){
    
    *anioMayorPersonas = *fechaMayorPersonas / 10000;
    *mesMayorPersonas = (*fechaMayorPersonas % 10000) / 100;
    *diaMayorPersonas = (*fechaMayorPersonas % 100);

    return;
}

void cantidadDePersonas(int *cantidadMayor, int *fecha, int *fechaMayorPersonas, float *totalPersonas, int *cantidad, int *cantidadFiestas){
    
    printf("Ingrese la cantidad de personas que asistirán a la fiesta: ");
    scanf("%i", &*cantidad);

    if(*cantidad > *cantidadMayor){
        *cantidadMayor = *cantidad;
        *fechaMayorPersonas = *fecha;
    }

    *totalPersonas += *cantidad;

    *cantidadFiestas += 1;

    return;
}

void tipoDeFiesta(int *fiestaC, int *fiestaS, int *fiestaO){

    char tipo;

    printf("Ingrese el tipo de fiesta a realizar - 'C' - 'S' - 'O': ");
    fflush(stdin);
    scanf("%c", &tipo); 

    if (tipo == 'C'){
       *fiestaC += 1;
    }

    if(tipo == 'S'){
        *fiestaS += 1;
    }

    if(tipo == 'O'){
        *fiestaO += 1;
    }

    return;
}

int ingresarFecha(int fecha){

    printf("Ingrese la fecha de la fiesta (AAAA/MM/DD): ");
    scanf("%i", &fecha);

    return fecha;
}

int main(){

   int fecha, fechaMayorPersonas = 0, fiestaC = 0, fiestaS = 0, fiestaO = 0, cantidad = 0, cantidadMayor = 0;
   int cantidadFiestas = 0;
   int diaMayorPersonas = 0, mesMayorPersonas = 0, anioMayorPersonas = 0;
   float totalPersonas = 0;
   int fechaMenu1 = 0, fechaMenu2 = 0, cantidadMenu1 = 0, cantidadMenu2 = 0;
   int diaMenu1 = 0, mesMenu1 = 0, anioMenu1 = 0, diaMenu2 = 0, mesMenu2 = 0, anioMenu2 = 0;
   float promedioTotalPersonas = 0;

   fecha = ingresarFecha(fecha);

   while(fecha > 0){

       tipoDeFiesta(&fiestaC, &fiestaS, &fiestaO);
     
       cantidadDePersonas(&cantidadMayor, &fecha, &fechaMayorPersonas, &totalPersonas, &cantidad, &cantidadFiestas);

       invertirFechaPersonas(&fechaMayorPersonas, &diaMayorPersonas, &mesMayorPersonas, &anioMayorPersonas);
       
       elegirMenu(&fechaMenu1, &fechaMenu2, &cantidadMenu1, &cantidadMenu2, &cantidad, &fecha);

       printf("\n");

       fecha = ingresarFecha(fecha);
    }

    invertirFechaMenu(&fechaMenu1, &diaMenu1, &mesMenu1, &anioMenu1);
    invertirFechaMenu(&fechaMenu2, &diaMenu2, &mesMenu2, &anioMenu2);

    promedioTotalPersonas = (totalPersonas / cantidadFiestas);

    printf("\n");
    printf("Total de fiestas C: %d\n", fiestaC);
    printf("Total de fiestas S: %d\n", fiestaS);
    printf("Total de fiestas O: %d\n", fiestaO);
    printf("La fiesta con mayor cantidad de personas es el: %d/%d/%d\n", diaMayorPersonas, mesMayorPersonas, anioMayorPersonas);
    printf("La fiesta con mayor cantidad de menu 1 es el: %d/%d/%d\n", diaMenu1, mesMenu1, anioMenu1);
    printf("La fiesta con mayor cantidad de menu 2 es el: %d/%d/%d\n", diaMenu2, mesMenu2, anioMenu2);
    printf("El promedio de personas por fiesta es de:  %f\n", promedioTotalPersonas);

    return 0;
}
