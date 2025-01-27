# The grepl function checks if a char/sequence of chars are in a string

string <- "an introduction to the R language"
grepl("an i", string) # true
grepl("extra", string) # false
grepl("R", string) # true
