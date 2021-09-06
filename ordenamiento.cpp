/**
 * @file ordenamiento.cpp
 *
 * Definicion de la clase "Ordenamiento"
 * 
 * @author Alejandro Delgado Rivera <AlejandroDR_IV@Outlook.com>
 * @version 1.0
 * @date 05/09/2021
 */

#include"ordenamiento.h"

Ordenamiento::Ordenamiento(int *ptrArregloEntrs, int cantElemts)
{
    // Inicializa las variables de clase
    this->ptrArregloEntrs = ptrArregloEntrs;
    this->cantElemts = cantElemts;
}

int* Ordenamiento::getPtrArregloEntrs(int ind)
{
    return (ptrArregloEntrs + ind);
}

void Ordenamiento::mostrarNums()
{
    int cont = 0;
    while(cont < cantElemts)  {
        cout << "Dato " << (cont + 1) << ": " << *(ptrArregloEntrs + cont) << endl;
        cont++;
    }
    cout << "\n" << cont << " datos\n" << endl;
}

void Ordenamiento::insertionSort()
{
    // Declaracion de variable auxiliar
    int auxKey;
    // Declara e inicia la variable para llevar el tiempo
    clock_t t = clock();

    // Bucle que se repetira hasta que el indice "j" sea igual al ultimo indice del arreglo
    for(int i = 0, j = 1; j < cantElemts; j++)  {
        auxKey = *(ptrArregloEntrs + j);
        i = j - 1;  // Indice anterior a "j"
        /* Bucle que se repetira hasta que se encuentre el lugar adecuado para el elemento "j"
           o hasta que se haya llegado al principio del arreglo */
        while(i > -1 and *(ptrArregloEntrs + i) > auxKey)  {
            // Se copiara en el elemento "i + 1" el contenido de "i" (dos numeros iguales consecutivos)
            *(ptrArregloEntrs + (i + 1)) = *(ptrArregloEntrs + i);
            i = i - 1;
        }
        /* El elemento "i + 1" se reemplaza por el valor de "auxKey"
           (siguiente elemento despues de salir del bucle anterior) */
        *(ptrArregloEntrs + (i + 1)) = auxKey;
    }

    // Detiene el tiempo
    t = clock() - t;
    cout << "\nInsertion Sort - Tiempo de ejecucion: " << float(t) / CLOCKS_PER_SEC << "segundos\n" << endl;
}

void Ordenamiento::selectionSort()
{
    // Declaracion de variable auxiliar para hacer el intercambio
    int auxInter;
    // Declaracion de variable auxiliar para indexar el elemento minimo en cada iteracion
    int min;
    // Declara e inicia la variable para llevar el tiempo
    clock_t t = clock();

    // Bucle anidado que se repetira hasta que se hayan acomodado todos los numeros
    for(int j = 0; j < (cantElemts - 1); j++)  {  // Indexa la posicion que se esta acomodando
        min = j;  // Minimo inicial
        for(int i = j + 1; i < cantElemts; i++)  {  // Recorre la matriz desde la siguiente posicion
            // Si el elemento "i" es menor que el elemento "min"
            if(*(ptrArregloEntrs + i) < *(ptrArregloEntrs + min))  {
                min = i;
            }
        }

        // Si encuentra un nuevo elemento minino al inicial, realiza el cambio
        if(min != j)  {
            auxInter = *(ptrArregloEntrs + j);
            *(ptrArregloEntrs + j) = *(ptrArregloEntrs + min);
            *(ptrArregloEntrs + min) = auxInter;
        }
    }

    // Detiene el tiempo
    t = clock() - t;
    cout << "\nSelection Sort - Tiempo de ejecucion: " << float(t) / CLOCKS_PER_SEC << "segundos\n" << endl;
}

