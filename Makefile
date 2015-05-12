all:
	clang++-3.5 -std=c++11 template_test.cpp ../gtest/gtest-all.o -lpthread -o template_test.o
	./template_test.o
