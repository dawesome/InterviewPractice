//
//  CycleDetection.hpp
//  InterviewPractice
//
//  Created by Michael Dawe on 12/14/16.
//
//

#ifndef CycleDetection_hpp
#define CycleDetection_hpp

#include <stdio.h>
#include <list>

class Graph {
private:
    int size;
    std::list<int>* edges;
    
public:
    Graph(int size);
    void addEdge(int from, int to);
    
    bool IsCyclic() const;
    
private:
    bool IsCyclicHelper(int node, bool visited[], bool inRecursionStack[]) const;
};

#endif /* CycleDetection_hpp */
