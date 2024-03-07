#include "../../include/includes.h"
#include "Vector3.h"

Vector3::Vector3()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

Vector3::Vector3(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

bool Vector3::isValid()
{
	if (this->x != 0 || this->y != 0 || this->z != 0)
		return true;
	return false;
}

float Vector3::Distance(Vector3 other)
{
	return sqrt(pow(this->x - other.x, 2) + pow(this->y - other.y, 2) + pow(this->z - other.z, 2));
}

Vector3 Vector3::LinearBezier(Vector3 to, float t)
{
	return Vector3(this->x, this->y, this->z) * (1 - t) + (to * t);
}

Vector3 Vector3::QuadraticBezier(Vector3 to, Vector3 mid, float t)
{
	return Vector3(this->x, this->y, this->z) * powf((1 - t), 2) + mid * 2 * (1 - t) * t + to * powf(t, 2);
}

void Vector3::Fix()
{
	while (this->y < 180)
		this->y += 360;
	while (this->y > 180)
		this->y -= 360;
	if (this->x > 89)
		this->x = 89;
	if (this->x < -89)
		this->x = -89;
}

void Vector3::Print()
{
	printf("x: %f, y: %f, z: %f\n", this->x, this->y, this->z);
}

Vector3 Vector3::operator+(Vector3 other)
{
	Vector3 temp;
	temp.x = this->x + other.x;
	temp.y = this->y + other.y;
	temp.z = this->z + other.z;
	return temp;
}

Vector3 Vector3::operator-(Vector3 other)
{
	Vector3 temp;
	temp.x = this->x - other.x;
	temp.y = this->y - other.y;
	temp.z = this->z - other.z;
	return temp;
}

Vector3 Vector3::operator*(Vector3 other)
{
	Vector3 temp;
	temp.x = this->x * other.x;
	temp.y = this->y * other.y;
	temp.z = this->z * other.z;
	return temp;
}

Vector3 Vector3::operator/(Vector3 other)
{
	Vector3 temp;
	temp.x = this->x / other.x;
	temp.y = this->y / other.y;
	temp.z = this->z / other.z;
	return temp;
}

Vector3 Vector3::operator+(float other)
{
	Vector3 temp;
	temp.x = this->x + other;
	temp.y = this->y + other;
	temp.z = this->z + other;
	return temp;
}

Vector3 Vector3::operator-(float other)
{
	Vector3 temp;
	temp.x = this->x - other;
	temp.y = this->y - other;
	temp.z = this->z - other;
	return temp;
}

Vector3 Vector3::operator*(float other)
{
	Vector3 temp;
	temp.x = this->x * other;
	temp.y = this->y * other;
	temp.z = this->z * other;
	return temp;
}

Vector3 Vector3::operator/(float other)
{
	Vector3 temp;
	temp.x = this->x / other;
	temp.y = this->y / other;
	temp.z = this->z / other;
	return temp;
}

void Vector3::operator+=(Vector3 other)
{
	this->x += other.x;
	this->y += other.y;
	this->z += other.z;
}

void Vector3::operator-=(Vector3 other)
{
	this->x -= other.x;
	this->y -= other.y;
	this->z -= other.z;
}

void Vector3::operator*=(Vector3 other)
{
	this->x *= other.x;
	this->y *= other.y;
	this->z *= other.z;
}

void Vector3::operator/=(Vector3 other)
{
	this->x /= other.x;
	this->y /= other.y;
	this->z /= other.z;
}

bool Vector3::operator==(Vector3 other)
{
	if (this->x == other.x && this->y == other.y && this->z == other.z)
		return true;
	return false;
}

bool Vector3::operator!=(Vector3 other)
{
	if (this->x != other.x && this->y != other.y && this->z != other.z)
		return true;
	return false;
}