#include <iostream>
#include <vector>
#include "histogram.h"
#include "svg.h"
#include <curl/curl.h>
#include <windows.h>
#include <cstdio>
using namespace std;
int main(int argc, char* argv[])
{
    string info = make_info_text();
    Input input;
    if (argc > 1)
    {
        input = download(argv[1]);
    }
    else
    {
        input = read_input(cin, true);

    }
    const auto bins = make_histogram(input);
    size_t F;
    cerr << "Enter BLOCK_WIDTH behind 3 and 30";
    cin >> F;
    show_histogram_svg(bins, F);
    return 0;
}

