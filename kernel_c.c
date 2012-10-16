#include <string.h>

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

	for (k = 0; k+3 < n; k+=4)
	{
		for (i = 0; i+3 < n; i+=4)
		{
			for (j = 0; j+3 < n; j+=4)
			{
				for (l = k; l < k+4; ++l)
				{
					for (m = i; m < i+4; ++m)
					{
						for (o = j; o < j+4; ++o)
						{
							c [m][o] += a [m][l] * b [l][o];
						}
					}
				}
			}
		}
	}
}
