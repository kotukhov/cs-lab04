#pragma once

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <curl/curl.h>
using namespace std;

struct Input
{
    vector<double> numbers;
    size_t bin_count;
};

struct Configurations
{
    bool UseHint;
    char UrlPage;
};

size_t write_data(void* items, size_t iztem_size, size_t item count, void* ctx);
Input download(const string& address);
vector<double> input_numbers(istream& in, size_t count); // ввод значений
void find_minmax(vector<double> numbers, double& min, double& max); // нахождение мин. и макс. значения
vector<size_t> make_histogram(const Input input); // составляет гистограмму
void show_histogram_text(vector<size_t> bins); // отображает гистограмму в текстовом виде
Input read_input(istream& in, bool promt);

