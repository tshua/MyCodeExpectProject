#include <stdio.h>
#include <string.h>
#include <algorithm>
using std::sort;
bool Greater(int one, int two)
{
	return one > two;
}
int main()
{
	char szOne[110];
	char szTwo[110];
	int nNumOne[26];
	int nNumTwo[26];
	while (scanf("%s%s", szOne, szTwo) == 2)
	{
		memset(nNumOne, 0, sizeof(int) * 26);
		memset(nNumTwo, 0, sizeof(int) * 26);
		char* psz = szOne;
		while (*psz)
		{
			++nNumOne[*psz - 'A'];
			++psz;
		}
		psz = szTwo;
		while (*psz)
		{
			++nNumTwo[*psz - 'A'];
			++psz;
		}
		sort(nNumOne, nNumOne + 26, Greater);
		sort(nNumTwo, nNumTwo + 26, Greater);
		bool bIsYes = true;
		for (int i = 0; i < 26; ++i)
		{
			if (nNumOne[i] < nNumTwo[i])
			{
				bIsYes = false;
				break;
			}
		}
		if (bIsYes)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}