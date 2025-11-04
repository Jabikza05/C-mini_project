student_details:main.o stud_add.o stud_del.o stud_show.o stud_mod.o stud_exit.o stud_save.o  stud_sort.o stud_del_all_rec.o stud_rev.o

	cc main.c stud_add.c stud_del.c stud_show.c stud_mod.c stud_exit.c stud_save.c  stud_sort.c stud_del_all_rec.c stud_rev.c -o student_details 

main.o:main.c
	cc -c main.c

stud_add.o:stud_add.c
	cc -c stud_add.c

stud_del.o:stud_del.c
	cc -c stud_del.c

stud_show.o:stud_show.c
	cc -c stud_show.c

stud_mod.o:stud_mod.c
	 cc -c stud_mod.c

stud_exit.o:stud_exit.c
	cc -c stud_exit.c

stud_save.o:stud_save.c
	cc -c stud_save.c

stud_sort.o:stud_sort.c
	cc -c stud_sort.c

stud_del_all_rec.o:stud_del_all_rec.c
	cc -c stud_del_all_rec.c

stud_rev.o:stud_rev.c
	cc -c stud_rev.c


