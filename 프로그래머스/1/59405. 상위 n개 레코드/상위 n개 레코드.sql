select NAME
from animal_ins
where
    DATETIME = (
        select min(DATETIME)
        from animal_ins
    );