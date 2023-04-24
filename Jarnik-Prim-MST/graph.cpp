#include "graph.h"
#include <vector>


using namespace std;

/**
* Graph constructors
*/
graph::graph(int node_num) 
{
	nodes.reserve(node_num);
	for (int i = 0; i < node_num; i++) 
	{
		nodes.emplace_back(i);
	}
	edges = vector<vector<edge>>(node_num, vector<edge>(node_num, 0.0));
}

/**
* Graph destructor
*/
graph::~graph()
{
	nodes.clear();
	vector<vector<edge>>().swap(edges);
}



/**
* Get number of nodes in the graph
*/

const size_t graph::get_num_nodes(void)
{
	return nodes.size();
}

graph::node graph::get_node(int x)
{
	return nodes[x];
}

/**
* Get number of edges in the graph
*/
const int graph::get_num_edges(void)
{
	int num_non_zero_element = 0;
	for (int i = 0; i < edges.size(); i++)
	{
		for (int j = 0; j < edges[i].size(); j++)
		{
			if (edges[i][j] != 0)
			{
				++num_non_zero_element;
			}
		}
	}
	int num_edges = num_non_zero_element / 2;

	return num_edges;
}

/**
* Check if two nodes are conncted in the graph
*/
const bool graph::is_connected(node node_x, node node_y)
{
	return(edges[node_x][node_y] != 0);
}

/**
* Get the neighbour of a node connected via an edges
*/
vector<pair<graph::node, graph::edge>> graph::get_neighbors(node node_x)
{

	vector<pair<node, edge>> neighbors;
	for (int i = 0; i < get_num_nodes(); i++)
	{
		double weight = edges[node_x][i];
		if (weight != 0)
		{
			neighbors.push_back(make_pair(i, weight));
		}
	}

	return neighbors;
}

/**
* Get neighbors of a node
*/
vector<graph::node> graph::get_neighbors_nodes(node node_x)
{
	vector <node> neighbors_node;
	for (int i = 0; i < get_num_nodes(); i++)
	{
		if (is_connected(node_x, i))
		{
			neighbors_node.push_back(i);
		}
	}
	return neighbors_node;
}

/**
* Get edges corresponding to neighbors of a node
*/
vector<graph::edge> graph::get_neighbors_edges(node node_x, node node_y)
{
	vector<edge> neighbors_edge;
	for (int i = 0; i < get_num_nodes(); i++)
	{
		double weight = edges[node_x][i];
		if (weight != 0)
		{
			neighbors_edge.push_back(weight);
		}

	}
	return neighbors_edge;
}




/**
* Add an edge between two nodes
*/
void graph::add_edge(int x, int y, const edge weight)
{
	edges[x][y] = weight;
	edges[y][x] = weight;
}

/**
* Delete an edge from from the graph
*/
void graph::delete_edge(node x, node y)
{
	edges[x][y] = edges[y][x] = 0.0;
}

/**
* Get the weight between two nodes
*/
const graph::edge graph::get_edge_value(node x, node y)
{
	if (is_connected(x, y) )
	{
		return edges[x][y];
	}
	return -1;
}


/** 
* Friend operator to print the graph with ostream
*/
ostream& operator<<(ostream& os, graph& g) 
{
	for (auto it = g.nodes.begin(); it != g.nodes.end(); ++it)
	{
		auto neighbors = g.get_neighbors_nodes(*it);
		os << "Node " << *it << ":";
		for (auto jt = neighbors.begin(); jt != neighbors.end(); ++jt) {
			os << " (" << *jt << ", " << g.get_edge_value(*it, *jt) << ")";
		}
		os << endl;
	}
	return os;
}