set serveroutput on 
DECLARE
s1_gpa StudentTable.GPA % TYPE;
max_gpa StudentTable.gpa%TYPE;
BEGIN
max_gpa := 0;
FOR i IN 1..5 LOOP

SELECT GPA
INTO s1_gpa
FROM StudentTable
WHERE RollNo=i;
IF s1_gpa > max_gpa then
	max_gpa := s1_gpa;
end if;

END LOOP;
dbms_output.put_line('Max GPA is: '||max_gpa||'');
end;
/