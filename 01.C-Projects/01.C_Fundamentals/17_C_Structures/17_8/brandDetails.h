#ifndef BRANDDETAILS_H
#define BRANDDETAILS_H

struct BrandDetails
{
	const char* brand;
	const char* brandDetails;
	const char* model;
	const char* modelDetails;
	float pricePerDay;
	unsigned isRentedCount;
} BrandDetail[4], *pBrandDetail;

#endif