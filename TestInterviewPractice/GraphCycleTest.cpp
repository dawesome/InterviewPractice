//
//  GraphCycleTest.cpp
//  InterviewPractice
//
//  Created by Michael Dawe on 12/14/16.
//
//

#include "gtest/gtest.h"
#include "CycleDetection.hpp"

TEST(CycleTest, CanCreateGraph)
{
    Graph graph(3);
}

TEST(CycleTest, CanAddEdge)
{
    Graph graph(3);
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
}

TEST(CycleTest, DoesDetectCycle)
{
    Graph graph(3);
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 0);
    ASSERT_TRUE(graph.IsCyclic());
    
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    ASSERT_TRUE(g.IsCyclic());
}

TEST(CycleTest, FindsCycleInLongChain) {
    Graph g(10);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 6);
    g.addEdge(6, 7);
    g.addEdge(7, 8);
    g.addEdge(5, 3);
    
    ASSERT_TRUE(g.IsCyclic());
}

TEST(CycleTest, AnotherTestCase) {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(0, 3);
    ASSERT_FALSE(g.IsCyclic());
}

TEST(CycleTest, FurtherTest) {
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(4, 3);
    g.addEdge(4, 5);
    g.addEdge(5, 4);
    ASSERT_TRUE(g.IsCyclic());
}

TEST(CycleTest, DoesDetectNonCycle)
{
    Graph graph(3);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    ASSERT_FALSE(graph.IsCyclic());
}
