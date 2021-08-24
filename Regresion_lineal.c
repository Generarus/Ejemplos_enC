// ROGRAMACIÓN AVANZADA Ejercicio 1: Regresión Lineal
// Este programa lee un archivo que contiene mediciones de temperatura tomadas cada 0.1 segundos
// En base a estos datos realiza un ajuste de curva utilizando el método de mínios cuadrados
// Finalmente grafica los datos de temperatura y su ajuste de curva T=mt+b
// Autor: GENARO HERNÁNDEZ VALDEZ
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    double T[100];
    double t[100];
    double signo;
    int i;
    int n; // Número de muestras
    char cadena [20];
    double St, ST, St2, StT, m, b;
    FILE *fp1=NULL; //Apuntador al archivo donde se guardan los datos a graficar
    FILE *fp2=NULL; //Apuntador al archivo donde se guardan los comandos gnuplot
    //Comandos gnUplot:
    char *cgnu [] ={"set title \"Grafica de Dispersión y Regresión lineal\"", 
                    "set xlabel \"Tiempo (segundos)\"", 
                    "set ylabel \"Temperatura (°C)\"", 
                    "set grid", 
                    "set autoscale", 
                    "plot 'GraficaDispersion.txt' [0:100] [0:50] with points, 'RegresionLineal.txt' with lines"
                    };
   
    fp2=fopen("GraficaDispersion.txt", "w"); //En este archivo se guardan los valores de temperatura contra el tiempo
    fp1=fopen("MedicionesTemperatura.txt", "r"); //Este archivo contiene las mediciones de temperatura
    fgets(cadena, 20, fp1);
    n=atoi(cadena);
    printf("%d\n",n);
    i=0;
    while(feof(fp1) == 0)
	    {
        fgets(cadena, 20, fp1);
        T[i]=(double) atof(cadena);
        t[i]=i*0.1;
        fprintf(fp2, "%f %f\n", t[i], T[i]);
        i++;
	    }
    fclose(fp1);
    fclose(fp2);
    printf("\n%d\n\n",i);

    //Regresión lineal
    for(i=0;i<n;i++) {
        St=St+t[i];
        ST=ST+T[i];
        St2=St2+t[i]*t[i];
        StT=StT+t[i]*T[i];
    }
    m=(n*StT-St*ST)/(n*St2-St*St);
    b=(St2*ST-StT*St)/(n*St2-St*St);//b=(1/n)*(ST-m*St);
    printf("\nModelo lineal (T = mt + b): T = %f t + %f\n\n", m, b);

    //Se genera archivo con los datos del modelo lineal:
    fp1=fopen("RegresionLineal.txt", "w");
    for(i=0; i<n; i++) fprintf(fp1, "%f %f\n", i*0.1, m*i*0.1+b);
    fclose(fp1);

    //Se guardan y ejecutan los comandos gnuplot que permiten visualizar las graficas
    fp2=popen("gnuplot -persitent", "w");
    for(i=0; i<6; i++) {
        fprintf(fp2, "%s\n", cgnu[i]);
    }
    pclose(fp2);
    return 0; 
}