void Ordenamiento::bubbleSort()
{
    // Declaracion de variable auxiliar para hacer el intercambio
    int auxInter;
    // Declara e inicia la variable para llevar el tiempo
    clock_t t = clock();

    // Bucle anidado que se repetira "(cantElemts - 1)" para hacer todas las comparaciones necesarias
    for(int i = 0; i < (cantElemts - 1); i++)  {
        // Bucle que realizara las comparaciones
        for(int j = cantElemts - 1; j >= i + 1; j--)  {
            // Si el elemento anterior es mayor los intercambia
            if(*(ptrArregloEntrs + j) < *(ptrArregloEntrs + (j - 1)))  {
                auxInter = *(ptrArregloEntrs + j);
                *(ptrArregloEntrs + j) = *(ptrArregloEntrs + (j - 1));
                *(ptrArregloEntrs + (j - 1)) = auxInter;
            }
        }
    }

    // Detiene el tiempo
    t = clock() - t;
    cout << "\nBubbleSort - Tiempo de ejecucion: " << float(t) / CLOCKS_PER_SEC << "segundos\n" << endl;
}

void Ordenamiento::mergeSort(int p, int r)
{
    // Declara e inicia la variable para llevar el tiempo
    clock_t t = clock();

    mrgSort(p, r);

    // Detiene el tiempo
    t = clock() - t;
    cout << "\nMerge Sort - Tiempo de ejecucion: " << float(t) / CLOCKS_PER_SEC << "segundos\n" << endl;
}

void Ordenamiento::mrgSort(int p, int r)
{
    /* Cuando "p = r" (solo se considera un elemento ya acomodado) sale de la funcion
       para seguir con la recursion sin hacer nada mas */
    if(p < r)  {
        // Cancula el indice de particion
        int q = floor((p + r) / 2);
        mrgSort(p, q);
        mrgSort((q + 1), r);
        // Para continuar con la recursion se mezclan los arreglos ya acomodados
        merge(p, q, r);
    }
}

void Ordenamiento::merge(int p, int q, int r)
{
    // Numero de elementos de cada arreglo
    int n1 = q - p + 1;
    int n2 = r - q;
    // Asignacion de memoria a arreglos que se mezclaran
    int *L = new int [n1], *R = new int [n2];
    
    // Bucles que llenaran cada matriz
    int i = 0, j = 0;
    for(i; i < n1; i++)  {
        *(L + i) = *(ptrArregloEntrs + (p + i - 1));
    }
    for(j; j < n2; j++)  {
        *(R + j) = *(ptrArregloEntrs + (q + j));
    }

    // Para indexar el arreglo al que apunta "ptrArregloEntrs"
    int k = p - 1;
    // Bucle que mezcla los arreglos
    i = j = 0;
    while(k < r)  {
        // Si ya se ha recorrido todo el arreglo "R" o "L"
        if(i == n1 || j == n2)  {
            if(i == n1)  {
                // Termina de pasar el arreglo restante
                while(k < r)  {
                    *(ptrArregloEntrs + k) = *(R + j);
                    j++;
                    k++;
                }
            }
            else  {
                // Termina de pasar el arreglo restante
                while(k < r)  {
                    *(ptrArregloEntrs + k) = *(L + i);
                    i++;
                    k++;
                }
            }
        }
        // Si el elemento siguiente de "L" es menor que el de "R"
        else if(*(L + i) <= *(R + j))  {
            *(ptrArregloEntrs + k) = *(L + i);
            i++;
        }
        // Si el elemento siguiente de "R" es menor que el de "L"
        else if(*(L + i) > *(R + j))  {
            *(ptrArregloEntrs + k) = *(R + j);
            j++;
        }
        k++;
    }

    // Libera la memoria asignada
    delete[] L;
    delete[] R;
}

void Ordenamiento::quickSort(int p, int r)
{
    // Declara e inicia la variable para llevar el tiempo
    clock_t t = clock();

    qckSort(p, r);

    // Detiene el tiempo
    t = clock() - t;
    cout << "\nQuick Sort - Tiempo de ejecucion: " << float(t) / CLOCKS_PER_SEC << "segundos\n" << endl;
}

