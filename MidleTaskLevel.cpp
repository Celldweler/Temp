#include"FunctionsUsed.h"

using namespace std;
/*
Дан файл f, компоненты которого являются целыми числами. Никакая из компонент файла не равна нулю. Файл f содержит столько же 
отрицательных чисел, сколько и положительных. Используя вспомогательный файл h, переписать компоненты файла f в файл g так, чтобы в файле
g сначала шли положительные, потом отрицательные числа.
*/
void MidleTaskLevel()
{//C:\\Users\\$Raime\\source\\repos\\Temp
	cout << "\Midle task level\n";
	FILE* f_out, *f_in,
		    *h_out, *h_in,//temp_file
		    *g_out, *g_in ;//файл в который надо записать сначала поло-ые числа затем отриц-ые
	//int handle;
	//handle = open("BaseFile", O_CREAT | O_WRONLY | O_TEXT, S_IREAD | S_IWRITE);

	f_out = fopen("basefile",  "wb");
	int var;
	cout << "\nСодержимое файла до обработки <<BaseFile.bin>> :\n";
	
	for (size_t i = 0; i < 10; i++)
	{
		fwrite(&(var = (1 + rand() % 10)), sizeof(int), 1, f_out);
		cout << var << " ";
		fwrite(&(var = (-1 - rand() % 10)), sizeof(int), 1, f_out);
		cout << var << " ";
	}
	cout << "\nСодержимое файла до обработки <<posdigfile.bin>> : <<posdigfile.bin>> is Empty\n";
	cout << "\nСодержимое файла до обработки <<negdigfile.bin>> : <<negdigfile.bin>> is Empty\n";
	int* buffer = (int*)malloc(20*sizeof(int));
		fclose(f_out);
		f_out = fopen("basefile", "rb");
		h_out = fopen("negdigfile", "wb");
		g_out = fopen("posdigfile", "wb");
		fread(buffer, sizeof(int), 20, f_out);
		fclose(f_out);
		int countneg = 0;
		cout << "\nСодержимое файла после обработки <<negdigfile.bin>> :\n";
		for (size_t i = 0; i < 20; i++)
		{
			if (buffer[i] < 0)
			{
				fwrite(&buffer[i], sizeof(int), 1, h_out); countneg++;
				cout << buffer[i] << " ";
			}
			else
			{
				fwrite(&buffer[i], sizeof(int), 1, g_out);
				//cout << buffer[i] << " ";

			}
		}
		fclose(h_out);
		fclose(g_out);
		free(buffer);
		buffer = new int[countneg];
		g_out = fopen("posdigfile", "ab");
		h_out = fopen("negdigfile", "rb");
		fread(buffer, sizeof(int), countneg, h_out);
		fwrite(buffer, sizeof(int), countneg, g_out);
		fclose(h_out);
		fclose(g_out);
		free(buffer);
		cout << "\nСодержимое файла после обработки <<BaseFile.bin>> : осталось без изменений\n";
		cout << "\nСодержимое файла после обработки <<posdigfile.bin>> :\n";
		buffer = (int*)malloc(20 * sizeof(int));
		f_out = fopen("posdigfile", "rb");
		fread(buffer, sizeof(int), 20, f_out);
		for (size_t i = 0; i < 20; i++)
		{
			cout << buffer[i] << " ";
		}
		free(buffer);
		fclose(f_out);
		//cout << "\nСодержимое файла после обработки <<posdigfile.bin>> :\n";

		

}