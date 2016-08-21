/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <string>
#include "graphMap.h"

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
}

void GraphMap::initCost() {
    g_cost[0] = "50";
    g_cost[1] = "40";
    g_cost[2] = "40";
    g_cost[3] = "45";
    g_cost[4] = "30";
    g_cost[5] = "25";
    g_cost[6] = "15";
    g_cost[7] = "25";
    g_cost[8] = "30";
    g_cost[9] = "35";
    g_cost[10] = "15";
    g_cost[11] = "15";
    g_cost[12] = "15";
    g_cost[13] = "25";
    g_cost[14] = "20";
    g_cost[15] = "15";
    g_cost[16] = "15";
    g_cost[17] = "15";
    g_cost[18] = "15";
    g_cost[19] = "30";
    g_cost[20] = "30";
    g_cost[21] = "20";
    g_cost[22] = "15";
    g_cost[23] = "45";
    g_cost[24] = "35";
    g_cost[25] = "30";
    g_cost[26] = "20";
    g_cost[27] = "15";
    g_cost[28] = "25";
    g_cost[29] = "35";
}

void GraphMap::initAdjacencyMatrix() {
    int i, j;
    for (i = 0; i < NUM_VERT; i++) {
        for (j = 0; j < NUM_VERT; j++) {
            g_adjacency[i][j] = 0;
        }
    }
}

void GraphMap::initCostMatrix()
{
    int i, j;
    for (i = 0; i < NUM_VERT; i++)
    {
        for (j = 0; j < NUM_VERT; j++)
        {
            g_costMat[i][j] = INFINITE;
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

void GraphMap::fillCostMatrix()
{
    int i, j;
    for (i = 0; i < NUM_ARCS; i++)
    {
        // Get the origin and destiny vertices from the arc definition
        string orig = g_arcs[i].substr(0, g_arcs[i].find("-"));
        string dest = g_arcs[i].substr(g_arcs[i].find("-") + 1);
        string cost = g_cost[i];
        
        // From the vertices names, get the index associated to the matrix
        int origIdx = getVertIndex(orig);
        int destIdx = getVertIndex(dest);
        
        g_costMat[origIdx][destIdx] = atoi(cost.c_str());
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

void GraphMap::printCostMatrix()
{
    int i, j;
    cout << "---Cost Matrix---" << endl;
    for (i = 0; i < NUM_VERT; i++)
    {
        for (j = 0; j < NUM_VERT; j++) {
            cout << g_costMat[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void GraphMap::printAdjacencyMatrix() {
    int i, j;
    cout << "---Adjacency Matrix---" << endl;
    for (i = 0; i < NUM_VERT; i++) {
        for (j = 0; j < NUM_VERT; j++) {
            cout << g_adjacency[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}