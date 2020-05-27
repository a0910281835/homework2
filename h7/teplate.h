//-------------------------------------
// FWinfo
//-------------------------------------
#define BUILD_COUNT 0
#define TASK_ID 0000
#define FW_SETTING_ID 0000
//#define _OFFLINE
#define MAX_W_SIZE 50
#define MAX_H_SIZE 50
#define MAX_WH_SIZE 100
//#define _TOUCH_PID_LOCK
#define TOUCH_PID 0x09050009
//#define _PEN_PID_LOCK
//#define _CS_PID_LOCK

//-------------------------------------
// SelfSense
//-------------------------------------
#define DMA_QRX_ENABLE         0
#define DMA_QRX_16BIT          1
#define SENSING_EN_QRX       0x0
#define SENSING_EN_FRX       0x0

#define QM_MODE             0x00
#define QM_LOOP             0x04
#define QM_RX_VREF_SEL      0x05

#define HV_R_CV             0x10
#define HV_R_CUR          0x0100

//#define _INCLUDE_SELF_OPEN_SHORT
#define SELF_REF_CHARGETIME 0xf00
#define TENDER_CHARGE          0
//#define _INCLUDE_SELF_OPEN_SHORT_DEBUG

//-------------------------------------
// MutualSense
//-------------------------------------
#define DMA_MRX_16BIT 1
#define DMA_MRX_AUTO_DIFF 0
#define DMA_MRX_RESULT_SEL 4
#define DMA_MRX_CONST 0x1

//#define _MUTUAL_DIF_16BIT_EN
#define SENSING_EN_MRX 0x1

#define TPCMQ_EN   0x1
#define DIFF_MODE  0x1

//#define _AUTO_HW_DIFF
//#define _USE_SIS9202
//#define _USE_SIS9203

#define LDO_R 5
#define MM_INT_NEG 1
#define MM_INT_POS 0
#define MM_INT_ILOOP 3

#define TX_MUT_S3_CYCLE_0  110
#define TX_MUT_D3_CYCLE_0  110

#define MM_PGA_GCF 0x6

#define RX_CYCLE 0x20
#define RX_PHASE 0x10

//#define _TX_NUM_OVER_128

//-------------------------------------
// Cali
//-------------------------------------
//#define _MEAN_SHIFT_BASE
#define MEAN_SHIFT_NOW_RATIO 8
#define MEAN_SHIFT_PRE_RATIO 8
#define MEAN_SHIFT_BASE_NUM  5
//#define _CALI_ENABLE
#define MAX_CALI_NUM 20
//#define _USE_CYCLE_ARRAY
#define RX_CYCLE_MAX 0x50
#define RX_CYCLE_MIN 0x1
#define RX_CYCLE_STP 0x2
#define TARGET_VOLTAGE 0xc00
#define TARGET_RANGE_HI 0x50
#define TARGET_RANGE_LO 0x50
#define CALI_PGA_GCF 0xf
#define CALI_ILOOP 0
//#define _DYN_LDO_R
#define CALI_LDO_R 12
//#define _CYCLE_NML_WGHT_ADJ_EN
#define CYCLE_PLS_CNT 0
#define CYCLE_MNS_CNT 0
#define CYCLE_NMLZTN 0
#define CYCLE_NML_WGHT 1
#define CYCLE_NML_DVSR 1
//-------------------------------------
// Multichip
//-------------------------------------
//#define   _MULTI_CHIP_EN
//#define   _MTU
//#define   _MC_NEW_STRUCT
//#define   _SPI_MST_SLV_PARAMETER_SYNC
//#define   _PARAMETER_SYNC_FOR_MST_RECEIVER
//#define   _SPI_MST_EN
#define     SPI_SLV_CS_NUM     0x1
#define     SPI_SLV_NUM        0x1
#define     MC_TX_NUM          60
#define     MC_RX_NUM          100
#define     MC_SLV0_START      1
#define     MC_SLV0_RX_NUM     40
#define     MC_SLV1_RX_NUM     40
#define     MUT_MC_AS_SLV      0x0
#define     MUT_MC_SLV_CH      0x0
#define     MUT_MC_SYNC_DIV    0x4
#define     MUT_MC_SYNC_SCYC   0xff0
#define     MUT_MC_SYNC_ECYC   0xf0
//#define  _SPI_SLV_EN
#define     SPI_SLV_CS         0x1
#define     SPI_SLV_INDEX      0x1
#define     _AUTO_DETECT_SPI_SLV_INDEX
//#define   _DIF_TRANSMISSION
