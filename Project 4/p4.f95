!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
! Program #4: Traveling Salesman Problem
! @author Nam Tran
! CS320
!
! This program, written in FORTRAN 95, solves the Traveling Salesman Problem:
!  A salesman must leave his home city and visit N cities after which he then
!  returns home. The order in which he visits the cities is unimportant, however
!  he must visit each of the N cities, and he must start and end at home. Your
!  task is to find the minimum tour.

PROGRAM P4
IMPLICIT NONE

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
! Variable Declarations

INTEGER :: number, status, numCity, I, J, K, first, last, globalMin
CHARACTER(len = 50) :: filename
CHARACTER(len = 50), DIMENSION (:), ALLOCATABLE :: cityName
INTEGER, DIMENSION (:,:), ALLOCATABLE :: cityDistance
INTEGER, DIMENSION (:), ALLOCATABLE :: path, bestPath

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
! Print title lines
PRINT *
PRINT *, "Program #2, Nam Tran"

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!Open the file and read number of cities

WRITE (*, '(1x,A)', ADVANCE="NO") "Enter filename:  "
READ *, filename

! Open the file and make sure it worked
OPEN(UNIT=9, FILE=filename, STATUS="OLD", ACTION="READ",&
    IOSTAT=status)

! In case of error
IF(status /= 0) THEN
    PRINT *, "ERROR, could not open file."
    stop
END IF

! Read number of cities
READ (UNIT = 9, FMT = 100) numCity

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!Allocate memory for all needed arrays

allocate(cityName(numCity))
allocate(cityDistance(numCity,numCity)) 
allocate(path(numCity)) 
allocate(bestPath(numCity))

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!Fill in arrays from data file

DO I = 1, numCity
	READ (9,'(A)') cityName (I)
	path(I) = I
	DO J = 1, numCity
		READ(9, FMT = 100) cityDistance(i,j)
	END DO 
END DO

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
! Use recursion to find minimal distance

! Initializing values
globalMin = 9001
bestPath = 0

CALL permute(2,numCity)

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!Print formatted output

PRINT *
DO I = 1, numCity
	IF (I .eq. numCity) THEN
		PRINT *, trim(cityName(bestPath(I))), " to ", trim(cityName(1)), " -- ", cityDistance(I, 1), " miles"
	ELSE
		PRINT *, trim(cityName(bestPath(I))), " to ", trim(cityName(bestPath(I+1))), " --", cityDistance(I, I + 1), " miles"
	END IF
END DO

PRINT *
PRINT *, "Best distance is: ", globalMin, " miles"
PRINT *

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
! Janitorial duties
close (9)
deallocate(cityName)
deallocate(cityDistance)
deallocate(path)
deallocate(bestPath)

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!Format labels

100 FORMAT (I6)

CONTAINS

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
! This subroutine permutes through the possible paths the
!  salesman can take and finds the minimum distance for that
!  permutation. Then compares against the globalMin, and if less
!  than the globalMin, updates the value, and saves that path
!	first		The bottom value for permutation
!	last		The top value for permutation
RECURSIVE SUBROUTINE permute(first, last)
	INTEGER :: first, last, I, J, K, currentMin
	IF (first .eq.last) THEN
		
		currentMin = cityDistance(1, path(2))
		
		DO I = 2, (last - 1)
			currentMin = currentMin + cityDistance(path(I), path(I + 1))
		END DO
		
		currentMin = currentMin + cityDistance(path(last), 1)
		IF (currentMin .lt. globalMin) THEN
			globalMin = currentMin
			DO I=1, numCity
				bestPath(I) = path(I)
				
			END DO
		END IF
	ELSE
		DO I = first, last
			CALL swap(first, I)
			CALL permute(first + 1, last)
			CALL swap(first, I)
		END DO
	END IF
END SUBROUTINE permute
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
! This subroutine swaps the values of the path for permutation
!	first		The bottom value for permutation
!	I		The iterated value for permutation
SUBROUTINE swap (first, I)
	INTEGER :: holder, first, I
	holder = path(first)
	path(first) = path(I)
	path(I) = holder
END SUBROUTINE swap


END PROGRAM P4
