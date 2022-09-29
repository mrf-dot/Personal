#include <stdio.h>
#include <string.h>
#include "algol.h"

#define STRSIZE 1000

VOID lowercase(STRING s)
BEGIN
	FOR INT i = 0; s[i] != '\0'; i++
	DO
		IF s[i] >= 'A' AND s[i] <= 'Z' THEN
			s[i] += 'a' - 'A'
		FI
	OD
END

INT isvalidkey(STRING k)
BEGIN
	FOR INT i = 0; k[i] != '\0'; i++
	DO
		IF k[i] < 'a' OR k[i] > 'z' THEN
			return 0
		FI
	OD
	return 1
END

VOID encrypt(STRING p, STRING k)
BEGIN
	INT pc, kc;
	FOR INT i = 0; p[i] != '\0'; i++
	DO
		IF (p[i] >= 'A' AND p[i] <= 'Z') OR (p[i] >= 'a' AND p[i] <= 'z') THEN
			p[i] = (p[i] <= 'Z' ? 'A' : 'a') + ((p[i] >= 'a' ? p[i] - 'a' : p[i] - 'A') + (k[i % (strlen(k) - 1)] - 'a')) % 26
		FI
	OD
END

INT main(INT argc, STRING argv[])
BEGIN
	CHAR p[STRSIZE], k[STRSIZE];
	fputs("Enter a string to be encrypted: ", stdout);
	fgets(p, STRSIZE, stdin);
	fputs("Enter a key: ", stdout);
	fgets(k, STRSIZE, stdin);
	lowercase(k);
	IF isvalidkey(k) THEN
		fputs("Key must contain only letters.", stderr);
		return 1
	FI
	encrypt(p, k);
	printf("Your encrypted string: %s", p);
	return 0
END

