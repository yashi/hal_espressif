/*
 * SPDX-FileCopyrightText: 2015-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __ESP_BT_CFG_H__
#define __ESP_BT_CFG_H__

#include <stdint.h>
#include <stdbool.h>
#include "esp_err.h"

#ifdef __cplusplus
extern "C" {
#endif

#if CONFIG_BT_NIMBLE_ENABLED
#include "syscfg/syscfg.h"
#endif

#define NIMBLE_LL_STACK_SIZE CONFIG_BT_LE_CONTROLLER_TASK_STACK_SIZE

#if CONFIG_BT_NIMBLE_ENABLED

    #if CONFIG_BT_NIMBLE_LL_CFG_FEAT_LE_CODED_PHY
    #define BLE_LL_SCAN_PHY_NUMBER_N (2)
    #else
    #define BLE_LL_SCAN_PHY_NUMBER_N (1)
    #endif

    #define DEFAULT_BT_LE_MAX_PERIODIC_ADVERTISER_LIST MYNEWT_VAL(BLE_MAX_PERIODIC_ADVERTISER_LIST)
    #define DEFAULT_BT_LE_MAX_PERIODIC_SYNCS MYNEWT_VAL(BLE_MAX_PERIODIC_SYNCS)
    #define DEFAULT_BT_LE_MAX_CONNECTIONS MYNEWT_VAL(BLE_MAX_CONNECTIONS)
    #define DEFAULT_BT_LE_ACL_BUF_SIZE MYNEWT_VAL(BLE_ACL_BUF_SIZE)
    #define DEFAULT_BT_LE_ACL_BUF_COUNT MYNEWT_VAL(BLE_ACL_BUF_COUNT)
    #define DEFAULT_BT_LE_HCI_EVT_BUF_SIZE MYNEWT_VAL(BLE_HCI_EVT_BUF_SIZE)
    #define DEFAULT_BT_LE_EXT_ADV_MAX_SIZE MYNEWT_VAL(BLE_EXT_ADV_MAX_SIZE)
    #define DEFAULT_BT_LE_MAX_EXT_ADV_INSTANCES MYNEWT_VAL(BLE_MULTI_ADV_INSTANCES)
    #define DEFAULT_BT_NIMBLE_WHITELIST_SIZE MYNEWT_VAL(BLE_LL_WHITELIST_SIZE)
    #define DEFAULT_BT_LE_HCI_EVT_HI_BUF_COUNT MYNEWT_VAL(BLE_HCI_EVT_HI_BUF_COUNT)
    #define DEFAULT_BT_LE_HCI_EVT_LO_BUF_COUNT MYNEWT_VAL(BLE_HCI_EVT_LO_BUF_COUNT)
    #define DEFAULT_BT_LE_COEX_PHY_CODED_TX_RX_TLIM_EFF CONFIG_BT_NIMBLE_COEX_PHY_CODED_TX_RX_TLIM_EFF

#else

    #if CONFIG_BT_LE_LL_CFG_FEAT_LE_CODED_PHY
    #define BLE_LL_SCAN_PHY_NUMBER_N (2)
    #else
    #define BLE_LL_SCAN_PHY_NUMBER_N (1)
    #endif

    #if defined(CONFIG_BT_LE_MAX_PERIODIC_ADVERTISER_LIST)
        #define DEFAULT_BT_LE_MAX_PERIODIC_ADVERTISER_LIST (CONFIG_BT_LE_MAX_PERIODIC_ADVERTISER_LIST)
    #else
        #define DEFAULT_BT_LE_MAX_PERIODIC_ADVERTISER_LIST (5)
    #endif

    #if defined(CONFIG_BT_LE_MAX_PERIODIC_SYNCS)
        #define DEFAULT_BT_LE_MAX_PERIODIC_SYNCS (CONFIG_BT_LE_MAX_PERIODIC_SYNCS)
    #else
        #define DEFAULT_BT_LE_MAX_PERIODIC_SYNCS (1)
    #endif

    #if defined(CONFIG_BT_LE_MAX_CONNECTIONS)
        #define DEFAULT_BT_LE_MAX_CONNECTIONS (CONFIG_BT_LE_MAX_CONNECTIONS)
    #else
        #define DEFAULT_BT_LE_MAX_CONNECTIONS (2)
    #endif

    #if defined(CONFIG_BT_LE_ACL_BUF_SIZE)
        #define DEFAULT_BT_LE_ACL_BUF_SIZE (CONFIG_BT_LE_ACL_BUF_SIZE)
    #else
        #define DEFAULT_BT_LE_ACL_BUF_SIZE (255)
    #endif

    #if defined(CONFIG_BT_LE_ACL_BUF_COUNT)
        #define DEFAULT_BT_LE_ACL_BUF_COUNT (CONFIG_BT_LE_ACL_BUF_COUNT)
    #else
        #define DEFAULT_BT_LE_ACL_BUF_COUNT (24)
    #endif

    #if defined(CONFIG_BT_LE_HCI_EVT_BUF_SIZE)
        #define DEFAULT_BT_LE_HCI_EVT_BUF_SIZE (CONFIG_BT_LE_HCI_EVT_BUF_SIZE)
    #else
        #define DEFAULT_BT_LE_HCI_EVT_BUF_SIZE (70)
    #endif

    #if defined(CONFIG_BT_LE_EXT_ADV_MAX_SIZE)
        #define DEFAULT_BT_LE_EXT_ADV_MAX_SIZE (CONFIG_BT_LE_EXT_ADV_MAX_SIZE)
    #else
        #define DEFAULT_BT_LE_EXT_ADV_MAX_SIZE (31)
    #endif

    #if defined(CONFIG_BT_LE_MAX_EXT_ADV_INSTANCES)
        #define DEFAULT_BT_LE_MAX_EXT_ADV_INSTANCES (CONFIG_BT_LE_MAX_EXT_ADV_INSTANCES)
    #else
        #define DEFAULT_BT_LE_MAX_EXT_ADV_INSTANCES (1)
    #endif

    #if defined(CONFIG_BT_LE_WHITELIST_SIZE)
        #define DEFAULT_BT_NIMBLE_WHITELIST_SIZE (CONFIG_BT_LE_WHITELIST_SIZE)
    #else
        #define DEFAULT_BT_NIMBLE_WHITELIST_SIZE (12)
    #endif

    #if defined(CONFIG_BT_LE_HCI_EVT_HI_BUF_COUNT)
        #define DEFAULT_BT_LE_HCI_EVT_HI_BUF_COUNT (CONFIG_BT_LE_HCI_EVT_HI_BUF_COUNT)
    #else
        #define DEFAULT_BT_LE_HCI_EVT_HI_BUF_COUNT (30)
    #endif

    #if defined(CONFIG_BT_LE_HCI_EVT_LO_BUF_COUNT)
        #define DEFAULT_BT_LE_HCI_EVT_LO_BUF_COUNT (CONFIG_BT_LE_HCI_EVT_LO_BUF_COUNT)
    #else
        #define DEFAULT_BT_LE_HCI_EVT_LO_BUF_COUNT (8)
    #endif

    #define DEFAULT_BT_LE_COEX_PHY_CODED_TX_RX_TLIM_EFF CONFIG_BT_LE_COEX_PHY_CODED_TX_RX_TLIM_EFF

#endif



#ifdef CONFIG_BT_LE_HCI_INTERFACE_USE_UART
#define HCI_UART_EN CONFIG_BT_LE_HCI_INTERFACE_USE_UART
#else
#define HCI_UART_EN 0 // hci ram mode
#endif

#ifdef CONFIG_BT_LE_SLEEP_ENABLE
#define NIMBLE_SLEEP_ENABLE CONFIG_BT_LE_SLEEP_ENABLE
#else
#define NIMBLE_SLEEP_ENABLE  0
#endif


#ifdef CONFIG_BT_LE_TX_CCA_ENABLED
    #define DEFAULT_BT_LE_TX_CCA_ENABLED (CONFIG_BT_LE_TX_CCA_ENABLED)
#else
    #define DEFAULT_BT_LE_TX_CCA_ENABLED (0)
#endif

#ifdef CONFIG_BT_LE_CCA_RSSI_THRESH
    #define DEFAULT_BT_LE_CCA_RSSI_THRESH (CONFIG_BT_LE_CCA_RSSI_THRESH)
#else
    #define DEFAULT_BT_LE_CCA_RSSI_THRESH (50)
#endif

#define DEFAULT_BT_LE_SCAN_RSP_DATA_MAX_LEN_N DEFAULT_BT_LE_EXT_ADV_MAX_SIZE


#if HCI_UART_EN
    #define DEFAULT_BT_LE_HCI_UART_TX_PIN (CONFIG_BT_LE_HCI_UART_TX_PIN)
    #define DEFAULT_BT_LE_HCI_UART_RX_PIN (CONFIG_BT_LE_HCI_UART_RX_PIN)
    #define DEFAULT_BT_LE_HCI_UART_PORT (CONFIG_BT_LE_HCI_UART_PORT)
    #define DEFAULT_BT_LE_HCI_UART_BAUD (CONFIG_BT_LE_HCI_UART_BAUD)
    #define DEFAULT_BT_LE_HCI_UART_DATA_BITS (UART_DATA_8_BITS)
    #define DEFAULT_BT_LE_HCI_UART_STOP_BITS (UART_STOP_BITS_1)
    #define DEFAULT_BT_LE_HCI_UART_PARITY (0)
    #define DEFAULT_BT_LE_HCI_UART_TASK_STACK_SIZE (CONFIG_BT_LE_HCI_UART_TASK_STACK_SIZE)
    #define DEFAULT_BT_LE_HCI_UART_FLOW_CTRL (0)
#else
    #define DEFAULT_BT_LE_HCI_UART_TX_PIN (0)
    #define DEFAULT_BT_LE_HCI_UART_RX_PIN (0)
    #define DEFAULT_BT_LE_HCI_UART_PORT (0)
    #define DEFAULT_BT_LE_HCI_UART_BAUD (0)
    #define DEFAULT_BT_LE_HCI_UART_DATA_BITS (0)
    #define DEFAULT_BT_LE_HCI_UART_STOP_BITS (0)
    #define DEFAULT_BT_LE_HCI_UART_PARITY (0)
    #define DEFAULT_BT_LE_HCI_UART_TASK_STACK_SIZE (0)
    #define DEFAULT_BT_LE_HCI_UART_FLOW_CTRL (0)
#endif

/* Unchanged configuration */

#define BLE_LL_CTRL_PROC_TIMEOUT_MS_N       (40000) /* ms */

#define BLE_LL_CFG_NUM_HCI_CMD_PKTS_N       (1)

#define BLE_LL_SCHED_ADV_MAX_USECS_N        (852)

#define BLE_LL_SCHED_DIRECT_ADV_MAX_USECS_N (502)

#define BLE_LL_SCHED_MAX_ADV_PDU_USECS_N    (376)

#define BLE_LL_SUB_VERS_NR_N                (0x0000)

#define BLE_LL_JITTER_USECS_N               (16)

#define BLE_PHY_MAX_PWR_DBM_N               (10)

#define BLE_LL_CONN_DEF_AUTH_PYLD_TMO_N     (3000)

#define RTC_FREQ_N                          (160000) /* in Hz */

#define BLE_LL_TX_PWR_DBM_N                 (9)


#define RUN_BQB_TEST                        (0)
#define RUN_QA_TEST                         (0)
#define NIMBLE_DISABLE_SCAN_BACKOFF         (0)


#ifdef __cplusplus
}
#endif

#endif /* __ESP_BT_CFG_H__ */
