#include <string.h>

#define MIN(x,y) ( (x<y) ? x : y)

void
sgemm_c (int n,
		 float a [n][n],
		 float b [n][n],
		 float c [n][n])
{
	int i;
	int j;
	int k;

	int l;
	int m;
	int o;

	memset (c, 0, n * n * sizeof (float) );

	for (k = 0; k < n; k+=100)
	{
		for (i = 0; i < n; i+=100)
		{
			for (j = 0; j < n; j+=100)
			{
				for (l = k; l < MIN (n, k+100); ++l)
				{
					for (m = i; m < MIN (n, i+100); ++m)
					{
						for (o = j; o < MIN (n, j+100); ++o)
						{
							c [m][o] += a [m][l] * b [l][o];
						}
					}
				}
			}
		}
	}
}
