#include "svg.h"

void svg_begin(double width, double height)
{
    cout << "<?xml version='1.0' encoding='UTF-8'?>\n";
    cout << "<svg ";
    cout << "width='" << width << "' ";
    cout << "height='" << height << "' ";
    cout << "viewBox='0 0 " << width << " " << height << "' ";
    cout << "xmlns='http://www.w3.org/2000/svg'>\n";
}

void svg_end()
{
    cout << "</svg>\n";
}

void svg_text(double left, double baseline, string text)
{
    cout << "<text x='" << left << "' y='" << baseline << "' >" << text << "</text>";
}

void svg_rect(double x, double y, double width, double height, string stroke, string fil)
{
    cout << "<rect x='" << x << "' y='" << y << "' width='" << width << "' height='" << height
         << "' stroke='" << stroke << "' fill='" << fil << "' />";
}

void show_histogram_svg(const vector<size_t>& bins, size_t SHIRINA_BLOCKA)
{

    const auto IMAGE_WIDTH = 400;
    const auto IMAGE_HEIGHT = 300;
    const auto TEXT_LEFT = 20;
    const auto TEXT_BASELINE = 20;
    const auto TEXT_WIDTH = 50;
    const auto BIN_HEIGHT = 30;
    const auto BLOCK_WIDTH = SHIRINA_BLOCKA;

    svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);

    double top = 0;

    size_t max_count = bins[0];

    for (size_t bin : bins)
    {
        if (bin > max_count)
        {
            max_count = bin;
        }
    }
    const size_t SCREEN_WIDTH = 100;
    const size_t MAX_ASTERISK = SCREEN_WIDTH - 50 - 20;
    for (size_t bin : bins)
    {
        const bool scalling_needed = max_count < MAX_ASTERISK;
        size_t bin_koeff = bin;
        if (scalling_needed)
        {
            const double koeff = (double)MAX_ASTERISK / max_count;
            bin_koeff = (size_t)(bin * koeff);
        }
        const double bin_width = BLOCK_WIDTH * bin_koeff;

        svg_text(TEXT_LEFT, top + TEXT_BASELINE, to_string(bin));
        svg_rect(TEXT_WIDTH, top, bin_width, BIN_HEIGHT, "red", "#ffeeee");
        top += BIN_HEIGHT;
    }

    svg_end();
}

string make_info_text ()
{
    stringstream buffer;

    DWORD /* ��� ������������ �������� double word 4 ����� */ info = GetVersion(); // ������� ��������� �������� ����� ������ Windows
    DWORD mask = 0x0000ffff; // ����� ��� ��������� ������
    DWORD version = info & mask;
    DWORD platform = info >> 16; // ����� ������ �� 16 ���
    DWORD mask_major = 0x0000ff;
    DWORD version_major = version & mask_major;
    DWORD version_minor = version >> 8;
    if ((info & 0x80000000) == 0) // �������� ��� ������� ��� = 0
    {
       DWORD build = platform;
       buffer << "Windows v" << version_major << "." << version_minor << " (build " << build << ") | ";
    }
    else printf("minor_bit = %u.\n", 1);
    char system_dir[MAX_PATH];
    char computer_name[MAX_COMPUTERNAME_LENGTH + 1];
    DWORD size = MAX_COMPUTERNAME_LENGTH + 1;
    GetComputerNameA(computer_name, &size); // ��������� ����� ����������
    buffer << /* �����, ������� << */ "Computer name: " << computer_name;

    return buffer.str();
}
