#include "Fixed.hpp"
#include "Point.hpp"
#include <cmath>

static float triDet(Point const a, Point const b, Point const c)
{
	float determinant;

	// the determinant formula to calculate the area of the triangle
	// | x1 y1 1 |
	// | x2 y2 1 | = 0.5 * determinant
	// | x3 y3 1 |
	determinant = a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat()) -
				  a.getY().toFloat() * (b.getX().toFloat() - c.getX().toFloat()) +
				  (b.getX().toFloat() * c.getY().toFloat() - c.getX().toFloat() * b.getY().toFloat());

	return determinant;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	const float eps = 1e-6f;
	float totalArea = std::fabs(triDet(a, b, c));
	if (totalArea < eps)
		return false;
	float detPAB, detPBC, detPCA;
	detPAB = std::fabs(triDet(point, a, b));
	detPBC = std::fabs(triDet(point, b, c));
	detPCA = std::fabs(triDet(point, c, a));
	// Check for point on the edge
	if (detPAB < eps || detPBC < eps || detPCA < eps)
		return false;
	// Check if sum of areas of PAB, PBC and PCA is same as ABC
	float sum = detPAB + detPBC + detPCA;
	if (std::fabs(sum - totalArea) <= eps)
		return true;
	return false;
}
