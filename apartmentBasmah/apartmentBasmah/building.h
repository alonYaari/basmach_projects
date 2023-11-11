#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tSize 5

typedef int floor[11];
typedef enum animalType{chicken = 1, ant, cat, pig, pigeon};

typedef struct Tenant {
	int nAnimalType;
	int nNeighbors;
}Tenant;

typedef Tenant* Tenanats;
typedef Tenant buildingArr[11][9];

//functions declerations

//-----------------------------------------------------------------------------
// initBuilding
// ---------
//
// General : The function gets a building and set all his values to zero.
//
// Parameters :
// buildingArr bAllBuilding - The building that will contain the animals
//
// Return Value : Void.
//
//-----------------------------------------------------------------------------
void initBuilding(buildingArr bAllBuilding);
//-----------------------------------------------------------------------------
// writeToFile
// ---------
//
// General : The function gets an array of a tenants the wants to live in the building
//			 Then, it inserts every tenant to a file.
//
// Parameters :
// Tenanats tArrTenants - The array of the Tenants wanted to live in the building.
// int nSize - The size of the array.
// 
// Return Value : Void.
//
//-----------------------------------------------------------------------------
void writeToFile(Tenanats tArrTenants, int nSize);
//-----------------------------------------------------------------------------
// placeTenantsInApartments
// ---------
//
// General : The function gets placing every animal that want to live in the building into a certein apartment.
//			 If the function can't find a place to the animal, she prints it on the screen. 
//
// Parameters :
// buildingArr bArrbulding - The building structure.
// Tenanats tArrTenants - The array of the animals wanted to live in the building.
// int nSize - The size of the array.
// 
// Return Value : Void.
//
//-----------------------------------------------------------------------------
void placeTenantsInApartments(buildingArr bArrbulding, Tenanats tArrTenant, int nSize);