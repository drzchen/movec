
all:	ge-ok

clean:	
	@rm -f *-bad *-ok *.output.txt *.error.txt

ge-ok: ge-ok.c  recipient.c  util.c
	gcc -o ge-ok ge-ok.c  recipient.c  util.c -I .

run: ge-ok
	./ge-ok > $<.output.txt 2> $<.error.txt

