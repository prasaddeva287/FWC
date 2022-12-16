#!/bin/bash

cd assembly
cd codes 

#pio run  

cd ..
 
pdflatex avra.tex
xdg-open avra.pdf
