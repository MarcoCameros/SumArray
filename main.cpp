// IMCOMPDefiniendoNHilos.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <cstdlib>

#ifdef _OPENMP
    #include <omp.h>
#else
    #define omp_get_thread_num() 0
#endif

#define N 1000
#define chunk 100
#define mostrar 10

void imprimeArreglo(float *d);

int main()
{

    std::cout << "Sumando Arreglos en Paralelo!\n";
    float a[N], b[N], c[N];
    int i;

    for (i =0; i< N; i++) {
        a[i] = rand() % 1000;
        b[i] = rand() % 1000;
    }

    int pedazos = chunk;

#pragma omp parallel for \
    shared(a,b,c,pedazos) private(i) \
    schedule(static, pedazos)
    for (i = 0; i< N; i++)
        c[i] = a[i] + b[i];

    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo a: " << std::endl;
    imprimeArreglo(a);
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo b: " << std::endl;
    imprimeArreglo(b);
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo c: " << std::endl;
    imprimeArreglo(c);
}

void imprimeArreglo(float *d) {
    for (int x=0;x <mostrar;x++) {
        std::cout << d[x] << " - ";
    }
    std::cout << std::endl;
}