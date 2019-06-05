Упражнение 14
===

Faculty
	- name
	- Student students[]
	- Teacher teachers[]

	load(filename)
	save(filename)

	Person* people[];

 	Teacher[] findTeachersBySubject(string)
 	Student findStudentByFN(long)
	
 	Person findPersonByEmail(string);

	add(Teacher)
	add(Student)

Person
	find
	> Student (name, email, fn)
	> Teacher (name, email, subjects)
