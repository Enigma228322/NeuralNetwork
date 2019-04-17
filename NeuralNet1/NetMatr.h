#pragma once
#include <iostream>
#include <vector>

class NetMatr
{
private:
	// Matrix itself
	double **matr;
	// Matrix dimension
	int n, m;
	// Checks is matrix filled up or not
	// To avoid getting passed array
	bool check_empty = true;
	// Matrix creation method
	void CreateMatr(int n, int m)
	{
		// set the check var
		check_empty = false;
		matr = new double*[n];
		for (int i = 0; i < n; i++)
		{
			matr[i] = new double[m];
			// Initialization by zeros
			for (int j = 0; j < m; j++) matr[i][j] = 0;
		}
	}
public:
	NetMatr() {}
	// Create simple matrix
	NetMatr(int n, int m)
	{
		this->n = n;
		this->m = m;
		CreateMatr(n, m);
	}
	// copy constructor
	NetMatr(const NetMatr &other)
	{
		this->n = other.n;
		this->m = other.m;
		check_empty = false;
		this->matr = new double*[other.n];
		for (int i = 0; i < other.n; i++)
		{
			this->matr[i] = new double[other.m];
			for (int j = 0; j < other.m; j++)
			{
				this->matr[i][j] = other.matr[i][j];
			}
		}
	}
	// Overload of '=' operator as copy constructor
	void operator=(const NetMatr &other)
	{
		this->n = other.n;
		this->m = other.m;
		check_empty = false;
		this->matr = new double*[other.n];
		for (int i = 0; i < other.n; i++)
		{
			this->matr[i] = new double[other.m];
			for (int j = 0; j < other.m; j++)
			{
				this->matr[i][j] = other.matr[i][j];
			}
		}
	}
	// Delete filled memory
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
	// Matrix multiplication
	NetMatr operator*(const NetMatr &other)
	{
		// Creating temporary matrix
		NetMatr temp(this->n, other.m);
		for(int i = 0; i < n; i++)
		{
			for (int j = 0; j < other.m; j++)
			{	
				for (int l = 0; l < m; l++)
				{
					temp.matr[i][j] += (matr[i][l] * other.matr[l][j]);
				}
			}
		}
		return temp;
	}
	// Substraction of matrixes
	NetMatr operator-(const NetMatr &other)
	{
		if (other.n != n || other.m != m)
			std::cout << "Attention!!! Matrixes dimensions are different";
		// Creating temporary matrix
		NetMatr temp(n, m);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				temp.matr[i][j] = matr[i][j] - other.matr[i][j];
			}
		}
		return temp;
	}
	// Square matrix transpotion
	NetMatr T()
	{
		// Create a temporary matr
		NetMatr temp = *this;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (j >= i) std::swap(temp.matr[i][j], temp.matr[j][i]);
			}
		}
		return temp;
	}
	// Setting matrix elements separately
	void SetMatr(int i, int j, double value)
	{
		matr[i][j] = value;
	}
	// Setting matrix using keyboard
	void SetMatr()
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				std::cin >> matr[i][j];
			}
		}
	}
	// Getting elements from matrix
	double GetEl(int i, int j)
	{
		try
		{
			return matr[i][j];
		}
		catch(...)
		{
			std::cout << "You getted passed out of array range";
		}
	}
	// Show matrix
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
	// Return widght and height of matrix
	int NSize() { return this->n; }
	int MSize() { return this->m; }
};

