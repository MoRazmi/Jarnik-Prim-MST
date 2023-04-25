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
	double get_mst_distance();
	void add_edges_to_pq(graph::node node, graph::edge edge);
	void add_neighbours_to_pq(graph g,graph::node node);


	~mst();
private:
	double distance;
	vector<graph::node> closed_nodes;
	vector<bool> visited;
	priority_queue<pair<graph::node, graph::edge>, vector<pair<graph::node, graph::edge>>, greater<pair<graph::node, graph::edge>>> pq;

	// Define a custom comparator for the priority queue
	struct CompareNodeEdge {
		bool operator()(const pair<graph::node, graph::edge>& lhs, const pair<graph::node, graph::edge>& rhs) const {
			return lhs.second > rhs.second;
		}
	};

};