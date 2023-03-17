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

DBMS_OUTPUT.PUT_LINE('Grade is');

IF s1_gpa <= 4 THEN
DBMS_OUTPUT.PUT_LINE('F');

ELSIF s1_gpa>4 and s1_gpa<=5 THEN
DBMS_OUTPUT.PUT_LINE('E');

ELSIF s1_gpa>5 and s1_gpa<=6 THEN
DBMS_OUTPUT.PUT_LINE('D');

ELSIF s1_gpa>6 and s1_gpa<=7 THEN
DBMS_OUTPUT.PUT_LINE('C');

ELSIF s1_gpa>7 and s1_gpa<=8 THEN
DBMS_OUTPUT.PUT_LINE('B');

ELSIF s1_gpa>8 and s1_gpa<=9 THEN
DBMS_OUTPUT.PUT_LINE('A');

ELSIF s1_gpa>9 and s1_gpa<=10 THEN
DBMS_OUTPUT.PUT_LINE('A+');

ELSE
DBMS_OUTPUT.PUT_LINE('No such GPA');
END IF;

end;
/