#pragma once
#define TRUE 1 

///<Library>
#include <io.h>
#include <process.h> /* for getpid() and the exec..() family */
#include <direct.h>
#include <fcntl.h>		/* open() and O_XXX flags */
#include <sys/stat.h>	/* S_IXXX flags */
#include <sys/types.h>	/* mode_t */
#include <Windows.h>
#include <stdio.h> 
#include <conio.h>
#include <process.h> 
#include <stdlib.h> 
#include <iostream>
#include<fstream>
#include<string>

#pragma warning(disable : 4996)

void BaseLevelTask();
void MidleTaskLevel();
///<\Library>

///<UsidFunctions> 


int BlockWriteFile(char* FileName, const char* Mode_Open_File,  //���������� ���������� � ���� � ������ String, �������� � ������ Mode, k ������ ����������� nxm.
	unsigned count_matrix, unsigned row, unsigned col); 


int* InitMatrix(unsigned,  //���������� ��������� �� ������� ������������ ������ �������� n*m*sizeof(int), ���������� �������� �������� �������, ����������� ������ l+1.
	unsigned, unsigned);


int* FreeMemory(unsigned, unsigned);//���������� ��������� �� ������� ������������ ������ �������� n*m*sizeof(int) ��� �������� ������������ ������� ����������� nxm.


void DisplayFile(const char*, const char*, unsigned, unsigned);//���������� ������� �� ����� ���������� ����� � ������ String, �������� � ������ Mode


void DisplayMatrix(int*, unsigned, unsigned); //������� �� ����� ���������� ������������ ������ �������� n*m*sizeof(int) �� ������ Pointer


void FillNewFileUnwantedMatrix(char* FileName1, char* FileName2, unsigned set_pos, unsigned count_matrix, unsigned row, unsigned col);//��������� 3�� ���� ������� ��������� �� �������


void DeleteUnwantedMatrixOfFile(char* String,  unsigned position, unsigned n, unsigned m);

///<\UsidFunctions>
