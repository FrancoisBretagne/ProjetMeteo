
EXO : exe

wind.o : wind.c header.h
	gcc -c $< -o $@

temperature.o : temperature.c header.h
	gcc -c $< -o $@
	
pression.o : pression.c header.h
	gcc -c $< -o $@
	
humidity.o : humidity.c header.h
	gcc -c $< -o $@
	
altitude.o : altitude.c header.h
	gcc -c $< -o $@
	
main.o : main.c header.h
	gcc -c $< -o $@

exe : wind.o temperature.o pression.o humidity.o altitude.o main.o
	gcc  $^ -o $@

clean:
	rm -f *.o
	rm exe


