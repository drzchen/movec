
all:	mime2-ok

clean:	
	@rm -f *-bad *-ok *.output.txt *.error.txt

mime2-ok: mime2-ok.c
	gcc -o mime2-ok mime2-ok.c  -I .

run: mime2-ok
	./mime2-ok s4.in > $<.output.txt 2> $<.error.txt
