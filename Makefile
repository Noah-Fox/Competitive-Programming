COMPILE = g++ -Wall -Werror -std=c++20

all:
	@echo "\t make <program>"

%: %.cc
	$(COMPILE) $< -o $@+

clean:
	rm *+
