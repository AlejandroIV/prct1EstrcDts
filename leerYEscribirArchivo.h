/**
 * @file leerYEscribirArchivo.h
 *
 * Declaracion de la clase "Archivo" que es para abrir un archivo, extraer los numeros que estan escritos
 * dentro del documento (uno por linea) y los almacena en un arreglo de tipo "int"
 * 
 * @author Alejandro Delgado Rivera <AlejandroDR_IV@Outlook.com>
 * @version 1.0
 * @date 04/09/2021
 */

#pragma once

#include<iostream>
#include<cstring>
#include<fstream>
#include<stdlib.h>
#include<string.h>

using namespace std;

class Archivo
{
    private:
        ifstream archivo;  // Archivo
        int cantNum;  // Cantidad de numeros que hay en el archivo
        string cadenaNumeros;  // Cadena que contendra todo los numeros
        int *ptrNumeros;  // Apuntador a arreglo de enteros

    public:
        /**
         * @brief Constructor de la clase "Archivo" que abrira el archivo con el nombre "nombreAch"
         * @param nombreArch Nombre del archivo
         */
        Archivo(string nombreArch);

        /**
         * @brief Metodo que contara la cantidad de numeros que hay en el archivo, creara
         * la cadena que se almacenara en "cadenaNumeros" y al final cierra el archivo
         */
        void contarNumerosYCrearCadenaNumeros();
        
        /**
         * @brief Metodo que extraera los numeros enteros de la cadena "cadenaNumeros"
         */
        void extraerNumeros();

        /**
         * @brief Metodo que regresa el numero "cantNum"
         */
        int getCantNum();

        /**
         * @brief Metodo que regresa la direccion al que apunta "ptrNumeros"
         */
        int* getPtrNumeros();

        /**
         * @brief Metodo que escribe el contenido del arreglo al que apunta "ptrNumeros" en un archivo de texto
         * @param nombre Nombre del archivo de salida
         */
        void escribirArrDocTxt(string nombre);

        /**
         * @brief Funcion amiga que convierte una cadena de caracteres a un entero
         * @param strNumero Numero en formato "str"
         * @param cantDigitos Cantidad de digitos
         */
        friend int strToInt(string strNumero, int cantDigitos);
};