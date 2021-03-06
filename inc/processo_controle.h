#include "stm32f4_discovery.h"
#include "stm32f4xx_tim.h"

#include "tm_stm32f4_i2c.h"
#include "MPU6050.h"
#include "HMC5883L.h"

#include "arm_math.h"
#include "kalman_filter.h"
#include "tratamento_sinal.h"

#ifndef _processo_controle_
#define _processo_controle_

	void setar_referencia(float Ref_pith, float Ref_roll, float Ref_yaw, float W_cte);
    void setar_parametros_PID(float Kp, float Ki, float Kd, float N, float Kp_yaw, float Ki_yaw, float Kd_yaw, float nYaw);
    void setar_parametros_Kalman(float32_t Q_angles, float32_t Q_biasacel, float32_t Q_biasmag, float32_t Q_biasAngle, float32_t R_acelerometro, float32_t R_magnetometro, float32_t R_angles);
	void setar_offset_acel(float offset[3]);
    void setar_offset_mag(float offset[3]);
	void setar_offset_gyro(float offset[3]);
	void retornar_parametros_pid(float *Kp, float *Ki, float *Kd);
    void retornar_parametros_Kalman(float32_t *Q_angles, float32_t *Q_biasacel, float32_t *Q_biasmag, float32_t *R_acelerometro, float32_t *R_magnetometro, float32_t *R_orthogonal);
	void processo_controle(void);
	void retornar_estado(float estado_KF[], float estado_PID[]);
	void retornar_estado_sensores(float Acelerometro[], float Giroscopio[], float Magnetometro[]);
	void retornar_offset_acel(float *offsetX, float *offsetY, float *offsetZ);
	void calculate_Yaw_Ref(float yaw_Rate);
	void iniciar_estado_Kalman();
    void processar_mpu6050();

#endif
