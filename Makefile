hellomake: asg.c
	astyle --style=ansi < asg.c > asg_s.c
	gcc -Wall asg.c -o hny.out -pg
	./hny.out
	gprof hny.out gmon.out > p_asg
	doxygen -g zxc
	doxygen zxc
	doxygen -w html header.html footer.html stylesheet.css zxc
