#pragma once

class Vector2
{
public:
	float x, y;

	Vector2();
	Vector2(float x, float y);
	bool isValid();
	float Distance(Vector2 other);
	void Print();

	Vector2 operator+(Vector2 other);
	Vector2 operator-(Vector2 other);
	Vector2 operator*(Vector2 other);
	Vector2 operator/(Vector2 other);

	void operator+=(Vector2 other);
	void operator-=(Vector2 other);
	void operator*=(Vector2 other);
	void operator/=(Vector2 other);
	bool operator==(Vector2 other);
	bool operator!=(Vector2 other);
};