set serveroutput on 
DECLARE
	CURSOR curs is select * from student order by tot_cred;
	stud_name student.name%type;
	stud_id student.id%type;
	stud_dept_name student.dept_name%type;
	stud_cred student.tot_cred%type;
BEGIN
	OPEN curs;
	LOOP
   	EXIT WHEN (curs%ROWCOUNT > 9) OR (curs%NOTFOUND);
   	fetch curs into stud_id, stud_name, stud_dept_name, stud_cred;
   	dbms_output.put_line(stud_id || ' ' || stud_name || ' ' || stud_dept_name
   	|| ' ' || stud_cred);
   	END LOOP;
   	CLOSE curs;
END;
/