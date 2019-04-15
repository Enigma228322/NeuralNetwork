#pragma once
#include <iostream>

class NetMatr
{
private:
	double **matr;
	int n, m;
	bool check_empty = true;
	void CreateMatr(int n, int m)
	{
		// set the check var
		check_empty = false;
		matr = new double*[n];
		for (int i = 0; i < m; i++)
		{
			matr[i] = new double[m];
		}
	}
public:
	NetMatr() {}
	// copy constructor
	void operator=(const NetMatr &other)
	{
		this->n = other.n;
		this->m = other.m;
		check_empty = false;
		this->matr = new double*[other.n];
		for (int i = 0; i < other.m; i++)
		{
			this->matr[i] = new double[other.m];
			for (int j = 0; j < other.m; j++)
			{
				this->matr[i][j] = other.matr[i][j];
			}
		}
	}

	~NetMatr()
	{
		for (int i = 0; i < n; i++)
		{
			delete [] matr[i];
		}
	}
	// Fill up the matrix with random numbers in range from	l_range to r_range
	NetMatr(int n, int m,int l_range, int r_range)
	{
		// Increasing bounds in 1000 times, for
		// using decimal(double) numbers in the future
		l_range *= (double)10e3;
		r_range *= (double)10e3;
		this->n = n;
		this->m = m;
		// Creating matrix
		CreateMatr(n, m);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				// dividing num to 1000, because 
				// if we need decimal numbers in range 0 - 1, we can divide big nums
				// for example 0,246 we should divide 246/1000
				matr[i][j] = (l_range + rand() % r_range) / 10e3;
				matr[i][j] *= ((i + j) % 2 == 0) ? -1 : 1;
			}
		}
	}

	void Show()
	{
		// Check emptiness of matr
		if (check_empty)
		{
			std::cout << "Массив пуст";
			return;
		}
		// matr output
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				std::cout << matr[i][j] << " ";
			}
			std::cout << "\n";
		}
	}
};

