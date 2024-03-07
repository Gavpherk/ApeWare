#include "../../include/includes.h"
#include "Vector2.h"

Vector2::Vector2()
{
	this->x = 0;
	this->y = 0;
}

Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}

bool Vector2::isValid()
{
	if (this->x != 0 || this->y != 0)
		return true;
	return false;
}

float Vector2::Distance(Vector2 other)
{
	return sqrt(pow(this->x - other.x, 2) + pow(this->y - other.y, 2));
}

void Vector2::Print()
{
	printf("x: %f, y: %f\n", this->x, this->y);
}

Vector2 Vector2::operator+(Vector2 other)
{
	Vector2 temp;
	temp.x = this->x + other.x;
	temp.y = this->y + other.y;
	return temp;
}

Vector2 Vector2::operator-(Vector2 other)
{
	Vector2 temp;
	temp.x = this->x - other.x;
	temp.y = this->y - other.y;
	return temp;
}

Vector2 Vector2::operator*(Vector2 other)
{
	Vector2 temp;
	temp.x = this->x * other.x;
	temp.y = this->y * other.y;
	return temp;
}

Vector2 Vector2::operator/(Vector2 other)
{
	Vector2 temp;
	temp.x = this->x / other.x;
	temp.y = this->y / other.y;
	return temp;
}

void Vector2::operator+=(Vector2 other)
{
	this->x += other.x;
	this->y += other.y;
}

void Vector2::operator-=(Vector2 other)
{
	this->x -= other.x;
	this->y -= other.y;
}

void Vector2::operator*=(Vector2 other)
{
	this->x *= other.x;
	this->y *= other.y;
}

void Vector2::operator/=(Vector2 other)
{
	this->x /= other.x;
	this->y /= other.y;
}

bool Vector2::operator==(Vector2 other)
{
	if (this->x == other.x && this->y == other.y)
		return true;
	return false;
}

bool Vector2::operator!=(Vector2 other)
{
	if (this->x != other.x && this->y != other.y)
		return true;
	return false;
}