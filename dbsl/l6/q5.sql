ALTER TABLE StudentTable ADD LetterGrade varchar(2);
set serveroutput on 

DECLARE
s1_roll number :=0;
s1_gpa StudentTable.GPA % TYPE;
s1_grade varchar(2);
BEGIN

WHILE s1_roll < 5
 LOOP
s1_roll := s1_roll + 1;

SELECT GPA
INTO s1_gpa
FROM StudentTable
WHERE RollNo=s1_roll;

IF s1_gpa <= 4 THEN
s1_grade := 'F';

ELSIF s1_gpa>4 and s1_gpa<=5 THEN
s1_grade := 'E';

ELSIF s1_gpa>5 and s1_gpa<=6 THEN
s1_grade := 'D';

ELSIF s1_gpa>6 and s1_gpa<=7 THEN
s1_grade := 'C';

ELSIF s1_gpa>7 and s1_gpa<=8 THEN
s1_grade := 'B';

ELSIF s1_gpa>8 and s1_gpa<=9 THEN
s1_grade := 'A';

ELSIF s1_gpa>9 and s1_gpa<=10 THEN
s1_grade := 'A+';

ELSE
DBMS_OUTPUT.PUT_LINE('No such GPA');
END IF;

update StudentTable set LetterGrade = s1_grade where RollNo=s1_roll;
 END LOOP;

 DBMS_OUTPUT.PUT_LINE('------The table is updated------');
END;
/