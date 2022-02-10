Write-Output "American Flag:`n"
Write-Output "`e[48;5;17m* * * * * * * * * * `e[48;5;124m$(" " * 27)`e[0m"
for ($i = 0; $i -lt 3; $i++) {
	Write-Output "`e[48;5;17m * * * * * * * * *  `e[47m$(" " * 27)`e[0m"
	Write-Output "`e[48;5;17m* * * * * * * * * * `e[48;5;124m$(" " * 27)`e[0m"
}
for ($i = 0; $i -lt 3; $i++) {
	Write-Output "`e[47m$(" " * 47)`e[0m"
	Write-Output "`e[48;5;124m$(" " * 47)`e[0m"
}
#####################################################################################
Write-Output "`nFrench Flag:`n"
for ($i = 0; $i -lt 15; $i++) {
	Write-Output "`e[48;5;17m$(" " * 15)`e[47m$(" " * 15)`e[41m$(" " * 15)`e[0m"
}
#####################################################################################
Write-Output "`nSwiss Flag:`n"
for ($i = 0; $i -lt 6; $i++) {
	Write-Output "`e[41m$(" " * 64)`e[0m"
}
for ($i = 0; $i -lt 7; $i++) {
	Write-Output "`e[41m$(" " * 26)`e[47m$(" " * 12)`e[41m$(" " * 26)`e[0m"
}
for ($i = 0; $i -lt 6; $i++) {
	Write-Output "`e[41m$(" " * 12)`e[47m$(" " * 40)`e[41m$(" " * 12)`e[0m"
}
for ($i = 0; $i -lt 7; $i++) {
	Write-Output "`e[41m$(" " * 26)`e[47m$(" " * 12)`e[41m$(" " * 26)`e[0m"
}
for ($i = 0; $i -lt 6; $i++) {
	Write-Output "`e[41m$(" " * 64)`e[0m"
}
#####################################################################################
Write-Output "`nGreek Flag:`n"
for ($i=0; $i -lt 2; $i++) {
	Write-Output "`e[48;5;17m$(" " * 8)`e[47m$(" " * 4)`e[48;5;17m$(" " * 42)`e[0m"
}
for ($i=0; $i -lt 2; $i++) {
	Write-Output "`e[48;5;17m$(" " * 8)`e[47m$(" " * 4)`e[48;5;17m$(" " * 8)`e[47m$(" " * 34)`e[0m"
}
for ($i=0; $i -lt 2; $i++) {
	Write-Output "`e[47m$(" " * 20)`e[48;5;17m$(" " * 34)`e[0m"
}
for ($i=0; $i -lt 2; $i++) {
	Write-Output "`e[48;5;17m$(" " * 8)`e[47m$(" " * 4)`e[48;5;17m$(" " * 8)`e[47m$(" " * 34)`e[0m"
}
for ($i=0; $i -lt 2; $i++) {
	Write-Output "`e[48;5;17m$(" " * 8)`e[47m$(" " * 4)`e[48;5;17m$(" " * 42)`e[0m"
}
for ($i=0; $i -lt 2; $i++) {
	Write-Output "`e[47m$(" " * 54)`e[0m"
	Write-Output "`e[47m$(" " * 54)`e[0m"
	Write-Output "`e[48;5;17m$(" " * 54)`e[0m"
	Write-Output "`e[48;5;17m$(" " * 54)`e[0m"
}
#####################################################################################
Write-Output "`nNorwegian Flag:`n"
for ($i=0; $i -lt 6; $i++) {
	Write-Output "`e[41m$(" " * 12)`e[47m  `e[48;5;17m$(" " * 4)`e[47m  `e[41m$(" " * 24)`e[0m"
}
Write-Output "`e[47m$(" " * 14)`e[48;5;17m$(" " * 4)`e[47m$(" " * 26)`e[0m"
for ($i=0; $i -lt 2; $i++) {
	Write-Output "`e[48;5;17m$(" " * 44)`e[0m"
}
Write-Output "`e[47m$(" " * 14)`e[48;5;17m$(" " * 4)`e[47m$(" " * 26)`e[0m"
for ($i=0; $i -lt 6; $i++) {
	Write-Output "`e[41m$(" " * 12)`e[47m  `e[48;5;17m$(" " * 4)`e[47m  `e[41m$(" " * 24)`e[0m"
}
#####################################################################################
Write-Output "`nTongan Flag:`n"
Write-Output "`e[47m$(" " * 24)`e[41m$(" " * 40)`e[0m"
for ($i=0; $i -lt 2; $i++) {
	Write-Output "`e[47m$(" " * 10)`e[41m$(" " * 4)`e[47m$(" " * 10)`e[41m$(" " * 40)`e[0m"
}
for ($i=0; $i -lt 2; $i++) {
	Write-Output "`e[47m$(" " * 6)`e[41m$(" " * 12)`e[47m$(" " * 6)`e[41m$(" " * 40)`e[0m"
}
for ($i=0; $i -lt 2; $i++) {
	Write-Output "`e[47m$(" " * 10)`e[41m$(" " * 4)`e[47m$(" " * 10)`e[41m$(" " * 40)`e[0m"
}
Write-Output "`e[47m$(" " * 24)`e[41m$(" " * 40)`e[0m"
for ($i=0; $i -lt 8; $i++) {
	Write-Output "`e[41m$(" " * 64)`e[0m"
}
#####################################################################################
Write-Output "`nBulgarian Flag:`n"
for ($i = 0; $i -lt 4; $i++) {
	Write-Output "`e[47m$(" " * 40)`e[0m"
}
for ($i = 0; $i -lt 4; $i++) {
	Write-Output "`e[42m$(" " * 40)`e[0m"
}
for ($i = 0; $i -lt 4; $i++) {
	Write-Output "`e[41m$(" " * 40)`e[0m"
}
#####################################################################################
Write-Output "`nBeninese Flag:`n"
# 30x20
for ($i=0; $i -lt 10; $i++) {
	Write-Output "`e[48;5;28m$(" " * 24)`e[48;5;226m$(" " * 36)`e[0m"
}
for ($i=0; $i -lt 10; $i++) {
	Write-Output "`e[48;5;28m$(" " * 24)`e[48;5;196m$(" " * 36)`e[0m"
}
#####################################################################################
Write-Output "`nGambian Flag:`n"
for ($i=0; $i -lt 6; $i++) {
	Write-Output "`e[48;5;196m$(" " * 54)`e[0m"
}
Write-Output "`e[47m$(" " * 54)`e[0m"
for ($i=0; $i -lt 4; $i++) {
	Write-Output "`e[48;5;18m$(" " * 54)`e[0m"
}
Write-Output "`e[47m$(" " * 54)`e[0m"
for ($i=0; $i -lt 6; $i++) {
	Write-Output "`e[48;5;28m$(" " * 54)`e[0m"
}
#####################################################################################
Write-Output "`nFinnish Flag:`n"
# 36x11
# `e[48;5;18m
for ($i=0; $i -lt 8; $i++) {
	Write-Output "`e[47m$(" " * 20)`e[48;5;18m$(" " * 12)`e[47m$(" " * 40)`e[0m"
}
for ($i = 0; $i -lt 6; $i++) {
	Write-Output "`e[48;5;18m$(" " * 72)`e[0m"
}
for ($i=0; $i -lt 8; $i++) {
	Write-Output "`e[47m$(" " * 20)`e[48;5;18m$(" " * 12)`e[47m$(" " * 40)`e[0m"
}
#####################################################################################
Write-Output "`nIcelandic Flag:`n"
for ($i = 0; $i -lt 7; $i++) {
	Write-Output "`e[48;5;18m$(" " * 14)`e[47m$(" " * 2)`e[48;5;1m$(" " * 4)`e[47m$(" " * 2)`e[48;5;18m$(" " * 28)`e[0m"
}
Write-Output "`e[47m$(" " * 16)`e[48;5;1m$(" " * 4)`e[47m$(" " * 30)`e[0m"
for ($i = 0; $i -lt 2; $i++) {
	Write-Output "`e[48;5;1m$(" " * 50)`e[0m"
}
Write-Output "`e[47m$(" " * 16)`e[48;5;1m$(" " * 4)`e[47m$(" " * 30)`e[0m"
for ($i = 0; $i -lt 7; $i++) {
	Write-Output "`e[48;5;18m$(" " * 14)`e[47m$(" " * 2)`e[48;5;1m$(" " * 4)`e[47m$(" " * 2)`e[48;5;18m$(" " * 28)`e[0m"
}
