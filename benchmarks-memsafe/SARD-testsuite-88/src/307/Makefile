
all:	ttflag-bad

clean:	
	@rm -f *-bad *-ok *.output.txt *.error.txt

ttflag-bad:  my-main.c ttflag-bad.c
	gcc -o ttflag-bad my-main.c ttflag-bad.c -I .

run: ttflag-bad
	./ttflag-bad -d 4294967200-100 > $<.output.txt 2> $<.error.txt

