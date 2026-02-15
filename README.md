# MSP430G2553 Distance Measurement System

⚠ Akademik Uyarı

Bu proje tarafımdan ders kapsamında geliştirilmiştir.

İzinsiz kopyalanması veya akademik amaçla teslim edilmesi yasaktır.
Lütfen kendi emeğinizle çalışın. Kullanmak isterseniz önce benimle iletişime geçiniz.


=== 
🇹🇷 TÜRKÇE 
===

## Proje Özeti

Bu proje Mikroişlemciler dersi kapsamında geliştirilmiş
uçtan uca bir gömülü sistem uygulamasıdır.

Sistem MSP430G2553 mikrodenetleyicisi kullanılarak
MSP430 LaunchPad üzerinde geliştirilmiştir.

Mesafe ölçümü Time-of-Flight sensörleri ile gerçekleştirilmiştir.


## Kullanılan Donanım

- MSP430G2553 Mikrodenetleyici
- MSP430 LaunchPad
- VL53L0X ToF Sensörü
- VL6180X Mesafe Sensörü
- I2C Haberleşme


## Donanım ve PCB Tasarımı

Bu proje kapsamında yalnızca yazılım geliştirilmemiş,
aynı zamanda sistemin kart tasarımı da tarafımdan yapılmıştır.

- Devre şeması Altium Designer kullanılarak çizilmiştir.
- PCB tasarımı Altium üzerinde hazırlanmıştır.
- Baskı devre üretimi gerçekleştirilmiştir.
- Lehimleme ve donanım montajı manuel olarak yapılmıştır.

Bu sayede proje hem yazılım hem donanım seviyesinde
tam entegre bir gömülü sistem olarak geliştirilmiştir.


## Yazılım Mimarisi

Proje modüler bir yapı ile geliştirilmiştir:

- src/        → Ana uygulama (main)
- drivers/    → GPIO, I2C ve sensör sürücüleri
- Images/     → Proje görselleri

Gerçekleştirilen yazılım çalışmaları:

- Bare-metal C programlama
- GPIO konfigürasyonu
- I2C protokol implementasyonu
- Sensör sürücü entegrasyonu
- Gerçek zamanlı mesafe ölçümü


=== 
🇬🇧 ENGLISH 
====

## Project Overview

This project was developed as part of the Microprocessors course
as a complete end-to-end embedded system.

The system is based on the MSP430G2553 microcontroller
and developed using the MSP430 LaunchPad.

Distance measurement is performed using Time-of-Flight sensors.


## Hardware Used

- MSP430G2553 Microcontroller
- MSP430 LaunchPad
- VL53L0X ToF Sensor
- VL6180X Distance Sensor
- I2C Communication


## Hardware & PCB Design

In addition to firmware development, the hardware was fully designed by me.

- Schematic design was created using Altium Designer.
- PCB layout was designed in Altium.
- PCB manufacturing was completed.
- Manual soldering and assembly were performed.

This makes the project a complete embedded system,
covering both hardware and firmware development.


## Software Architecture

The project follows a modular architecture:

- src/        → Main application
- drivers/    → GPIO, I2C, and sensor drivers
- Images/     → Project images

Implemented features:

- Bare-metal C programming
- GPIO configuration
- I2C protocol implementation
- Sensor driver integration
- Real-time distance measurement

