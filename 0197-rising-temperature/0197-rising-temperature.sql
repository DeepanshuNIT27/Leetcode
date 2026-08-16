# Write your MySQL query statement below
SELECT id
FROM (
     SELECT id ,
        temperature,
        recordDate,
        LAG(recordDate) OVER(ORDER BY recordDate) AS previous_date,
        LAG(temperature) OVER(ORDER BY recordDate) AS previous_temperature
        FROM Weather 
        
) t
WHERE temperature > previous_temperature
AND DATEDIFF(recordDate,previous_date) = 1;
