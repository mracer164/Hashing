#include <iostream>
#include <random>

using namespace std;
const int TABLE_SIZE = 20;
unsigned long * hashTable = new unsigned long[TABLE_SIZE];
unsigned long x = 123456789, y = 362436069, z = 521288629;
unsigned long randomNumberGenerator()
{
	unsigned long t;
	x ^= x << 16;
	x ^= x >> 5;
	x ^= x << 1;

	t = x;
	x = y;
	y = z;
	z = t ^ x ^ y;

	return z;
}
int randomWithinRange(int lowerBound, int upperBound)
{
	random_device rd; 
	mt19937 eng(rd()); 
	uniform_int_distribution<> distr(lowerBound, upperBound); 

	return distr(eng);
}
void fillHashTable(int fillPercentage, unsigned long * hashTable)
{
	
	bool repeated = false;
	int currentIndex = 0;
	int lastFilledIndex = 0;
	int fillingProgress = 0;
	int upperBound = TABLE_SIZE*fillPercentage / 100;
	int * generatedNumbers = new int[upperBound];
	int generatedNumbersIterator = 0;
	while (fillingProgress <= upperBound)
	{
		currentIndex = randomWithinRange(0, TABLE_SIZE);
		generatedNumbers[generatedNumbersIterator] = currentIndex;
		for (int i = 0; i <= lastFilledIndex; i++)
		{
			if (generatedNumbers[i] == currentIndex && generatedNumbersIterator != i)
			{
				repeated = true;
			}
			else
			{
				generatedNumbersIterator++;
			}
		}
		if (repeated == false)
		{
			hashTable[currentIndex] = randomNumberGenerator();
			fillingProgress++;
			repeated = false;
		}
		else
		{
			repeated = false;
			continue;
		}

	}
}
int hashInt(int toHash, int i)
{
	int hash;
	if (i == 0)
	{
		hash = toHash % TABLE_SIZE;
	}
	else
	{
		hash = ((toHash % TABLE_SIZE) + 3 * i) % TABLE_SIZE;
	}
	return hash;
}
bool hash_lin_prob_insert(int x, int * hashTable)
{
	int index;
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		index = hashInt(x, i);
		if (hashTable[index] == NULL)
		{
			hashTable[index] = x;
			return true;
		}
	}
	return false;
}
bool hash_lin_prob_search(int x, int * hashTable)
{
	int index;
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		index = hashInt(x, i);
		if (hashTable[index] == x)
			return true;
		else if (hashTable[index] == NULL)
			return false;
	}
	return false;
}


int main()
{
	fillHashTable(25, hashTable);
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		cout << hashTable[i] << endl;
	}
	return 0;
}