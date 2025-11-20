SELECT DATETIME as 시간
from ANIMAL_INS
where datetime =
    (select max(datetime)
     from animal_ins);