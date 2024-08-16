#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX 500
void Initboard(char squre[MAX][MAX], int n, int m);

void flash(char squre[MAX][MAX], int n, int m);

void print(char squre[MAX][MAX], int n, int m);