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
#define NUM_ARCS 36
#define NUM_VERT 20
#define INFINITE 999

#include <string>
using namespace std;

class GraphMap{
private:
    int g_adjacency[NUM_VERT][NUM_VERT];
    int g_DistanceMat[NUM_VERT][NUM_VERT];
    string g_vertices[NUM_VERT];
    string g_arcs[NUM_ARCS];
    string g_distance[NUM_ARCS];
    int p[8][8];//se utiliza para sacar los caminos
public:
    GraphMap(void);
    void initVertices(void);
    void initArcs(void);
    void initCost(void);
    void initAdjacencyMatrix();
    void initDistanceMatrix();
    void fillAdjacencyMatrix();
    void fillDistanceMatrix();
    void printAdjacencyMatrix();
    void printDistanceMatrix();
    int getVertIndex(string vertName);
    string getVertName(int vertIdx);
    void shortestPath(string orig, string dest);
};

#endif /* GRAPHMAP_H */

