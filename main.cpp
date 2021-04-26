﻿#include <iostream>
#include <vector>
#include "histogram.h"
#include "svg.h"

using namespace std;

int main()
{
    size_t number_count;
    cerr << "Enter number count: ";
    cin >> number_count;
    cerr << "Enter numbers: ";
    const auto numbers = input_numbers(cin, number_count);
    size_t bin_count;
    cerr << "Enter column count: ";
    cin >> bin_count;
    const auto bins = make_histogram (numbers, bin_count);
    size_t F, BLOCK;
    cerr << "Enter BLOCK_WIDTH behind 3 and 30";
    cin >> F;
    show_histogram_svg(bins, F);
    return 0;
}

