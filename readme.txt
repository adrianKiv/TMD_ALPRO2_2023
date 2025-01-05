>> SINGLE QUERY LIST :
- INSERT
- UPDATE
- DELETE
- SELECT
- JOIN

>> DOUBLE QUERY LIST :
- INSERT UPDATE
- INSERT DELETE
- INSERT SELECT
- UPDATE SELECT
- DELETE SELECT

>> FORMAT QUERY :
INSERT [nama_table] - [kode/primary key] : [value 1] - [value 2] - [value 3] [value 4] / [kode/primary key] - [value 1] - [value 2] - [value 3]
UPDATE [nama_table] - [kode/primary key] : [value 1] - [value 2] - [value 3] [value 4] / [kode/primary key] - [value 1] - [value 2] - [value 3]
DELETE [nama_table] - [kode/primary key]
SELECT [nama_table]
JOIN [nama_table] - [nama_table]
INSERT UPDATE [nama_table] - [kode/primary key] : [value 1] - [value 2] - [value 3] [value 4] / [kode/primary key] - [value 1] - [value 2] - [value 3]
INSERT DELETE [nama_table] - [kode/primary key] : [value 1] - [value 2] - [value 3] [value 4] / [kode/primary key] - [value 1] - [value 2] - [value 3]
INSERT SELECT [nama_table] - [kode/primary key] : [value 1] - [value 2] - [value 3] [value 4] / [kode/primary key] - [value 1] - [value 2] - [value 3]
UPDATE SELECT [nama_table] - [kode/primary key] : [value 1] - [value 2] - [value 3] [value 4] / [kode/primary key] - [value 1] - [value 2] - [value 3]
DELETE SELECT [nama_table] - [kode/primary key]

>> QUERY BERHASIL :
INSERT Ttani PTN14 tomat 3_kg bogor PTK11;
UPDATE Tternak PTK13 ayam 99_kg selatan;
DELETE Tternak PTK4;

INSERT UPDATE Tternak PTK14 sapi_medan 101_kg balik_papan;
INSERT DELETE Ttani PTN15 nanas 98kg solo PTK7;
INSERT SELECT Tternak PTK15 domba 94kg western;
DELETE SELECT Ttani PTN8;
UPDATE SELECT Tternak PTK10 domba_garut 39_kg bali;

JOIN Ttani Tternak;

>> QUERY GAGAL :
INSERT Ttani PTN3 nagka 33_kg bogor PTK4;
UPDATE Tternak PTK20 ayam_bakar 64_kg timur;
DELETE Ttani PTN221;
INSERT DELET Ttani PTN1 naga_goreng 65_kg kingdom;
INEERT SELECT Tternak PTK2 naga_goreng 65_kg kingdom;
INSERT Ttani PTN9 markisa 32_kg;

>> QUERY SELECT :
SELECT table;
SELECT Tternak;
SELECT Ttani;

>> QUERY SELECT GAGAL :
SELECT Tlaut;

>> QUERY KELUAR PROGRAM :
- keluar
- keluar;