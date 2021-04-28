
all:	nxt-bad

clean:	
	@rm -f *-bad *-ok *.output.txt *.error.txt

nxt-bad: nxt-bad.c 
	gcc -o nxt-bad nxt-bad.c -I . -lresolv

run: nxt-bad
	./nxt-bad > $<.output.txt 2> $<.error.txt
