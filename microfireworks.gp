#!/usr/bin/gnuplot

set terminal epslatex standalone monochrome
set output "/tmp/scaling.tex"

set xlabel "$1/r~(\\mu m)^{-1}$"
set ylabel "$U~(\\mu m / s)$"
plot 'public/presentations/microfireworks/data/bucket-output.txt' with errorbars lw 2 ps 2 pt 6 notitle,\
1.983934+0.899089*x lw 2 notitle

set output "/tmp/plot.tex"
set xlabel "$r~(\\mu m)$"
set ylabel "$U~(\\mu m / s)$"
plot 'public/presentations/microfireworks/data/bucket-output-radial.txt' with errorbars lw 2 ps 2 pt 6 notitle,\
1.983934+0.899089*(1.0 / x) lw 2 notitle
