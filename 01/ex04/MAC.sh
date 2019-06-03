#!/bin/sh
ifconfig | grep 'ether ' | sed 's/\(.*\)ether//g'
