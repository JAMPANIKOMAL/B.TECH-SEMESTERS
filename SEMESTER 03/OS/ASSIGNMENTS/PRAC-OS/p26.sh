#!/bin/bash

# Function to calculate Simple Interest
calculate_simple_interest() {
    echo "Enter Principal Amount (P): "
    read principal
    echo "Enter Rate of Interest (R): "
    read rate
    echo "Enter Time Period in years (T): "
    read time

    # Simple Interest formula: SI = (P * R * T) / 100
    simple_interest=$(echo "scale=2; ($principal * $rate * $time) / 100" | bc)
    echo "Simple Interest (SI): $simple_interest"
}

# Function to calculate Compound Interest
calculate_compound_interest() {
    echo "Enter Principal Amount (P): "
    read principal
    echo "Enter Rate of Interest (R): "
    read rate
    echo "Enter Time Period in years (T): "
    read time
    echo "Enter Number of Times Interest is Compounded per Year (N): "
    read n

    # Compound Interest formula: CI = P * ((1 + R/(100*N))^(N*T)) - P
    compound_interest=$(echo "scale=2; $principal * ((1 + $rate / (100 * $n)) ^ ($n * $time)) - $principal" | bc -l)
    echo "Compound Interest (CI): $compound_interest"
}

# Main program
echo "Choose the type of interest to calculate:"
echo "1. Simple Interest"
echo "2. Compound Interest"
read choice

case $choice in
    1) calculate_simple_interest ;;
    2) calculate_compound_interest ;;
    *) echo "Invalid choice!" ;;
esac
