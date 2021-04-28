
all:	ttflag-ok

clean:	
	@rm -f *-bad *-ok *.output.txt *.error.txt

ttflag-ok: my-main.c ttflag-ok.c
	gcc -o ttflag-ok my-main.c ttflag-ok.c -I .

run: ttflag-ok
	./ttflag-ok -d 4294967200-100 > $<.output.txt 2> $<.error.txt

