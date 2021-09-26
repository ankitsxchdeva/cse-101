CC = clang 

prog0:	prog0.c
	$(CC) `pkg-config --cflags cairo` -o prog0 prog0.c `pkg-config --libs cairo`

clean:
	rm -f prog0
	rm -f *.png

scan-build:
	scan-build make