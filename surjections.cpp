// surjections.cpp
// Christian Ellison
#include <iostream>
#include <fstream>
// Other include files?
using namespace std;
int power(int, int);
int NIFormula(int, int, int&);
int Srecursive(ifstream&, ofstream&, int, int);

void main() {
	ifstream fin("surjections.in");
	if (fin.is_open()) {
		ofstream fout("surjections.out");

		int m, n;

		fin >> m; fin >> n;

		while (!fin.eof())
		{
			fout << "S(" << m << "," << n << ") = " << Srecursive(fin, fout, m, n) << endl;
			fin >> m; fin >> n;
		}

		fout.close();
		fin.close();
	}
	else {
		cout << "Input file not found." << endl;
	}
}


int Srecursive(ifstream &fin, ofstream &fout, int m, int n)
{
	int result = 0;
	if (n == 1)
	{
		result = 1;
		//fout << "S(" << m << "," << n << ") = " << 1 << endl;
		return result;
	}
	else if (m < n)
	{
		//fout << "S(" << m << "," << n << ") = " << 0 << endl;
		return result;
	}
	else if (m == n)
	{
		int temp = m;
		for (int i = m - 1; i > 1; i--)
			temp *= i;
		result = temp;
		//fout << "S(" << m << "," << n << ") = " << temp << endl;
		return result;
	}
	else
	{
		int pow = power(n, m);
		int NI = 0, S = 0;
		//fout << pow << endl;
		for (int i = 1; i < n; i++)
		{
			NI += NIFormula(n, i, NI);
			S += Srecursive(fin, fout, m, i);
		}
		result = pow - NI * S;
		return result;
	}
}
int NIFormula(int n, int i, int &total)
{
	if (0 < i && i < n)
	{
		total = NIFormula(n - 1, i - 1, total) + NIFormula(n - 1, i, total);
		return total;
	}
	else
		return 1;
}

int power(int base, int power)
{
	int total = base;
	for (int i = power; i > 1; i--)
	{
		total *= base;
	}
	return total;
}