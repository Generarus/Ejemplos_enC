// Ejercicio 2 Sección 1 nivel Intermedio
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
    char *cgnu [] ={"set title \"Grafico 1\"", "set xlabel \"Valores aleatorios de x\"", "set ylable \"Valores aleatorios de y\"", "plot 'DatosXY.txt' with lines"};
    //Se abren los archivos
    fp1=fopen("DatosXY.txt", "w");
    fp2=popen("gnuplot -persitent", "w");
    //Se generan datos aleatorios para ambas variables x,y:
    for(i=0; i<20; i++) {
        fprintf(fp1, "%f %f\n", x, y);
        x=1.0*i+1.0+(rand()%10);
        y=(rand()%20);
    }
    //Se guardan los comandos gnuplot que permiten visualizar la grafica
    for(i=0; i<4; i++) {
        fprintf(fp2, "%s\n", cgnu[i]);
    }
    fclose(fp1);
    pclose(fp2);   
    return 0; 
}