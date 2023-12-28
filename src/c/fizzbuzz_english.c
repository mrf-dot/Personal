#include <stdio.h>
#include "english.h"

valueless fizzbuzz requiring nothing
evaluates
	let i equal one
	then while i less than 101
	evaluate
		when i mod 15 is zero
		evaluates
			puts with "FizzBuzz" supplied
		finish
		otherwise when i mod five is zero
		evaluates
			puts with "Buzz" supplied
		finish
		otherwise when i mod three is zero
		evaluates
			puts with "Fizz" supplied
		finish
		alternatively
		evaluates
			printf with "%d\n" also i supplied
		finish
		i equals i plus one
	finish
finish

always
evaluates
	fizzbuzz with nothing supplied
	then returns zero
finish

