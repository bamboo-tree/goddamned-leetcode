SELECT c.name as "Customers"
FROM Customers as c
LEFT JOIN Orders as o ON o.customerId = c.id
WHERE o.customerId IS NULL;
