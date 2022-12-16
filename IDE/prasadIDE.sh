#!/bin/bash
cd  IDE
cd  codes

 pio run

cd ..

 pdflatex ide.tex

xdg-open ide.pdf
