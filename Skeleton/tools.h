#pragma once

#include <iostream>
#include <vector>
#include <array>
#include <cmath>

class Matrix {
public:
	Matrix();
	~Matrix()=default;
	std::array<std::array<double,4>, 4> mat;
};

class Vec {
public:
	Vec();
	~Vec()=default;
	Vec(double a, double b, double c);

	void Set(double a, double b, double c);

	double X() {
		return vec[0];
	}

	double Y() {
		return vec[1];
	}

	double Z() {
		return vec[2];
	}

	std::array<double, 4> vec;
}; 

Matrix rotate_x(double x_angle);

Matrix rotate_y(double y_angle);

Matrix rotate_z(double z_angle);

Matrix translate(double x, double y, double z);

Vec mat_vec_multiply(const Matrix& M, const Vec& V);

Matrix mat_mat_multiply(const Matrix& M1, const Matrix& M2);

class Line {
public:
	Line(Vec begin, Vec end, std::string name) : _begin{ begin }, _end{ end }, _name{name} {}
	~Line() = default;

	Vec & begin() {
		return _begin;
	}

	Vec & end() {
		return _end;
	}

	std::string name() {
		return _name;
	}

private:
	Vec _begin;
	Vec _end;
	std::string _name;
};


class Circle {
public:
	Circle(Vec center, std::string name) : _center{ center }, _name{ name } {}
	~Circle() = default;

	Vec & center() {
		return _center;
	}

	std::string name() {
		return _name;
	}

	double radius() {
		return _radius;
	}

private:
	Vec _center;
	std::string _name;
	double _radius = 3.0;

};