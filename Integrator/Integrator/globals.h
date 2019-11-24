#pragma once

#define LOG(format, ...) log(__FILE__, __LINE__, format, __VA_ARGS__);
void log(const char file[], int line, const char* format, ...);

#define SCREEN_SIZE 2
#define SCREEN_WIDTH 1080
#define SCREEN_HEIGHT 720
#define WIN_FULLSCREEN 0
#define WIN_FULLSCREEN_DESKTOP 0
#define WIN_BORDERLESS 0
#define WIN_RESIZABLE 0

const double GRAVITY = -9.81;

const double WATER_DENSITY = 1000.0;
const double AIR_DENSITY = 1.2;

const double fps = 60.0;
double dt;