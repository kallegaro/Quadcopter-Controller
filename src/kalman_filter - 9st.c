/*
 * kalman_filter.c
 *
 *  Created on: Sep 8, 2013
 *      Author: Bruno
 */
#ifndef ARM_MATH_CM4
	#define ARM_MATH_CM4
#endif

#define ARM_MATH_MATRIX_CHECK


#ifndef __FPU_USED
  	#define __FPU_USED 1
#endif

#ifndef __FPU_PRESENT
  	#define __FPU_PRESENT 1
#endif

#include <stm32f4xx_conf.h>
#include "kalman_filter.h"
#include "arm_math.h"

//------ Fun��o para c�lculo do filtro de kalman sobre o Girosc�pio e o Aceler�metro -------///
//Utiliza DCM -> Varia��o do vetor com base na velocidae agular para atualiza��o da matrz de atualiza��o de estados.
//Bruno f. M. Callegaro - 20/12/2013


float kalman_filter(kalman_filter_state *buffer_filtro, float medida_gyro[], float medida_accel[], float medida_mag[])
{
	//Instancias das matrizes utilizadas para o c�lculo
	arm_matrix_instance_f32 X;			//Matriz de estados. [9,1]
	arm_matrix_instance_f32 F;			//Matriz de transi��o de estados. [9,9]
	arm_matrix_instance_f32 Ft;			//Matriz de transi��o de estados transposta. [9,9]
	arm_matrix_instance_f32 I;			//Matriz identidadee. [9,9]
	arm_matrix_instance_f32 P;			//Matriz de confiabilidade do processo de atualiza��o. [3,3]
	arm_matrix_instance_f32 H;			//Matriz de mapeamento do estado para o erro [6x9]
	arm_matrix_instance_f32 Ht;			//Matriz de mapeamento do estado para o erro transposta. [9x6]
	arm_matrix_instance_f32 Qrdt;		//Matriz de covari�ncia multiplicada por dt; [9,9]
	arm_matrix_instance_f32 R;			//Matriz de vari�ncia [6,6]
	arm_matrix_instance_f32 z;
	arm_matrix_instance_f32 y;			//Matriz de erro entre medidas e estado estimado. [6,1]
	arm_matrix_instance_f32 S;			//Matriz .... [6,6]
	arm_matrix_instance_f32 Sinv;		//Matriz F inversa.
	arm_matrix_instance_f32 K;			//Matriz com os ganhos de Kalman [9,6]

		//Matrices intermedi�rias para c�lculo

	arm_matrix_instance_f32 temp_calc_910;
	arm_matrix_instance_f32 temp_calc_911;
	
	arm_matrix_instance_f32 temp_calc_990;
	arm_matrix_instance_f32 temp_calc_991;
	arm_matrix_instance_f32 temp_calc_992;
	arm_matrix_instance_f32 temp_calc_993;

	arm_matrix_instance_f32 temp_calc_610;

	arm_matrix_instance_f32 temp_calc_660;

	arm_matrix_instance_f32 temp_calc_690;

	arm_matrix_instance_f32 temp_calc_960;
	//Vari�veis para c�lculos
	float theta_x = (medida_gyro[0] - buffer_filtro->ultimo_estado[6])*buffer_filtro->dt; //Atualiza as vari�veis de deslocamento angular. - medida atual menos bias obtido no estado anterior.
	float theta_y = (medida_gyro[1] - buffer_filtro->ultimo_estado[7])*buffer_filtro->dt;
	float theta_z = (medida_gyro[2] - buffer_filtro->ultimo_estado[8])*buffer_filtro->dt;


	//Matriz identidade utilizada para facilitar atualiza��o das matrizes.
	float I_f32[81] = {1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1};
	arm_mat_init_f32(&I, 9, 9, I_f32);

	//Buffers que cont�m os valores em cada uma das matrizes.

	float X_f32[9];
	arm_copy_f32(buffer_filtro->ultimo_estado, X_f32, 9);
	arm_mat_init_f32(&X, 9, 1, X_f32);

	float P_f32[81];
	arm_copy_f32(buffer_filtro->P, P_f32, 81);
	arm_mat_init_f32(&P, 9, 9, P_f32);


	//Matriz de atualiza��o dos estados
	float F_f32[81] = {1, (theta_z), -(theta_y), 0, 0, 0, 0, 0, 0, -(theta_z), 1, (theta_x), 0, 0, 0, 0, 0, 0, (theta_y), -(theta_x), 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, (theta_z), -(theta_y), 0, 0, 0, 0, 0, 0, -(theta_z), 1, (theta_x), 0, 0, 0, 0, 0, 0, (theta_y), -(theta_x), 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1};
	arm_mat_init_f32(&F, 9, 9, F_f32);


	//Matriz de atualiza��o dos estados transposta
	float Ft_f32[81];
	arm_mat_init_f32(&Ft, 9, 9, Ft_f32);
	arm_mat_trans_f32(&F, &Ft);


	//Matriz de covari�ncias
	float Qacel = (buffer_filtro->Q_acel)*(buffer_filtro->dt);
	float Qmag = (buffer_filtro->Q_mag)*(buffer_filtro->dt);
	float Qbias = (buffer_filtro->Q_bias)*(buffer_filtro->dt);

	float Qrdt_f32[81] = {(Qacel), 0, 0, 0, 0, 0, 0, 0, 0, 0, (Qacel), 0, 0, 0, 0, 0, 0, 0, 0, 0, (Qacel), 0, 0, 0, 0, 0, 0, 0, 0, 0, (Qmag), 0, 0, 0, 0, 0, 0, 0, 0, 0, (Qmag), 0, 0, 0, 0, 0, 0, 0, 0, 0, (Qmag), 0, 0, 0, 0, 0, 0, 0, 0, 0, (Qbias), 0, 0, 0, 0, 0, 0, 0, 0, 0, (Qbias), 0, 0, 0, 0, 0, 0, 0, 0, 0, (Qbias)};
	arm_mat_init_f32(&Qrdt, 9, 9, Qrdt_f32);


	//Matriz de vari�ncias
	float Racel = buffer_filtro->R_acel;
	float Rmag = buffer_filtro->R_mag;
	
	float R_f32[36] = {(Racel), 0, 0, 0, 0, 0, 0, (Racel), 0, 0, 0, 0, 0, 0, (Racel), 0, 0, 0, 0, 0, 0, (Rmag), 0, 0, 0, 0, 0, 0, (Rmag), 0, 0, 0, 0, 0, 0, (Rmag)};
	arm_mat_init_f32(&R, 6, 6, R_f32);


	//Matriz de erro entre medida e estado estimado
	float y_f32[6];
	arm_mat_init_f32(&y, 6, 1, y_f32);


	//Matriz que cont�m as medidas do aceler�metro e magnetometro.
	float z_f32[6] = {medida_accel[0], medida_accel[1], medida_accel[2], medida_mag[0], medida_mag[1], medida_mag[2]};
	arm_mat_init_f32(&z, 6, 1, z_f32);

	//Matriz de mapeamento dos estados - H
	float H_f32[54] = {1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0};
	arm_mat_init_f32(&H, 6, 9, H_f32);

	//Matriz de mapeamento dos estados transposta - Ht
	float Ht_f32[54] = {1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; 
	arm_mat_init_f32(&Ht, 9, 6, Ht_f32);

	//Matriz S...
	float S_f32[36];
	arm_mat_init_f32(&S, 6, 6, S_f32);

	float Sinv_f32[36];
	arm_mat_init_f32(&Sinv, 6, 6, Sinv_f32);

	//Matriz do ganho de Kalman 
	float K_f32[54];
	arm_mat_init_f32(&K, 9, 6, K_f32);

	//Matrizes de suporte para o c�lculo
		//Matrizes de 9 linhas e 1 coluna
	float temp_calc_910_f32[9];
	float temp_calc_911_f32[9];
	
	arm_mat_init_f32(&temp_calc_910, 9, 1, temp_calc_910_f32);
	arm_mat_init_f32(&temp_calc_911, 9, 1, temp_calc_911_f32);

	//Matrizes de 9 linhas e 9 colunas
	float temp_calc_990_f32[81];
	float temp_calc_991_f32[81];
	float temp_calc_992_f32[81];
	float temp_calc_993_f32[81];

	arm_mat_init_f32(&temp_calc_990, 9, 9, temp_calc_990_f32);
	arm_mat_init_f32(&temp_calc_991, 9, 9, temp_calc_991_f32);
	arm_mat_init_f32(&temp_calc_992, 9, 9, temp_calc_992_f32);
	arm_mat_init_f32(&temp_calc_993, 9, 9, temp_calc_993_f32);


	//Matrizes de 6linhas e 1 coluna
	float temp_calc_610_f32[6];

	arm_mat_init_f32(&temp_calc_610, 6, 1, temp_calc_610_f32);

	//Matrizes de 6 linhas e 6 colunas
	float temp_calc_660_f32[36];

	arm_mat_init_f32(&temp_calc_660, 6, 6, temp_calc_660_f32);

	//Matrizes de 6 linhas e 9 colunas
	float temp_calc_690_f32[54];

	arm_mat_init_f32(&temp_calc_690, 6, 9, temp_calc_690_f32);

	//Matrizes de calculos de 9 linhas e 6 colunas
	float temp_calc_960_f32[54];

	arm_mat_init_f32(&temp_calc_960, 9, 6, temp_calc_960_f32);


	//C�lculos do filtro de Kalman
	//Etapas de predi��o - "A Priori"
	//X = F*X
	arm_mat_mult_f32(&F, &X, &temp_calc_910);

	//P = F*P*F'
	arm_mat_mult_f32(&F, &P, &temp_calc_990);
	arm_mat_mult_f32(&temp_calc_990, &Ft, &temp_calc_991);

	//P = P+Qrdt
	arm_mat_add_f32(&temp_calc_991, &Qrdt, &P);

	//y = z - H*X = z - H*X
	arm_mat_mult_f32(&H, &temp_calc_910, &temp_calc_610);
	arm_mat_sub_f32(&z, &temp_calc_610, &y);

	//S = H*P*H' + R
	arm_mat_mult_f32(&H, &P, &temp_calc_690);
	arm_mat_mult_f32(&temp_calc_690, &Ht, &temp_calc_660);
	arm_mat_add_f32(&temp_calc_660, &R, &S);

	//Sinv = inv(S);
	arm_mat_inverse_f32(&S, &Sinv);

	//Kk = P*H*S^(-1)
	arm_mat_mult_f32(&P, &Ht, &temp_calc_960);
	arm_mat_mult_f32(&temp_calc_960, &Sinv, &K);

	//temp_calc_911 = Kk*y
	arm_mat_mult_f32(&K, &y, &temp_calc_911);

	//X = temp_calc_910 + temp_calc_911;
	arm_mat_add_f32(&X, &temp_calc_911, &temp_calc_910);

	//P = (I-K*H)P
	arm_mat_mult_f32(&K, &H, &temp_calc_992);
	arm_mat_sub_f32(&I, &temp_calc_992, &temp_calc_993);

	arm_mat_mult_f32(&temp_calc_993, &P, &temp_calc_992);

	arm_copy_f32(X_f32, buffer_filtro->ultimo_estado, 9);
	arm_copy_f32(temp_calc_992_f32, buffer_filtro->P, 81);
	return 0;

}

