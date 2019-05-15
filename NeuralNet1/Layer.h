#pragma once
#include <vector>

struct Layer
{
	Layer() {}
	Layer(int size_)
	{
		size = size_;
	}

	Layer(int size_,const std::vector <double> &values_)
	{
		size = size_;
		values = values_;
	}
	void operator=(const Layer &other)
	{
		size = other.size;
		values.resize(size);
		for (int i = 0; i < size; i++)
		{
			values[i] = other.values[i];
		}
	}

	Layer operator-(const Layer &other)
	{
		std::vector <double> v(size);
		for (int i = 0; i < size; i++)
		{
			v[i] = values[i] - other.values[i];
		}
		return Layer(size, v);
	}
	Layer operator-(double other)
	{
		std::vector <double> v(size);
		for (int i = 0; i < size; i++)
		{
			v[i] = values[i] - other;
		}
		return Layer(size, v);
	}
	double operator*(const Layer &other)
	{
		double sum = 0;
		for (int i = 0; i < size; i++)
		{
			sum += values[i] * other.values[i];
		}
		return sum;
	}
	Layer operator*(double val)
	{
		std::vector <double> v(size);
		for (int i = 0; i < size; i++)
		{
			v[i] = values[i] * val;
		}
		return Layer(size, v);
	}
	double Sum()
	{
		double sum = 0;
		for (int i = 0; i < size; i++)
		{
			sum += values[i];
		}
		return sum;
	}

	std::vector <double> values;
	int size;
};