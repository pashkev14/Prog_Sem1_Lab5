#include <fstream>

void outrow(float** a, int &row, int& cols, std::ofstream& out) {
	for (int i = 0; i < cols; ++i) out << *(*(a + row) + i) << ' ';	
	out << '\n';
}