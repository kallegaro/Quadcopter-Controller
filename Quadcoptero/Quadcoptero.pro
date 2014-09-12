TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += ../inc

SOURCES += \
    ../lib/src/peripherals/misc.c \
    ../lib/src/peripherals/stm32f4xx_adc.c \
    ../lib/src/peripherals/stm32f4xx_can.c \
    ../lib/src/peripherals/stm32f4xx_crc.c \
    ../lib/src/peripherals/stm32f4xx_cryp.c \
    ../lib/src/peripherals/stm32f4xx_cryp_aes.c \
    ../lib/src/peripherals/stm32f4xx_cryp_des.c \
    ../lib/src/peripherals/stm32f4xx_cryp_tdes.c \
    ../lib/src/peripherals/stm32f4xx_dac.c \
    ../lib/src/peripherals/stm32f4xx_dbgmcu.c \
    ../lib/src/peripherals/stm32f4xx_dcmi.c \
    ../lib/src/peripherals/stm32f4xx_dma.c \
    ../lib/src/peripherals/stm32f4xx_exti.c \
    ../lib/src/peripherals/stm32f4xx_flash.c \
    ../lib/src/peripherals/stm32f4xx_fsmc.c \
    ../lib/src/peripherals/stm32f4xx_gpio.c \
    ../lib/src/peripherals/stm32f4xx_hash.c \
    ../lib/src/peripherals/stm32f4xx_hash_md5.c \
    ../lib/src/peripherals/stm32f4xx_hash_sha1.c \
    ../lib/src/peripherals/stm32f4xx_i2c.c \
    ../lib/src/peripherals/stm32f4xx_iwdg.c \
    ../lib/src/peripherals/stm32f4xx_pwr.c \
    ../lib/src/peripherals/stm32f4xx_rcc.c \
    ../lib/src/peripherals/stm32f4xx_rng.c \
    ../lib/src/peripherals/stm32f4xx_rtc.c \
    ../lib/src/peripherals/stm32f4xx_sdio.c \
    ../lib/src/peripherals/stm32f4xx_spi.c \
    ../lib/src/peripherals/stm32f4xx_syscfg.c \
    ../lib/src/peripherals/stm32f4xx_tim.c \
    ../lib/src/peripherals/stm32f4xx_usart.c \
    ../lib/src/peripherals/stm32f4xx_wwdg.c \
    ../lib/src/stm32f4_discovery.c \
    ../lib/src/system_stm32f4xx.c \
    ../src/ADXL345.c \
    ../src/aquisicao_IMU.c \
    ../src/array_functions.c \
    ../src/controle_motores.c \
    ../src/funcoes_spi.c \
    ../src/HMC5883L.c \
    ../src/kalman_filter.c \
    ../src/L3G4200D.c \
    ../src/main (bcallegaro-System-Product-Name's conflicted copy 2014-08-23).c \
    ../src/main.c \
    ../src/MPU6050.c \
    ../src/nRF24l01.c \
    ../src/processamento_entrada.c \
    ../src/processo_controle.c \
    ../src/stm32f4_discovery.c \
    ../src/stm32f4_discovery_lis302dl.c \
    ../src/stm32f4xx_it.c \
    ../src/system_stm32f4xx.c \
    ../src/tratamento_sinal.c \
    ../.metadata/.plugins/org.eclipse.cdt.make.core/specs.cpp \
    ../.metadata/.plugins/org.eclipse.cdt.make.core/specs.c \
    ../lib/src/peripherals/misc.c \
    ../lib/src/peripherals/stm32f4xx_adc.c \
    ../lib/src/peripherals/stm32f4xx_can.c \
    ../lib/src/peripherals/stm32f4xx_crc.c \
    ../lib/src/peripherals/stm32f4xx_cryp.c \
    ../lib/src/peripherals/stm32f4xx_cryp_aes.c \
    ../lib/src/peripherals/stm32f4xx_cryp_des.c \
    ../lib/src/peripherals/stm32f4xx_cryp_tdes.c \
    ../lib/src/peripherals/stm32f4xx_dac.c \
    ../lib/src/peripherals/stm32f4xx_dbgmcu.c \
    ../lib/src/peripherals/stm32f4xx_dcmi.c \
    ../lib/src/peripherals/stm32f4xx_dma.c \
    ../lib/src/peripherals/stm32f4xx_exti.c \
    ../lib/src/peripherals/stm32f4xx_flash.c \
    ../lib/src/peripherals/stm32f4xx_fsmc.c \
    ../lib/src/peripherals/stm32f4xx_gpio.c \
    ../lib/src/peripherals/stm32f4xx_hash.c \
    ../lib/src/peripherals/stm32f4xx_hash_md5.c \
    ../lib/src/peripherals/stm32f4xx_hash_sha1.c \
    ../lib/src/peripherals/stm32f4xx_i2c.c \
    ../lib/src/peripherals/stm32f4xx_iwdg.c \
    ../lib/src/peripherals/stm32f4xx_pwr.c \
    ../lib/src/peripherals/stm32f4xx_rcc.c \
    ../lib/src/peripherals/stm32f4xx_rng.c \
    ../lib/src/peripherals/stm32f4xx_rtc.c \
    ../lib/src/peripherals/stm32f4xx_sdio.c \
    ../lib/src/peripherals/stm32f4xx_spi.c \
    ../lib/src/peripherals/stm32f4xx_syscfg.c \
    ../lib/src/peripherals/stm32f4xx_tim.c \
    ../lib/src/peripherals/stm32f4xx_usart.c \
    ../lib/src/peripherals/stm32f4xx_wwdg.c \
    ../lib/src/stm32f4_discovery.c \
    ../lib/src/system_stm32f4xx.c \
    ../src/ADXL345.c \
    ../src/aquisicao_IMU.c \
    ../src/array_functions.c \
    ../src/controle_motores.c \
    ../src/funcoes_spi.c \
    ../src/HMC5883L.c \
    ../src/kalman_filter.c \
    ../src/L3G4200D.c \
    ../src/main (bcallegaro-System-Product-Name's conflicted copy 2014-08-23).c \
    ../src/main.c \
    ../src/MPU6050.c \
    ../src/nRF24l01.c \
    ../src/processamento_entrada.c \
    ../src/processo_controle.c \
    ../src/stm32f4_discovery.c \
    ../src/stm32f4_discovery_lis302dl.c \
    ../src/stm32f4xx_it.c \
    ../src/system_stm32f4xx.c \
    ../src/tratamento_sinal.c

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    ../inc/ADXL345.h \
    ../inc/aquisicao_IMU.h \
    ../inc/array_functions.h \
    ../inc/controle_motores.h \
    ../inc/funcoes_spi.h \
    ../inc/HMC5883L.h \
    ../inc/kalman_filter.h \
    ../inc/L3G4200D.h \
    ../inc/MPU6050.h \
    ../inc/nRF24l01.h \
    ../inc/processamento_entrada.h \
    ../inc/processo_controle.h \
    ../inc/stm32f4_discovery.h \
    ../inc/stm32f4_discovery_lis302dl.h \
    ../inc/stm32f4xx_conf.h \
    ../inc/stm32f4xx_it.h \
    ../inc/tratamento_sinal.h \
    ../lib/inc/core/arm_common_tables.h \
    ../lib/inc/core/arm_math.h \
    ../lib/inc/core/core_cm0.h \
    ../lib/inc/core/core_cm0plus.h \
    ../lib/inc/core/core_cm3.h \
    ../lib/inc/core/core_cm4.h \
    ../lib/inc/core/core_cm4_simd.h \
    ../lib/inc/core/core_cmFunc.h \
    ../lib/inc/core/core_cmInstr.h \
    ../lib/inc/core/core_sc000.h \
    ../lib/inc/core/core_sc300.h \
    ../lib/inc/peripherals/misc.h \
    ../lib/inc/peripherals/stm32f4xx_adc.h \
    ../lib/inc/peripherals/stm32f4xx_can.h \
    ../lib/inc/peripherals/stm32f4xx_crc.h \
    ../lib/inc/peripherals/stm32f4xx_cryp.h \
    ../lib/inc/peripherals/stm32f4xx_dac.h \
    ../lib/inc/peripherals/stm32f4xx_dbgmcu.h \
    ../lib/inc/peripherals/stm32f4xx_dcmi.h \
    ../lib/inc/peripherals/stm32f4xx_dma.h \
    ../lib/inc/peripherals/stm32f4xx_exti.h \
    ../lib/inc/peripherals/stm32f4xx_flash.h \
    ../lib/inc/peripherals/stm32f4xx_fsmc.h \
    ../lib/inc/peripherals/stm32f4xx_gpio.h \
    ../lib/inc/peripherals/stm32f4xx_hash.h \
    ../lib/inc/peripherals/stm32f4xx_i2c.h \
    ../lib/inc/peripherals/stm32f4xx_iwdg.h \
    ../lib/inc/peripherals/stm32f4xx_pwr.h \
    ../lib/inc/peripherals/stm32f4xx_rcc.h \
    ../lib/inc/peripherals/stm32f4xx_rng.h \
    ../lib/inc/peripherals/stm32f4xx_rtc.h \
    ../lib/inc/peripherals/stm32f4xx_sdio.h \
    ../lib/inc/peripherals/stm32f4xx_spi.h \
    ../lib/inc/peripherals/stm32f4xx_syscfg.h \
    ../lib/inc/peripherals/stm32f4xx_tim.h \
    ../lib/inc/peripherals/stm32f4xx_usart.h \
    ../lib/inc/peripherals/stm32f4xx_wwdg.h \
    ../lib/inc/pdm_filter.h \
    ../lib/inc/stm32f4_discovery.h \
    ../lib/inc/stm32f4xx.h \
    ../lib/inc/system_stm32f4xx.h

OTHER_FILES += \
    ../Makefile

