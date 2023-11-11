#include "building.h"

//Directions Arrays
int dirx[8] = { -1,-1, -1,0,1,1,1 };
int diry[8] = { -1,0, 1,1,1,-1,-1 };


void initBuilding(buildingArr bAllBuilding)
{
	Tenant tenant;
	tenant.nAnimalType = 0;
	tenant.nNeighbors = 0;

	//Sets the array values to zero.
	for (int nIndex = 0; nIndex < 11; nIndex++)
	{
		for (int jIndex = 0; jIndex < 9; jIndex++)
		{
			bAllBuilding[nIndex][jIndex] = tenant;
		}
	}
}

void writeToFile(Tenanats tArrTenants, int nSize)
{
	//Opens the input file.
	FILE* fp = fopen("building.dat", "wt");
	char cInputFile[17] = "Appartment1.txt";
	fwrite(cInputFile, sizeof(char) , strlen(cInputFile)+1, fp);
	
	//Writes the tenants into the file.
	for (int i = 0; i < nSize; i++)
	{
		Tenant temp = tArrTenants[i];
		fwrite(&temp,sizeof(Tenant),1, fp );
	}
	fclose(fp);
}

//-----------------------------------------------------------------------------
// numOfNeigbors
// ---------
//
// General : The function calculate the amount of neghibors of a single nApartment.
//
// Parameters :
// buildingArr bAllBuilding - The building that contains the animals.
// int nFloor - Has the nFloor number of the nApartment.
// int nApartment - Has the nApartment number on a single nFloor. 
//
// Return Value : INTEGER - The number of the neigbors.
//
//-----------------------------------------------------------------------------
int numOfNeigbors(buildingArr bArrBulding, int nFloor, int nApartment)
{
	int nNeigbors = 0;//counter

	//Checks every neigbor.
	for (int i = 0; i < 8; i++)
	{
		if ((bArrBulding[nFloor + diry[i]][nApartment + dirx[i]]).nAnimalType != 0)//Cheks if in there is a tenant in the neighbor nApartment.
		{
			nNeigbors++;
		}
	}
	return nNeigbors;
}

//-----------------------------------------------------------------------------
// lookForBadNeighbor
// ---------
//
// General : The function checks if the tenant can place next to those neighbors..
//
// Parameters :
// buildingArr bAllBuilding - The building that contains the animals.
// int nFloor - Has the nFloor number of the nApartment.
// int nApartment - Has the nApartment number on a single nFloor. 
// int nAnimalType - Has the type of the animal of the new tenant.
// 
// Return Value : INTEGER - If he found a 'badd' neighbor - return 0.
//							Otherwise return 1.
//
//-----------------------------------------------------------------------------
int lookForBadNeighbor(buildingArr bArrBulding,int nFloor, int nApartment, int nAnimalType)
{
	//Checks every neigbor.
	for (int i = 0; i < 8; i++)
	{
		if ((bArrBulding[nFloor + diry[i]][nApartment + dirx[i]]).nAnimalType == nAnimalType)//Looking for a 'bad' neighbor.
		{
			return 0;
		}
	}
	return 1;
}

// canBeNeigbor
// ---------
//
// General : The function sends the right parameters for every animal to lookForBadNeighbor.
//
// Parameters :
// buildingArr bAllBuilding - The building that contains the animals.
// Tenant tenant - The new tenant.
// int nFloor - Has the nFloor number of the nApartment.
// int nApartment - Has the nApartment number on a single nFloor. 
// 
// Return Value : INTEGER - If the new tenant can seat in that nApartment - return 1.
//							Otherwise return 0.
//
//-----------------------------------------------------------------------------
int canBeNeigbor(buildingArr arrbulding, Tenant tenant, int floor, int apartment)
{
	//Each animal has its on treatment.
	switch (tenant.nAnimalType)
	{
	case 1:
		return lookForBadNeighbor(arrbulding, floor, apartment, 2);
		break;
	case 2:
		return lookForBadNeighbor(arrbulding, floor, apartment, 1);
		break;
	case 3:
		return lookForBadNeighbor(arrbulding, floor, apartment, 4);
		break;
	case 4:
		return lookForBadNeighbor(arrbulding, floor, apartment, 3);
		break;
	default:
		return 1;
		break;
	}
	return 1;
}

// canBePlaced
// ---------
//
// General : The function checks weather the tenant can place in these specific nApartment.
//
// Parameters :
// buildingArr bAllBuilding - The building that contains the animals.
// Tenant tenant - The new tenant.
// int nFloor - Has the nFloor number of the nApartment.
// int nApartment - Has the nApartment number on a single nFloor. 
// 
// Return Value : INTEGER - If the new tenant can seat in that nApartment - return 1.
//							Otherwise return 0.
//
//-----------------------------------------------------------------------------
int canBePlaced(buildingArr bArrBulding, Tenant tenant, int nFloor, int nApartment)
{
	//Running all tests.
	if (tenant.nAnimalType >= numOfNeigbors(bArrBulding, nFloor, nApartment) && canBeNeigbor(bArrBulding, tenant, nFloor, nApartment) 
		&& bArrBulding[nFloor][nApartment].nAnimalType == 0)
	{
		return 1;
	}
	return 0;
}

void placeTenantsInApartments(buildingArr bArrBuilding, Tenanats tArrTenant, int nSize)
{
	int nPlaced = 0;
	int nIndex = 0;
	FILE* fpR = fopen("building.dat", "rt");
	FILE* fpW = fopen("building1.txt", "wt");
	Tenant tempTenant;
	tempTenant.nAnimalType = 0;
	tempTenant.nNeighbors = 0;
	char cInputFile[17] = "Appartment1.txt";
	
	//Reads the input file name.
	fread(&cInputFile, sizeof(char), strlen(cInputFile) + 1, fpR);
	//Reads the first tenant.
	fread(&tempTenant, sizeof(Tenant), 1, fpR);

	//Reding all tenants
	while(!feof(fpR))
	{
		nPlaced = 0;

		//Go through all the floors unless a place for the tenant is already been found.
		for (int floor = 1; floor < 11 && !nPlaced; floor++)
		{
			//Go through all the apartment in a specific floor unless a place for the tenant is already been found.
			for (int apartment = 1; apartment < 9 && !nPlaced; apartment++)
			{
				//Wheter the tenants can place in this specific apartment.
				if (canBePlaced(bArrBuilding, tempTenant, floor, apartment))
				{	
					//Insert the animal to its place on the building
					bArrBuilding[floor][apartment].nAnimalType = tempTenant.nAnimalType;
					//Writing to file every animal and its location.
					fprintf(fpW,"tenants: %d rent an apartment in floor: %d, apartment: %d\n", ++nIndex, floor, apartment);
					//Indicates that the program found a place.
					nPlaced = 1;
					//Reding the next animal's data.
					fread(&tempTenant, sizeof(Tenant), 1, fpR);
				}
			}
		}
		if (!nPlaced)
		{
			printf("Tweet and sons cant rent a place for: %d\n", ++nIndex);
		}
	}
	fclose(fpR);
	fclose(fpW);
}