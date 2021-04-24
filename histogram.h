#pragma once

#include <iostream>
#include <vector>

using namespace std;

vector<double> input_numbers(size_t count); // ввод значений
void find_minmax(vector<double> numbers, double& min, double& max); // нахождение мин. и макс. значения
vector<size_t> make_histogram(vector<double>numbers, size_t bin_count); // составляет гистограмму
void show_histogram_text(vector<size_t> bins); // отображает гистограмму в текстовом виде

