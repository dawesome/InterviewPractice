//
//  CycleDetection.cpp
//  InterviewPractice
//
//  Created by Michael Dawe on 12/14/16.
//
//

#include "CycleDetection.hpp"

Graph::Graph(int size) : size(size)
{
    edges = new std::list<int>[size]();
}

void Graph::addEdge(int from, int to)
{
    edges[from].push_back(to);
}

bool Graph::IsCyclic() const
{
    bool visited[size];
    bool inRecursionStack[size];
    for (int i = 0; i < size; ++i) {
        visited[i] = false;
        inRecursionStack[i] = false;
    }
    
    for (int i = 0; i < size; ++i) {
        if (IsCyclicHelper(i, visited, inRecursionStack)) {
            return true;
        }
        
    }
    return false;
}

bool Graph::IsCyclicHelper(int node, bool visited[], bool inRecursionStack[]) const
{
    visited[node] = true;
    inRecursionStack[node] = true;
    
    std::list<int>::iterator iter = edges[node].begin();
    for (; iter != edges[node].end(); ++iter) {
        if(!visited[*iter] && IsCyclicHelper(*iter, visited, inRecursionStack)) {
            return true;
        }
        else if (inRecursionStack[*iter]) {
            return true;
        }
    }
    inRecursionStack[node] = false;
    return false;
}
