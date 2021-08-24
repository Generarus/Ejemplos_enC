// Este programa guards en un archivo mediciones de temperatura tomadas cada 0.1 segundos
// Autor: GENARO HERNÁNDEZ VALDEZ
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    double t;
    double signo;
    int i;
    int n=100; // Número de muestras que se van a generar
    FILE *fp1=NULL; //Apuntador al archivo donde se guardan los datos a graficar
    
   
    //Se genera archivo con los datos de temperatura:
    if((fp1=fopen("MedicionesTemperatura.txt", "w")) != NULL) {
        printf("\nArchivo abierto exitosamente\n");
        fprintf(fp1, "%d", n); //Guarda el número de mediciones
        for(i=0; i<n; i++) {
            if((rand()%2)==0) signo=-1.0;
            else signo=1.0;
            t=i*0.1;
            fprintf(fp1, "\n%f", 0.6*t+25.0+signo*(rand()%5)); //Guarda mediciones de temperatura
        }
        fclose(fp1); 
    }
    else printf("\nNo se logró abrir el archivo para guardar las mediciones de temperatura\n"); 
    return 0; 
}