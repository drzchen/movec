
all:	ns-lookup-bad create

clean:	
	@rm -f *-bad *-ok create *.output.txt *.error.txt

ns-lookup-bad: ns-lookup-bad.c
	gcc -o ns-lookup-bad ns-lookup-bad.c

create:	create_address_file.c
	gcc -o create create_address_file.c ; \
	./create

run: ns-lookup-bad create
	./ns-lookup-bad b4.in > $<.output.txt 2> $<.error.txt
