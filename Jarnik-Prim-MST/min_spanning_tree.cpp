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
	visited[node_x] = true;
}

/**
* Add new edge to priority queue which is sorted from lowest to highest edge value
*/
void mst::add_edges_to_pq( graph::node node, graph::edge edge)
{
	pair<graph::node, graph::edge> e (node, edge);

	pq.push(e);
}

/**
* Check whether the node is been already added to spanning tree or not
*/
bool mst::is_node_visited(graph::node node_x)
{
	return (visited[node_x]);
}

/**
* Add all neighbours of a node to the priority queue.
*/
void mst::add_neighbours_to_pq(graph g, graph::node node_x)
{
	vector<pair<graph::node, graph::edge>> neighbors = g.get_neighbors(node_x);
	for (auto neighbor : neighbors) {
		if (!is_node_visited(neighbor.first))
		{
			pq.push(neighbor);
		}
	}
}

/*********************************************************************************
* The Jarnik - Prim Spanning Tree Algorithm
**********************************************************************************/
double mst::prim_spanning_tree(graph g)
{
	visited.resize(g.get_num_nodes());
	visited.assign(g.get_num_nodes(), false);
	add_closed_nodes(0);
	add_neighbours_to_pq(g, 0);
	while (get_closed_nodes_size() != g.get_num_nodes())
	{
		graph::node voluteer_node = pq.top().first;
		graph::edge volunteer_edge = pq.top().second;
		if (is_node_visited(voluteer_node))
		{
			pq.pop();
		}

		add_closed_nodes(voluteer_node);
		distance += volunteer_edge;
		add_neighbours_to_pq(g, voluteer_node);
		pq.pop();
	}


	return distance;
}

/**
* Get the minimum spanning tree distance
*/
double mst::get_mst_distance()
{
	return distance;
}

/**
* Minimum spanning tree destructor
*/
mst::~mst()
{
	// destructor code here
}