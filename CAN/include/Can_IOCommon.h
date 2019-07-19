/* Can_IOCommon.h: define base address and structure of bxCAN Hw STM32F407VG */

#ifndef CAN_IOCOMMON_H
#define CAN_IOCOMMON_H

/*
 * Define HW structure map
 */

/* Master Control and Status registers */
typedef struct Can_CtrlSts_STag {
  /* Master control register */
  uint32 ulMCReg;
  /* Master status register */
  uint32 ulMSReg;
  /* Transmit mailbox status register */
  uint32 ulTSReg;
  /* Receive FIFO0 status register */
  uint32 ulRF0Reg;
  /* Receive FIFO1 status register */
  uint32 ulRF1Reg;
  /* Interrupt enable register */
  uint32 ulIEReg;
  /* Error status register */
  uint32 ulESReg;
  /* Bit timing register, configure baudrate */
  uint32 ulBTReg;
} Can_CtrlSts;

/* Transmit mailbox register */
typedef struct Can_TxMbx_STag {
  /* ID field value, ID type, frame type, TxRequest - TIxR */
  uint32 ulTXIDRQReg;
  /* DLC, TimeStamp - TDTxR */
  uint32 ulTXDLCTSReg;
  /* Data low - TDLxR */
  uint32 ulTXDATALReg;
  /* Data high - TDHxR */
  uint32 ulTXDATAHReg;
} Can_TxMbx;

/* Receive FIFO mailbox register */
typedef struct Can_RxMbx_STag {
  /* ID field value, ID type, frame type - RIxR */
  uint32 ulRXIDReg;
  /* DLC, Filter match index, TimeStamp - RDTxR */
  uint32 ulRXDLCTSR;
  /* Receive Data low - RDLxR */
  uint32 ulRXDATALReg;
  /* Receive Data high - RDHxR */
  uint32 ulRXDATAHReg;
} Can_RxMbx;

/* Receive rule register */
typedef struct Can_Filter_STag {
  uint32 ulFMReg;
  uint32 ulFM1Reg;
  uint32 dummy0;
  uint32 ulFS1Reg;
  uint32 dummy1;
  uint32 ulFFA1Reg;
  uint32 dummy2;
  uint32 ulFA1Reg;
  uint32 dummy3[8];
  uint32 ulFReg[28][2];
} Can_Filter;


/*
 * Define address of HW
 */

#define CAN1_BASEADDR 0x40006400UL
#define CAN2_BASEADDR 0x40006800UL

#define Can1_CtrlSts (*(volatile Can_CtrlSts *)(CAN1_BASEADDR + 0UL))
#define Can1_




#endif /*End of Can_IOCommon.h*/