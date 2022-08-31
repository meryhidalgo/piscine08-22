#!/bin/sh
id -p $FT_USER | grep 'groups' | tr ' ' ',' | cut -f 2 | tr -d '\n'
