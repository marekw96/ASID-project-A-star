#include <iostream>
#include <string>
#include "include/Graph.h"
#include <fstream>

using namespace std;

int main()
{
	string name = "graph.txt";

	cout << "Podaj nazwe pliku z macierza: ";
	cin >> name;
	ifstream file;
	file.open(name);
	if (!file.good())
		cout << "Z³y plik :/";

	Graph graph(file);

	cout << endl << "Rozmiar macierzy: ";
	cout << graph.getXsize() << " x " << graph.getYsize() << endl;

	int x1, x2, y1, y2;
	cout << "Skad szukac: ";
	cin >> x1 >> y1;
	cout << "Docelowy: ";
	cin >> x2 >> y2;

	if(!graph.getValueOfNode(x1,y1))
	{
		cout << "To pole (" << x1 << "," << y1 << ") jest niedostepne";
		exit(1);
	}

	if (!graph.getValueOfNode(x2, y2))
	{
		cout << "To pole (" << x2 << "," << y2 << ") jest niedostepne";
		exit(1);
	}

	auto patch = graph.getPatch(x1, y1, x2, y2);
	if (patch.size())
	{
		cout << "Znalezione droga prowadzi przez:" << endl; 
		for (const auto &p : patch) 
			std::cout << p.first << " " << p.second << std::endl;
	}
	else
		cout << "Brak drogi";

	cin.ignore();
	cin.get();
	return 0;
}