
Human : main.o English.o Chinese.o
	g++ -o $@ $^
%.o : %.cpp
	g++ -c -o $@ $<
clean:
	rm -f *.o Human