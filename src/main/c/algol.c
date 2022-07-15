#include <stdio.h>

#define STRING char *
#define IF if(
#define THEN ) {
#define ELSE } else {
#define FI ;}
#define WHILE while (
#define DO ) {
#define OD ;}
#define INT int
#define BEGIN {
#define END }

INT compare(s1, s2)
	STRING s1;
	STRING s2;
BEGIN
	WHILE *s1++ == *s2
	DO
		IF *s2++ == 0
			THEN return(0);
		FI
	OD
END

INT main()
BEGIN
	printf("%d\n", compare("A STRING", "A STRING"));
END

