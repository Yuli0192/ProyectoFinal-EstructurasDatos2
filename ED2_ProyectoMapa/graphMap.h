/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   graphMap.h
 *
 * Created on August 20, 2016, 3:05 PM
 */

#ifndef GRAPHMAP_H
#define GRAPHMAP_H
#define NUM_ARCS 30
#define NUM_VERT 20
#define INFINITE 8

#include <string>
using namespace std;

class GraphMap{
private:
    int g_adjacency[NUM_VERT][NUM_VERT];
    int g_costMat[NUM_VERT][NUM_VERT];
    string g_vertices[NUM_VERT];
    string g_arcs[NUM_ARCS];
    string g_cost[NUM_ARCS];
public:
    GraphMap(void);
    void initVertices(void);
    void initArcs(void);
    void initCost(void);
    void initAdjacencyMatrix();
    void initCostMatrix();
    void fillAdjacencyMatrix();
    void fillCostMatrix();
    void printAdjacencyMatrix();
    void printCostMatrix();
    int getVertIndex(string vertName);
    string getVertName(int vertIdx);
};

#endif /* GRAPHMAP_H */

