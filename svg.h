#pragma once

#include <iostream>
#include <vector>
#include <sstream>
#include <windows.h>
#include <curl/curl.h>

using namespace std;

void svg_begin(double width, double height); // вывод загаловка
void svg_end(); // окончание cvg
void svg_text(double left, double baseline, string text); // вывод подписей к столбцам
void svg_rect(double x, double y, double width, double height, string stroke = "black", string fil = "black"); // вывод прямоугольника в svg
void show_histogram_svg(const vector<size_t>& bins, size_t SHIRINA_BLOCKA); // вывод гистограммы в svg
string make_info_text(); // строка под гистограммой svg
