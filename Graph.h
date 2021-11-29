//==============================================================================
// Filename: Graph.h
// Author: Aaron Thompson
// Date Created: 11/1/2021
// Date Last Modified: 10/1/2021
// Description: https://en.wikipedia.org/wiki/Graph_(discrete_mathematics)
// https://en.wikipedia.org/wiki/Graph_(abstract_data_type)
//==============================================================================
#ifndef GRAPH_H
#define GRAPH_H

#include "Map.h"
#include "Vector.h"
#include "Array.h"

template <class K>
struct Edge {
	K start;
	K end;
	double weight=1;
};

namespace ds {
template <class K, class T>
class Graph {
//VARIABLE(s)
//------------------------------------------------------------------------------
	public:
		const int& count() { return data.count(); }
		const bool& empty() { return data.empty(); }
		const bool& directed() { return _directed; }
		const Array<Edge<K>>& path() { return _path; }
	private:
		HashMap<K, T> data;
		HashMap<K, Vector<Edge<K>>> graph;
		bool _directed;
		Array<Edge<K>> _path;
		unsigned int (*pHash)(K);

//FUNCTION(s)
//------------------------------------------------------------------------------
	public:
		//Data Manipulation Function(s)
		void AddVertex(K label, T value) {
			data.Add(label, value);
			if(graph.Find(label) == -1) {
				Vector<Edge<K>> edges = Vector<Edge<K>>();
				graph.Add(label, edges);
			}
		}

		void AddDirectedEdge(K a, K b, double weight=1);
		void AddUndirectedEdge(K a, K b, double weight=1);
		void AddEdge(K a, K b, double weight, bool directed=false);
		void AddEdge(K a, K b, bool directed=false);

		void RemoveVertex(K label) {
			data.Remove(label);
			graph.Remove(label);
		}

		void RemoveEdge(K a, K b, bool directed = false);
		void Clear();


//CONSTRUCTOR(s)/DESTRUCTOR(s)
//------------------------------------------------------------------------------

//FUNCTION(s)
//------------------------------------------------------------------------------
		//Data Retrieval Function(s)
		Array<Array<double>> GetAdjacencyMatrix();
		Array<Edge<K>> GetEdges(K v);
		Array<Pair<K, T>> GetNeighbors(K v);
		int GetDegree();
		int GetIndegree();
		int GetOutdegree();
		Array<Pair<K, T>> GetVertices();
		Array<K> GetLabels();
		Array<T> GetData();
		Array<Edge<K>> GetEdges();

		//Search Function(s)
		bool BFS(K start, K target);
		bool DFS(K start, K target);
};

} //END namespace ds
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
#endif //END namespace GRAPH_H
