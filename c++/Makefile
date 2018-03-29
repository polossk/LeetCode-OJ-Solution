CC      = g++
EXEC    = main.exe
CXXFLAGS = -std=c++11 -lm

leetcode: leetcode???.cpp
	$(CC) -o $(EXEC) $< $(CXXFLAGS)
	$(EXEC)

clean: $(EXEC)
	del $(EXEC)

.PHONY: clean