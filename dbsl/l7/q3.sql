set serveroutput on 
declare
    cursor disp_curs is with stud as (select * from (student natural join takes natural join section)),ins as (select * from (instructor natural join teaches natural join section))
                select course_id,title,ins.dept_name,credits,ins.name,ins.building,ins.room_number,ins.time_slot_id,count(*) as no_of_students from stud inner join  ins using(course_id,sec_id,semester,year) natural join course
                group by (course_id,title,ins.dept_name,credits,ins.name,ins.building,ins.room_number,ins.time_slot_id);
begin
    for temp in disp_curs
        loop
            dbms_output.put_line('Course ID : '|| temp.course_id);
            dbms_output.put_line('Title : '|| temp.title);
            dbms_output.put_line('Department : '|| temp.dept_name);
            dbms_output.put_line('Credits : '|| temp.credits);
            dbms_output.put_line('Instructor Name : '|| temp.name);
            dbms_output.put_line('Building : '|| temp.building);
            dbms_output.put_line('Room Number : '|| temp.room_number);
            dbms_output.put_line('Time Slot ID : '|| temp.time_slot_id);
            dbms_output.put_line('Total Students : '|| temp.no_of_students);
        end loop;
end;
/