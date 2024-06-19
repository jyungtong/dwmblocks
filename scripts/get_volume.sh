#!/bin/bash

# Check if audio is muted
if pactl get-sink-mute @DEFAULT_SINK@ | grep -q "Mute: yes"; then
    echo "-"
else
    # Get the volume percentage
    pactl get-sink-volume @DEFAULT_SINK@ | sed -n 's/.* \([0-9]*%\).*/\1/p'
fi
