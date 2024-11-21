# Sogeor Platform x86 Boot MBR

## Введение

Данный метод загрузки основан на главной загрузочной записи (MBR) и состоит из 3-х следующих
стадий: `injector`, `manager`, `adapter`.

## Стадии

### `injector`

Данная стадия состоит только из MBR, загружает следующую стадию и передаёт ей управление. Если загрузить не удалось, то
выводит следующее сообщение: `Initial boot failed`.

### `manager`

Данный подраздел временно недоступен.

### `adapter`

Данный подраздел временно недоступен.

## Образ

### На накопителе

| Начальный адрес | Конечный адрес |      Размер | Примечание        |
|----------------:|---------------:|------------:|:------------------|
|             0x0 |          0x1FF |       512 Б | Стадия `injector` |
|           0x200 |      До 0x77FF |  До 29.5 Кб | Стадия `manager`  |
|       До 0x7800 |     До 0x7F9FF | До 480.5 Кб | Стадия `adapter`  |
|             ... |            ... |             | ...               |

### В оперативной памяти

| Начальный адрес | Конечный адрес |      Размер | Примечание                              |
|----------------:|---------------:|------------:|:----------------------------------------|
|             0x0 |          0x3FF |        1 Кб | Таблица векторов прерываний (IVT)       |
|           0x400 |          0x4FF |       256 Б | Область данных BIOS (BDA)               |
|           0x500 |          0x5FF |       256 Б | ...                                     |
|           0x600 |      До 0x7BFF |  До 29.5 Кб | Стадия `manager`                        |
|          0x7C00 |         0x7DFF |       512 Б | Стадия `injector`                       |
|          0x7E00 |     До 0x7FFFF | До 480.5 Кб | Стадия `adapter`                        |
|         0x80000 |        0x9FFFF |      128 Кб | Расширенная область данных BIOS (EBDA)  |
|         0xA0000 |        0xAFFFF |       64 Кб | Расширенная видеопамять (Для EGA)       |
|         0xB0000 |        0xBFFFF |       64 Кб | Стандартная видеопамять (Для MDA и CGA) |
|         0xC0000 |        0xCFFFF |       64 Кб | Расширения BIOS                         |
|         0xD0000 |        0xEFFFF |      128 Кб | Для LIM EMS и картриджей PCjr           |
|         0xF0000 |        0xFFFFF |       64 Кб | BIOS                                    |
|             ... |            ... |             | ...                                     |