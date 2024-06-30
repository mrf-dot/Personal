.de H
.NH
\\$1
.XS
.LG
\\*(SN\t\\$1
.NL
.XE
..
.de H2
.NH 2
\\$1
.XS
\\*(SN\t\t\\$1
.XE
..
.de SC
.DS B
.fam C
..
.de SE
.DE
.fam T
..
.de BU
.IP \(bu
..
.if t .ds TX \fRT\\h'-0.1667m'\\v'0.20v'E\\v'-0.20v'\\h'-0.125m'X\fP
.if n .ds TX TeX
.if t .ds LX \fRL\\h'-0.36m'\\v'-0.15v'\s-2A\s0\\h'-0.15m'\\v'0.15v'\fP\*(TX
.if n .ds LX LaTeX
\# .nr commands modify number registers. For example, PS changes the
\# font size and LL changes the line length. I set PS to 12p
\# and LL to 6.5i so that the document has 12 point font and
\# 1 inch margins
.nr PS 12p
.nr LL 6.5i
.nr HY 0
