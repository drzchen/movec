
all:	call-realpath-ok

clean:	
	@rm -f *-ok *.output.txt *.error.txt

call-realpath-ok: call-realpath-ok.c realpath-2.4.2.c
	gcc -o call-realpath-ok call-realpath-ok.c realpath-2.4.2.c

run: call-realpath-ok
	./call-realpath-ok /aaa/aaa/aaa/aaa/aaa/aaa/aaa/aaa/aaa/aa/aaa/aaa/aaa/aaa/aaa/aaa/aaa/aaa/aaa/aaa/aa/aaa/aaa/aaa/aaa/aaa/aaa/aaa/aaa/aaa/aaa/aa/aaa/aaa/aaa/aaa/aaa/aaa/aaa/aaa/aaa/aaa/aa/aaa/aaa/aaa/aaa/aaa/aaa/aaa/aaa/aaa/aaa/aa/aaa/aaa/aaa/aaa/aaa/aaa/aaa/aaa/aaa/aaa/aa/aaa/aaa/aaa/aaa/aaa/aaa/aaa/aaa/aaa/aaa/aa/aaa/aaa/aaa/aaa/aaa/aaa/aaa/aaa/aaa/aaa/aa/aaa/aaa/aaa/aaa/aaa/aaa/aaa/aaa/aaa/aaa/aa/aaa > $<.output.txt 2> $<.error.txt

