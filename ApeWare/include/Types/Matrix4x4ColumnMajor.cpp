#include "../../include/includes.h"
#include "Matrix4x4ColumnMajor.h"

Matrix4x4ColumnMajor::Matrix4x4ColumnMajor(float r1c1, float r2c1, float r3c1, float r4c1, 
										   float r1c2, float r2c2, float r3c2, float r4c2, 
										   float r1c3, float r2c3, float r3c3, float r4c3, 
										   float r1c4, float r2c4, float r3c4, float r4c4)
{
	this->r1 = Vector4(r1c1, r1c2, r1c3, r1c4);
	this->r2 = Vector4(r2c1, r2c2, r2c3, r2c4);
	this->r3 = Vector4(r3c1, r3c2, r3c3, r3c4);
	this->r4 = Vector4(r4c1, r4c2, r4c3, r4c4);
}

Matrix4x4ColumnMajor::Matrix4x4ColumnMajor(Vector4 r1, Vector4 r2, Vector4 r3, Vector4 r4)
{
	this->r1 = r1;
	this->r2 = r2;
	this->r3 = r3;
	this->r4 = r4;
}

void Matrix4x4ColumnMajor::Print()
{
	printf("r1c1: %f, r1c2: %f, r1c3: %f, r1c4: %f\n", this->r1.x, this->r1.y, this->r1.z, this->r1.w);
	printf("r2c1: %f, r2c2: %f, r2c3: %f, r2c4: %f\n", this->r2.y, this->r2.y, this->r2.y, this->r2.y);
	printf("r3c1: %f, r3c2: %f, r3c3: %f, r3c4: %f\n", this->r3.z, this->r3.z, this->r3.z, this->r3.z);
	printf("r4c1: %f, r4c2: %f, r4c3: %f, r4c4: %f\n\n", this->r4.x, this->r4.y, this->r4.z, this->r4.w);
}

Vector2 Matrix4x4ColumnMajor::W2S(Vector3 worldPosition, Vector2 resolution)
{
	Vector4 clipCords;
	clipCords.x = this->r1.x * worldPosition.x + this->r2.x * worldPosition.y + this->r3.x * worldPosition.z + this->r4.x;
	clipCords.y = this->r1.y * worldPosition.x + this->r2.y * worldPosition.y + this->r3.y * worldPosition.z + this->r4.y;
	clipCords.z = this->r1.z * worldPosition.x + this->r2.z * worldPosition.y + this->r3.z * worldPosition.z + this->r4.z;
	clipCords.w = this->r1.w * worldPosition.x + this->r2.w * worldPosition.y + this->r3.w * worldPosition.z + this->r4.w;

	Vector3 normalizeDeviceCords;
	normalizeDeviceCords.x = clipCords.x / clipCords.w;
	normalizeDeviceCords.y = clipCords.y / clipCords.w;
	normalizeDeviceCords.z = clipCords.z / clipCords.w;

	Vector2 screenCords;
	screenCords.x = (resolution.x / 2 * normalizeDeviceCords.x) + (normalizeDeviceCords.x + resolution.x / 2);
	screenCords.y = -(resolution.y / 2 * normalizeDeviceCords.y) + (normalizeDeviceCords.y + resolution.y / 2);
	
	return screenCords;
}