#include "tools.h"

Vec::Vec() {
	vec[0] = 0.0; vec[1] = 0.0; vec[2] = 0.0; vec[3] = 1.0;
}

Vec::Vec(double a, double b, double c) {
	vec[0] = a; vec[1] = b; vec[2] = c; vec[3] = 1.0;
}

void Vec::Set(double a, double b, double c) {
	vec[0] = a; vec[1] = b; vec[2] = c;
}

Matrix::Matrix() {
	mat[0][0] = 0.0; mat[0][1] = 0.0; mat[0][2] = 0.0; mat[0][3] = 0.0;
	mat[1][0] = 0.0; mat[1][1] = 0.0; mat[1][2] = 0.0; mat[1][3] = 0.0;
	mat[2][0] = 0.0; mat[2][1] = 0.0; mat[2][2] = 0.0; mat[2][3] = 0.0;
	mat[3][0] = 0.0; mat[3][1] = 0.0; mat[3][2] = 0.0; mat[3][3] = 1.0;
}

Vec mat_vec_multiply(const Matrix& M, const Vec& V)
{
	unsigned int i, j;
	Vec tmp;

	for (i = 0; i < 4; i++)
	{
		tmp.vec[i] = 0.0;
		for (j = 0; j < 4; j++) tmp.vec[i] = tmp.vec[i] + (M.mat[i][j] * V.vec[j]);
	}
	return tmp;
}

Matrix mat_mat_multiply(const Matrix& M1, const Matrix& M2) {
	int i, j, k;
	Matrix tmp;

	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
		{
			tmp.mat[i][j] = 0.0;
			for (k = 0; k < 4; k++)
				tmp.mat[i][j] = tmp.mat[i][j] + (M1.mat[i][k] * M2.mat[k][j]);
		}
	return tmp;
}

Matrix rotate_x(double x_angle) {
	double alpha = x_angle * 3.1415 / 100.0;
	Matrix rot;

	rot.mat[0][0] = 1;
	rot.mat[1][1] = cos(alpha);
	rot.mat[1][2] = -sin(alpha);
	rot.mat[2][2] = cos(alpha);
	rot.mat[2][1] = sin(alpha);

	return rot;
}

Matrix rotate_y(double y_angle) {
	double alpha = y_angle * 3.1415 / 100.0;
	Matrix rot;

	rot.mat[0][0] = cos(alpha);
	rot.mat[1][1] = 1.0;
	rot.mat[0][2] = -sin(alpha);
	rot.mat[2][2] = cos(alpha);
	rot.mat[2][0] = sin(alpha);

	return rot;
}

Matrix rotate_z(double z_angle) {
	double alpha = z_angle * 3.1415 / 180.0;
	Matrix rot;

	rot.mat[0][0] = cos(alpha);
	rot.mat[1][1] = cos(alpha);
	rot.mat[0][1] = -sin(alpha);
	rot.mat[2][2] = 1;
	rot.mat[1][0] = sin(alpha);

	return rot;
}

Matrix translate(double x, double y, double z) {
	Matrix trans;

	trans.mat[0][0] = 1;
	trans.mat[1][1] = 1;
	trans.mat[2][2] = 1;
	trans.mat[0][3] = x;
	trans.mat[1][3] = y;
	trans.mat[2][3] = z;

	return trans;
}