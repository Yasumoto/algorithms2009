#!/bin/sh

pdflatex $1.tex

#remove temporary files
rm $1.aux
rm $1.log

evince $1.pdf
