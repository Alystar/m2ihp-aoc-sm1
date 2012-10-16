#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/******************************************************************************/

extern void sgemm_c (int n, float ** a, float ** b, float ** c);
extern void sgemm_f90_ (int * n, float a [*n][*n], float b [*n][*n], float c [*n][*n]);
extern uint64_t rdtsc ( );

/******************************************************************************/

static void
init_array (int n,
			float a [n][n])
{
	int i, j;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			a [i][j] = ( (float) rand () ) / RAND_MAX;
		}
	}
}

static void
print_array (int n,
			 float a [n][n],
			 const char * s)
{
	int i;
	int j;

	for (i = 0; i < n; i++)
	{
		printf ("%s: ", s);

		for (j = 0; j < n; j++)
		{
			printf ("%f ", a [i][j]);
		}
		putchar ('\n');
	}
}

/******************************************************************************/

int
main (int argc, char * argv [])
{
	if (argc != 3)
	{
		fprintf (stderr, "usage: %s <size> <nb repets>\n", argv [0]);
		abort ();
	}

	/**********************************************************************/

	int		i;
	int		n = atoi (argv [1]);
	int		r = atoi (argv [2]);

	float	* pa = malloc (n * n * sizeof *pa );
	float	* pb = malloc (n * n * sizeof *pb );
	float	* pc = malloc (n * n * sizeof *pc );

	float	(* a) [n] = (float (*) [n]) pa;
	float	(* b) [n] = (float (*) [n]) pb;
	float	(* c) [n] = (float (*) [n]) pc;

	/**********************************************************************/

	init_array (n, a);
	init_array (n, b);

	/**********************************************************************/

	sgemm_c (n, a, b, c);

	uint64_t t1 = rdtsc ();

	for (i = 0; i < r; i++)
	{
		sgemm_c (n, a, b, c);
	}

	uint64_t t2 = rdtsc ();

	printf ("C: %2f cycles / MAD\n",
		(t2 - t1) / ( (float) n * n * n * r) );

	print_array (n, c, "C");

	/**********************************************************************/

	sgemm_f90_ (&n, a, b, c);

	t1 = rdtsc ();

	for (i = 0; i < r; i++)
	{
		sgemm_f90_ (&n, a, b, c);
	}

	t2 = rdtsc ();

	printf ("F: %2f cycles / MAD\n",
		(t2 - t1) / ( (float) n * n * n * r) );

	print_array (n, c, "F");

	/**********************************************************************/

	free (pa);
	free (pb);
	free (pc);

	return EXIT_SUCCESS;
}