# Write your MySQL query statement below
SELECT v.customer_id , 
    COUNT(*) - COUNT(transaction_id ) AS count_no_trans
FROM Visits v
LEFT JOIN Transactions t
ON v.visit_id = t.visit_id
GROUP BY v.customer_id 
HAVING COUNT(*) - COUNT(t.transaction_id) > 0;

