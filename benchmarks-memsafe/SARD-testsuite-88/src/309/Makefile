
all:	txt-dns-file-bad

clean:	
	@rm -f *-bad *-ok *.output.txt *.error.txt

txt-dns-file-bad: txt-dns-file-bad.c my-util.c  
	gcc -o txt-dns-file-bad txt-dns-file-bad.c my-util.c  -I . -lresolv

run: txt-dns-file-bad
	./txt-dns-file-bad > $<.output.txt 2> $<.error.txt
