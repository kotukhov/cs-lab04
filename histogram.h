#pragma once

#include <iostream>
#include <vector>

using namespace std;

struct Input {
    vector<double> numbers;
    size_t bin_count;
};

vector<double> input_numbers(istream& in, size_t count); // ввод значений
void find_minmax(vector<double> numbers, double& min, double& max); // нахождение мин. и макс. значения
vector<size_t> make_histogram(const Input input); // составляет гистограмму
void show_histogram_text(vector<size_t> bins); // отображает гистограмму в текстовом виде
Input read_input(istream& in, bool promt);
