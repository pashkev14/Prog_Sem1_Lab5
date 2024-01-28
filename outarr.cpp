#include <fstream>
#include "outrow.h"

void outarr(float** a, int& rows, int& cols, std::ofstream& out) {
	out << "—читан массив:\n";
	for (int i = 0; i < rows; ++i) outrow(a, i, cols, out);
}