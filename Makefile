objects = play_random play_taylor task_5 arrays structs structs2 structs3 readfile fishing_readmap fishing_readmap_function test1_practice play play_before_test1 hello_world if_for_while pointer bubble_sort recursion_factorial recursion_fibonacci epfu_lab2b epfu_lab1_task2 epfu_lab3d epfu_lab4b epfu_lab5 epfu_lab6g epfu_lab6c epfu_lab7c test2_practice NVec Complex test2_question makcay1_lab7a

all: $(objects)

makcay1_lab7a: makcay1_lab7a.c -lm
test2_question: test2_question.c
epfu_lab1_task2: epfu_lab1_task2.c
epfu_lab_2b: epfu_lab2b.c
epfu_lab3d: epfu_lab3d.c
	cc -o epfu_lab3d epfu_lab3d.c -lm
epfu_lab4b: epfu_lab4b.c
epfu_lab5: epfu_lab5.c
epfu_lab6g: epfu_lab6g.c
epfu_lab6g: epfu_lab6g.c
epfu_lab7c: epfu_lab7c.c
bubble_sort: bubble_sort.c
play_random: play_random.c
play_taylor : play_taylor.c
	cc -o play_taylor play_taylor.c -lm
task_5 : task_5.c
pointer: pointer.c
arrays : arrays.c
if_for_while : if_for_while.c
hello_world: hello_world.c
recursion_fibonacci: recursion_fibonacci.c
recursion_factorial: recursion_factorial.c
structs : structs.c
structs2 : structs2.c
structs3 : structs3.c
readfile: readfile.c
fishing_readmap: fishing_readmap.c
fishing_readmap_function: fishing_readmap_function.c
test1_practice: test1_practice.c
test2_practice: test2_practice.c
play: play.c
play_before_test1: play_before_test1.c
NVec: NVec.c
Complex: Complex.c -lm

.PHONY : clean
clean :
	rm $(objects)
	rm *.o
