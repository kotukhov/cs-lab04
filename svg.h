#pragma once

#include <iostream>
#include <vector>
#include <sstream>
#include <windows.h>
#include <curl/curl.h>

using namespace std;

void svg_begin(double width, double height); // ����� ���������
void svg_end(); // ��������� cvg
void svg_text(double left, double baseline, string text); // ����� �������� � ��������
void svg_rect(double x, double y, double width, double height, string stroke = "black", string fil = "black"); // ����� �������������� � svg
void show_histogram_svg(const vector<size_t>& bins, size_t SHIRINA_BLOCKA); // ����� ����������� � svg
string make_info_text(); // ������ ��� ������������ svg
