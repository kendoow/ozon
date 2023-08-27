SELECT
    f.id AS fulfilment_id,
    f.name AS fulfilment_name,
    p.id AS package_id,
    p.name AS package_name,
    t.departure_time AS time_in,
    t.arrival_time AS time_out,
    (t.arrival_time - t.departure_time) AS storage_time
FROM
    transportations t
JOIN
    packages p ON t.package_id = p.id
JOIN
    fulfilments f ON t.destination_id = f.id
ORDER BY
    storage_time DESC,
    time_in ASC,
    f.id ASC,
    p.id ASC;
