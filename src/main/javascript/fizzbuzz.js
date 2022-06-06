for (i = 1; i < 101; i++) {
	fizzstr = "";
	fizzstr += i % 3 == 0 ? "Fizz" : "";
	fizzstr += i % 5 == 0 ? "Buzz" : "";
	fizzstr += i % 7 == 0 ? "Foo" : "";
	fizzstr += i % 9 == 0 ? "Bar" : "";
	console.log(fizzstr ? fizzstr : i );
}	
