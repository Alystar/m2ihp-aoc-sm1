void
sgemm_c (int n,
		 float a [n][n],
		 float b [n][n],
		 float c [n][n])
{
	int i;
	int j;
	int k;

	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			c [i][j] = 0.0f;
		}
	}

	for (k = 0; k < n; ++k)
	{
		for (i = 0; i < n; ++i)
		{
			for (j = 0; j+3 < n; j += 4)
			{
				c [i][j] += a [i][k] * b [k][j];
				c [i][j + 1] += a [i][k] * b [k][j+1];
				c [i][j + 2] += a [i][k] * b [k][j+2];
				c [i][j + 3] += a [i][k] * b [k][j+3];
			}

			for (; j < n; j++)
				c [i][j] += a [i][k] * b [k][j];
		}
	}
}
