mahjong_test : detect_win.cpp main.cpp
	g++ -std=c++11 -o $@ $^
