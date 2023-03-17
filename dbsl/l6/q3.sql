set serveroutput on 
declare
issue date;
rdate date;
fine number(5);
late number(5);
begin
	issue:=to_date('&issue','dd-mm-yy');
	rdate:=to_date('&rdate','dd-mm-yy');

late := rdate - issue;

IF late <= 7 THEN
DBMS_OUTPUT.PUT_LINE('No fine');

ELSIF late between 8 and 15 THEN
DBMS_OUTPUT.PUT_LINE('The fine is: '|| late*1||' Rs');

ELSIF late between 16 and 30 THEN
DBMS_OUTPUT.PUT_LINE('The fine is: '|| late*2||' Rs');

ELSIF late >=30 THEN
DBMS_OUTPUT.PUT_LINE('The fine is: '|| late*5||' Rs');

ELSE
DBMS_OUTPUT.PUT_LINE('No such input');
END IF;

end;
/