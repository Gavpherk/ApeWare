#pragma once

class RGBA
{
public:
	float r, g, b, a;

	RGBA();
	RGBA(float r, float g, float b, float a);
	void ConvertToRGBA1();
	void ConvertToRGBA255();
	void Lerp(float value, float maxValue, RGBA endColor, RGBA startColor);
	void Print();

	RGBA operator+(RGBA other);
	RGBA operator-(RGBA other);
	RGBA operator*(RGBA other);
	RGBA operator/(RGBA other);

	void operator+=(RGBA other);
	void operator-=(RGBA other);
	void operator*=(RGBA other);
	void operator/=(RGBA other);
	bool operator==(RGBA other);
	bool operator!=(RGBA other);
};