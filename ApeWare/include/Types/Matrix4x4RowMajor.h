#pragma once

class Matrix4x4RowMajor
{
public:
	Vector4 r1, r2, r3, r4;

	Matrix4x4RowMajor(float r1c1, float r1c2, float r1c3, float r1c4,
					  float r2c1, float r2c2, float r2c3, float r2c4,
					  float r3c1, float r3c2, float r3c3, float r3c4,
					  float r4c1, float r4c2, float r4c3, float r4c4);

	Matrix4x4RowMajor(Vector4 r1, Vector4 r2, Vector4 r3, Vector4 r4);
	void Print();
	Vector2 W2S(Vector3 worldPosition);
};