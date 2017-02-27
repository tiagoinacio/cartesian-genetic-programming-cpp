all:
	make lint && make build && make docs && make open

lint:
	python cpplint.py src/*/*

build:
	make clean && clang++ -std=c++14 -Wunicode-whitespace -g main.cpp src/*/*.cpp -o bin/main -v

# -I /usr/local/Cellar/boost/1.63.0/include -L /usr/local/Cellar/boost/1.63.0/lib
run:
	./bin/main

docs:
	doxygen doxy.conf

open:
	./bin/main

clean:
	rm -rf bin && mkdir bin
