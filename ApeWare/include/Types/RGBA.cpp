#include "../../include/includes.h"
#include "RGBA.h"

RGBA::RGBA()
{
	this->r = 0;
	this->g = 0;
	this->b = 0;
	this->a = 0;
}

RGBA::RGBA(float r, float g, float b, float a)
{
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
}

void RGBA::ConvertToRGBA1()
{
	this->r /= 255;
	this->g /= 255;
	this->b /= 255;
}

void RGBA::ConvertToRGBA255()
{
	this->r *= 255;
	this->g *= 255;
	this->b *= 255;
}

void RGBA::Lerp(float value, float maxValue, RGBA endColor, RGBA startColor)
{
	float percent = value / maxValue;
	this->r = endColor.r + percent * (startColor.r - endColor.r);
	this->g = endColor.g + percent * (startColor.g - endColor.g);
	this->b = endColor.b + percent * (startColor.b - endColor.b);
	this->a = 255;
}

void RGBA::Print()
{
	printf("r: %f, g: %f, b: %f, a: %f\n", this->r, this->g, this->b, this->a);
}

RGBA RGBA::operator+(RGBA other)
{
	RGBA temp;
	temp.r = this->r + other.r;
	temp.g = this->g + other.g;
	temp.b = this->b + other.b;
	temp.a = this->a + other.a;
	return temp;
}

RGBA RGBA::operator-(RGBA other)
{
	RGBA temp;
	temp.r = this->r - other.r;
	temp.g = this->g - other.g;
	temp.b = this->b - other.b;
	temp.a = this->a - other.a;
	return temp;
}

RGBA RGBA::operator*(RGBA other)
{
	RGBA temp;
	temp.r = this->r * other.r;
	temp.g = this->g * other.g;
	temp.b = this->b * other.b;
	temp.a = this->a * other.a;
	return temp;
}

RGBA RGBA::operator/(RGBA other)
{
	RGBA temp;
	temp.r = this->r / other.r;
	temp.g = this->g / other.g;
	temp.b = this->b / other.b;
	temp.a = this->a / other.a;
	return temp;
}

void RGBA::operator+=(RGBA other)
{
	this->r += other.r;
	this->g += other.g;
	this->b += other.b;
	this->a += other.a;
}

void RGBA::operator-=(RGBA other)
{
	this->r -= other.r;
	this->g -= other.g;
	this->b -= other.b;
	this->a -= other.a;
}

void RGBA::operator*=(RGBA other)
{
	this->r *= other.r;
	this->g *= other.g;
	this->b *= other.b;
	this->a *= other.a;
}

void RGBA::operator/=(RGBA other)
{
	this->r /= other.r;
	this->g /= other.g;
	this->b /= other.b;
	this->a /= other.a;
}

bool RGBA::operator==(RGBA other)
{
	if (this->r == other.r && this->g == other.g && this->b == other.b && this->a == other.a)
		return true;
	return false;
}

bool RGBA::operator!=(RGBA other)
{
	if (this->r != other.r && this->g != other.g && this->b != other.b && this->a != other.a)
		return true;
	return false;
}