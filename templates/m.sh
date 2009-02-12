#!/bin/sh

#double LateXing for bib consistency
pdflatex $1.tex
pdflatex $1.tex

bibtex $1

pdflatex $1.tex
pdflatex $1.tex 


#remove temporary files
rm $1.bbl
rm $1.aux
rm $1.log
rm $1.blg

