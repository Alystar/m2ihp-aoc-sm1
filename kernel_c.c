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
			for (j = 0; j < n; ++j)
			{
				c [i][j] += a [i][k] * b [k][j];
			}
		}
	}
}
