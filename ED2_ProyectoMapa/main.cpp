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
#include "graphMap.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    GraphMap *map = new GraphMap();
    map->initAdjacencyMatrix();
    map->fillAdjacencyMatrix();
    map->printAdjacencyMatrix();
    map->initDistanceMatrix();
    map->fillDistanceMatrix();
    map->printDistanceMatrix();
    return 0;
}

