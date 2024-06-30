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
\# This command makes everything within dollar signs ($) appear as a
\# mathematical equation
.EQ
delim $$
.EN
\# The document must include a TL (title) tag and an AU (author) tag
.RP no
.TL
Basic Typesetting with Groff
.AU
Mitch Feigenbaum
.AI
Lake Braddock Secondary School
.ND
\#25 January 2022
.AB
Mathematical typesetting in professional settings is typically done through either \*(LX/\*(TX or Word\**.
\# You can include footnotes by using the \** symbol and including a footnote tag
.FS
Word is a registered trademark of Microsoft Corporation\[rg].
.FE
However, there is a simple and free way to make professional looking documents with tables, mathematical symbols, and chemical equations that is installed by default on all *nix systems (macOS, Linux, BSD). The program groff can beautifully typeset documents in a fashion superior to most widely used document creation programs.
.AE
.H "Mathematical Typesetting"
\# Groff collapses white space.
.PP
Below are a few famous equations rendered in groff. The equivalent \*(LX and Word versions for these would be made much more difficult. Mathematical equations in groff are rendered through the groff companion program eqn. The table is created through the groff companion program tbl.
\# Tables require arguments and can contain inline math equations
\# You can separate table columns with tabs (not spaces).
.TS H
allbox expand;
cB s.
Famous Equations
.TH
.T&
l r.
Pythagorean Theorem	$c = sqrt{a sup 2 + b sup 2}$
Sigma	$lim from {N -> inf} sum from {k = 1} to N {k sup 2}$
Quadratic Formula	$x = {-b +- sqrt{b sup 2 - 4ac}} over 2a$
Newton's First Law	$sum F = 0~\[hA]~dv over dt = 0$
Newton's Second Law	$sum F = ma$
Newton's Third Law	$F sub A = - F sub B$
Golden Ratio	$phi = {1 + sqrt 5} over 2 = 1.6180339887....$
Fourier Transform	$F ( k over N DELTA t) = sum from {j = 0} to N - 1 f ( j DELTA t ) e sup {- {i 2 pi jk} over N}~~~n = 0, 1, ..., N-1$
Einstein Field Equations	$G sub {mu nu} + lambda g sub {mu nu} = kappa T sub {mu nu}$
Definite Integral	$int from a to b f(x)dx.$
Legendre Function	$P sub {n,m} ( cos theta ) = 1 over {2 sup n n!} (t - t sup 2) sup {m / 2} {d sup {n + m}} over {dt sup {n + m}} (t sup 2 - 1) sup n$
Navier-Stokes Equations	$rho ( {partial u} over {partial t} + u cdot del u) = - del sub p + del cdot T sub D + f$
Simple Matrix	$A = left [ matrix {lcol {0 above 1 above 2} ccol {-1 above 0 above 1} ccol {-2 above -1 above 0} rcol {-3 above -2 above -1}} right ]$
Discrete Masses	$I = sum from i { m sub i cdot  r sub i} = sum from i {left |  r sub i right | sup 2 m}$
Low Amplitude Simple Pendulum	$omega = sqrt {g over L} left [ 1 + sum from {k = 1} to inf {{prod from {n = 1} to k {2n - 1}} over {prod from {n = 1} to m {2n}} sin sup {2n}  THETA} right ]$
Gravitomagnetic Field	$xi = G over {2c sup 2} { L 3 (  L cdot  r hat )  r hat} over {left |  r right | sup 3}$
Tsiolkovsky rocket equation	$DELTA v = v sub e ln {m sub 0} over {m sub f} = I sub {sp} g sub 0 ln {m sub 0} over {m sub f}$
.TE
.H "Chemical Typesetting"
.PP
Below are a few chemical equations that demonstrate the capabilities of groff's companion program chem.
.KS
.H2 "Butane $roman{C sub 4 H sub 10}$"
.LP
.cstart
H
bond right
C
bond up
H
bond down from C
H
bond right from C
C
bond up
H
bond down from C
H
bond right from C
C
bond up
H
bond down from C
H
bond right from C
C
bond up
H
bond down from C
H
bond right from C
H
.cend
.KE
.KS
.H2 "Propane $roman{C sub 3 H sub 8}$"
.LP
.cstart
H
bond se
C
bond sw
H
bond down from C
H
bond ne from C
C
bond nw
H
bond ne from C
H
bond se from C
C
bond down from C
H
bond se from C
H
bond ne from C
H
.cend
.KE
.KS
.H2 "Methyl Formate $roman{C sub 2 H sub 4 O sub 2}$"
.LP
.cstart
H
bond ne
C
double bond up
O
bond se from C
O
bond ne
CH3
.cend
.KE
.KS
.H2 "Glucose $roman{C sub 6 H sub 12 O sub 6}$"
.LP
.cstart
R1: ring pointing right put O at 6
bond down from R1.V1
OH
bond down from R1.V2
OH
bond up from R1.V3
OH
bond down from R1.V4
bond down
OH
bond up from R1.V5
CH2OH
.cend
.KE
.KS
.H2 "Ethanimine $roman{C sub 2 H sub 5 N}$"
.LP
.cstart
C
bond se
H
bond sw from C
H
bond nw from C
H
bond ne from C
C
bond up
H
double bond se from C
N
bond ne
H
.cend
.KE
.KS
.H2 "Methylacetylene $roman{C sub 3 H sub 4}$"
.LP
.cstart
H
bond right
C
triple bond right
C
bond right
C
bond up
H
bond down from C
H
bond right from C
H
.cend
.KE
.KS
.H2 "Ethenol $roman{CH sub 2 CHOH}$"
.LP
.cstart
H
bond se
C
bond down
H
double bond ne from C
C
bond se
H
bond up from C
O
bond ne
H
.cend
.KE
\# Add the TC macro at the end to make a table of contents
.TC
