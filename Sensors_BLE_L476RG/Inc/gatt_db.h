/******************** (C) COPYRIGHT 2019 STMicroelectronics ********************
 * File Name          : gatt_db.h
 * Author             : SRA
 * Version            : V1.0.0
 * Date               : Oct-2019
 * Description        : Header file for gatt_db.c
 *******************************************************************************
 * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
 * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
 * TIME.
 * AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
 * INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
 * CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
 * INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
 ******************************************************************************/

#ifndef GATT_DB_H
#define GATT_DB_H

/* Includes ------------------------------------------------------------------*/
#include "hci.h"

/* Exported defines ----------------------------------------------------------*/
#define X_OFFSET 200
#define Y_OFFSET 50
#define Z_OFFSET 1000

/**
 * @brief Number of application services
 */
#define NUMBER_OF_APPLICATION_SERVICES (2)

/**
 * @brief Define How Many quaterions you want to trasmit (from 1 to 3)
 *        In this sample application use only 1
 */
#define SEND_N_QUATERNIONS 1

/* Exported typedef ----------------------------------------------------------*/
/**
 * @brief Structure containing acceleration value of each axis.
 */
typedef struct {
  int32_t AXIS_X;
  int32_t AXIS_Y;
  int32_t AXIS_Z;
} AxesRaw_t;

enum {
  ACCELERATION_SERVICE_INDEX = 0,
  ENVIRONMENTAL_SERVICE_INDEX = 1
};

/* Exported function prototypes ----------------------------------------------*/
tBleStatus Add_HWServW2ST_Service(void);
tBleStatus Add_SWServW2ST_Service(void);
void Read_Request_CB(uint16_t handle);
tBleStatus Environmental_Update(int32_t press, int16_t temp, int16_t humi);
tBleStatus Acc_Update(AxesRaw_t *x_axes, AxesRaw_t *g_axes, AxesRaw_t *m_axes);
tBleStatus Quat_Update(AxesRaw_t *q_axes);

#endif /* GATT_DB_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
