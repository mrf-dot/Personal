#include <stdio.h>

#include "algol.h"

INT compare(s1, s2)
	STRING s1;
	STRING s2;
BEGIN
	WHILE *s1++ == *s2
	DO
		IF *s2++ == 0 THEN
			return(0);
		FI
	OD
END

INT main()
BEGIN
	STRING s = "A STRING";
	printf("%d\n", compare(s, "Another STRING"));
END

