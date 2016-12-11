#ifndef GRAPH_CLASS
#define GRAPH_CLASS

#include <fstream>
#include <vector>
#include <utility>

class Graph
{
private:
	std::ifstream &f;
	std::vector<int> matrix;
	std::pair<int, int> xy;

	void parseGraphFromFile();

public:
	Graph(std::ifstream &file);
	Graph() = delete;
	Graph(const Graph &g) = delete;
	Graph(const Graph &&g) = delete;
	~Graph();

	int getValueOfNode(const int &x, const int &y) const;
	int getXsize() const;
	int getYsize() const;
	double approxDistance(const int &x1, const int &y1, const int &x2, const int &y2) const;
	std::vector<std::pair<int, int>> getPatch(const int &x1, const int &y1, const int &x2, const int &y2);
	std::vector<std::pair<int,int>> getNeighbors(const int &x, const int &y);
};

#endif // !GRAPH_CLASS

