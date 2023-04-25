// Jarnik-Prim-MST.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "graph.h"
#include "min_spanning_tree.h"

using namespace std;

int main()
{
    std::cout << "Hello World!\n";

    graph g_test(9);
    g_test.add_edge(0, 2, 3);
    g_test.add_edge(0, 1, 4);
    g_test.add_edge(0, 4, 7);
    g_test.add_edge(1, 3, 1);
    g_test.add_edge(3, 5, 1);
    g_test.add_edge(4, 5, 1);
    g_test.add_edge(3, 4, 3);
    g_test.add_edge(2, 4, 4);
    g_test.add_edge(5, 7, 2);
    g_test.add_edge(7, 8, 3);
    g_test.add_edge(5, 8, 4);
    g_test.add_edge(4, 8, 3);
    g_test.add_edge(4, 6, 5);
    g_test.add_edge(6, 8, 5);

    mst m{};
    cout << g_test;
    m.prim_spanning_tree(g_test);
}
