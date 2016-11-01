all : mahjong_test test

mahjong_test : detect_win.cpp main.cpp
	g++ -std=c++11 -o $@ $^
test : detect_win.cpp test_case.cpp test.cpp
	g++ -g -std=c++11 -o $@ $^

clean : 
	rm mahjong_test test
