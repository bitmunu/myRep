/* Вариант - 7.

2.	Дан файл, содержащий русский текст, размер текста не превышает 10 К байт.
Найти в тексте N(N ≤ 100) самых длинных слов, содержащих заданную букву и не содержащих другую заданную букву.
Записать найденные слова в текстовый файл в порядке не возрастания длины.
Все найденные слова должны быть разными. Число N вводить из файла.*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <locale.h>
#include <algorithm>
#include <set>

bool sortVec(std::string a, std::string b);
void make_Words_Clean(std::vector<std::string>& a);
void erase_Words_Criteria(std::vector<std::string>& a);
void erase_Equal_Words(std::vector<std::string> &a);


int main()
{
    std::ifstream in;

    in.open("input.txt");

    if (!in.is_open())
    {
        std::cout << "file is not open";
        return 1;
    }

    char N[1] = { ' ' };
    in.read (N, 1);
    in.seekg(0);
    int n = (int)N[0] - 48;

    std::vector<std::string> vec;
    std::string b;

    int cnt = 0;
    while (!in.eof())
    {
        std::getline(in, b, ' ');
        vec.push_back(b);
        cnt++;
    }

    make_Words_Clean(vec);
    erase_Words_Criteria(vec);
    erase_Equal_Words(vec);
    std::sort(vec.begin(), vec.end(), sortVec);

    std::ofstream out;
    out.open("output.txt");

    if (!out.is_open())
    {
        std::cout << "file is not open";
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        std::cout << vec[i] << std::endl;
        out << vec[i] << std::endl;
    }
}

bool sortVec(std::string a, std::string b)
{
    return a.length() > b.length();
}

void erase_Words_Criteria(std::vector<std::string>& a)
{
    bool ee = 0; // нужная буква 'e'
    bool nn = 0; // ненужная буква 'n'

    for (int i = 0; i < a.size(); i++)
    {
        ee = 0;
        nn = 0;

        for (int j = 0; j < a[i].length(); j++)
        {
            if (a[i][j] == 'e')
            {
                ee = 1;
            }

            else if (a[i][j] == 'n')
            {
                nn = 1;
            }

        }

        if ((nn == 1) || ((nn != 1) && (ee != 1)))
        {
            a.erase((a.begin() + i));
            i--;
        }
    }
}

void erase_Equal_Words(std::vector<std::string> &a)
{
    std::set<std::string> s(a.begin(), a.end());
    a.assign(s.begin(), s.end());
}

void make_Words_Clean(std::vector<std::string>& a)
{
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a[i].length(); j++)
        {
            if (a[i][j] == ',' || a[i][j] == '.' || a[i][j] == '!' || a[i][j] == '?' || a[i][j] == ':')
            {
                a[i].erase(j);
            }
        }
    }
}