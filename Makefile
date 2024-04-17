compile: code.c 
	gcc code.c -o raid

run: 
	./raid

clean: 
	rm raid

upload:
	mkdir -p src
	cp code.c src/
	cp Makefile src/
	zip -r raid.zip src