/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include "graphMap.h"

#define INFINITY 100
#define MAX 20

GraphMap::GraphMap() {
    this->initVertices();
    this->initArcs();
    this->initCost();
}

void GraphMap::initVertices() {
    g_vertices[0] = "Dept Registro";
    g_vertices[1] = "Dept Becas";
    g_vertices[2] = "Dept Cobro";
    g_vertices[3] = "Dept Contabilidad";
    g_vertices[4] = "Dept Decanatura";
    g_vertices[5] = "Dept TI";
    g_vertices[6] = "Sala Reuniones";
    g_vertices[7] = "Soda";
    g_vertices[8] = "Baños";
    g_vertices[9] = "Biblioteca";
    g_vertices[10] = "Lab 1";
    g_vertices[11] = "Lab 2";
    g_vertices[12] = "Lab 3";
    g_vertices[13] = "Lab 4";
    g_vertices[14] = "Lab 5";
    g_vertices[15] = "Lab 6";
    g_vertices[16] = "Lab 7";
    g_vertices[17] = "Lab 8";
    g_vertices[18] = "Lab 9";
    g_vertices[19] = "Lab 10";
}

void GraphMap::initArcs() {
    g_arcs[0] = "Baños-Lab 9";
    g_arcs[1] = "Lab 9-Lab 10";
    g_arcs[2] = "Lab 10-Biblioteca";
    g_arcs[3] = "Biblioteca-Soda";
    g_arcs[4] = "Soda-Baños";
    g_arcs[5] = "Baños-Lab 2";
    g_arcs[6] = "Lab 2-Lab 3";
    g_arcs[7] = "Lab 3-Dept Registro";
    g_arcs[8] = "Dept Registro-Dept Decanatura";
    g_arcs[9] = "Dept Decanatura-Lab 1";
    g_arcs[10] = "Lab 1-Lab 2";
    g_arcs[11] = "Lab 9-Lab 4";
    g_arcs[12] = "Lab 4-Lab 5";
    g_arcs[13] = "Lab 5-Dept Becas";
    g_arcs[14] = "Dept Becas-Dept Registro";
    g_arcs[15] = "Lab 3-Lab 4";
    g_arcs[16] = "Lab 10-Lab 6";
    g_arcs[17] = "Lab 6-Lab 5";
    g_arcs[18] = "Lab 6-Lab 7";
    g_arcs[19] = "Lab 7-Dept Cobro";
    g_arcs[20] = "Dept Cobro-Dept Becas";
    g_arcs[21] = "Biblioteca-Lab 8";
    g_arcs[22] = "Lab 8-Lab 7";
    g_arcs[23] = "Lab 8-Sala Reuniones";
    g_arcs[24] = "Sala Reuniones-Dept Contabilidad";
    g_arcs[25] = "Dept Contabilidad-Dept Cobro";
    g_arcs[26] = "Soda-Dept TI";
    g_arcs[27] = "Dept TI-Lab 1";
    g_arcs[28] = "Dept TI-Sala Reuniones";
    g_arcs[29] = "Dept Contabilidad-Dept Decanatura";
    g_arcs[30] = "Dept Contabilidad-Sala Reuniones";
    g_arcs[31] = "Dept Cobro-Lab 7";
    g_arcs[32] = "Lab 7-Lab 6";
    g_arcs[33] = "Lab 5-Lab 4";
    g_arcs[34] = "Lab 6-Lab 10";
    g_arcs[35] = "Lab 2-Baños";
}

void GraphMap::initCost() {
    g_distance[0] = "20";
    g_distance[1] = "25";
    g_distance[2] = "25";
    g_distance[3] = "30";
    g_distance[4] = "15";
    g_distance[5] = "15";
    g_distance[6] = "5";
    g_distance[7] = "15";
    g_distance[8] = "20";
    g_distance[9] = "20";
    g_distance[10] = "5";
    g_distance[11] = "5";
    g_distance[12] = "5";
    g_distance[13] = "15";
    g_distance[14] = "10";
    g_distance[15] = "5";
    g_distance[16] = "5";
    g_distance[17] = "5";
    g_distance[18] = "5";
    g_distance[19] = "15";
    g_distance[20] = "15";
    g_distance[21] = "10";
    g_distance[22] = "5";
    g_distance[23] = "25";
    g_distance[24] = "20";
    g_distance[25] = "15";
    g_distance[26] = "10";
    g_distance[27] = "5";
    g_distance[28] = "15";
    g_distance[29] = "20";
    g_distance[30] = "2";
    g_distance[31] = "1";
    g_distance[32] = "1";
    g_distance[33] = "1";
    g_distance[34] = "8";
    g_distance[35] = "9";
}

void GraphMap::initAdjacencyMatrix() {
    int i, j;
    for (i = 0; i < NUM_VERT; i++) {
        for (j = 0; j < NUM_VERT; j++) {
            g_adjacency[i][j] = 0;
        }
    }
}

void GraphMap::initDistanceMatrix() {
    int i, j;
    for (i = 0; i < NUM_VERT; i++) {
        for (j = 0; j < NUM_VERT; j++) {
            g_DistanceMat[i][j] = INFINITE;
        }
    }
}

int GraphMap::getVertIndex(string vertName) {
    int i;
    for (i = 0; i < NUM_VERT; i++) {
        if (g_vertices[i] == vertName) {
            return i;
        }
    }
    return -1;
}

string GraphMap::getVertName(int vertIdx) {
    if (vertIdx >= 0 && vertIdx < NUM_VERT)
        return g_vertices[vertIdx];
    else
        return "";
}

