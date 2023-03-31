drop table salary_raise;
create table salary_raise(
    Instructor_Id number(5) primary key,
    Raise_date date,
    Raise_amt number(10,5)
);

set serveroutput on 
DECLARE 
raise_amount number(6);
new_sal number(6);
raise_date date;
update_salary instructor % ROWTYPE; 
CURSOR c IS (SELECT * from instructor) for UPDATE;
BEGIN
    OPEN c;
    raise_date:=sysdate;
            LOOP
            fetch c into update_salary;
            exit when c%NOTFOUND;
            raise_amount:=(update_salary.salary*1.05)-update_salary.salary;
            new_sal:=update_salary.salary*1.05;
            update instructor set salary = new_sal where current of c;
            insert into salary_raise values(update_salary.id,raise_date,raise_amount);
             
            END LOOP;
        CLOSE c;
END;
/
