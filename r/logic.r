logical1 <- TRUE
logical2 <- FALSE

# element wise and/or
# does not utilize short circuit logic
# evaulates entire vector and returns a vector of results
logical1 & logical2 # FALSE
logical1 & logical1 # TRUE
logical1 | logical2 # TRUE

# statement wise and/or
# utilizes short circuit logic
(logical1 == logical1) && (logical1 == logical1) # TRUE
(logical1 == logical1) || !(logical1 == logical1) # TRUE
!(logical1 == logical1) || !(logical1 == logical1) # FALSE

# ! is the negation operator
logical1 # TRUE
!logical1 # FALSE
