/*
	��������� �� ���������� ���������� ������� � �������� ����� � ����������� ������-������ �� ���� ��������
	�����: ����� ����� ����������, ������ 2309. ������ 5.1
	����: ������: 03.11.2022 ���������: 09.11.2022
*/

#include "defsize.h"
#include "inarr.h"
#include "outarr.h"
#include "process.h"

int main() {
	std::ifstream infile("in.txt");
	std::ofstream outfile("out.txt");
	outfile << "��������� ������ ������.\n";
	if (infile.is_open()) {
		int rows = 0, cols = 0;
		bool flag = false;
		infile >> rows >> cols;
		outfile << "������� �������� ��� ����� � �������� - " << rows << " � " << cols << ", ��������������.\n";
		if (rows <= 0 || cols <= 0) {
			outfile << "������������ ����� ����� �/��� ��������. ���� �� �������� ���������� ���������.\n��������� ��������� ������.";
			return 0;
		}
		outfile << "������������ ����������� �������� �������� ���������� �������.\n";
		defsize(infile, outfile, rows, cols, flag);
		if (flag) {
			outfile << "�� ������� ���������� ���������� ��������� ������ � �����. ���������� ��������� ����� ����������.\n��������� ��������� ������.";
			return 0;
		}
		outfile << "������������ ������ � ������.\n";
		float** A = new float* [rows];
		for (int i = 0; i < rows; ++i) *(A + i) = new float[cols];
		inarr(A, infile, rows, cols);
		outarr(A, rows, cols, outfile);
		process(A, rows, cols, outfile);
		for (int i = 0; i < rows; ++i) delete[] * (A + i);
		delete[]A;
	}
	else outfile << "������� ���� �� ������.\n";
	outfile << "��������� ��������� ������.";
	infile.close();
	outfile.close();
	return 0;
}