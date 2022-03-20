#!/bin/sh
Xvfb "$DISPLAY" -ac -screen 0 "$XVFB_RES" -nolisten tcp $XVFB_ARGS &
XVFB_PROC=$!
"$@"
kill $XVFB_PROC