#pragma once

class Vector3
{
public:
	float x, y, z;

	Vector3();
	Vector3(float x, float y, float z);
	bool isValid();
	float Distance(Vector3 other);
	Vector3 LinearBezier(Vector3 to, float t);
	Vector3 QuadraticBezier(Vector3 to, Vector3 mid, float t);
	void Fix();
	void Print();

	Vector3 operator+(Vector3 other);
	Vector3 operator-(Vector3 other);
	Vector3 operator*(Vector3 other);
	Vector3 operator/(Vector3 other);

	Vector3 operator+(float other);
	Vector3 operator-(float other);
	Vector3 operator*(float other);
	Vector3 operator/(float other);

	void operator+=(Vector3 other);
	void operator-=(Vector3 other);
	void operator*=(Vector3 other);
	void operator/=(Vector3 other);
	bool operator==(Vector3 other);
	bool operator!=(Vector3 other);
};