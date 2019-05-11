#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <time.h> 
#include <cmath>

class NetMatr
{
private:
	// Matrix itself
	std::vector <std::vector <double>> matr;
	// Matrix dimension
	int n, m;
public:
	NetMatr() {}
	// Create simple matrix
	/*NetMatr(int n, int m)
	{
		this->n = n;
		this->m = m;
		matr.resize(n, std::vector <double>(m, 0));
	}*/
	// copy constructor
	NetMatr(const NetMatr &other)
	{
		this->n = other.n;
		this->m = other.m;
		// Creating matrix
		matr.resize(n, std::vector <double>(m, 0));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
 				matr[i][j] = other.matr[i][j];
			}
		}
	}
	// Making new matrix with 2 vectors
	NetMatr(std::vector <double> &first, std::vector <double> &second)
	{
		this->n = first.size();
		this->m = second.size();
		matr.resize(n, std::vector <double>(m, 0));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				matr[i][j] = first[i] * second[j];
			}
		}
	}

	// Overload of '=' operator as copy constructor
	void operator=(const NetMatr &other)
	{
		this->n = other.n;
		this->m = other.m;
		matr.resize(n, std::vector <double>(m, 0));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				matr[i][j] = other.matr[i][j];
			}
		}
	}
	// Delete filled memory
	~NetMatr() {}
	// Fill up the matrix with random numbers in range from	l_range to r_range
	NetMatr(int n, int m)
	{
		this->n = n;
		this->m = m;
		// Creating matrix
		matr.resize(n, std::vector <double>(m, 0));

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				// dividing num to 1000, because 
				// if we need decimal numbers in range 0 - 1, we can divide big nums
				// for example 0,246 we should divide 246/1000
				matr[i][j] = (double(rand()) / RAND_MAX);
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
	// Martix multiplication by number
	NetMatr operator*(const double &num)
	{
		// Creating temporary matrix
		NetMatr temp = *this;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				temp.matr[i][j] *= num;
			}
		}
		return temp;
	}
	// Martix multiplication by number
	void operator*=(const double &num)
	{
		// Creating temporary matrix
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				matr[i][j] *= num;
			}
		}
	}
	// Matrix addition
	NetMatr operator+(const NetMatr &other)
	{
		if (other.n != n || other.m != m)
			std::cout << "Matrix dimensions aren't matching!!!";
		// Create temporary matrix
		NetMatr temp = *this;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				temp.matr[i][j] += other.matr[i][j];
			}
		}
		return temp;
	}
	void operator+=(const double &other)
	{
		// Create temporary matrix
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				matr[i][j] += other;
			}
		}
	}
	// Matrix addition
	void operator+=(const NetMatr &other)
	{
		if (other.n != n || other.m != m)
			std::cout << "Matrix dimensions aren't matching!!!";
		// Create temporary matrix
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				matr[i][j] += other.matr[i][j];
			}
		}
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
	// Another substraction -=
	void operator-=(const NetMatr &other)
	{
		if (other.n != n || other.m != m)
			std::cout << "Attention!!! Matrixes dimensions are different";
		// Creating temporary matrix
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				matr[i][j] -= other.matr[i][j];
			}
		}
	}
	// Substact number from the matrix
	void operator-=(double num)
	{
		// Creating temporary matrix
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				matr[i][j] -= num;
			}
		}
	}
	// Substact number from the matrix
	NetMatr operator-(double num)
	{
		// Creating temporary matrix
		NetMatr temp(n, m);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				temp.matr[i][j] = matr[i][j] - num;
			}
		}
		return temp;
	}
	std::vector <double> operator*(std::vector <double> &other)
	{
		std::vector <double> v(n, 0);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < other.size(); j++)
			{
				v[i] += matr[i][j] * other[j]; // fixing here
			}
		}
		return v;
	}
	// Any matrix transpose
	NetMatr Transpose()
	{
		// Create a new matrix
		NetMatr temp(m, n);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				temp.matr[j][i] = matr[i][j];
			}
		}
		return temp;
	}
	// Setting matrix elements separately
	void SetMatr(int i, int j, double value)
	{
		matr[i][j] = value;
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
		if (matr.empty())
		{
			std::cout << "Массив пуст!\n";
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
	int NSize() { return n; }
	int MSize() { return m; }
};

