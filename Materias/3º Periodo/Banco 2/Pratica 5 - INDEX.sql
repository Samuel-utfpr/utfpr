

CREATE TABLE vendas (
id SERIAL PRIMARY KEY,
cliente_id INT,
data_venda DATE,
valor NUMERIC(10,2)
);

INSERT INTO vendas (cliente_id, data_venda, valor)
SELECT 
    (RANDOM() * 1000)::INT,
    DATE '2020-01-01' + (RANDOM() * 1825)::INT,
    RANDOM() * 1000
FROM generate_series(1, 10000);--om duas casas decimais


CREATE INDEX idx_vendas_data_venda ON vendas (data_venda);

EXPLAIN ANALYZE
SELECT * FROM vendas
WHERE data_venda >= '2020-01-01';

EXPLAIN ANALYZE
SELECT * FROM vendas
WHERE data_venda >= '2025-01-01';
