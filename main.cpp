// SumArrays.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <cstdlib>

#ifdef _OPENMP
    #include <omp.h>
#else
    #define omp_get_thread_num() 0
#endif


//Definimos las variables que seran usadas para la sumatoria.
//En este caso difinimos N como 1000 siendo este el tamaño de nuestros arreglos
#define N 1000
//Chunk sera la cantidad de valores que seran sumados por hilo
#define chunk 100
//Mostrar sera usando para imprimir los primeros valores del arreglo para comprobar la sumatoria
#define mostrar 10

void imprimeArreglo(float *d);

int main()
{

    // Verificamos si OMP esta disponible para realizar la sumatoria de arreglos de manera paralela
    # ifdef _OPENMP
        std::cout << "OMP disponible y funcionando" << std::endl;
    # endif


    //Definimos los 3 arreglos necesarios para el ejercicio
    //Todos los arreglos tendran un tamaño de N
    std::cout << "Sumando Arreglos en Paralelo!\n";
    float a[N], b[N], c[N];
    int i;

    for (i =0; i< N; i++) {
        //arreglo a con valores aleatorios del 0 al 1000
        a[i] = rand() % 1000;
        //arreglo b con valores aleatorios del 0 al 1000
        b[i] = rand() % 1000;
    }
    //El arreglo C tendra la sumatoria del arreglo a y b
    //Pedazos almacena el valor de chunk
    int pedazos = chunk;


    // Al usar pragma omp parallel indicamos al compilador que realizará un ciclo for de manera paralela.
    // Cada hilo procesará un subconjunto del arreglo.
    // Con shared indicamos que las variables (en este caso, los arreglos) son compartidas entre todos los hilos.
    // En este caso no hay problema de colisión porque cada hilo estará trabajando en un segmento diferente del arreglo.
    // Al definir private(i) estamos indicando que la variable i será independiente para cada hilo, con un valor único por hilo.
    // El ciclo for(i=0; i<N; i++) será procesado por todos los hilos dividiéndose cada segmento indicado.

#pragma omp parallel for \
    shared(a,b,c,pedazos) private(i) \
    schedule(static, pedazos)
    for (i = 0; i< N; i++)
        c[i] = a[i] + b[i];
    //al terminar imprime los arreglos mostrando la sumatoria de los arreglos a y b
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo a: " << std::endl;
    //usamos la implementacion del metodo imprimeArreglo
    imprimeArreglo(a);
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo b: " << std::endl;
    imprimeArreglo(b);
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo c: " << std::endl;
    imprimeArreglo(c);
}

//Implementamos el metodo imprimeArreglo para recorrer el arreglo y imprimir sus valores
void imprimeArreglo(float *d) {
    for (int x=0;x <mostrar;x++) {
        std::cout << d[x] << " - ";
    }
    std::cout << std::endl;
}