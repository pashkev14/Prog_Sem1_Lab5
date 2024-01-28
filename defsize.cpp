#include <fstream>

void defsize(std::ifstream& in, std::ofstream& out, int& est_rows, int& est_cols, bool& fail) {
	in.unsetf(std::ios::skipws);
	bool cols_changed = false;
	char tmp;
	unsigned int row_count = 0, col_count = 0, char_count = 0;
	in >> tmp;
	int arr_start = in.tellg();
	do {
		in >> tmp;
		if (in.eof()) {
			if (char_count) {
				++col_count;
				if (col_count < est_cols) {
					est_cols = col_count;
					cols_changed = true;
				}
			}
			if (col_count) ++row_count;
			break;
		}
		if ((tmp == ' ' || tmp == '\t') && char_count) {
			++col_count;
			char_count = 0;
		}
		else if (tmp == '\n') {
			if (char_count) ++col_count;
			if (col_count) ++row_count;
			if (col_count && col_count < est_cols) {
				est_cols = col_count;
				cols_changed = true;
			}
			char_count = 0;
			col_count = 0;
		}
		else if (tmp != ' ' && tmp != '\n' && tmp != '\t') ++char_count;
	} 
	while (true);
	if (row_count < est_rows) {
		if (row_count) out << "��������� ����� ����� �� ������������� �������������.\n� ������ ����� �������� �����: " << row_count << ".\n";
		est_rows = row_count;
	}
	else out << "��������� ����� ����� ������������� ��� �����������.\n";
	if (cols_changed && est_cols) out << "��������� ����� �������� �� ������������� �������������.\n� ������ ����� �������� ��������: " << est_cols << ".\n";
	else out << "��������� ����� �������� ������������� ��� �����������.\n";
	if (!est_rows || !est_cols) fail = true;
	in.clear();
	in.seekg(arr_start, std::ios::beg);
}