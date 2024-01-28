/*
	Программа по считыванию двумерного массива с входного файла и образования вектор-строки из сумм столбцов
	Автор: Савин Павел Алексеевич, группа 2309. Версия 5.1
	Даты: Начало: 03.11.2022 Окончание: 09.11.2022
*/

#include "defsize.h"
#include "inarr.h"
#include "outarr.h"
#include "process.h"

int main() {
	std::ifstream infile("in.txt");
	std::ofstream outfile("out.txt");
	outfile << "Программа начала работу.\n";
	if (infile.is_open()) {
		int rows = 0, cols = 0;
		bool flag = false;
		infile >> rows >> cols;
		outfile << "Считаны значения для строк и столбцов - " << rows << " и " << cols << ", соответственно.\n";
		if (rows <= 0 || cols <= 0) {
			outfile << "Недопустимое число строк и/или столбцов. Файл не подлежит дальнейшей обработке.\nПрограмма завершила работу.";
			return 0;
		}
		outfile << "Производится определение реальных размеров двумерного массива.\n";
		defsize(infile, outfile, rows, cols, flag);
		if (flag) {
			outfile << "Не удалось определить корректный двумерный массив в файле. Дальнейшая обработка файла невозможна.\nПрограмма завершила работу.";
			return 0;
		}
		outfile << "Производится запись в массив.\n";
		float** A = new float* [rows];
		for (int i = 0; i < rows; ++i) *(A + i) = new float[cols];
		inarr(A, infile, rows, cols);
		outarr(A, rows, cols, outfile);
		process(A, rows, cols, outfile);
		for (int i = 0; i < rows; ++i) delete[] * (A + i);
		delete[]A;
	}
	else outfile << "Входной файл не найден.\n";
	outfile << "Программа завершила работу.";
	infile.close();
	outfile.close();
	return 0;
}