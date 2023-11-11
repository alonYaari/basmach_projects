#include "building.h"

void main()
{
	//Making an array of tenants.
	Tenant* Tenanats = malloc(sizeof(Tenant)*tSize);
	Tenant a;
	a.nAnimalType = 1;
	a.nNeighbors = 1;
	Tenant b;
	b.nAnimalType = 2;
	b.nNeighbors = 3;
	Tenant c;
	c.nAnimalType = 2;
	c.nNeighbors = 5;
	Tenant d;
	d.nAnimalType = 5;
	d.nNeighbors = 2;
	Tenant e;
	e.nAnimalType = 4;
	e.nNeighbors = 0;
	Tenanats[0] = a;
	Tenanats[1] = b;
	Tenanats[2] = c;
	Tenanats[3] = d;
	Tenanats[4] = e;

	
	writeToFile(Tenanats, tSize);
	buildingArr arr;
	initBuilding(arr);
	//calls for the main function.
	placeTenantsInApartments(arr, Tenanats, tSize);
}