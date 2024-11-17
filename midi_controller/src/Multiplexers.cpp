//
// Created by Leozor on 17/11/2024.
//

#include "Multiplexers.h"
//Analog multiplexer on Arduino analog pin A10, enable pin on pin 6
CD74HC4067 mux1 = {
    A10,
    {2, 3, 4, 5},
    6,
};

//Analog multiplexer on Arduino analog pin A10, enable pin on pin 7
CD74HC4067 mux2 = {
    A10,
    {2, 3, 4, 5},
    7,
};

//Analog multiplexer on Arduino analog pin A10, enable pin on pin 8
CD74HC4067 mux3 = {
    A10,
    {2, 3, 4, 5},
    8,
};

//Analog multiplexer on Arduino analog pin A10, enable pin on pin 8
CD74HC4067 mux4 = {
    A10,
    {2, 3, 4, 5},
    9,
};

//Analog multiplexer on Arduino analog pin A10, enable pin on pin 8
CD74HC4067 mux5 = {
    A10,
    {2, 3, 4, 5},
    10,
};