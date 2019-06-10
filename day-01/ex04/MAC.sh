#!/bin/bash
ifconfig -a | grep "ether " | sed "s/[ 	]//g" | sed "s/ether//g"

