#include "Sun.h"
#include <iostream>
#include <cmath>

namespace myspace
{
	void read(int* k[], const int n)
	{
		for (int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				std::cin >> k[i][j];
			}
		}
	}

	void show(int* k[], const int n)
	{
		std::cout << std::endl;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				std::cout << "[" << k[i][j] << "]" << " ";
			}
			std::cout << std::endl;
		}
	}

	bool if_max(int* k[], const int n)
	{
		bool c = 1;
		for (int i = 0; i < n; i++)
		{
			int iMax = k[i][0];
			for (int j = 1; j < n; j++)
			{
				if (k[i][j] >= iMax)
				{
					iMax = k[i][j];
				}
			}
			if (iMax != k[i][i])
			{
				c = 0;
				break;
			}
		}
		if (c == 0)
		{
			return 0;
		}
		else return 1;
	}

	int node(int* k[], const int n)
	{
		int Proizv = 1;
		for (int i = 0; i < n; i++)
		{
			Proizv = Proizv * k[i][i];
		}
		return Proizv;
	}

	void infect_with_max(int* k[], const int n, int Proizv)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (k[i][j] == 0)
				{
					k[i][j] = Proizv;
				}
			}
		}
	}
}