#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include "soc/soc_caps.h"
#include <stdint.h>

// ── USB ─────────────────────────────────────────────────────────────────────
#define USB_VID 0x303A
#define USB_PID 0x1001
#define USB_as_HID 1

// ── UART0 (debug) ────────────────────────────────────────────────────────────
static const uint8_t TX = 43;
static const uint8_t RX = 44;
#define SERIAL_TX 43
#define SERIAL_RX 44

// ── I2C (SDA=8, SCL=9) -> OLED SSD1306 (Перевели на боковой пин 9!) ─────────
#define GROVE_SDA 8
#define GROVE_SCL 9    // ИСПРАВЛЕНО: Был 18, теперь 9 — это боковой пин Super Mini!

#define HAS_SI5351 0   // Отключаем генератор клоков, у нас его нет
static const uint8_t SDA = GROVE_SDA;
static const uint8_t SCL = GROVE_SCL;

// ── SPI bus (shared для nRF24) ────────────────────────────────────────────────
#define SPI_MOSI_PIN 11  // Боковой MOSI
#define SPI_SCK_PIN  12  // Боковой SCK
#define SPI_MISO_PIN 13  // Боковой MISO
#define SPI_SS_PIN   10  // Боковой CSN для nRF24
static const uint8_t MOSI = SPI_MOSI_PIN;
static const uint8_t MISO = SPI_MISO_PIN;
static const uint8_t SCK  = SPI_SCK_PIN;
static const uint8_t SS   = SPI_SS_PIN;

// Отключаем CC1101, так как ты просил оставить только nRF24
#define CC1101_GDO0_PIN  -1
#define CC1101_SS_PIN    -1

// Отключаем SD-карту (или вешаем CS на неиспользуемый пин, например, 43-TX)
#define SDCARD_CS    43 

// ── NRF24L01 #1 (Твоё радио — ВСЕ ПИНЫ НА БОКУ!) ─────────────────────────────
#ifndef USE_NRF24_VIA_SPI
#define USE_NRF24_VIA_SPI
#endif
#define NRF24_CE_PIN   14  // Боковой пин CE
#define NRF24_SS_PIN   10  // Боковой пин CSN
#ifndef NRF24_MOSI_PIN
#define NRF24_MOSI_PIN SPI_MOSI_PIN
#endif
#ifndef NRF24_SCK_PIN
#define NRF24_SCK_PIN  SPI_SCK_PIN
#endif
#ifndef NRF24_MISO_PIN
#define NRF24_MISO_PIN SPI_MISO_PIN
#endif

// ── IR (Инфракрасный порт — ТЕПЕРЬ ТОЖЕ НА БОКУ!) ───────────────────────────
#define RXLED   1   // ИК-Приемник -> пин GPIO 1 (боковой)
#define TXLED   2   // ИК-Диод -> пин GPIO 2 (боковой)
#define LED_ON  HIGH
#define LED_OFF LOW

#define RF_TX_DEFAULT -1
#define RF_RX_DEFAULT -1
#define BUZZ_PIN -1

// ── Кнопки управления (ВСЕ 6 ШТУК ТЕПЕРЬ НА БОКОВЫХ ПИНАХ!) ──────────────────
#define HAS_5_BUTTONS
#define BTN_ALIAS "\"OK\""
#define SEL_BTN  7   // OK    -> GPIO 7 (Боковой!)
#define UP_BTN   3   // UP    -> GPIO 3 (Боковой!)
#define DW_BTN   4   // DOWN  -> GPIO 4 (Боковой!)
#define L_BTN    5   // LEFT  -> GPIO 5 (Боковой!)
#define R_BTN    6   // RIGHT -> GPIO 6 (Боковой!)
#define ESC_BTN  0   // BACK  -> GPIO 0 (Боковая кнопка BOOT на плате!)
#define BTN_ACT  LOW

// ── Настройки экрана ─────────────────────────────────────────────────────────
#define HAS_SCREEN  1
#define ROTATION    2
#define MINBRIGHT   0
#define TFT_BL              -1
#define BACKLIGHT           -1
#define SMOOTH_FONT         0       

#define FP 1
#define FM 1
#define FG 2

#define DEVICE_NAME "\"BruceButBetter\""

#endif /* Pins_Arduino_h */

