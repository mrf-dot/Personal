let fizzbuzz:string;
for (let i:number = 1; i < 101; i++) {
	fizzbuzz = "";
	fizzbuzz += (i % 3 == 0) ? "Fizz" : "";
	fizzbuzz += (i % 5 == 0) ? "Buzz" : "";
	console.log((fizzbuzz == "") ? i : fizzbuzz);
}
