#!/bin/bash

extract_errors()
{
    journalctl -p err -b
}

extract_errors
