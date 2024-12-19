# STM32_HAL_AccelStepper
STM32 HAL based AccelStepper library.

This is STM32 HAL based AccelStepper library. Library allows you to control stepper as easy as you can do it with Arduino AccelStepper library.

## Prerequisites
In order to be able to use this library you have to install STM32_HAL_micros library. All the information as well as installation instaructions you can find here:

https://github.com/vverenich/STM32_HAL_micros/tree/main

## Installation
1) Copy the src/ folder to your project
2) Edit Pin.h file at the following location:

```
// Replace it with the actual path to main.h
#include "../Core/Inc/main.h"
```

3) Edit AccelStepper.cpp file at the following ocation:

```
// Replace it with the actual path to main.h
#include "../../Core/Inc/main.h"
// Replace it with the actual path to micros.h
#include "../../Core/Inc/micros.h"
```

## Example

```
#include <string.h>

#include <memory>

#include "main.h"
#include "AccelStepper.h"


Pin EN_Pin{GPIOD, GPIO_PIN_5};
Pin STEP_Pin{GPIOD, GPIO_PIN_6};
Pin DIR_Pin{GPIOD, GPIO_PIN_7};

std::unique_ptr<AccelStepper> accelStepper{nullptr};

void setupCpp() {
    // Enable stepper 
    HAL_GPIO_WritePin(EN_Pin.m_GPIOx, EN_Pin.m_GPIO_Pin, GPIO_PIN_RESET);
    
    accelStepper = std::make_unique<AccelStepper>(AccelStepper::DRIVER, STEP_Pin, DIR_Pin);
        
        
    accelStepper->setMaxSpeed(1000);
    accelStepper->setAcceleration(50);
    accelStepper->moveTo(2000);
}

void loopCpp() {
    if (!accelStepper->run()) {
        accelStepper->moveTo(-accelStepper->currentPosition());
    }
}

extern "C" {

void setup() {
    setupCpp();
}

void loop() {
    loopCpp();
}
}

```
