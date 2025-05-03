outfile: header.o main.o stud_add.o stud_show.o del_all.o stud_save.o stud_mod.o stud_rev.o stud_sort.o count.o stud_del.o stud_exit.o
	cc header.c main.c stud_add.c stud_show.c del_all.c stud_save.c stud_mod.c stud_rev.c stud_sort.c count.c stud_del.c stud_exit.c -o student
main.o: main.c
	cc -c main.c
stud_add.o: stud_add.c
	cc -c stud_add.c
stud_show.o: stud_show.c
	cc -c stud_show.c
header.o: header.c
	cc -c header.c
del_all.o: del_all.c
	cc -c del_all.c
stud_save.o: stud_save.c
	cc -c stud_save.c	
stud_mod.o: stud_mod.c
	cc -c stud_mod.c
stud_rev.o: stud_rev.c
	cc -c stud_rev.c
stud_sort.o: stud_sort.c
	cc -c stud_sort.c
count.o: count.c
	cc -c count.c
stud_del.o: stud_del.c
	cc -c stud_del.c
stud_exit.o: stud_exit.c
	cc -c stud_exit.c


