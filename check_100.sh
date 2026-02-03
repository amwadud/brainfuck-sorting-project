#!/bin/bash

while true; do
    # 1. Generate 100 unique random numbers between -1000 and 1000
    ARG=$(shuf -i 1-2147483647 -n 100 | awk '{print $1 - 1000}' | tr '\n' ' ')

    # 2. Run push_swap and count operations
    COUNT=$(./push_swap "$ARG" | wc -l)

    # 3. Check if the output is actually sorted using the checker
    CHECK=$(./push_swap "$ARG" | ./checker_linux "$ARG")

    if [ "$CHECK" != "OK" ]; then
        echo "❌ FAILED: Checker said $CHECK"
        echo "Numbers: $ARG"
        break
    elif [ "$COUNT" -gt 700 ]; then
        echo "⚠️  TOO SLOW: $COUNT operations"
        echo "Numbers: $ARG"
        break
    else
        echo "✅ OK: $COUNT operations"
    fi
done
