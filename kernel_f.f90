SUBROUTINE sgemm_f90 (n, a, b, c)
  IMPLICIT NONE

  INTEGER n
  REAL a (n, n), b (n, n), c (n, n)
  INTEGER i, j, k

  c = 0.0

  DO k = 1, n
    DO i = 1, n
      DO j = 1, n, 1
        c (j, i) = c (j, i) + a (k, i) * b (j, k)
      END DO
    END DO
  END DO

  RETURN
END SUBROUTINE sgemm_f90