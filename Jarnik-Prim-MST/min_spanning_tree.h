#pragma once
#include <iostream>
#include <vector>
#include "graph.h"
#include <queue>

using namespace std;

class mst
{
public:
	mst();

	double prim_spanning_tree(graph g);
	vector<graph::node> get_closed_nodes();
	size_t get_closed_nodes_size();
	bool is_node_visited(graph::node node_x);
	void add_closed_nodes(graph::node node_x);
//	graph::node find_minimum_edge_size(graph g);
	double get_mst_distance();

	~mst();
private:
	double distance;
	vector<graph::node> closed_nodes;
	vector<bool> visited;
	priority_queue<graph::edge, vector<graph::edge>, greater<graph::edge>> pq;

};