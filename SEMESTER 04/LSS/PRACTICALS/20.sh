#!/bin/bash

check_temperature()
{
    sensors | grep 'Package id 0'
}

check_temperature
