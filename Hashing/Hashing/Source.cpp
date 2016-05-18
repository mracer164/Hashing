#include <iostream>

using namespace std;
const int TABLE_SIZE = 1000000;
unsigned long x = 123456789, y = 362436069, z = 521288629;
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
int randomNumberGenerator()
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

int main()
{

	return 0;
}