void Ordenamiento::qckSort(int p, int r)
{
    /* Cuando "p = r" sale de la funcion quiere decir que ya se acomodo el arreglo desde
       p hasta q (en la recursion) y sale de la funcion para seguir con la recursion */
    if(p < r)  {
        /* Manda a llamar el metodo "particion" para obtener un indice
           "q" y acomodar el arreglo desde "p" hasta "q" (en la recursion) */
        int q = particion(p, r);
        // Para continuar con la recursion (el elemento "q" ya esta acomodado)
        qckSort(p, q - 1);
        qckSort(q + 1, r);
    }
}

int Ordenamiento::particion(int p, int r)
{
    // Elemento pivote para hacer las comparaciones
    int x = *(ptrArregloEntrs + (r - 1));
    // Para indexar los valores menores a "x"
    int i = p - 1;
    // Declaracion de variable auxiliar para hacer el intercambio
    int auxInter;

    // Bucle que se repite hasta que se llegue al penultimo elemento del subarreglo
    for(int j = p; j <= (r - 1); j++)  {
        /* Para mantener los elementos de la iquierda menores o
           iguales que los de la derecha tomando como pivote a "x" */
        if(*(ptrArregloEntrs + (j - 1)) <= x)  {
            i++;
            // Intercambia el elemento "i" con el elemento "j"
            auxInter = *(ptrArregloEntrs + (j - 1));
            *(ptrArregloEntrs + (j - 1)) = *(ptrArregloEntrs + (i - 1));
            *(ptrArregloEntrs + (i - 1)) = auxInter;
        }
    }

    // Intercambia el elemento "i + 1" con el elemento "r"
    *(ptrArregloEntrs + (r - 1)) = *(ptrArregloEntrs + i);
    *(ptrArregloEntrs + i) = x;

    return ++i;
}

void Ordenamiento::mergeSortHibrido(int p, int r)
{
    // Declara e inicia la variable para llevar el tiempo
    clock_t t = clock();

    mrgSortHibrido(p, r);

    // Detiene el tiempo
    t = clock() - t;
    cout << "\nMerge Sort Hibrido - Tiempo de ejecucion: " << float(t) / CLOCKS_PER_SEC << "segundos\n" << endl;
}

void Ordenamiento::mrgSortHibrido(int p, int r)
{
    // Si el arreglo es lo suficientemente grande sigue con la recursion
    if(p < r && (r - p) > 30000)  {
        // Cancula el indice de particion
        int q = floor((p + r) / 2);
        mrgSortHibrido(p, q);
        mrgSortHibrido((q + 1), r);
        // Para continuar con la recursion se mezclan los arreglos ya acomodados
        merge(p, q, r);
    }
    // Cuando el arreglo tenga menos de 30002 datos se aplica Insertion Sort
    else if(p < r)  {
        // Variable de tipo "Ordenamiento" para aplicar Insertion Sort
        Ordenamiento insSrt(this->getPtrArregloEntrs(p - 1), (r - p + 1));
        insSrt.insertionSort();
    }
}

void Ordenamiento::quickSortAleatorizado(int p, int r)
{
    // Declara e inicia la variable para llevar el tiempo
    clock_t t = clock();

    qckSortAleatorizado(p, r);

    // Detiene el tiempo
    t = clock() - t;
    cout << "\nQuick Sort Aleatorizado - Tiempo de ejecucion: " << float(t) / CLOCKS_PER_SEC << "segundos\n" << endl;
}

void Ordenamiento::qckSortAleatorizado(int p, int r)
{
    // LLeva a cabo el mismo algoritmo que "qckSort", pero usa un pivote aleatorio
    if(p < r)  {
        int q = randParticion(p, r);
        qckSortAleatorizado(p, q - 1);
        qckSortAleatorizado(q + 1, r);
    }
}

int Ordenamiento::randParticion(int p, int r)
{
    // Declaracion de variable auxiliar para hacer el intercambio
    int auxInter;
    // Genera un numero aleatorio entre "p" y "r"
    int i = p + (rand() % (r + 1 - p));

    // Intercambia el pivote por el elemento aleatorio
    auxInter = *(ptrArregloEntrs + (r - 1));
    *(ptrArregloEntrs + (r - 1)) = *(ptrArregloEntrs + (i - 1));
    *(ptrArregloEntrs + (i - 1)) = auxInter;

    return particion(p, r);
}