#include <iostream>
#include <vector>
#include "histogram.h"
#include "svg.h"
#include <curl/curl.h>
#include <sstream>
#include <string>
#include <windows.h>

using namespace std;

int main(int argc, char* argv[])
{

    /*
    const char* name = "Commander Shepard";
int year = 2154;
printf("%s was born in %d.\n", name, year);
// Commander Shepard was born in 2154.
    */
    Input input;
    if (argc > 1)
    {
        // работа с cURL
        input = download(argv[1]);
    }
    else
    {
        input = read_input(cin, true);

    }
    printf("Windows (decimal) version is %u.\n", GetVersion());
    printf("Windows (16x) version is %x. \n", GetVersion());
    return 0;

    input = read_input(cin, true);
    const auto bins = make_histogram(input);
    size_t F;
    cerr << "Enter BLOCK_WIDTH behind 3 and 30";
    cin >> F;
    show_histogram_svg(bins, F);
    return 0;
}


/*size_t number_count;
    cerr << "Enter number count: ";
    cin >> number_count;
    cerr << "Enter numbers: ";
    const auto numbers = input_numbers(cin, number_count);
    size_t bin_count;
    cerr << "Enter column count: ";
    cin >> bin_count; */
