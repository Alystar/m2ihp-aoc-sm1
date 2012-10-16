SUBROUTINE sgemm_f90
	IMPLICIT NONE

	REAL a (n, n), b (n, n), c (n, n)
	INTEGER i, j, k

	DO i = 1, n
		DO j = 1, n
			c (j, i) = 0.0
			DO k = 1, n
				c (j, i) = a (k, i) * b (j, k)
			END DO
		END DO
	END DO

	RETURN
END SUBROUTINE sgemm_f90