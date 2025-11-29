# include <iostream>
# include <fstream>
# include "Complex.h"
using namespace std;

int main() {
	ifstream domain("domain.txt");
	ofstream nFile("nfile.txt");
	Complex z0, z;
	double numRows = 500, numCols = 500, nMax = 5000, row, col, n;
	double realMin, realMax, imagMin, imagMax;
	domain >> realMin; domain >> realMax; domain >> imagMin; domain >> imagMax;
	cout << realMin << " ";
	cout << realMax << " ";
	cout << imagMin << " ";
	cout << imagMax << endl;
	for (row = 0; row < numRows; row++) {
		for (col = 0; col < numCols; col++) {
			z0.setVals((realMax - realMin) * col / (numCols - 1.0) + realMin, (imagMax - imagMin) * row / (numRows - 1.0) + imagMin);
			z = z0; n = 0;
			while (n < nMax && z.getMag() < 2) {
				z = z * z + z0;
				n++;
			}
			nFile << n << " ";
		}
		nFile << endl;
	}
	domain.close(); nFile.close();
	return 0;
}

void generateSmallGrid() {
	ofstream FID("LabData.txt");
	const int numRows = 24, numCols = 20;
	Complex z[numRows][numCols];

	for (int row = 0; row < numRows; row++) {
		for (int col = 0; col < numCols; col++) {
			double realVal = -1.5 + col * (0.5 + 1.5) / (numCols - 1);
			double imagVal = -1.2 + row * (1.2 + 1.2) / (numRows - 1);
			z[row][col].setVals(realVal, imagVal);

			z[row][col] = z[row][col] * z[row][col] + z[row][col];

			FID << z[row][col].getMag() << " ";
		}
		FID << endl;
	}

	FID.close();
	cout << "24x20 grid written to LabData.txt" << endl;
}
