Results_hw5.pdf: Results_hw5.tex Graficas.png
	pdflatex $<

Graficas.png: Datos.dat Plots.py
	python Plots.py

Datos.dat: CurvaRotacion.x RadialVelocities.dat
	./CurvaRotacion.x

CurvaRotacion.x: CurvaRotacion.c 
	gcc CurvaRotacion.c -lm -o CurvaRotacion.x



