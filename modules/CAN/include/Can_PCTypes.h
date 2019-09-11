/*******************************************************************************
* File:         Can_PCTypes.h
* Revision:
* Author:
* Date:         02.08.2019
* Description:  
*******************************************************************************/
#ifndef CAN_PCTYPES_H
#define CAN_PCTYPES_H

typedef enum Can_ModeOpType_ETag
{
  CAN_INTERRUPT,
  CAN_POLLING,
  CAN_MIXED
} Can_ModeOpType;

/* Type of CanIcomSignalOperation */
typedef enum Can_IcomSignalOperationType_ETag
{
  CAN_ICOM_SIG_OP_AND = 0u,
  CAN_ICOM_SIG_OP_EQUAL,
  CAN_ICOM_SIG_OP_GREATER,
  CAN_ICOM_SIG_OP_SMALLER,
  CAN_ICOM_SIG_OP_XOR
} Can_IcomSignalOperationType;

typedef enum Can_IcomLevelType_ETag
{
  CAN_ICOM_LEVEL_ONE,
  CAN_ICOM_LEVEL_TWO
} Can_IcomLevelType;

typedef enum CanIcomVariantType_ETag
{
  CAN_ICOM_VARIANT_NONE,
  CAN_ICOM_VARIANT_HW,
  CAN_ICOM_VARIANT_SW
} CanIcomVariantType;

/* Data structure contain pre-compile data:
  ref to EcuM wakeup API
  ref to ICOM configuration data
  tx/rx/busoff processing option
  interrupt enable/disable status
  controller sw status
  controller tx/rx error status
  */
/* [ref]: ECUC_Can_00354 */
typedef struct Can_ControllerPCConfigType_STag
{
  EcuM_WakeupSourceType CanWakeupRef;
  Can_ModeOpType enCanWakeupModeOp;
  Can_ModeOpType enCanBusoffModeOp;
  Can_ModeOpType enCanRxModeOp;
  Can_ModeOpType enCanTxModeOp;
  uint8 ucCanControllerId;
} Can_ControllerPCConfigType;

/* Data structure contain pre-compile data:
  general configuration data of CAN module
  */
/* [ref]: ECUC_Can_00328 */
typedef struct Can_GeneralPCConfigType_STag
{
  uint8 ucCanIndex;
  uint8 ucCanMultiplexedTx;
  uint8 ucCanIcomEnable;
  Can_IcomGeneralPCConfigType * stCanIcomGeneral;
} Can_GeneralPCConfigType;

/* [ref]: ECUC_Can_00444 */
typedef struct Can_IcomGeneralPCConfigType_STag
{
  Can_IcomLevelType CanIcomLevel;
  CanIcomVariantType CanIcomVariant;
} Can_IcomGeneralPCConfigType;

#endif /*End of Can_PCTypes.h*/
