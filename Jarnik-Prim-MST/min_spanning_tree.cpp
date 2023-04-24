#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#include "min_spanning_tree.h"
#include "graph.h"


/**
* minimmum spanning tree constrcutor
*/
mst::mst() 
{
	distance = 0; 
	closed_nodes = {};
	visited = {};
}

/**
* Get the size of the current minimimum spanning tree 
*/
size_t mst::get_closed_nodes_size()
{
	return closed_nodes.size();
}


/**
* Add a new node to closed nodes
*/
void mst::add_closed_nodes(graph::node node_x)
{
	closed_nodes.push_back(node_x);
	visited[node_x];
}

#if 0
graph::node mst::find_minimum_edge_size(graph g)
{
	for (auto it = closed_nodes.begin(); it != closed_nodes.end(); ++it)
	{
		auto neighbors = g.get_neighbors_nodes(*it);
		for (auto jt = neighbors.begin(); jt != neighbors.end(); ++jt)
		{

		}
	}
	auto neighbors = g.get_neighbors_nodes(*it);
}
#endif
double mst::prim_spanning_tree(graph g)
{
	visited.resize(g.get_num_nodes());
	visited.assign(g.get_num_nodes(), false);
	add_closed_nodes(0);
	while (get_closed_nodes_size() != g.get_num_nodes())
	{

	}

	return distance;
}

