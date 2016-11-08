placas.pdf: grafica.py v.txt ex.txt ey.txt
	python grafica.py
v.txt ex.txt ey.txt:a.out
	./a.out
a.out:placas.c
	gcc placas.c
clean:
	rm -f a.out v.txt ex.txt ey.txt