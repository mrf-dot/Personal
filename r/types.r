# numeric
number1 <- 32.8
number2 <- 81

# integer (denoted by postfix L)
int1 <- 10L
int2 <- 5L

# complex (denoted by i)
complex1 <- 10 + 1i
complex2 <- 3 + 2i

# character
char1 <- 'a'
char2 <- "Hello"
char3 <- "world"

# logical
logic1 <- TRUE
logic2 <- FALSE

# show data types of all variables
class(number1)
class(number2)
class(int1)
class(int2)
class(complex1)
class(complex2)
class(char1)
class(char2)
class(char3)
class(logic1)
class(logic2)

# typecast numbers
class(as.numeric(complex1))
class(as.integer(number1))
class(as.complex(int1))
