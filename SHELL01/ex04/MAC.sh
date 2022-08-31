#!/bin/sh
ifconfig | grep ether | cut -c 8- | sed 2d | tr -d ' '
