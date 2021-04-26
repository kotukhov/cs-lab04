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

DWORD info = GetVersion();
DWORD mask = 0x0000ffff;
DWORD version = info & mask;
DWORD platform = info >> 16;
DWORD mask_major = 0x0000ff;
DWORD version_minor = version >> 8;
printf ("Windows version is %u.\n", version)
printf ("Version Major is %u.\n", version_major;
printf ("Version Minor is %u.\n", version_minor;
return 0;

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
