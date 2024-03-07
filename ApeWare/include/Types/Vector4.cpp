#include "../../include/includes.h"
#include "Vector4.h"

Vector4::Vector4()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
	this->w = 0;
}

Vector4::Vector4(float x, float y, float z, float w)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

bool Vector4::isValid()
{
	if (this->x != 0 || this->y != 0 || this->z != 0 || this->w != 0)
		return true;
	return false;
}

void Vector4::Print()
{
	printf("x: %f, y: %f, z: %f, a: %f\n", this->x, this->y, this->z, this->w);
}

Vector4 Vector4::operator+(Vector4 other)
{
	Vector4 temp;
	temp.x = this->x + other.x;
	temp.y = this->y + other.y;
	temp.z = this->z + other.z;
	temp.w = this->w + other.w;
	return temp;
}

Vector4 Vector4::operator-(Vector4 other)
{
	Vector4 temp;
	temp.x = this->x - other.x;
	temp.y = this->y - other.y;
	temp.z = this->z - other.z;
	temp.w = this->w - other.w;
	return temp;
}

Vector4 Vector4::operator*(Vector4 other)
{
	Vector4 temp;
	temp.x = this->x * other.x;
	temp.y = this->y * other.y;
	temp.z = this->z * other.z;
	temp.w = this->w * other.w;
	return temp;
}

Vector4 Vector4::operator/(Vector4 other)
{
	Vector4 temp;
	temp.x = this->x / other.x;
	temp.y = this->y / other.y;
	temp.z = this->z / other.z;
	temp.w = this->w / other.w;
	return temp;
}

void Vector4::operator+=(Vector4 other)
{
	this->x += other.x;
	this->y += other.y;
	this->z += other.z;
	this->w += other.w;
}

void Vector4::operator-=(Vector4 other)
{
	this->x -= other.x;
	this->y -= other.y;
	this->z -= other.z;
	this->w -= other.w;
}

void Vector4::operator*=(Vector4 other)
{
	this->x *= other.x;
	this->y *= other.y;
	this->z *= other.z;
	this->w *= other.w;
}

void Vector4::operator/=(Vector4 other)
{
	this->x /= other.x;
	this->y /= other.y;
	this->z /= other.z;
	this->w /= other.w;
}

bool Vector4::operator==(Vector4 other)
{
	if (this->x == other.x && this->y == other.y && this->z == other.z && this->w == other.w)
		return true;
	return false;
}

bool Vector4::operator!=(Vector4 other)
{
	if (this->x != other.x && this->y != other.y && this->z != other.z && this->w != other.w)
		return true;
	return false;
}