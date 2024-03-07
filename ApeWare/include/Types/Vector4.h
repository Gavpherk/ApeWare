#pragma once

class Vector4
{
public:
	float x, y, z, w;

	Vector4();
	Vector4(float x, float y, float z, float w);
	bool isValid();
	void Print();

	Vector4 operator+(Vector4 other);
	Vector4 operator-(Vector4 other);
	Vector4 operator*(Vector4 other);
	Vector4 operator/(Vector4 other);

	void operator+=(Vector4 other);
	void operator-=(Vector4 other);
	void operator*=(Vector4 other);
	void operator/=(Vector4 other);
	bool operator==(Vector4 other);
	bool operator!=(Vector4 other);
};