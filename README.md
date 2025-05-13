# PSoC Digital Safe Emulator (CajaFuerte)

## Overview

This project implements a digital safe interface using a PSoC microcontroller. It has features for  password entry via a keypad and a 2-digit 7-segment display for feedback and messages, and an RGB LED for status indication. The system allows users to enter a password, verify it, change it, and toggle input censoring.

## Features

-   **Password Protection**: Secure access using a numeric password.
-   **Keypad Input**: Standard 0-9 digit entry plus dedicated function keys.
-   **7-Segment Display**: Shows the last two entered digits (either actual numbers or '*' if censored) and scrolls status messages (e.g., "ACCESS GRANTED", "ACCESS DENIED", "RESET", "NEW PASS SET").
-   **RGB LED Status Indicator**:
    -   **Blue**: One character of the password entered.
    -   **White**: Two or more characters of the password entered.
    -   **Green (Successful Action)**: Indicates a correct password entry or other successful operations.
    -   **Red/Flashing (Error/Alert)**: Indicates an incorrect password (momentarily blue, then resets).
-   **Password Censoring**: Option to display '*' instead of the actual digits entered.
-   **Change Password**: Functionality to update the stored password.
-   **Input Reset**: Clear the current password entry.

## Hardware Requirements

-   **PSoC Microcontroller**: I can't quite recall the exact board we used. All I remember is that it was a PSoC from Cypress, and that we used PSoC Creator.
-   **Matrix Keypad**: A standard 4x4 or similar matrix keypad.
-   **2-Digit 7-Segment Display**: Common cathode or common anode, driven via multiplexing.
-   **RGB LED**: Or individual Red, Green, and Blue LEDs for status. The code directly controls pins for Red and Blue components (`Led_R_Write`, `Led_B_Write`). In our case the PSoC came built in with leds we could use.

## Software Components

The project is structured into several C files and headers:

-   `main.c`: Main application loop, handles display updates based on input length and LED status.
-   `PasswordActions.c`/`.h` (if .h existed): Manages all password-related logic including:
    -   Storing and verifying the password.
    -   Setting a new password.
    -   Toggling character censoring (`*` or actual digit).
    -   Handling password state and length.
-   `LibKeypad.c`/`LibKeypad.h`: Implements keypad scanning using an ISR. Decodes key presses into digits or special commands (Check Password, Reset, Set New Password, Toggle Censor).
-   `LibDisplay.c`/`LibDisplay.h`: Controls the 2-digit 7-segment display.
    -   Functions to display individual characters/numbers.
    -   Manages multiplexing of the two digits.
    -   Function to scroll strings across the display.
-   `LED_Actions.c`/`LED_Actions.h`: Controls the RGB LED, providing functions to set it to White, Blue, or Green (based on the function names and intended states).
-   `Globals.h`: Currently an empty header file.
-   `project.h`: Standard PSoC project header file providing hardware definitions.

## How to Use

The default password is **`1234`**.

Do note that there aren't any mappings for the LEDs or KeyPad, since they were managed through PSoC Creator. You will need to manually map them yourself using some program to be able to use it.

Afterwards you will need to load the program on the PSoC itself to be able to run it.