/**
 * @file main.cpp
 * 
 * Codigo para aplicar diferentes algoritmos de ordenamiento a un arreglo de enteros extraidos de un archivo
 * 
 * @author Alejandro Delgado Rivera <AlejandroDR_IV@Outlook.com>
 * @version 1.0
 * @date 06/09/2021
 */ 


#include"leerYEscribirArchivo.h"
#include"ordenamiento.h"

int main()
{
    string nombre;
    cout << "Escribe el nombre del archivo con los datos de entrada (con extension): ";  // PEDIR NOMBRE DE ARCHIVO DE SALIDA SIN EXTENSION
    cin >> nombre;
    cin.clear();
    cin.ignore(1000, '\n');

    // Abre el archivo
    Archivo arch(nombre);
    // Extrae los numeros del archivo
    arch.contarNumerosYCrearCadenaNumeros();
    arch.extraerNumeros();

    // Crea el objeto que aplicara los algoritmos de ordenamiento sobre el arreglo
    Ordenamiento sort(arch.getPtrNumeros(), arch.getCantNum());

    // Si quiere aplicar otro algoritmo con la misma entrada es necesario volver a iniciar el programa
    cout << "\nElije el algoritmo de ordenamiento que desee aplicar\n" << endl;
    cout << "1 - Insertion Sort" << endl;
    cout << "2 - Selection Sort" << endl;
    cout << "3 - BubbleSort" << endl;
    cout << "4 - Merge Sort" << endl;
    cout << "5 - Quick Sort" << endl;
    cout << "6 - Merge Sort Hibrido" << endl;
    cout << "7 - Quick Sort Aleatorizado" << endl;
    int opcion;
    cout << "Opcion: ";
    cin >> opcion;
    cin.clear();
    cin.ignore(1000, '\n');

    system("clear");

    switch(opcion)  {
            case 1:
                sort.insertionSort();
                break;

            case 2:
                sort.selectionSort();
                break;

            case 3:
                sort.bubbleSort();
                break;

            case 4:
                sort.mergeSort(1, arch.getCantNum());
                break;

            case 5:
                sort.quickSort(1, arch.getCantNum());
                break;

            case 6:
                sort.mergeSortHibrido(1, arch.getCantNum());
                break;

            case 7:
                sort.quickSortAleatorizado(1, arch.getCantNum());
                break;

            default:
                cout << "\nOpcion invalida\n";
                exit(1);
                break;
    }

    cout << "\nElija una de las siguientes opciones\n" << endl;

    do  {
        cout << "1 - Mostrar el arreglo ordenado (si el arreglo es muy grande es posible que no se vean todos los elementos)" << endl;
        cout << "2 - Escribir el contenido del arreglo ordenado en un documento de texto" << endl;
        cout << "0 - Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        cin.clear();
        cin.ignore(1000, '\n');
        cout << endl;

        switch(opcion)  {
            case 1:
                sort.mostrarNums();
                break;

            case 2:
                // Pide el nombre del archivo de salida al usuario
                cout << "Escribe el nombre del archivo (sin extension): ";
                cin >> nombre;
                cin.clear();
                cin.ignore(1000, '\n');
                arch.escribirArrDocTxt(nombre + ".txt");
                cout << endl;
                break;

            default:
                continue;
                break;
        }
    }  while(opcion > 0 && opcion < 3);

    system("clear");
    system("pause");
    return 0;
}