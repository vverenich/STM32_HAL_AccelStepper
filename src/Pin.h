#ifndef PIN_H
#define PIN_H

#include <cstdint>
// Replace it with the actual path to main.h
#include "../Core/Inc/main.h"

struct Pin {
    GPIO_TypeDef* m_GPIOx{nullptr};
    uint16_t m_GPIO_Pin{};
};

#endif
