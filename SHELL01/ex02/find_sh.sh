#!/bin/sh
find . -type f -name \*.sh -print0 | xargs -0 basename  -s .sh
