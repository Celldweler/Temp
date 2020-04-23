#include"FunctionsUsed.h"
using namespace std;
/*
Базовый уровень
Задание: 
создать текстовый файл с произвольной информацией. Организовать  просмотр содержимого файла. 
Организовать чтение и обработку данных из файла в соответствии с индивидуальным заданием. 
Сохранить полученные результаты в новый текстовый файл:

 «Школьник»: фамилия; имя; отчество; пол; национальность; рост; вес; дата рождения (год, месяц 
 число); номер телефона; домашний адрес (почтовый индекс, страна, область, район, город, улица,
 дом, квартира); школа; класс. Вывести сведения про всех учеников пятых классов
*/
#ifndef _Schoolboy
#define _Schoolboy
struct Schoolboy
{
    string   fio;
    unsigned clas;
};
#endif // !_Schoolboy


void BaseLevelTask()
{
	cout << "\nBase task level\n";
    FILE* f_in, *f_out;
    f_out = fopen("Schoolboys", "wb");
    string mas_name[] = { "Михайл Грибков Сергеевич", "Березуцкий Сергей Вячеславович", "Валяев Ахмед Расим Оглу"};
    Schoolboy* mas = new Schoolboy[3];
    for (size_t i = 0; i < 3; i++)
    {
        mas[i].fio = mas_name[i];
        mas[i].clas = 2 + rand() % 4;
    }
    fread(mas, sizeof(Schoolboy), 3, f_out);
    cout << "\nДанные о школьниках прочитанны с файла <<Schoolboys.bin>>: \n";
    f_in = fopen("Schoolboys", "rb");
    f_out = fopen("schoolboys5clases", "w + b");
    fread(mas, sizeof(Schoolboy), 3, f_in);
    fclose(f_in);
    int counter = 0;
    for (size_t i = 0; i < 3; i++)
    {
        if (mas[i].clas == 5)
        {
            fwrite(&mas[i], sizeof(Schoolboy), 1, f_out); counter++;
        }
        cout << "\t" << i + 1 << "." << mas[i].fio << " " << mas[i].clas << "\n";
    }
            fclose(f_out);
    cout << "\nДанные об всех учениках 5ых классов прочитанных с файла <<schoolboys5clases.bin>>: \n";
    if (counter == 0)
    {
        cout << "\tДанные о 5класниках отсутствуют в файле \n";
        delete[] mas;
        return;

    }
    
      Schoolboy* buffer = new Schoolboy[counter];
    f_in = fopen("schoolboys5clases", "rb");
    fread(buffer, sizeof(Schoolboy), counter, f_in);
    for (size_t i = 0; i < counter; i++)
    {
        cout << "\t" << i + 1 << "." << buffer[i].fio << " " << buffer[i].clas << "\n";

    }
    fclose(f_in);

}
