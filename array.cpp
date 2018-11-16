#include <iostream>
#include <string.h>
#include <assert.h>
using namespace std;

int tally(const string a[], int n, string target)
{
	if (n < 0)
	{
		return -1; //returns -1 if n is negative
	}
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == target)
		{
			count++;
		}
	}
	return count;
}

int findMatch(const string a[], int n, string target)
{
	if (n < 0)
	{
		return -1; //returns -1 if n is negative
	}
	for (int i = 0; i < n; i++)
	{
		if (a[i] == target)
		{
			return i;
		}
	}
	return -1;
}

bool findRun(const string a[], int n, string target, int& begin, int& end)
{
	if (n <0) {
		return false; //returns false if n is negative
	}
	for (int i = 1; i < n; i++)
	{
		if (target == a[i - 1])
		{
			begin = i;
			if (target == a[i])
			{
				int j = i;
				while ((j < n) && (a[j] == target))
				{
					j++;
				}
				end = j;
				return true;
			}
			return true;
		}
	}
	return false;
}

int positionOfMin(const string a[], int n)
{
	if (n < 0)
	{
		return -1;//returns -1 if n is negative
	}
	int positionOfMin = 0;
	for (int k = 0; k < n; k++) {
		if (a[k] <= a[positionOfMin]) {
			positionOfMin = k;
		}
	}
	return positionOfMin;
}

int moveToEnd(string a[], int n, int pos) {
	if (pos > n)
	{
		return -1;
	}
	if (n < 0)
	{
		return -1;//returns -1 if n is negative
	}
	string selected = a[pos];
	for (int i = 0; i < n; i++)
	{
		if (i < pos)
		{
			a[i] = a[i];
		}
		else if (i > pos)
		{
			a[i - 1] = a[i];
			continue;
		}
	}
	a[(n - 1)] = selected;

	return pos;
}

int moveToBeginning(string a[], int n, int pos)
{
	if (pos > n)
	{
		return -1;
	}
	if (n < 0)
	{
		return -1;//returns -1 if n is negative
	}
	string selected = a[pos];
	for (int i = pos; i >= 0; i--)
	{
		if (i <= pos)
		{
			a[i] = a[i - 1];
		}
	}
	a[0] = selected;
	return pos;
}

int findDifference(const string a1[], int n1, const string a2[], int n2)
{
	if ((n1 < 0) || (n2<0))
	{
		return -1;
	}

	int a;
	int b;
	for (a = 0, b = 0; a < n1, b < n2; a++, b++)
	{
		if (a1[a] == a2[b])
		{
			continue;
		}
		else
		{
			return a;
		}
	}
	return a;
}


int eliminateDups(string a[], int n)
{
	if (n < 0)
	{
		return -1;
	}

	int i = 0;
	int numItemsRetained = 0;
	while (i < n)
	{
		if (i + 1<n)
		{
			if (a[i] == a[i + 1])// two items are consecutive in a sequene
			{
				// shift every item to the right of index i one to the left
				for (int j = i; j < n; j++)
				{
					if (j + 1<n)
					{
						a[j] = a[j + 1];
						a[j + 1] = "i3oc";
					}
				}
			}

			if (a[i] == a[i + 1] && a[i] != "i3oc")
			{
				i--;
			}
		}
		i++;
	}

	for (int i = 0; i < n; i++) {
		if ((a[i] != "i3oc"))
		{
			numItemsRetained++;
		}
	}
	return numItemsRetained;
}


bool subsequence(const string a1[], int n1, const string a2[], int n2) {
	if (n2 < 0 || n1 <0)
	{
		return false; //returns false if n1 or n2 is negative
	}

	int r = 0;
	for (int k = 0; k<n1; k++)
	{
		if (a1[k] == a2[r])
			r++;
	}
	if (r == n2)
		return true;
	else
		return false;
}

bool isNondecreasing(const string a3[], int n3)
{
	for (int i = 1; i < n3; i++)
	{
		if (a3[i - 1] < a3[i])
		{
			continue;
		}
		else
		{
			return false;
		}
	}
	return true;
}

