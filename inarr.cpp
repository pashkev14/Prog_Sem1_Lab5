#include <fstream>

void inarr(float** a, std::ifstream& in, int& max_rows, int& max_cols) {
	char tmpc{};
	float tmpf;
	unsigned int chars_count = 0, rows_count = 0, cols_count = 0;
	int line_start, line_end;
	do {
		cols_count = 0;
		chars_count = 0;
		line_start = in.tellg();
		line_end = in.tellg();
		in.unsetf(std::ios::skipws);
		do {
			in >> tmpc;
			if (in.eof()) {
				if (chars_count) ++cols_count;
				tmpc = '\n';
			}
			if (tmpc != ' ' && tmpc != '\n' && tmpc != '\t') ++chars_count;
			if (chars_count && (tmpc == ' ' || tmpc == '\n' || tmpc == '\t')) ++cols_count;
		} 
		while (tmpc != '\n');
		if (in.eof()) in.clear();
		line_end = in.tellg();
		if (cols_count >= max_cols) {
			in.seekg(line_start, std::ios::beg);
			in.setf(std::ios::skipws);
			for (int i = 0; i < max_cols; ++i) {
				in >> tmpf;
				*(*(a + rows_count) + i) = tmpf;
			}
			++rows_count;
			in.seekg(line_end, std::ios::beg);
		}
		if (rows_count == max_rows) break;
	} 
	while (true);
}