
all:	nxt-ok

clean:	
	@rm -f *-bad *-ok *.output.txt *.error.txt

nxt-ok: nxt-ok.c 
	gcc -o nxt-ok nxt-ok.c -I . -lresolv

run: nxt-ok
	./nxt-ok > $<.output.txt 2> $<.error.txt
