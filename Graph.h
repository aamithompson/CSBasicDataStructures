//==============================================================================
// Filename: Graph.h
// Author: Aaron Thompson
// Date Created: 11/1/2021
// Date Last Modified: 12/1/2021
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

template <class K>
bool operator==(const Edge<K>& lhs, const Edge<K>& rhs) {
	return (lhs.start==rhs.start) && (lhs.end == rhs.end);
}

namespace ds {
template <class K, class T>
class Graph {
//VARIABLE(s)
//------------------------------------------------------------------------------
	public:
		const int& count() { return data.count(); }
		const bool& empty() { return data.empty(); }
		const bool& directed() { return _directed; }
		const Array<Edge<K>>& path() { return new Array<Edge<K>>(_path, _path.length()); }
		const bool& pathfound() { return _pathfound; }
	private:
		HashMap<K, T> data;
		HashMap<K, Vector<Edge<K>>*> graph;
		bool _directed;
		Array<Edge<K>> _path;
		bool _pathfound;
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

		void AddDirectedEdge(K a, K b, double weight = 1) {
			Vector<Edge<K>> * edges = graph.GetValue(a);
			Edge edge = { a, b, weight };
			edges->Add(edge);
		}

		void AddUndirectedEdge(K a, K b, double weight=1) {
			AddDirectedEdge(a, b, weight);
			AddDirectedEdge(b, a, weight);
		}

		void AddEdge(K a, K b, double weight, bool directed=false) {
			if(directed) {
				AddDirectedEdge(a, b, weight);
			} else {
				AddUndirectedEdge(a, b, weight);
			}
		}

		void AddEdge(K a, K b, bool directed=false) {
			AddEdge(a, b, 1.0, true);
		}

		//TODO: SEARCH GRAPH EDGES VECTORS TO REMOVE EDGE
		void RemoveVertex(K label) {
			data.Remove(label);
			graph.Remove(label);
		}

		void RemoveDirectedEdge(K a, K b) {
			Vector<Edge<K>> * edges = graph.GetValue(a);
			Edge edge = { a, b, 0.0 };
			edges->Remove(edge)
		}

		void RemoveUndirectedEdge(K a, K b) {
			RemoveDirectedEdge(a, b);
			RemoveDirectedEdge(b, a);
		}

		void RemoveEdge(K a, K b, bool directed = false) {
			if(directed) {
				RemoveDirectedEdge(a, b);
			} else {
				RemoveUndirectedEdge(a, b);
			}
		}

		void Clear() {
			data.Clear();
			Array<K> arr = graph.Keys();
			for (int i = 0; i < arr.length(); i++) {
				Vector<Edge<K>> * edges = graph.GetValue(arr[i]);
				delete edges;
			}
			graph.Clear();
		}


//CONSTRUCTOR(s)/DESTRUCTOR(s)
//------------------------------------------------------------------------------

//FUNCTION(s)
//------------------------------------------------------------------------------
		//Data Retrieval Function(s)
		//TODO: CHECK
		Array<Array<double>> GetAdjacencyMatrix() {
			Array<Array<double>> matrix = Array<Array<double>>(data.count());
			Array<K> arr = graph.Keys();
			for(int i = 0; i < matrix.length(); i++) {
				Array<double> row = Array<double>(data.count());
				Vector<Edge<K>> * edges = graph.GetValue(arr[i]);
				for(int j = 0; j < row.length(); j++) {
					for(int k = 0; k < edges.length(); k++) {
						if((*edges)[k] == arr[j]) {
							row[j] = (*edges)[k].weight;
						}
					}
				}

				matrix[i] = Array<double>(row, row.length());
			}

			return matrix;
		}

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
