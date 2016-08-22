/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 *
 * Created on August 20, 2016, 2:58 PM
 */

#include <cstdlib>
#include <iostream>
#include "graphMap.h"

using namespace std;

void showMenu(void);

/*
 * 
 */
int main(void) {
    // Initialization routines
    GraphMap *map = new GraphMap();
    map->initAdjacencyMatrix();
    map->fillAdjacencyMatrix();
    map->initDistanceMatrix();
    map->fillDistanceMatrix();

    int resp;
    int keep = true;
    while (keep) {
        showMenu();
        cin >> resp;
        switch (resp) {
            case 1:
                //Se ingresa el metodo de buscar ubicacion
                break;
            case 2:
                map->shortestPath("A", "B");
                break;
            case 3:
                map->printAdjacencyMatrix();
                break;
            case 4:
                map->printDistanceMatrix();
                break;
            case 5:
                keep = false;
                break;
            default:
                cout << "Valor inválido..." << endl;
        }
    }
    return 0;
}

void showMenu() { //menu
    cout << "1. Mostrar ubicación" << endl;
    cout << "2. Mostrar camino mínimo" << endl;
    cout << "3. Imprimir matriz de adyacencia" << endl;
    cout << "4. Imprimir matriz de distancia" << endl;
    cout << "5. Salir" << endl;
    cout << "Seleccione una opción: ";
}
