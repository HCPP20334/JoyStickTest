# Ссылки
-----------------------------------------------------------------------------
 > [Документация к JoyStickAPI](./JoyStickAPI.md)
 |
 > [Скачать JE 1.1.5.3 x64](https://github.com/HCPP20334/JoyStickTest/releases/download/JE_1.1.5.3/JE_x64.exe)
 |
 > [Скачать JE 1.1.5.3 x86](https://github.com/HCPP20334/JoyStickTest/releases/download/JE_1.1.5.3/JE_x86.exe)
 |
 > [Скачать Исходники JE + API](https://github.com/HCPP20334/JoyStickTest/archive/refs/tags/JE.zip)
 |
 > [Скачаете JEUpdater для получение новых версии](https://github.com/HCPP20334/JoyStickTest/releases/download/JEUpdater/JEUpdate.exe)
-----------------------------------------------------------------------------
![пп](https://github.com/HCPP20334/JoyStickTest/assets/76736848/c8047a11-4896-47fa-8d3e-63d06deb7dc5)

 Сборка 1.1.5.3 (Обновление)
 Теперь есть две версии программы
 64 битная основная и 32 битная 
 ---------------------------
 Теперь есть хедеры под 32 бита
 Color32.h
 dSys32.h
 JoyStick32.h - (JoyStickAPI32)
 * в папке JE32 лежат исходники JE_x86.exe
20.11.2023
--------------------------------------------------------
16.11.23
-------

 * Добавлен тест скорости процессора
> Позже исходя из данных о скорости буду делать оптимизация под каждый тип процессора
------------------------------------------------------
Работает на моем API JoyStickAPI(JoyStick.h
Написана на С++ (С++11 MinGW TDM 4.9.2 64 bit) - JE_x64.exe 
Написана на С++ (С++11 MinGW TDM 4.9.2 32 bit) - JE_x86.exe
Писал в DevC++ 5.11 
# Компиляция С++ в других IDE и компиляторах
-------------------------------------------------------
для Компиляции из под VS нужно в начале добавить #pragma comment("lib","lib.lib") 
У меня не получилось скомпилить из под VSCode из того не могу подключить библиотеку для работы 
# Какие библиотеки используются в JE
> psapi , xinput , gdi32
-------------------------------------------------------
# Русcкий
![image](https://github.com/HCPP20334/JoyStickTest/assets/76736848/f7870d10-da42-49bd-bddb-e618524fd0d7)

# English
![image](https://github.com/HCPP20334/JoyStickTest/assets/76736848/ed2c84b1-88ef-4402-b01f-765d9abc0675)

HCPP Studio 2023
# Баги с кодировкой 
-------------
# замените символы как тут
![image](https://github.com/HCPP20334/JoyStickTest/assets/76736848/da97c999-7709-4d19-b30d-bb6621206e4e)

