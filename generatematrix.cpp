#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	string fn;
	unsigned int x, y;
	char fill;
	cout << "Plik wyjsciowy: ";
	cin >> fn;
	cout << "Rozmiar (X Y): ";
	cin >> x >> y;
	cout << "Uzupelniaj znakiem: ";
	cin >> fill;

	ofstream out(fn);
	out << x <<" "<< y << endl;
	for(unsigned int j = 0; j < y; j++)
	{
		for (unsigned int i = 0; i < x; i++)
			out << fill << " ";
		out << endl;
	}

	out.close();
	/*
	cin.ignore();
	cin.get();*/
	return 0;
}