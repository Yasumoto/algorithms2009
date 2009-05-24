CC=pdflatex
.PHONY: clean

all:
	$(CC) *.tex && $(CC) *.tex && bibtex joeSmith_MaxFlow && $(CC) *.tex && $(CC) *.tex
clean:
	rm -f *.aux *.log joeSmith_MaxFlow.pdf *.dvi *.blg
