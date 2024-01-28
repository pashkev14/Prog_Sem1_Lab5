#include <fstream>
#include "outrow.h"

void process(float** a, int& rows, int& cols, std::ofstream& out) {
	float** p = new float* [1];
	*p = new float[cols];
	for (int i = 0; i < cols; ++i) {
		float summary = 0.0;
		for (int j = 0; j < rows; ++j) summary += *(*(a + j) + i);
		*(*p + i) = summary;
	}
	out << "Сформирован вектор:\n";
	int* row = new int(0);
	outrow(p, *row, cols, out);
	delete row;
	delete[] * (p + 0);
	delete []p;
}