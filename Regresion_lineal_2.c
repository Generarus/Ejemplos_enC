// PROGRAMACIÓN AVANZADA Ejercicio 1: Regresión Lineal

// Este programa lee un archivo que contiene mediciones de desplazamientos tomadas cada Delta_t segundos
// En base a estos datos realiza un ajuste de curva utilizando el método de mínios cuadrados
// Finalmente grafica las muestras de desplazamiento vs tiempo y su ajuste de curva d=mt+b

// El archivo de datos inicia con el número de muestras (n), tiempo inicial (to), el intervalo
// con el que se incrementa el tiempo (Delta_t), seguido de las muestras de desplazaiento (d)

// Autor: GENARO HERNÁNDEZ VALDEZ
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    double d[100];
    double t[100];
    double signo, to, Delta_t;
    int i;
    int n; // Número de muestras
    char cadena [30];
    double St, Sd, St2, Std, m, b;
    FILE *fp1=NULL; //Apuntador al archivo donde se guardan los datos a graficar
    FILE *fp2=NULL; //Apuntador al archivo donde se guardan los comandos gnuplot
    //Comandos gnuplot:
    char *cgnu [] ={"set title \"Grafica de Dispersión y Regresión lineal\"", 
                    "set xlabel \"Tiempo (segundos)\"", 
                    "set ylabel \"Temperatura (°C)\"", 
                    "set grid", 
                    "set autoscale", 
                    "plot 'GraficaDispersion.txt' with points, 'RegresionLineal.txt' with lines"
                    };
   
    fp1=fopen("GraficaDispersion.txt", "w");   // Abre archivo donde se guardaran los valores de d vs t
    fp2=fopen("MedicionesDistancia.txt", "r"); // Abre archivo que contiene las mediciones de desplazamiento (d)
    fgets(cadena, 30, fp2);
    n=atoi(cadena); printf("%d\n",n); //Número de muestras
    fgets(cadena, 30, fp2);
    to=(double) atof(cadena); printf("%f\n",to);// Tiempo inicial
    fgets(cadena, 30, fp2);
    Delta_t=(double) atof(cadena); printf("%f\n",Delta_t);// Incrementos de tiempo
    i=0;
    while(feof(fp2) == 0)
	    {
        fgets(cadena, 30, fp2);
        d[i]=(double) atof(cadena); printf("%f\n",d[i]); // Desplazamiento
        t[i]=to+i*Delta_t; // Tiempo
        fprintf(fp1, "%f %f\n", t[i], d[i]); // Guarda d vs t para realizar grafica de dispersión
        i++;
	    }
    fclose(fp1);
    fclose(fp2);
    printf("\n%d\n\n",i);

    //Regresión lineal
    for(i=0;i<n;i++) {
        St=St+t[i];
        Sd=Sd+d[i];
        St2=St2+t[i]*t[i];
        Std=Std+t[i]*d[i];
    }
    m=(n*Std-St*Sd)/(n*St2-St*St);  // Pendiente de la recta
    b=(St2*Sd-Std*St)/(n*St2-St*St);// Ordenada al origen del modelo lineal, b=(1/n)*(Sd-m*St); 
    printf("\nModelo lineal (d = mt + b): d = %f t + %f\n\n", m, b);

    //Se genera archivo con los datos del modelo lineal:
    fp1=fopen("RegresionLineal.txt", "w");
    for(i=0; i<n; i++) fprintf(fp1, "%f %f\n", t[i], m*t[i]+b);
    fclose(fp1);

    //Se guardan y ejecutan los comandos gnuplot que permiten visualizar las graficas
    fp2=popen("gnuplot -persitent", "w");
    for(i=0; i<6; i++) {
        fprintf(fp2, "%s\n", cgnu[i]);
    }
    pclose(fp2);
    return 0; 
}