# 🧩 STM32 USB Stack (Bare-Metal USB 2.0 Device Implementation)

A fully custom **USB 2.0 Full-Speed Device Stack** (Control Transfers only) for the STM32L4 series — implemented **from scratch** without any libraries or hardware abstraction layers (HAL). Built to gain low-level mastery of the USB protocol and device enumeration process.

> ⚠️ No HAL. No CMSIS USB stack. No middleware. Just raw C and bit-banging your way into USB.

---

![GitHub repo size](https://img.shields.io/github/repo-size/yourusername/stm32-usb-stack?color=blue)
![Lines of code](https://img.shields.io/tokei/lines/github/yourusername/stm32-usb-stack)
![License](https://img.shields.io/github/license/yourusername/stm32-usb-stack?color=green)
![Build](https://img.shields.io/badge/build-manual%20(make)-red)

---

## 🎯 Project Goals

- Implement a **minimal USB 2.0 Full-Speed Device Stack** on STM32L433RC
- Support **Control Transfers** (SETUP, DATA, STATUS) for descriptors
- **Enumerate successfully on a host system** (e.g., Windows/Linux)
- Use **logic analyzers** to debug low-level USB packets
- Optional: Implement a **USB bootloader (DFU-style)**

---

## 📚 Educational Value

This project is perfect if you want to:

- Learn **how USB works at the protocol level**
- Master **control transfer state machines**
- Debug and analyze USB traffic in a logic analyzer
- Write register-level embedded firmware without relying on vendor APIs
- Demonstrate your skill on **resumes, internships, or personal portfolios**

---

## ⚙️ Tech Stack

| Layer | Technology |
|-------|------------|
| MCU | STM32L433RCT6 (Cortex-M4, 256KB Flash, 64KB RAM) |
| Language | C (bare-metal, freestanding) |
| Toolchain | arm-none-eabi-gcc, Make |
| Debug | Logic analyzer (e.g., Saleae Logic 8), USB protocol decoder |
| Upload | ST-Link, DFU boot mode |

---

## 📁 Folder Structure

```bash
stm32-usb-stack/
├── src/                   # USB logic and control flow
├── inc/                   # Headers and protocol definitions
├── device/                # STM32 register definitions (manual or CMSIS)
├── startup/               # Vector table and Reset_Handler (assembly)
├── utils/                 # Logic analyzer logs, timing notes
├── docs/                  # USB protocol write-ups, DFU design notes
├── test/                  # Test cases, USB enumeration logs
├── Makefile               # Build system
├── linker.ld              # Memory layout and section mapping
└── README.md              # This file!
