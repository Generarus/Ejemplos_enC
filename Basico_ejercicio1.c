// Ejercicio 1 nivel básico
// Imprime un menú y selecciona una opción
// Autor: GENARO HERNÁNDEZ VALDEZ
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
//#include <iostream.h>


int main() 
{
    int opcion=0;
    int i;
    printf("\nOperaciones matemáticas básicas:\n");
    printf("\n1.- Suma\n\n2.- Resta\n\n3.- Multiplicación\n\n4.- División\n\n5.- Salir\n\n");
    
    while (opcion != 5) {   
        printf("\nElija una opción: ");
        scanf("%d", &opcion);

        if (opcion==1) printf("\nElegiste la opción %d: suma\n\n", opcion);
        else if(opcion==2) printf("\nElegiste la opción %d: resta\n\n", opcion);
            else if(opcion==3) printf("\nElegiste la opción %d: multiplicación\n\n", opcion);
                else if(opcion==4) printf("\nElegiste la opción %d: división\n\n", opcion);
                    else if(opcion==5) printf("\nElegiste la opción %d: salir\n\n", opcion);
                         else printf("\nOpción no valida\n\n");
    
        //printf("\nPresione cualquier tecla para continuar\n\n");
        //scanf("%d", &i);
        //clear();
    }  
    return 0; 
}