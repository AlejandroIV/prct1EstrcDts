/**
 * @file ordenamiento.h
 *
 * Declaracion de la clase "Ordenamiento" que es para aplicar distintos algoritmos de
 * ordenamiento a un arreglo de enteros
 * 
 * @author Alejandro Delgado Rivera <AlejandroDR_IV@Outlook.com>
 * @version 1.0
 * @date 04/09/2021
 */

#pragma once


#include<iostream>
#include<cstring>
#include<string.h>
#include<ctime>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

class Ordenamiento
{
    private:
        int cantElemts;  // Cantidad de numeros que hay en el arreglo
        int *ptrArregloEntrs;  // Apuntador a arreglo de enteros

    public:
        /**
         * @brief Constructor de la clase "Ordenamiento"
         * @param ptrArregloEntrs Puntero a arreglo de enteros
         * @param cantElemts Cantidad de elementos
         */
        Ordenamiento(int *ptrArregloEntrs, int cantElemts);

        /**
         * @brief Metodo que regresa la direccion al que apunta "ptrArregloEntrs" en la posicion "ind"
         * @param ind Indice inicial
         */
        int* getPtrArregloEntrs(int ind);

        /**
         * @brief Metodo que muestra todos los elementos del arreglo al que apunta "ptrArregloEntrs"
         */
        void mostrarNums();

        /**
         * @brief Metodo que aplica el algoritmo de Insertion Sort
         */
        void insertionSort();

        /**
         * @brief Metodo que aplica el algoritmo de Selection Sort
         */
        void selectionSort();

        /**
         * @brief Metodo que aplica el algoritmo de BubbleSort
         */
        void bubbleSort();

        /**
         * @brief Metodo que manda a llamar a "mrgSort" y lleva la cuenta del tiempo
         * @param p Indice de inicio (mayor o igual que 1)
         * @param r Indice final (menor o igual que la cantidad de datos)
         */
        void mergeSort(int p, int r);

        /**
         * @brief Metodo que aplica el algoritmo de MergeSort
         * @param p Indice de inicio (mayor o igual que 1)
         * @param r Indice final (menor o igual que la cantidad de datos)
         */
        void mrgSort(int p, int r);

        /**
         * @brief Metodo que aplica el algoritmo para mezclar dos arreglos ordenados
         * @param p Indice de inicio (mayor o igual que 1)
         * @param q Indice de particion
         * @param r Indice final (menor o igual que la cantidad de datos)
         */
        void merge(int p, int q, int r);

        /**
         * @brief Metodo que manda a llamar a "qckSort" y lleva la cuenta del tiempo
         * @param p Indice de inicio (mayor o igual que 1)
         * @param r Indice final (menor o igual que la cantidad de datos)
         */
        void quickSort(int p, int r);

        /**
         * @brief Metodo que aplica el algoritmo de QuickSort
         * @param p Indice de inicio (mayor o igual que 1)
         * @param r Indice final (menor o igual que la cantidad de datos)
         */
        void qckSort(int p, int r);

        /**
         * @brief Metodo que aplica el algoritmo para pasar los numeros menores del lado izquierdo del subarreglo
         * @param p Indice de inicio (mayor o igual que 1)
         * @param r Indice del pivote (menor o igual que la cantidad de datos)
         * @return int Indice para particionar el arreglo (depende del pivote)
         */
        int particion(int p, int r);

        /**
         * @brief Metodo que manda a llamar a "mrgSortHibrido" y lleva la cuenta del tiempo
         * @param p Indice de inicio (mayor o igual que 1)
         * @param r Indice final (menor o igual que la cantidad de datos)
         */
        void mergeSortHibrido(int p, int r);

        /**
         * @brief Metodo que aplica el algoritmo de MergeSort Hibrido
         * @param p Indice de inicio (mayor o igual que 1)
         * @param r Indice final (menor o igual que la cantidad de datos)
         */
        void mrgSortHibrido(int p, int r);

        /**
         * @brief Metodo que manda a llamar a "qckSortAleatorizado" y lleva la cuenta del tiempo
         * @param p Indice de inicio (mayor o igual que 1)
         * @param r Indice final (menor o igual que la cantidad de datos)
         */
        void quickSortAleatorizado(int p, int r);

        /**
         * @brief Metodo que aplica el algoritmo de QuickSort Aleatorizado
         * @param p Indice de inicio (mayor o igual que 1)
         * @param r Indice final (menor o igual que la cantidad de datos)
         */
        void qckSortAleatorizado(int p, int r);

        /**
         * @brief Metodo que calcula el indice de inicio para despues llamar a "particion"
         * @param p Indice de inicio (mayor o igual que 1)
         * @param r Indice final (menor o igual que la cantidad de datos)
         * @return int Indice para particionar el arreglo (depende del pivote aleatorio)
         */
        int randParticion(int p, int r);
};