void GraphMap::fillDistanceMatrix() {
    int i, j;
    for (i = 0; i < NUM_ARCS; i++) {
        // Get the origin and destiny vertices from the arc definition
        string orig = g_arcs[i].substr(0, g_arcs[i].find("-"));
        string dest = g_arcs[i].substr(g_arcs[i].find("-") + 1);
        string cost = g_distance[i];

        // From the vertices names, get the index associated to the matrix
        int origIdx = getVertIndex(orig);
        int destIdx = getVertIndex(dest);

        g_DistanceMat[origIdx][destIdx] = atoi(cost.c_str());
    }
}

void GraphMap::fillAdjacencyMatrix() {
    int i, j;
    for (i = 0; i < NUM_ARCS; i++) {
        // Get the origin and destiny vertices from the arc definition
        string orig = g_arcs[i].substr(0, g_arcs[i].find("-"));
        string dest = g_arcs[i].substr(g_arcs[i].find("-") + 1);

        // From the vertices names, get the index associated to the matrix
        int origIdx = getVertIndex(orig);
        int destIdx = getVertIndex(dest);

        g_adjacency[origIdx][destIdx] = 1;
        g_adjacency[destIdx][origIdx] = 1;
    }
}

void GraphMap::printDistanceMatrix() {
    int i, j;
    cout << "---------------Locations-----------" << endl;
    for (i = 0; i < NUM_VERT; i++) {

        cout << setw(3) << i + 1 << ") " << g_vertices[i] << endl;
    }
    cout << "----------------------------------Distance Matrix---------------------------------" << endl;
    cout << "   ";
    for (i = 0; i < NUM_VERT; i++) {

        cout << setw(3) << i + 1 << " ";
    }
    cout << endl;
    cout << "   " << "-------------------------------------------------------------------------------" << endl;
    for (i = 0; i < NUM_VERT; i++) {
        cout << i + 1;
        if (i < 9) {
            cout << " ";
        }
        cout << "|";
        for (j = 0; j < NUM_VERT; j++) {
            cout << setw(3) << g_DistanceMat[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void GraphMap::printAdjacencyMatrix() {
    int i, j;

    cout << "---------------Locations-----------" << endl;
    for (i = 0; i < NUM_VERT; i++) {

        cout << setw(3) << i + 1 << ") " << g_vertices[i] << endl;
    }
    cout << "----------------------------------Adjacency Matrix---------------------------------" << endl;

    cout << "   ";
    for (i = 0; i < NUM_VERT; i++) {

        cout << setw(3) << i + 1 << " ";
    }
    cout << endl;
    cout << "   " << "-------------------------------------------------------------------------------" << endl;
    for (i = 0; i < NUM_VERT; i++) {
        cout << i + 1;
        if (i < 9) {
            cout << " ";
        }
        cout << "|";
        for (j = 0; j < NUM_VERT; j++) {
            cout << setw(3) << g_adjacency[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Reference implementation taken from:
// http://www.thecrazyprogrammer.com/2014/03/dijkstra-algorithm-for-finding-shortest-path-of-a-graph.html

void GraphMap::shortestPath(int orig, int dest)//takes the route of shortest paths between vertices
{
    // TODO: Grab these from the user.
    int startnode = orig;
    int endnode = dest;

    int cost[MAX][MAX];
    int distance[MAX];
    int pred[MAX];
    int visited[MAX];
    int count;
    int mindistance;
    int nextnode;
    int i;
    int j;
    int n = MAX;

    //pred[] stores the predecessor of each node
    //count gives the number of nodes seen so far
    //create the cost matrix
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            //if(G[i][j]==0)
            if (g_DistanceMat[i][j] == INFINITY)
                cost[i][j] = INFINITY;
            else
                cost[i][j] = g_DistanceMat[i][j];

    //initialize pred[],distance[] and visited[]
    for (i = 0; i < n; i++) {
        distance[i] = cost[startnode][i];
        pred[i] = startnode;
        visited[i] = 0;
    }

    distance[startnode] = 0;
    visited[startnode] = 1;
    count = 1;

    while (count < n - 1) {
        mindistance = INFINITY;

        //nextnode gives the node at minimum distance
        for (i = 0; i < n; i++)
            if (distance[i] < mindistance&&!visited[i]) {
                mindistance = distance[i];
                nextnode = i;
            }

        //check if a better path exists through nextnode            
        visited[nextnode] = 1;
        for (i = 0; i < n; i++)
            if (!visited[i])
                if (mindistance + cost[nextnode][i] < distance[i]) {
                    distance[i] = mindistance + cost[nextnode][i];
                    pred[i] = nextnode;
                }
        count++;
    }
    cout << "--------------------------------------------------------------" << endl;
    cout << "La distancia mínima desde el " << getVertName(startnode) << " al " << getVertName(endnode) << " son: " << distance[endnode] << " metros." << endl;
    
    cout << "El camino mínimo = " << endnode + 1;
    
    j = endnode;
    do {
        j = pred[j];
        cout << "<-" << j + 1;
    } while (j != startnode);
    cout << endl;
    cout << "--------------------------------------------------------------" << endl;
};

void GraphMap::printAdjacentLocations(int vertIndex)//show the adjacent locations
{
    int i;
    string vertName = g_vertices[vertIndex];
    cout << "--------------------------------------------------------------" << endl;
    cout << " Las ubicaciones adyacentes de " << vertName << " son: " << endl;

    for (i = 0; i < NUM_VERT; i++) {
        if (g_adjacency[vertIndex][i] == 1) {
            cout << "  -" << getVertName(i) << endl;
        }
    }

    cout << "--------------------------------------------------------------" << endl;
}

void GraphMap::printLocations()//show the locations
{
    int i;
    cout << "---------------Locations-----------" << endl;
    for (i = 0; i < NUM_VERT; i++) {

        cout << setw(3) << i + 1 << ") " << g_vertices[i] << endl;
    }
}