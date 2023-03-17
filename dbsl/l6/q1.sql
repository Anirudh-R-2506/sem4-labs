set serveroutput on 
declare
s1_roll StudentTable.RollNo % TYPE;
s1_gpa StudentTable.GPA % TYPE;
begin
	s1_roll:='&RollNo';

SELECT GPA
INTO s1_gpa
FROM StudentTable
WHERE RollNo=s1_roll;

dbms_output.put_line('RollNo:'||s1_roll||'   GPA:'||s1_gpa||'');
end;
/