int makeMerger(const string a1[], int n1, const string a2[], int n2,
	string result[], int max) {
	if (n2 < 0 || n1 <0)
	{
		return -1; //returns false if n1 or n2 is negative
	}

	bool nondecs_a1 = true;

	for (int i = 1; i < n1; i++)
	{
		if (a1[i - 1] < a1[i])
		{
			continue;
		}
		else
		{
			nondecs_a1 = false;
		}
	}

	bool nondecs_a2 = true;

	for (int i = 1; i < n2; i++)
	{
		if (a2[i - 1] < a2[i])
		{
			continue;
		}
		else
		{
			nondecs_a2 = false;
		}
	}

	if (((n1 + n2) > max) || (nondecs_a1 && nondecs_a2))
	{
		//  Return −1 if the result would have more than max elements or if a1 and/or a2 are not in nondecreasing order
		return -1;
	}

	int i = 0;
	int j = 0;
	int k = 0;
	while (k < max) {
		if ((i < n1) && (j < n2)) // if i and j are ! out of bounds
		{
			if (a1[i] < a2[j])
			{
				if ((n1 - 1) == i)
				{

					result[k] = a1[i];
					result[k + 1] = a2[j];
					k++;
					j++;
				}
				else
				{

					result[k] = a1[i];
					k++;
					i++;
				}
			}
			else if (a1[i] > a2[j])
			{
				if ((n2 - 1) == j)
				{

					result[k] = a2[j];
					result[k + 1] = a1[i];
					k++;
					j++;
				}
				else
				{

					result[k] = a2[j];
					k++;
					j++;
				}

			}
			else
			{
				result[k] = a1[i];
				k++;
				i++;
			}
		}
		else {
			break;
		}
	}

	return n1 + n2;
}

int separate(string a[], int n, string separator)
{
	if (n < 0)
	{
		return -1; //returns -1 if n is negative
	}
	int pos;
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		string temp = a[i];
		if (a[i] > separator)
		{

			for (int j = i; j < (n - 1); j++)
			{
				a[j] = a[j + 1];
			}
			count++;
			i--;
			a[(n - 1)] = temp;

			if (count == n)
			{
				if (a[i - 1] > a[i])
				{
					string Shiftlast = a[i];
					a[i] = a[i - 1];
					a[i - 1] = Shiftlast;
				}

				if (a[0] > separator)
				{
					return n;
				}

				pos = i + 1;
				return pos;
			}
		}
	}
	return n;
}

int main()
{
	string h[7] = { "romanoff", "thor", "rogers", "banner", "", "parker", "rogers" };
	assert(tally(h, 7, "rogers") == 2);
	assert(tally(h, 7, "") == 1);
	assert(tally(h, 7, "rhodes") == 0);
	assert(tally(h, 0, "rogers") == 0);
	assert(findMatch(h, 7, "rogers") == 2);
	assert(findMatch(h, 2, "rogers") == -1);
	int bg;
	int en;

	string g[4] = { "romanoff", "thor", "banner", "parker" };
	assert(positionOfMin(g, 4) == 2);
	assert(findDifference(h, 4, g, 4) == 2);
	assert(subsequence(h, 7, g, 4));
	assert(moveToEnd(g, 4, 1) == 1 && g[1] == "banner" && g[3] == "thor");

	string f[4] = { "parker", "banner", "thor", "rogers" };
	assert(moveToBeginning(f, 4, 2) == 2 && f[0] == "thor" && f[2] == "banner");

	string e[5] = { "parker", "parker", "parker", "thor", "thor" };
	assert(eliminateDups(e, 5) == 2 && e[1] == "thor");

	string x[4] = { "rhodes", "rhodes", "tchalla", "thor" };
	string y[4] = { "banner", "parker", "rhodes", "rogers" };
	string z[10];
	assert(makeMerger(x, 4, y, 4, z, 10) == 8 && z[5] == "rogers");

	cout << "All tests succeeded" << endl;
}