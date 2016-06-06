
Human : main.o English.o Chinese.o Human.o
	g++ -o $@ $^
%.o : %.cpp
	g++ -c -o $@ $<
clean:
	rm -f *.o Human