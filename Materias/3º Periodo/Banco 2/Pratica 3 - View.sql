--ATV 1
create view TotalPorCliente as select c.nome, sum(r.valor) as TotalGasto 
from cliente c inner join corrida r on c.cliid = r.cliid 
group by nome

--ATV 2
CREATE VIEW CORRIDASPORTAXI AS 
SELECT DISTINCT PLACA, COUNT(*) AS QuantidadeCorridas FROM CORRIDA
GROUP BY PLACA;

--ATV 3
CREATE VIEW CLIENTESSEMCORRIDA AS 
SELECT C.NOME FROM CLIENTE AS C LEFT JOIN CORRIDA AS R
ON C.CLIID = R.CLIID 
WHERE R.CLIID IS NULL

-- ATV 4
CREATE VIEW TaxiNovo AS
SELECT *
FROM Taxi
WHERE AnoFab >= 2000
WITH CHECK OPTION;

INSERT INTO TaxiNovo (Placa, Marca, Modelo, AnoFab)
VALUES ('XYZ1234', 'Toyota', 'Etios', 1999);
--REPOSTA: Insert não é executado pois não satifaz a clasula do WHERE na VIew