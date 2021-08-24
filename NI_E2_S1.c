// Ejercicio 2 Sección 1 nivel Intermedio: Grafica (x,y) de números aleatorios
// Gráfica valores aleatorios (x,y)
// Autor: GENARO HERNÁNDEZ VALDEZ
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    double x=0.0;
    double y=0.0;
    int i;
    FILE *fp1=NULL; //Apuntador al archivo donde se guardan los datos a graficar
    FILE *fp2=NULL; //Apuntador al archivo donde se guardan los comandos gnuplot
    //Comandos gnUplot:
    char *cgnu [] ={"set title \"Números aleatorios\"", 
                    "set xlabel \"Valores aleatorios de x\"", 
                    "set ylabel \"Valores aleatorios de y\"", 
                    "set grid", 
                    "set autoscale", 
                    "plot 'DatosXY.txt' [0:30] [0:50] with points"
                    };
    //Se abren los archivos
    fp1=fopen("DatosXY.txt", "w");
    fp2=popen("gnuplot -persitent", "w");
    //Se generan datos aleatorios para ambas variables x,y:
    for(i=0; i<100; i++) {
        x=1.0*(rand()%20);
        y=1.0*(rand()%10)+i;
        fprintf(fp1, "%f %f\n", x, y);
    }
    //Se guardan los comandos gnuplot que permiten visualizar la grafica
    for(i=0; i<6; i++) {
        fprintf(fp2, "%s\n", cgnu[i]);
    }
    fclose(fp1);
    pclose(fp2);   
    return 0; 
}